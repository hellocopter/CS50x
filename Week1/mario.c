#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int h = height;

    for (int i = 0; i < h; i++)
    {

        for (int t = 1; t < height; t++)
        {
            printf(" ");
        }

        for (int j = height; j <= h; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = height; j <= h; j++)
        {
            printf("#");
        }

        height--;
        printf ("\n");
    }

}