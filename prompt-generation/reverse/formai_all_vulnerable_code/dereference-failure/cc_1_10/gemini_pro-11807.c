//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

int main(int argc, char *argv[])
{
    int width, height;
    char *text;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    text = argv[1];

    width = strlen(text);
    height = 1;

    for (int i = 0; i < width; i++) {
        if (text[i] == '\n') {
            height++;
        }
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Text is too large. Maximum width is %d characters and maximum height is %d lines.\n", MAX_WIDTH, MAX_HEIGHT);
        return EXIT_FAILURE;
    }

    char *bitmap = malloc(width * height);
    memset(bitmap, ' ', width * height);

    int x = 0;
    int y = 0;

    for (int i = 0; i < width; i++) {
        if (text[i] == '\n') {
            x = 0;
            y++;
        } else {
            bitmap[y * width + x] = text[i];
            x++;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", bitmap[y * width + x]);
        }
        printf("\n");
    }

    free(bitmap);

    return EXIT_SUCCESS;
}