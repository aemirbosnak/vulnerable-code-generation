//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

int main(int argc, char *argv[])
{
    // Check for valid input
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    // Get the text to convert
    char *text = argv[1];

    // Calculate the width of the text
    int width = strlen(text);

    // Create a 2D array to store the ASCII art
    char art[MAX_WIDTH][MAX_WIDTH];

    // Initialize the array to spaces
    for (int i = 0; i < MAX_WIDTH; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            art[i][j] = ' ';
        }
    }

    // Convert the text to ASCII art
    int x = 0;
    int y = 0;
    for (int i = 0; i < width; i++) {
        char c = text[i];

        // Convert the character to ASCII art
        int ascii = (int)c;
        for (int j = 0; j < 8; j++) {
            int bit = (ascii >> (7 - j)) & 1;
            art[x + j][y] = bit ? '#' : ' ';
        }

        // Move to the next column
        x += 8;

        // Wrap to the next line if necessary
        if (x >= MAX_WIDTH) {
            x = 0;
            y += 8;
        }
    }

    // Print the ASCII art
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            putchar(art[i][j]);
        }
        putchar('\n');
    }

    return 0;
}