#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define variables
  int pyramidSize, i, j;

  do
  {
  // Ask for size
  pyramidSize = get_int("Size: \n");
  }
  while (pyramidSize < 1 || pyramidSize > 8);

  for (i = 0; i < pyramidSize; i++)
  {
  // Loop for blankspaces
  for (j = pyramidSize - 1; j > i; j--)
  printf(" ");

  // Loop for dashes
  for (j = 0; j <= i; j++)
  printf("#");

  printf("  ");
  for (j = 0; j <= i; j++)
  printf("#");
  printf("\n");
  }
}
