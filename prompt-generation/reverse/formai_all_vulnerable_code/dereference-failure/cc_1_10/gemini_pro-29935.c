//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

char *text_to_ascii(const char *text, int *width, int *height);

int main(void) {
    const char *text = "Hello, world!";
    int width, height;
    char *ascii_art = text_to_ascii(text, &width, &height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(ascii_art[i * width + j]);
        }
        putchar('\n');
    }

    free(ascii_art);
    return 0;
}

char *text_to_ascii(const char *text, int *width, int *height) {
    int len = strlen(text);
    if (len == 0) {
        *width = 0;
        *height = 0;
        return NULL;
    }

    // Calculate the width and height of the ASCII art.
    *width = (len + WIDTH - 1) / WIDTH;
    *height = (len + HEIGHT - 1) / HEIGHT;

    // Allocate memory for the ASCII art.
    char *ascii_art = malloc(*width * *height);
    if (ascii_art == NULL) {
        return NULL;
    }

    // Convert the text to ASCII art.
    int k = 0;
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            if (k < len) {
                ascii_art[i * *width + j] = text[k++];
            } else {
                ascii_art[i * *width + j] = ' ';
            }
        }
    }

    return ascii_art;
}