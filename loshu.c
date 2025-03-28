#include <stdio.h>
#include <stdbool.h>

bool isLoshu(int arr[][3])
{
    // Check for uniqueness
    int *arrFlat = (int *)arr; // convert to 1D array
    for(int i = 0; i < 9; ++i)
    {
        for(int k = 0; k < 9; ++k)
        {
            if(i == k)
                continue;

            if(arrFlat[i] == arrFlat[k])
                return false;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        // check rows
        if (arr[i][0] + arr[i][1] + arr[i][2] != 15)
            return false;

        // check columns
        if (arr[0][i] + arr[1][i] + arr[2][i] != 15)
            return false;
    }

    // check diagonals
    if (arr[0][0] + arr[1][1] + arr[2][2] != 15)
        return false;

    if (arr[2][0] + arr[1][1] + arr[0][2] != 15)
        return false;
    return true;
}

void printLoshu(int arr[][3])
{
    for (int i = 0; i < 3; ++i)
        printf("[%u %u %u]\n", arr[i][0], arr[i][1], arr[i][2]);
}


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
        int loshu[3][3] = {
            {4,9,2},
            {3,5,7},
            {8,1,4}
        };

        if (isLoshu(loshu))
        {
            printf("This is a loshu!\n");
        }
        else
        {
            printf("This is not a loshu!\n");
        }
        printLoshu(loshu);
    }
    return 0;
}