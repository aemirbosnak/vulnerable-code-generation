//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

int main()
{
    char **ascii_art = NULL;
    int rows = 0, cols = 0;

    // Allocate memory for the ASCII art
    ascii_art = malloc(sizeof(char *) * MAX_WIDTH);
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        ascii_art[i] = malloc(sizeof(char) * MAX_WIDTH);
    }

    // Get the number of rows and columns from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Create the ASCII art
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            ascii_art[r][c] = rand() % 26 + 65;
        }
    }

    // Print the ASCII art
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", ascii_art[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_WIDTH; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}