#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int N = 26;

void substitute(string key);

int main(int argc, string argv[]) // check if argument contains only 26 different keys
{
    if (argc != 2) // checks for more than 1 argument
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) > 26) // checks for more than 26 letters
    {
        printf("Key must contain only 26 different alphabets.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) // checks for non-letters
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only 26 different alphabets.\n");
            return 1;
        }

        for (int j = i + 1; j < N; j++) // checks for repeated letters
        {
            if (toupper(argv[1][j]) == toupper(argv[1][i]))
            {
                printf("Key must contain only 26 different alphabets.\n");
                return 1;
            }
        }
    }
    substitute(argv[1]);
}

void substitute(string key)
{
    char cipher;

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        int char_pos = plaintext[i];

        if (isupper(plaintext[i])) // changes plaintext to key if uppercase
        {
            cipher = key[char_pos - 65];
            printf("%c", toupper(cipher));
        }
        else if (islower(plaintext[i]))
        {
            cipher = key[char_pos - 97]; // changes plaintext to key if lowercase
            printf("%c", tolower(cipher));
        }
        else
        {
            printf("%c", plaintext[i]); // prints any character that is not letter
        }
    }
    printf("\n");
}