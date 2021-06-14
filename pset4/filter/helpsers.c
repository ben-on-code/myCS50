#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int originalRed = pixel.rgbtRed;
            int originalGreen = pixel.rgbtGreen;
            int originalBlue = pixel.rgbtBlue;
            image[i][j].rgbtRed = cap(round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue));
            image[i][j].rgbtGreen = cap(round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue));
            image[i][j].rgbtBlue = cap(round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue));
        }
    }
}

// Swap values as David taught
void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}
// Check pixels
bool isValidPixels(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

RGBTRIPLE getBlurredPixels(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, blueValue, greenValue;
    redValue = blueValue = greenValue = 0;
    int qValidPixels = 0;

    for (int deltai = -1; deltai <= 1; deltai++)
    {
        for (int deltaj = -1; deltaj <= 1; deltaj++)
        {
            int newI = i + deltai;
            int newJ = j + deltaj;
            if (isValidPixels(newI, newJ, height, width))
            {
                qValidPixels++;
                redValue += image[newI][newJ].rgbtRed;
                greenValue += image[newI][newJ].rgbtGreen;
                blueValue += image[newI][newJ].rgbtBlue;
            }
        }
    }
    // Define struct
    RGBTRIPLE bluerredPixel;
    bluerredPixel.rgbtRed = round((float) redValue / qValidPixels);
    bluerredPixel.rgbtGreen = round((float) greenValue / qValidPixels);
    bluerredPixel.rgbtBlue = round((float) blueValue / qValidPixels);
    return bluerredPixel;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newImage[i][j] = getBlurredPixels(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = newImage[i][j];
        }
    }
}
