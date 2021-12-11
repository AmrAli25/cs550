#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get the name of the person
    string name = get_string("what's your name: ");
    printf("hello, %s\n", name);
}