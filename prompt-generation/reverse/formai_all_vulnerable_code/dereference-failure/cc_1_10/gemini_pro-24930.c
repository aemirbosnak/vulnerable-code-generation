//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Character set for ASCII art
char *charset = " .:-=+*#%@";

// Conversion function
void text_to_ascii(char *text, int width, int height) {
    // Allocate memory for the ASCII art
    char *art = (char *)malloc(width * height * sizeof(char));

    // Initialize the ASCII art to empty space
    memset(art, ' ', width * height);

    // Convert the text to ASCII art
    int char_index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (char_index < strlen(text)) {
                // Get the character from the text
                char c = text[char_index++];

                // Convert the character to an index in the character set
                int index = (int)((float)c / 255.0 * (strlen(charset) - 1));

                // Set the corresponding pixel in the ASCII art
                art[y * width + x] = charset[index];
            }
        }
    }

    // Print the ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", art[y * width + x]);
        }
        printf("\n");
    }

    // Free the memory allocated for the ASCII art
    free(art);
}

// Main function
int main() {
    // Get the text to convert from the user
    char text[1024];
    printf("Enter the text to convert to ASCII art: ");
    scanf("%s", text);

    // Get the width and height of the ASCII art
    int width, height;
    printf("Enter the width and height of the ASCII art (e.g. 100 50): ");
    scanf("%d %d", &width, &height);

    // Convert the text to ASCII art
    text_to_ascii(text, width, height);

    return 0;
}