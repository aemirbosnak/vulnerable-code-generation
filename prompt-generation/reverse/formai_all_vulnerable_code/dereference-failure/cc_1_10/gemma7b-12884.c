//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINES 50
#define MAX_COLS 100

int main()
{
    int nLines, nCols, seed, i, j, r;
    char **arr;

    printf("Welcome to the ASCII Art Generator!\n");

    printf("Enter the number of lines: ");
    scanf("%d", &nLines);

    printf("Enter the number of columns: ");
    scanf("%d", &nCols);

    seed = time(NULL);
    srand(seed);

    arr = (char**)malloc(nLines * sizeof(char*));
    for (i = 0; i < nLines; i++)
    {
        arr[i] = (char*)malloc(nCols * sizeof(char));
    }

    for (i = 0; i < nLines; i++)
    {
        for (j = 0; j < nCols; j++)
        {
            r = rand() % 3;
            arr[i][j] = r + 'a';
        }
    }

    for (i = 0; i < nLines; i++)
    {
        for (j = 0; j < nCols; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}