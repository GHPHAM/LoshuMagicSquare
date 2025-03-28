#include <stdio.h>

int main()
{
    char choice;
    printf("WELCOME TO THE LO SHU PROGRAM\n");
    printf("Run loshu randomizer? (y/n): ");
    scanf(" %c", &choice); // leading space to ignore whitespace
    while (getchar() != '\n');  // Clear input buffer, space before `%c` skips leading whitespace

    if (choice == 'y')
    {

    }
    else
    {

    }
}