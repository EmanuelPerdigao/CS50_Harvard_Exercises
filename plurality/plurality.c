#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    //loop the list of candidates
    for (int i = 0; i < candidate_count; i++)
    {

        //if the string name is in the list of candidates
        if (strcmp(candidates[i].name, name) == 0)
        {
            //increment 1 to the parameter votes of the the current candidate
            candidates[i].votes += 1;
            // and return true
            return true;
        }
    }
    //if the string name isnt on the list return false to the program know
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //create some variables to help me
    int higherValue = 0;
    int candidateNumber [candidate_count];
    string winner;

    //loop the votes parameter and find the higher value
    for (int i = 0; i < candidate_count; i++)
    {
        //if the current votes paramente is greater then the last candidate
        if (candidates[i].votes > higherValue)
        {
            //set the higher value to the higher value of votes
            higherValue = candidates[i].votes;
        }
    }

    //when i know whats the higher value loop the votes again
    for (int i = 0; i < candidate_count; i++)
    {
        //if the number of votes is equal to the higher value of votes
        if (candidates[i].votes == higherValue)
        {
            //print the winner
            winner = candidates[i].name;
            printf("%s\n", winner);
        }
    }

    return;
}