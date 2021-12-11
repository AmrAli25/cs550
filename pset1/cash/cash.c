#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int d = 0, q = 0, p = 0, n = 0;

    // get the input of dollars
    do
    {
        dollars = get_float("change owed: ");
    }
    while (dollars < 0);

    // convert dollars to cents
    int cents = round(dollars * 100);

    while (cents > 0)
    {
        // get num of quarters
        if (cents >= 25)
        {
            cents = cents - 25;
            q++;
        }
        // get num of dims
        else if (cents >= 10 && cents < 25)
        {
            cents = cents - 10;
            d++;
        }
        // get num of nikles
        else if (cents >= 5 && cents < 10)
        {
            cents = cents - 5;
            n++;
        }
        // get num of pennies
        else
        {
            cents = cents - 1;
            p++;
        }
    }
    // the number of needed coins 
    int coins = q + d + p + n;
    printf("%i\n", coins);

}