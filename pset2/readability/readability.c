#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Prototype
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);



int main(void)
{
    // get the text from the user :
    
    string TEXT = get_string("Text: ");
    
    // count the letters , words and sentences.
    
    int letters = count_letters(TEXT);
    int words = count_words(TEXT);
    int sentences = count_sentences(TEXT);
    
    // find Coleman-Liau index
    
    float L = letters * 100.00 / words;
    float S = sentences * 100.00 / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    
    //decide the grade of the text
    
    if (index > 0 && index <= 16)
    {
        printf("Grade %i\n", (int)round(index));
    }
    else if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade 16+\n");
    }
}


// function to count letters

int count_letters(string text)
{
    // variable to count letters
    
    int count = 0;
    
    // loop over the whole text
    
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            count++;
        }
    }
       
    return count;
}



// function to count words

int count_words(string text)
{
    // variable to count the words
    
    int count = 1;  
    
    // loop for all the text
    
    for (int i = 0, j = strlen(text); i < j; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    
    return count;
}

// function to count sentence
int count_sentences(string text)
{
    // variable to count the sentence
    
    int count = 0;
    
    // loop over the whole text
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}


