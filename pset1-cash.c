#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Run function for coins calculation
int get_change(float dollars);

int main(void)
{
    float dollars;
    // Prompt user for amount
    do
    {
        dollars = get_float("Change owed: ");
    }
    while(dollars < 0);
    // Prints results
    printf("Coins: %i\n", get_change(dollars));
}
// Function for coins calculation
int get_change(float dollars)
{
    // Calculate how many coins will be used
    int cents = round(dollars * 100);
    int coins = 0;
    int value[] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        coins += cents / value[i];
        cents = cents % value[i];
    }
    return coins;
}
