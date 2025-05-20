//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void beautify(char **arr, int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] == '\0')
            {
                for (k = j; k < MAX; k++)
                {
                    arr[i][k] = ' ';
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s", arr[i]);
    }
}

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));

    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Fill the array with some data
    arr[0][0] = 'H';
    arr[0][1] = 'E';
    arr[0][2] = 'L';
    arr[0][3] = 'L';
    arr[0][4] = '\0';

    arr[1][0] = 'W';
    arr[1][1] = 'O';
    arr[1][2] = 'R';
    arr[1][3] = 'L';
    arr[1][4] = '\0';

    beautify(arr, 2);

    return 0;
}