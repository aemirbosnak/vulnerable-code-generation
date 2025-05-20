//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **ascii_art = NULL;
    int rows, cols;

    // Allocate memory for the ASCII art
    ascii_art = malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
    {
        ascii_art[i] = malloc(sizeof(char) * 20);
    }

    // Get the number of rows and columns
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
    for (int i = 0; i < 5; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}