//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the ASCII Art Generator!\n");
    printf("Please enter the number of rows you want: ");
    int numRows;
    scanf("%d", &numRows);
    printf("Please enter the number of columns you want: ");
    int numCols;
    scanf("%d", &numCols);

    // Allocate memory for the ASCII art
    char **asciiArt = (char **)malloc(numRows * sizeof(char *));
    for (int i = 0; i < numRows; i++)
    {
        asciiArt[i] = (char *)malloc(numCols * sizeof(char));
    }

    // Get the ASCII art
    printf("Enter the ASCII art you want: ");
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            scanf("%c", &asciiArt[r][c]);
        }
    }

    // Print the ASCII art
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < numCols; c++)
        {
            printf("%c ", asciiArt[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < numRows; i++)
    {
        free(asciiArt[i]);
    }
    free(asciiArt);

    return 0;
}