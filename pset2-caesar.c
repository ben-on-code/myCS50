#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool isValidKey(string s);

int main(int argc, string argv[])
{
    if (argc != 2 || !isValidKey(argv[1]))
    {
        printf(".Usage: ./caesar key\n");
        return 1;
    }

    // Convert STRING to a NUMBER
    int key = atoi(argv[1]);

    // Prompt plain text to the user
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Cipher the actual plaintext
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            // ci = (pi + k) % 26
            printf("%c", 'a' + ((plaintext[i] - 'a') + key) % 26);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", 'A' + ((plaintext[i] - 'A') + key) % 26);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}

bool isValidKey(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
        if (!isdigit(s[i]))
        {
            return false;
        }
    return true;
}
