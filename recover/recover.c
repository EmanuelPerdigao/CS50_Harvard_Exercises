#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    char buffer[100];

    FILE *file = fopen(argv[1], "r");

    sprintf(buffer, "%i", *file);
    printf("%s",buffer);


    
}