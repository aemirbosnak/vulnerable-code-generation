//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

char *chars = " .:-=+*#%@"
" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

int main() {
    char *text = "Hello, ASCII art!";

    // Calculate the size of the ASCII art
    int width = strlen(text) * 6;
    int height = 6;

    // Create an array to store the ASCII art
    char *art = malloc(width * height);

    // Generate the ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Calculate the index of the character in the text
            int index = x / 6;

            // Get the character from the text
            char c = text[index];

            // Calculate the index of the character in the chars array
            int charIndex = (int)(c * (strlen(chars) - 1) / 255.0);

            // Get the character from the chars array
            char charc = chars[charIndex];

            // Set the character in the ASCII art array
            art[y * width + x] = charc;
        }
    }

    // Print the ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", art[y * width + x]);
        }
        printf("\n");
    }

    // Free the memory used by the ASCII art
    free(art);

    return 0;
}