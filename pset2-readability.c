#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int get_grade(string s);

int main()
{
    // Promp for a text
    string text = get_string("Text: ");
    int grade = get_grade(text);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(grade));
    }

    return 0;
}

int get_grade(string s)
{
    // Declare and initialize variables
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        // Count letters
        char ch = s[i];
        if (isalpha(ch))
        {
            letters++;
        }
        // Count words
        else if (isspace(ch))
        {
            words++;
        }
        // Count sentences
        else if ((ch == '.') || (ch == '!') || (ch == '?'))
        {
            sentences++;
        }
    }
    // Calculate and print GRADE
    // index = 0.0588 * L - 0.296 * S - 15.8
    float L = (letters * 100.00) / words;
    float S = (sentences * 100.00) / words;
    return round(0.0588 * L - 0.296 * S - 15.8);
}
