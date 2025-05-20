//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y;
    char **arr;

    // Allocate memory for the array
    arr = (char **)malloc(5 * sizeof(char *));
    for (x = 0; x < 5; x++)
    {
        arr[x] = (char *)malloc(10 * sizeof(char));
    }

    // Get the dimensions of the ASCII art
    printf("Enter the number of rows: ");
    scanf("%d", &y);

    printf("Enter the number of columns: ");
    scanf("%d", &x);

    // Create the ASCII art
    for (x = 0; x < y; x++)
    {
        for (y = 0; y < x; y++)
        {
            arr[x][y] = rand() % 26 + 65;
        }
    }

    // Print the ASCII art
    for (x = 0; x < y; x++)
    {
        for (y = 0; y < x; y++)
        {
            printf("%c ", arr[x][y]);
        }
        printf("\n");
    }

    // Free the memory
    for (x = 0; x < 5; x++)
    {
        free(arr[x]);
    }
    free(arr);

    return 0;
}