//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

char *text = NULL;
int width = 0;
int height = 0;

void print_art() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", text[i * width + j]);
        }
        printf("\n");
    }
}

int main() {
    char *input = NULL;
    size_t input_len = 0;

    printf("Enter text to convert to ASCII art:\n");
    getline(&input, &input_len, stdin);

    // Remove trailing newline
    input[strlen(input) - 1] = '\0';

    // Calculate width and height of ASCII art
    width = strlen(input);
    height = (width + MAX_WIDTH - 1) / MAX_WIDTH;

    // Allocate memory for ASCII art
    text = malloc(width * height);
    if (text == NULL) {
        fprintf(stderr, "Error allocating memory for ASCII art\n");
        exit(1);
    }

    // Convert text to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            text[i * width + j] = input[j];
        }

        // Pad remaining columns with spaces
        for (int j = width; j < MAX_WIDTH; j++) {
            text[i * width + j] = ' ';
        }
    }

    // Print ASCII art
    print_art();

    // Free memory
    free(text);
    free(input);

    return 0;
}