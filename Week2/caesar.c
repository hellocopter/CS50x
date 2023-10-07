#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char cha, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");

    int k = atoi(argv[1]);

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            plaintext[i] = rotate(plaintext[i], k);
        }
    }
    printf("ciphertext: %s\n", plaintext);
}

char rotate(char cha, int k)
{
    if (isupper(cha))
    {
        cha = ((cha - 65 + k) % 26) + 65;
    }
    else
    {
        cha = ((cha - 97 + k) % 26) + 97;
    }

    return cha;
}