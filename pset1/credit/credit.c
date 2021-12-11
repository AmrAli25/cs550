#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num;
    int digit = 0;

    // get the number of card:

    do
    {
        num = get_long("Number: ");
    }
    while (num < 0);

    // count the card digit:
    long cardnumber = num;
    while (cardnumber > 0)
    {
        cardnumber /= 10;
        digit++;
    }

    //check if the card is valid as a digit count:

    if ((digit != 13) && (digit != 15) && (digit != 16))
    {
        printf("INVALID\n");
    }

    // get the digit in array:

    int card[digit];
    for (int i = 0; i < digit; i++)
    {
        card[i] = num % 10;
        num /= 10;
        
    }
    // save the true card number
    
    int truecard[digit];
    
    for (int i = 1; i < digit; i++)
    {
        truecard[i] = card[i];
    
    }
    // multiblay the second digits 
    
    for (int i = 1; i < digit; i += 2)
    {
        card[i] = card[i] * 2;
    }
    
    int sum = 0;
    int temp;
    
    //check for VISA
    
    if (digit == 13)
    {
        for (int i = 0; i < digit; i++)
        {
            // the allgorism for checking the last digit
            temp = (card[i] % 10) + (card[i] / 10 % 10);
            sum = sum + temp;
        }
        if (truecard[12] == 4 && sum % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    // check for American Express
    
    if (digit == 15)
    {
        for (int i = 0; i < digit; i++)
        {
            // the allgorism for checking the last digit
        
            temp = (card[i] % 10) + (card[i] / 10 % 10);
            sum = sum + temp;
        }
        if (truecard[14] == 3 && sum % 10 == 0 && (truecard[13] == 4 || truecard[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    // check for VISA or MASTERCARD
    
    if (digit == 16)
    {
        for (int i = 0; i < digit; i++)
        { 
            // the allgorism for checking the last digit
        
            temp = (card[i] % 10) + (card[i] / 10 % 10);
            sum = sum + temp;
        }
        if (truecard[15] == 4 && sum % 10 == 0)
        {
            printf("VISA\n");
        }
        else if (truecard[15] == 5 && sum % 10 == 0 && (truecard[14] == 1 || truecard[14] == 2 || truecard[14] == 3 || truecard[14] == 4
        
                 || truecard[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }


}