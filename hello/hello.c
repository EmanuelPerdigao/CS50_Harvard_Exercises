#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get string name
    string name = get_string("What's your name? ");

    //print hello and the name we get before
    printf("hello, %s\n", name);
}