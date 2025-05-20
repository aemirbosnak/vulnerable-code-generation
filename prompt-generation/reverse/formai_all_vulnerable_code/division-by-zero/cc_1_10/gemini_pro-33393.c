//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// ASCII art character set
char charset[] = " .,-;:=+*#%@";

// Function to convert a text string to ASCII art
void text_to_ascii(char *text, int width, int height) {
    // Calculate the character width and height
    int char_width = width / strlen(text);
    int char_height = height / 5;

    // Create a 2D array to store the ASCII art
    char **ascii_art = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc(width * sizeof(char));
    }

    // Convert each character in the text string to ASCII art
    int x = 0, y = 0;
    for (int i = 0; i < strlen(text); i++) {
        // Get the ASCII code of the character
        int ascii_code = (int) text[i];

        // Calculate the brightness of the character
        int brightness = (ascii_code - 32) * 16 / 31;

        // Draw the character in ASCII art
        for (int j = 0; j < char_width; j++) {
            for (int k = 0; k < char_height; k++) {
                // Set the pixel brightness
                ascii_art[y + k][x + j] = charset[brightness];
            }
        }

        // Increment the x coordinate
        x += char_width;

        // If the x coordinate is greater than the width, then wrap to the next line
        if (x >= width) {
            x = 0;
            y += char_height;
        }
    }

    // Print the ASCII art to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);
}

// Main function
int main() {
    // Get the text string from the user
    char text[100];
    printf("Enter the text string: ");
    scanf("%s", text);

    // Get the width and height of the ASCII art
    int width, height;
    printf("Enter the width and height of the ASCII art: ");
    scanf("%d %d", &width, &height);

    // Convert the text string to ASCII art
    text_to_ascii(text, width, height);

    return 0;
}