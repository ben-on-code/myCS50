#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Define variables
    int startSize, endSize;
    int years = 0;

    // Prompt for start population size
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // Prompt for end population size
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);

    // Calculate number of years until we reach threshold
    while (startSize < endSize)
    {
        startSize = startSize + (startSize / 3) - (startSize / 4);
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);
}
