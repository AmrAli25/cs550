#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // defention
    int n, i, j, k, counter = 0 ;


    // Get the size of the pyramids
    do
    {
        n  = get_int(" Height: ");
    }
    while (n > 8 || n < 1);



    for (i = 1 ; i <= n ; i++)
    {
        // Loop for the left side pyramid

        for (j = n - 1 ; j >= i ; j--)
        {
            printf(" ");
            counter++;
        }

        // get the hash for the left side pyramid

        for (k = n - counter ; k >= 1  ; k--)
        {
            printf("#");
        }

        // space between two pyramids

        printf("  ");

        // loop for right pyramid

        for (int s = 1 ; s <= i ; s++)
        {
            printf("#");

        }

        counter = 0 ;
        printf("\n");
    }

}