#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for input
    long number = get_long("Number: ");

    // counting number of digits
    long number_backup = number; // setting number_backup to credit card number
    int digits;
    for (digits = 0; number_backup > 0; digits++)
    {
        number_backup /= 10;
    }

    // Print invalid if digits are not 13, 15 or 16
    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // storing digits into array
    number_backup = number; // resetting number_backup to credit card number
    int number_array[digits - 1];
    for (int j = digits - 1; j >= 0; j--)
    {
        number_array[j] = number_backup % 10;
        number_backup /= 10;
    }

    // multiply every other digit by 2, starting from 2nd last digit
    int number_multiply = 0;
    int number_multiply_sum = 0;

    for (int i = digits - 2; i >= 0; i -= 2)
    {
        number_multiply = number_array[i] * 2;
        number_multiply_sum += number_multiply % 10;
        if (number_multiply > 9)
        {
            number_multiply_sum += number_multiply / 10;
        }
    }

    // calculate sum of digits that were not muliplied by 2, starting from last digit
    int number_sum = 0;
    for (int i = digits - 1; i >= 0; i -= 2)
    {
        number_sum += number_array[i];
    }

    // calculate sum of multiplied and unmultiplied digits
    int number_total = number_sum + number_multiply_sum;


    // print AMEX, MASTERCARD, VISA or INVALID
    if ((number_array[0] == 3) && (number_array[1] == 4 || number_array[1] == 7) && (digits == 15) && (number_total % 10 == 0))
    {
        printf("AMEX\n");
    }
    else if ((number_array[0] == 5) && (number_array[1] > 0 && number_array[1] < 6) && (digits == 16) && (number_total % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    else if ((number_array[0] == 4) && (digits == 13 || digits == 16) && (number_total % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return (0);
}