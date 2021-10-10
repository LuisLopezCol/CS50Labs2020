#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;

            int avg = round((red + green + blue) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }

    return;
}

// Convert image to sepia

int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue;
    int sepiaRed;
    int sepiaGreen;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sepiaBlue = limit(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            sepiaRed = limit(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));

            image[j][i].rgbtBlue = sepiaBlue;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtRed = sepiaRed;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Brute force...
    /*RGBTRIPLE imageBuffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            imageBuffer[i][j] = image[i][width - j - 1];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageBuffer[i][j];
        }
    }*/
    RGBTRIPLE imageBuffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            imageBuffer[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = imageBuffer[i][j];
        }
    }

    /* for (int i = 0; i < height; i++) //Con esta funcion partes una foto en dos, la primera parte se refleja en la segunda
    {
        for (int j = 0; j < width; j++)
        {
            temp = image[i][width-j];
            image[i][j] = image[i][width-j];
            image[i][width-j] = temp;
        }
    } */
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a new array with the blur effect
    RGBTRIPLE imageBuffer[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumaRed = 0;
            float sumaGreen = 0;
            float sumaBlue = 0;
            int counter = 0;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    if (((i - 1 + k) >= 0) && ((j - 1 + l) >= 0) && ((i - 1 + k) <= (height - 1)) && ((j - 1 + l) <= (width - 1)))
                    {
                        sumaRed += image[i - 1 + k][j - 1 + l].rgbtRed;
                        sumaGreen += image[i - 1 + k][j - 1 + l].rgbtGreen;
                        sumaBlue += image[i - 1 + k][j - 1 + l].rgbtBlue;
                        counter++;
                    }
                }
            }
            imageBuffer[i][j].rgbtRed = round(sumaRed / counter);
            imageBuffer[i][j].rgbtGreen = round(sumaGreen / counter);
            imageBuffer[i][j].rgbtBlue = round(sumaBlue / counter);
        }
    }
    //Rewrite the picture with the new values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = imageBuffer[i][j];
        }
    }
    return;
}
