#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

//variables
int arrayRow = 0;
int arrayCollum = 0;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    //loop to the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //if the string name is in the list of candidates
        if (strcmp(candidates[i].name, name) == 0)
        {
            //store the preferences
            preferences[voter][rank] = i;
            // and return true
            return true;
        }
    }
    //if the string name isnt on the list return false to the program know
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    //loop until i = voter_count(number of voters)
    for (int i = 0; i != voter_count; i++)
    {
        //loop 3 times if needed
        for (int j = 0; j < 3; j++)
        {
            //if the candidate is not eliminated
            if (candidates[preferences[i][j]].eliminated != true)
            {
                //increment candidate votes
                candidates[preferences[i][j]].votes++;
                j = 3;
            }
        }

    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    //loop until i = voter_count(number of voters)
    for (int i = 0; i < candidate_count; i++)
    {
        //if the candidate have votes to win
        if (candidates[i].votes > voter_count / 2)
        {
            //print the winner
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    //if not return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int lowerValue = voter_count;

    //loop to the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //if the candidate is not eliminated
        if (candidates[i].eliminated != true)
        {
            //if the candidate votes value is lower then loweValue
            if (candidates[i].votes < lowerValue)
            {
                //set the lowerValue to the candidate votes
                lowerValue = candidates[i].votes;
            }
        }

    }
    //return the lowerValue
    return lowerValue;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    //loop to the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //if the candidate is not eliminated
        if (candidates[i].eliminated != true)
        {
            //if the min number is not equal to the candidate votes
            if (min != candidates[i].votes)
            {
                //return false
                return false;
            }
        }
    }
    //return true if is tie
    return true;

}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    //loop to the candidate count
    for (int i = 0; i < candidate_count; i++)
    {
        //if the candidate have the min votes and is not elimanted
        if (candidates[i].votes == min && candidates[i].eliminated != true)
        {
            //eliminate candidate
            candidates[i].eliminated = true;
        }
    }
    return;
}