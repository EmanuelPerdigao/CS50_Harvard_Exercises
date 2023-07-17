#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void readability_Level(string text);
void calculate_Grade();

int letters = 0;
int sentences = 0;
int words = 0;

int main(void)
{
    //ask the text
    string text = get_string("Text: ");

    readability_Level(text);
    calculate_Grade();

}
//check the readability level
void readability_Level(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        //if it's a sentence
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
        //if it's a word
        if (text[i] == ' ')
        {
            words++;
        }
        //if it's a letter
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
}

//calculate the grade of the text
void calculate_Grade()
{
    //convert the int variables to float
    float sentencesFloat = sentences;
    float wordsFloat = words + 1;
    float lettersFloat = letters;

    float L = (lettersFloat / wordsFloat) * 100;
    float S = (sentencesFloat / wordsFloat) * 100;

    //calculate the grade value with the formula
    float gradeValue = 0.0588 * L - 0.296 * S - 15.8;
    //round the grade value
    int x =  round(gradeValue);

    //print the grade of the text
    if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    if (x >= 1 && x <= 15)
    {
        printf("Grade %i\n", x);
    }
} dede