#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int binaryNumber[] = {};

void print_bulb(int bit);

int main(void)
{
    //get the message
    string text = get_string("Message: ");

    //Loop trough the message letter by letter
    for (int i = 0; i < strlen(text); i++)
    {
        //if the letter is in the ascii table
        if (text[i] >= 0 && text[i] <= 127)
        {
            //get the current number and covert it to dec number
            int currentNumber = text[i];

            //for loop to reach a byte
            for (int counter = 0; counter != BITS_IN_BYTE; counter++)
            {

                //if the number is odd
                if (currentNumber % 2 == 1)
                {
                    //add 1 to the byte array
                    binaryNumber[counter] = 1;
                }
                //if is even
                else
                {
                    //add 0 to the byte array
                    binaryNumber[counter] = 0;
                }
                //divide the number by 2
                currentNumber /= 2;
            }

            //invert the byte array
            for (int counter = 7; counter != -1; counter--)
            {
                //print the array
                print_bulb(binaryNumber[counter]);
            }
            //add new line
            printf("\n");
        }
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
