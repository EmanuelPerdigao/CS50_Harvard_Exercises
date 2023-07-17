#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int i = 0;
    //get the positive cents
    do
    {
        i = get_int("Change owed: ");
    }
    while (i < 0);

    return i;
}

int calculate_quarters(int cents)
{
    //calculate quarters
    int counter = 1;
    int returnValue = 0;

    for (int i = 0; i < cents; i++)
    {
        if (counter == 25)
        {
            ++returnValue;
            counter = 0;
        }
        ++counter;
    }
    return returnValue;

}

int calculate_dimes(int cents)
{
    //calculate dimes
    int counter = 1;
    int returnValue = 0;

    for (int i = 0; i < cents; i++)
    {
        if (counter == 10)
        {
            ++returnValue;
            counter = 0;
        }
        ++counter;
    }
    return returnValue;
}

int calculate_nickels(int cents)
{
    //calculate nickels
    int counter = 1;
    int returnValue = 0;

    for (int i = 0; i < cents; i++)
    {
        if (counter == 5)
        {
            ++returnValue;
            counter = 0;
        }
        ++counter;
    }
    return returnValue;
}

int calculate_pennies(int cents)
{
    //calculate pennies
    return cents;
}
