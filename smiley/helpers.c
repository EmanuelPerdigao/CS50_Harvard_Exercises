#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    //loop to the height value
    for (int i = 0; i < height; i++)
    {
        //loop to the width value
        for (int z = 0; z < width; z++)
        {
            //define pixel to the image
            RGBTRIPLE pixel = image[i][z];

            //if the current pixel is black change to other color
            if (pixel.rgbtBlue == 0x00 && pixel.rgbtGreen == 0x00 && pixel.rgbtRed == 0x00)
            {
                //change to red
                image[i][z].rgbtBlue = 0x00;
                image[i][z].rgbtGreen = 0x00;
                image[i][z].rgbtRed = 0xff;
            }
        }

    }

}
