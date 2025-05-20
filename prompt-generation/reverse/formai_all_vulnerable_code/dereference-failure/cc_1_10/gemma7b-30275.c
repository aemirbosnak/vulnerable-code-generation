//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

int main()
{
    int width, height;
    char **ascii_art;

    // Allocate memory for the ASCII art
    ascii_art = (char **)malloc(MAX_HEIGHT * sizeof(char *));
    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        ascii_art[i] = (char *)malloc(MAX_WIDTH * sizeof(char));
    }

    // Generate a random ASCII art
    srand(time(NULL));
    width = rand() % MAX_WIDTH;
    height = rand() % MAX_HEIGHT;

    // Draw the ASCII art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ascii_art[i][j] = rand() % 26 + 65;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_HEIGHT; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return 0;
}