//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

char *text_to_ascii_art(const char *text, int width, int height) {
    if (width < 1 || height < 1) {
        return NULL;
    }
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        return NULL;
    }

    int text_length = strlen(text);

    // Create a 2D array to store the ASCII art
    char **ascii_art = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        ascii_art[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            ascii_art[i][j] = ' ';
        }
    }

    // Convert the text to ASCII art
    int current_x = 0;
    int current_y = 0;
    for (int i = 0; i < text_length; i++) {
        char character = text[i];

        // If the current character is a newline, then move to the next line
        if (character == '\n') {
            current_x = 0;
            current_y++;
            continue;
        }

        // If the current character is a space, then increment the current x coordinate
        if (character == ' ') {
            current_x++;
            continue;
        }

        // Otherwise, add the character to the ASCII art
        ascii_art[current_y][current_x] = character;

        // Increment the current x coordinate
        current_x++;
    }

    // Convert the 2D array to a single string
    char *result = malloc(sizeof(char) * (width * height + 1));
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            result[index++] = ascii_art[i][j];
        }
        result[index++] = '\n';
    }
    result[index] = '\0';

    // Free the 2D array
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);

    return result;
}

int main() {
    // Get the text from the user
    char *text = NULL;
    size_t text_length = 0;
    getline(&text, &text_length, stdin);

    // Convert the text to ASCII art
    char *ascii_art = text_to_ascii_art(text, MAX_WIDTH, MAX_HEIGHT);

    // Print the ASCII art
    printf("%s", ascii_art);

    // Free the ASCII art
    free(ascii_art);

    return 0;
}