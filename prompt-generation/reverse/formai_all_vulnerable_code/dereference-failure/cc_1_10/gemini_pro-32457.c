//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

char *text;
int width, height;
int **grid;

void init_grid() {
    grid = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(int));
    }
}

void free_grid() {
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);
}

void print_grid() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    // Get the input text.
    printf("Enter the text you want to convert to ASCII art: ");
    text = malloc(1024);
    gets(text);

    // Calculate the width and height of the ASCII art.
    width = strlen(text);
    height = 1;
    for (int i = 0; i < width; i++) {
        if (text[i] == '\n') {
            height++;
        }
    }

    // Initialize the grid.
    init_grid();

    // Convert the text to ASCII art.
    int x = 0, y = 0;
    for (int i = 0; i < width; i++) {
        if (text[i] == '\n') {
            x = 0;
            y++;
        } else {
            grid[y][x] = 1;
            x++;
        }
    }

    // Print the ASCII art.
    print_grid();

    // Free the grid.
    free_grid();

    // Free the input text.
    free(text);

    return 0;
}