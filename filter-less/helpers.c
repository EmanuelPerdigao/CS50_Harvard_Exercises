#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int averageValue = 0;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop to the height value
    for (int i = 0; i < height; i++)
    {
        //loop to the width value
        for (int z = 0; z < width; z++)
        {
            //define pixel to the image
            RGBTRIPLE pixel = image[i][z];

            //find the average value pixel by pixel
            averageValue = round((image[i][z].rgbtBlue + image[i][z].rgbtGreen + image[i][z].rgbtRed) / 3.0);

            //define pixel by pixel to the average value
            image[i][z].rgbtBlue = averageValue;
            image[i][z].rgbtGreen = averageValue;
            image[i][z].rgbtRed = averageValue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    //sepiaRgbvalues
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    for (int i = 0; i < height; i++)
    {
        //loop to the width value
        for (int z = 0; z < width; z++)
        {
            //define pixel to the image
            RGBTRIPLE pixel = image[i][z];

            //find the average value pixel by pixel
            sepiaRed = round((0.393 * image[i][z].rgbtRed) + (0.769 * image[i][z].rgbtGreen) + (0.189 * image[i][z].rgbtBlue));
            sepiaGreen = round((0.349 * image[i][z].rgbtRed) + (0.686 * image[i][z].rgbtGreen) + (0.168 * image[i][z].rgbtBlue));
            sepiaBlue = round((0.272 * image[i][z].rgbtRed) + (0.534 * image[i][z].rgbtGreen) + (0.131 * image[i][z].rgbtBlue));

            //if sepia values exceed the max value (255)
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            //define pixel by pixel to the average value
            image[i][z].rgbtBlue = sepiaBlue;
            image[i][z].rgbtGreen = sepiaGreen;
            image[i][z].rgbtRed = sepiaRed;
        }

    }

    return;
}

// Reflect image horizontally

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //create counter variable
    int counter;

    //create struct
    typedef struct
    {
        int rgbtBlue;
        int rgbtGreen;
        int rgbtRed;
    }
    rgbValues;

    //create an array
    rgbValues rowArray[width];

    //loop to the height value
    for (int i = 0; i < height; i++)
    {
        //loop to the width value
        for (int z = 0; z < width; z++)
        {
            //copy the rgb values to the rowArray
            rowArray[z].rgbtBlue = image[i][z].rgbtBlue;
            rowArray[z].rgbtGreen = image[i][z].rgbtGreen;
            rowArray[z].rgbtRed = image[i][z].rgbtRed;
        }
        //define counter to the last value
        counter = width - 1;

        for (int z = 0; z < width; z++)
        {
            //define the new values
            image[i][z].rgbtBlue =  rowArray[counter].rgbtBlue;
            image[i][z].rgbtGreen =  rowArray[counter].rgbtGreen;
            image[i][z].rgbtRed =  rowArray[counter].rgbtRed;

            counter--;
        }
    }

    return;
}

// Blur image                                    altura largura
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a copy array
    RGBTRIPLE copy[height][width];

    //loop to the height
    for (int i = 0; i < height; i++)
    {
        //loop to the width
        for (int z = 0; z < width; z++)
        {
            //create a copy of the imagine
            copy[i][z] = image[i][z];
        }
    }

    //loop to the height
    for (int i = 0; i < height; i++)
    {
        //loop to the width value
        for (int z = 0; z < width; z++)
        {
            //create some variables
            int rowCounter = 0;
            int columnCounter = 0;
            float boxPixelsCounter = 0.00;
            int redValue = 0;
            int greeValue = 0;
            int blueValue = 0;
            int x;
            int y;

            x = i + 2;
            y = z + 2;

            //loop in columnCounter 3 pixels
            for (columnCounter = (i - 1); columnCounter < x; columnCounter++)
            {
                //loop in rowCounter 3 pixels
                for (rowCounter = (z - 1); rowCounter < y; rowCounter++)
                {
                    //if the column counter and the row counter is greater then 0 and less then height and width
                    if (columnCounter >= 0 && rowCounter >= 0 && columnCounter < height && rowCounter < width)
                    {
                        //sum the rgb values
                        redValue  += image[columnCounter][rowCounter].rgbtRed;
                        greeValue += image[columnCounter][rowCounter].rgbtGreen;
                        blueValue += image[columnCounter][rowCounter].rgbtBlue;
                        //increment pixels counter
                        boxPixelsCounter++;
                    }
                }
            }
            //then store the new values to the copy of the image
            copy[i][z].rgbtRed = round(redValue / boxPixelsCounter);
            copy[i][z].rgbtGreen = round(greeValue / boxPixelsCounter);
            copy[i][z].rgbtBlue = round(blueValue / boxPixelsCounter);
        }
    }
    //loop to the height
    for (int i = 0; i < height; i++)
    {
        //loop to the width
        for (int z = 0; z < width; z++)
        {
            //define the image with the copy created before
            image[i][z] = copy[i][z];
        }
    }
    return;
}
