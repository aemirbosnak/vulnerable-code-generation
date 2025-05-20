//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the ASCII art
#define ART_WIDTH 80
#define ART_HEIGHT 30

// Choose the character to represent dark pixels in the art
#define DARK_CHAR '@'

// Utility function to clear the screen
void clear_screen() {
    printf("\033[2J");
}

// Utility function to position the cursor
void set_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

// Main function
int main(int argc, char *argv[]) {

    // Check that a string was passed as argument
    if (argc < 2) {
        printf("Please provide a string as argument.\n");
        return 1;
    }

    // Extract the input string from the command line arguments
    char *input = argv[1];

    // Calculate the length of the input string
    int input_length = 0;
    while (input[input_length] != '\0') {
        input_length++;
    }

    // Allocate memory for the ASCII art matrix
    char **art = (char **)malloc(ART_HEIGHT * sizeof(char *));
    for (int i = 0; i < ART_HEIGHT; i++) {
        art[i] = (char *)malloc((ART_WIDTH + 1) * sizeof(char));
    }

    // Clear the screen and position the cursor at the top left corner
    clear_screen();
    set_cursor(1, 1);

    // Initialize the ASCII art matrix
    for (int i = 0; i < ART_HEIGHT; i++) {
        for (int j = 0; j < ART_WIDTH; j++) {
            art[i][j] = ' ';
        }
        art[i][ART_WIDTH] = '\0';
    }

    // Generate the ASCII art
    int x = 0;
    for (int i = 0; i < input_length; i++) {
        int chr = (int)input[i];
        int width = (chr >= 32 && chr <= 127) ? 6 : 3;
        if (x + width > ART_WIDTH) {
            break;
        }
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < ART_HEIGHT; k++) {
                char pixel = (j == width - 1) ? ' ' : DARK_CHAR;
                art[k][x+j] = pixel;
            }
        }
        x += width;
    }

    // Print the ASCII art
    for (int i = 0; i < ART_HEIGHT; i++) {
        printf("%s\n", art[i]);
    }

    // Free the memory allocated for the ASCII art matrix
    for (int i = 0; i < ART_HEIGHT; i++) {
        free(art[i]);
    }
    free(art);

    // Exit
    return 0;
}