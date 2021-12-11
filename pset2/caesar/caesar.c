#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // check if the arg is correct

    if (argc != 2)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }



c    string key = argv[1];
    int count = 0;

    // check if the key is a number

    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]))
        {
            count++;
        }
    }

    int KEY;

    // if it's a number convert it to digit

    if (count == strlen(key))
    {
        KEY = atoi(key);
    }
    else
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }

    // get the plaintext from the user
    string ptext = get_string("Plaintext: ");
    int rem = 0;
     
    // loop over the whole text
    
    for (int i = 0; i < strlen(ptext); i++)
    {   
        // check if it is at the end of the alphabet
        if (ptext[i] == 'z')
        {
            ptext[i] = 'a';
            ptext[i] += (KEY % 26) - 1 ;
        }
        
        else if (ptext[i] == 'Z')
        {
            ptext[i] = 'A';
            ptext[i] += (KEY % 26) - 1;
        }
        // some standerd spaces not needed to be cipherd
        else if (ptext[i] == ' ' || ptext[i] == '.' || ptext[i] == '?' || ptext[i] == '!' || ptext[i] == ',')
        {
            ptext[i] = ptext[i];
        }
        // ciphering the text
        else
        {
            int value = ptext[i];
            value += (KEY % 26);
            ptext[i] += (KEY % 26);
            
            // check if it's in bound of the ascii char 
            if (ptext[i] > 123)
            {
                rem = ptext[i] - 123;
                ptext[i] = 'a';
                ptext[i] += rem;
            }
            else if (value >= 123)
            {
                value = value - 123;
                ptext[i] = 'a';
                ptext[i] += value;
        
            }
            else if (ptext[i] > 90 && ptext[i] < 97)
            {
                rem = ptext[i] - 91;
                ptext[i] = 'A';
                ptext[i] += rem ;
            }

        }

    }
    // print the ciphered text
    printf("ciphertext: %s\n", ptext);
    return 0;
}
