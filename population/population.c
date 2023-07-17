#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int populationSizeMin = 0;
    int populationSizeMax = 0;
    int n = 0;
    int populationValue = 0;

    // TODO: Prompt for start size

    do{
        populationSizeMin = get_int("Start size: ");
        populationValue = populationSizeMin;
    }
    while (populationSizeMin < 9);


    // TODO: Prompt for end size

    do{
        populationSizeMax = get_int("End size: ");
    }
    while (populationSizeMax < populationSizeMin);

    // TODO: Calculate number of years until we reach threshold

    while(populationValue < populationSizeMax){
        populationValue = populationValue + populationValue / 3 - populationValue / 4;
        n++;
    }

    // TODO: Print number of years

    printf("Years: %i\n", n);
}
