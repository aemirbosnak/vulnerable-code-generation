//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert text to ASCII art
int text_to_ascii(char *text, int width, int height, char **art) {
    // Check if input is valid
    if (text == NULL || width <= 0 || height <= 0 || art == NULL) {
        return -1;
    }

    // Allocate memory for the ASCII art
    *art = malloc(width * height * sizeof(char));
    if (*art == NULL) {
        return -1;
    }

    // Convert text to ASCII art
    int x, y, i;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            i = y * width + x;
            if (i < strlen(text)) {
                (*art)[i] = text[i];
            } else {
                (*art)[i] = ' ';
            }
        }
    }

    return 0;
}

// Function to print ASCII art
void print_ascii_art(char *art, int width, int height) {
    // Check if input is valid
    if (art == NULL || width <= 0 || height <= 0) {
        return;
    }

    // Print ASCII art
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            printf("%c", art[y * width + x]);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if input is valid
    if (argc < 4) {
        printf("Usage: %s text width height\n", argv[0]);
        return -1;
    }

    // Get input
    char *text = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    // Convert text to ASCII art
    char *art;
    int status = text_to_ascii(text, width, height, &art);
    if (status != 0) {
        printf("Error converting text to ASCII art\n");
        free(art);
        return -1;
    }

    // Print ASCII art
    print_ascii_art(art, width, height);

    // Free memory
    free(art);

    return 0;
}