#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check if argc is true
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // check if the key is 26 alphabitical character   
    int count = 0;
    bool re = 0;
    // loop over the key
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]) - i; j++)
        {
            // check if a char is repeated
            if (argv[1][i] == argv[1][j])
            {
                printf("key characters mustn't be repeated\n");
                return 1;
            }
            else 
            {
                re = 1;
            }
        }
        // check if the key is alphabit only
        
        if (isalpha(argv[1][i]))
        {
            count++;
        }
        else 
        {
            printf("key must contain 26 characters only \n");
            return 1;
        }
    }
    // check if the key 26 character
    if (strlen(argv[1]) != 26 && count != 25 && re == 1)
    {
        printf("key must contain 26 characters\n");
        return 1;
    }
    // save the key
    string KEY = argv[1];

    // get the plaintext fron the user
    string ptext = get_string("plaintext: ");
   
    
    for (int k = 0; k < strlen(ptext); k++)
    {
        // symbols stay symbols
        if (ptext[k] == ' ' || ptext[k] == '.' || ptext[k] == '!' || ptext[k] == ',' || ptext[k] == '?')
        {
            ptext[k] = ptext[k];
        }
        // check if it is upper or lower case
        if (islower(ptext[k]))
        {
            int index  = ptext[k] - 97;
            ptext[k] = tolower(KEY[index]);
        }
        else if (isupper(ptext[k]))
        {
            int index  = ptext[k] - 65;
            ptext[k] = toupper(KEY[index]);
        }
    }
    // print the ciphered text
    printf("ciphertext: %s\n", ptext);
    return 0;
}
