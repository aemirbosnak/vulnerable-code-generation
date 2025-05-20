//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int width = strlen(text);
    int height = 1;

    // Create a 2D array to store the ASCII art
    char **art = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        art[i] = malloc(sizeof(char) * width);
    }

    // Clear the ASCII art array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            art[i][j] = ' ';
        }
    }

    // Draw the text in ASCII art
    for (int i = 0; i < width; i++) {
        char c = text[i];
        int x = i;
        int y = 0;
        while (c != '\0') {
            art[y][x] = c;
            y++;
            if (y >= height) {
                height++;
                art = realloc(art, sizeof(char *) * height);
                for (int j = 0; j < height; j++) {
                    art[j] = realloc(art[j], sizeof(char) * width);
                }
                for (int j = 0; j < height; j++) {
                    for (int k = 0; k < width; k++) {
                        if (art[j][k] == ' ') {
                            art[j][k] = '.';
                        }
                    }
                }
                y = 0;
            }
            if (c == '\n') {
                x = 0;
                y = 0;
            } else {
                x++;
                if (x >= width) {
                    width++;
                    for (int j = 0; j < height; j++) {
                        art[j] = realloc(art[j], sizeof(char) * width);
                    }
                    for (int j = 0; j < height; j++) {
                        for (int k = 0; k < width; k++) {
                            if (art[j][k] == ' ') {
                                art[j][k] = '.';
                            }
                        }
                    }
                    x = 0;
                }
            }
            c = text[i + (y * width)];
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", art[i][j]);
        }
        printf("\n");
    }

    // Free the ASCII art array
    for (int i = 0; i < height; i++) {
        free(art[i]);
    }
    free(art);

    return 0;
}