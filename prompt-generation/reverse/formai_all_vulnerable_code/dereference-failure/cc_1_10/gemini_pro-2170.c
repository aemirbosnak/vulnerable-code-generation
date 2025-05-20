//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *text = argv[1];
    int width = strlen(text);
    if (width > MAX_WIDTH) {
        fprintf(stderr, "Error: text is too long (max width is %d)\n", MAX_WIDTH);
        return EXIT_FAILURE;
    }

    int height = 1;
    for (int i = 0; i < width; i++) {
        if (text[i] == '\n') {
            height++;
        }
    }

    char *ascii_art = malloc(width * height + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return EXIT_FAILURE;
    }

    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (text[index] == '\n') {
                ascii_art[index] = '\n';
            } else {
                ascii_art[index] = text[index];
            }
            index++;
        }
    }
    ascii_art[index] = '\0';

    printf("%s", ascii_art);
    free(ascii_art);

    return EXIT_SUCCESS;
}