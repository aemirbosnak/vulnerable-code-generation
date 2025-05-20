//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *text;
    int width;
    int height;
} TextArt;

TextArt *text_to_ascii_art(char *text, int width, int height) {
    TextArt *art = malloc(sizeof(TextArt));
    art->text = text;
    art->width = width;
    art->height = height;

    // Create a 2D array of characters to store the ASCII art
    char **grid = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(sizeof(char) * width);
    }

    // Fill the grid with spaces
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = ' ';
        }
    }

    // Draw the text onto the grid
    int x = 0;
    int y = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c == '\n') {
            x = 0;
            y++;
        } else {
            grid[y][x] = c;
            x++;
        }
    }

    // Convert the grid to a single string
    char *art_string = malloc(sizeof(char) * width * height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            art_string[i * width + j] = grid[i][j];
        }
    }

    // Free the grid
    for (int i = 0; i < height; i++) {
        free(grid[i]);
    }
    free(grid);

    // Set the art struct's text field to the art string
    art->text = art_string;

    return art;
}

void print_text_art(TextArt *art) {
    printf("%s", art->text);
}

int main() {
    // Create a text art object
    TextArt *art = text_to_ascii_art("Hello, world!", 80, 20);

    // Print the text art
    print_text_art(art);

    // Free the text art object
    free(art);

    return 0;
}