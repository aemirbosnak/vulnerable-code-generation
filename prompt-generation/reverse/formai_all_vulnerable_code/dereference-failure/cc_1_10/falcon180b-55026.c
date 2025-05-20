//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *text;
    int width;
    int height;
    char **lines;
} TextToAsciiArt;

TextToAsciiArt *text_to_ascii_art_create(const char *text) {
    TextToAsciiArt *ascii_art = malloc(sizeof(TextToAsciiArt));
    ascii_art->text = strdup(text);
    ascii_art->width = strlen(text);
    ascii_art->height = 1;
    ascii_art->lines = malloc(sizeof(char *));
    ascii_art->lines[0] = strdup(text);
    return ascii_art;
}

void text_to_ascii_art_destroy(TextToAsciiArt *ascii_art) {
    free(ascii_art->text);
    for (int i = 0; i < ascii_art->height; i++) {
        free(ascii_art->lines[i]);
    }
    free(ascii_art->lines);
    free(ascii_art);
}

void text_to_ascii_art_resize(TextToAsciiArt *ascii_art, int width) {
    ascii_art->width = width;
    ascii_art->height = (int) ceil((double) strlen(ascii_art->text) / width);
    ascii_art->lines = realloc(ascii_art->lines, sizeof(char *) * ascii_art->height);
    for (int i = ascii_art->height - 1; i >= 0; i--) {
        ascii_art->lines[i] = realloc(ascii_art->lines[i], strlen(ascii_art->text) + 1);
    }
}

void text_to_ascii_art_render(TextToAsciiArt *ascii_art, FILE *output) {
    for (int i = 0; i < ascii_art->height; i++) {
        fprintf(output, "%s\n", ascii_art->lines[i]);
    }
}

int main() {
    TextToAsciiArt *ascii_art = text_to_ascii_art_create("Hello, World!");
    text_to_ascii_art_resize(ascii_art, MAX_WIDTH);
    text_to_ascii_art_render(ascii_art, stdout);
    text_to_ascii_art_destroy(ascii_art);
    return 0;
}