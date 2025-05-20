//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create ASCII art from a given string
void generateAsciiArt(char *str) {

    // Define the array of ASCII characters to be used
    char ascii_characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_ascii_characters = strlen(ascii_characters);

    // Get length of the input string and calculate its dimensions on the screen
    int len = strlen(str);
    int width = 80;
    int height = len / width;

    if (len % width != 0) {
        height++;
    }

    // Allocate a 2D array to store the ASCII art
    char **ascii_art = (char **) malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        ascii_art[i] = (char *) malloc(width * sizeof(char));
    }

    // Generate the ASCII art
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (index >= len) {
                ascii_art[i][j] = ' ';
            } else {
                int ascii_index = ((int) str[index]) % num_ascii_characters;
                ascii_art[i][j] = ascii_characters[ascii_index];
                index++;
            }
        }
    }

    // Print the ASCII art to the screen
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    // Free memory allocated to the 2D array
    for (int i = 0; i < height; i++) {
        free(ascii_art[i]);
    }
    free(ascii_art);
}

int main() {
    char str[] = "Hello, World!";
    generateAsciiArt(str);
    return 0;
}