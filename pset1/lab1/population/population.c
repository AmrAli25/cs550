#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end, n = 0;

    // TODO: Prompt for start size

    do
    {
        start = get_int("Put the statr size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size

    do
    {
        end = get_int("put the end size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

    while (start < end)
    {
        int inc = (start / 3) - (start / 4);
        start += inc;
        n++;
    }

    // TODO: Print number of years

    printf("Years: %i\n ", n);
}

    
