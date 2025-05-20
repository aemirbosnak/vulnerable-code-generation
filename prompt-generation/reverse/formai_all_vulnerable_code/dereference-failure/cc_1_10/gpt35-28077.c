//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Donald Knuth
// C Text to ASCII Art Generator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 40    // Width of ASCII art
#define HEIGHT 30   // Height of ASCII art

// Function to get input from user
char* getInput() {
    char* input = malloc(256 * sizeof(char));
    printf("Enter text (max. 256 characters):\n");
    fgets(input, 256, stdin);
    return input;
}

int main() {
    // Get input from user
    char* text = getInput();

    // Create ASCII art
    int len = strlen(text);
    char art[HEIGHT][WIDTH];
    memset(art, ' ', HEIGHT * WIDTH);

    // Loop through text and create art
    int x = 0, y = 0;
    for (int i = 0; i < len; i++) {
        // If end of line reached, move to next line
        if (text[i] == '\n') {
            y++;
            x = 0;
            continue;
        }

        // Convert character to ASCII code
        int code = (int)text[i];

        // Check if ASCII code is printable
        if (code >= 32 && code <= 126) {
            // Add character to art
            art[y][x] = text[i];
        }

        // Move to next position in art
        x++;
        if (x >= WIDTH) {
            y++;
            x = 0;
        }
        if (y >= HEIGHT) {
            break;
        }
    }

    // Print ASCII art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    // Free memory
    free(text);

    return 0;
}