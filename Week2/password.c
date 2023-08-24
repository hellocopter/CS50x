// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lowercase = 0;
    bool uppercase = 0;
    bool number = 0;
    bool symbol = 1;

    for (int i = 0; i < strlen(password); i++)
    {
        if (lowercase == 0)
        {
            lowercase = islower(password[i]);
        }

        if (uppercase == 0)
        {
            uppercase = isupper(password[i]);
        }

        if (number == 0)
        {
            number = isdigit(password[i]);
        }

        if (symbol == 1)
        {
            symbol = isalnum(password[i]);
        }

    }

    if (lowercase == 1 && uppercase == 1 && number == 1 && symbol == 0)
    {
        return true;
    }
    return false;
}
