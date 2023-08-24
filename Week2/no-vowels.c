// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word1);

int main(int argc, string argv[])
{
    string word = argv[1];

    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }

    printf("%s\n", replace(word));

    return 0;
}

string replace(string word1)
{
    for (int i = 0; i < strlen(word1); i++)
    {
        if (word1[i] == 'a')
        {
            word1[i] = '6';
        }
        else if (word1[i] == 'e')
        {
            word1[i] = '3';
        }
        else if (word1[i] == 'i')
        {
            word1[i] = '1';
        }
        else if (word1[i] == 'o')
        {
            word1[i] = '0';
        }
    }
    return (word1);
}