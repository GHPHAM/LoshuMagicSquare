#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool isLoshu(int arr[][3])
{
    // Check for uniqueness
    bool used[10] = {false};
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(used[arr[i][j]] || arr[i][j] < 1 || arr[i][j] > 9)
                return false;

            used[arr[i][j]] = true;
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

void genLoshu(int arr[][3])
{
    bool used[10] = {false};
    int count = 0;

    while (count < 9) {
        int num = rand() % 9 + 1;

        // Calculate row and column
        int row = count / 3;
        int col = count % 3;

        if (!used[num])
        {
            arr[row][col] = num;
            used[num] = true;
            count++;
        }
    }
}

void overwritePreviousLines() {
    // Move cursor up 4 lines
    printf("\033[4A");

    // Clear each line
    for (int i = 0; i < 4; ++i)
        printf("\033[K\n");

    // Move cursor back up 4 lines
    printf("\033[4A");
}

int main()
{
    srand(time(NULL));

    char choice;
    printf("WELCOME TO THE LO SHU PROGRAM\n");
    printf("Run loshu randomizer? (y/n): ");
    scanf(" %c", &choice); // leading space to ignore whitespace
    while (getchar() != '\n');  // Clear input buffer, space before `%c` skips leading whitespace

    unsigned long int count = 0;
    if (choice == 'y')
    {
        printf("Randomizing! Iteration count: \n");
        while (true)
        {
            ++count;
            printf("%d\n", count);

            int loshu[3][3];
            genLoshu(loshu);
            printLoshu(loshu);

            if (isLoshu(loshu))
            {
                printf("This is a loshu!\n");
                return 0;
            }
            else
            {
                overwritePreviousLines(); // Ged rid of the previous lines
            }
        }

    }
    else
    {
        printf("What is a loshu?\n");
        int loshu[3][3] = {
            {4,9,2},
            {3,5,7},
            {8,1,4}
        };

        if (isLoshu(loshu))
            printf("This is a loshu!\n");
        else
            printf("This is not a loshu!\n");

        printLoshu(loshu);
    }
    return 0;
}