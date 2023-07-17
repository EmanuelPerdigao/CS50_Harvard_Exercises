#include <cs50.h>
#include <stdio.h>

int height = 0;
int neededSpaces = 1;

int main(void)
{
    //get the height with some while conditions
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //for loop until i < height
    for (int i = 0; i < height; i++)
    {

        //adding spaces
        while (neededSpaces != height - i)
        {
            printf(" ");
            neededSpaces++;
        }
        //reset the variable
        neededSpaces = 1;

        //printing the #
        for (int n = -1; n < i; n++)
        {
            printf("#");
        }
        //adding new line
        printf("\n");

    }

}