//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generateAsciiArt(const char *text) {
    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->data = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));
    art->width = 0;
    art->height = 0;

    int i = 0;
    int j = 0;
    while (*text) {
        if (*text == '\n') {
            art->height++;
            j = 0;
        } else if (j >= MAX_WIDTH) {
            art->width = MAX_WIDTH;
            art->height++;
            j = 0;
        } else if (isprint(*text)) {
            art->data[i++] = *text;
            j++;
        }
        text++;
    }

    if (j > 0) {
        art->width = j;
        art->height++;
    }

    return art;
}

void printAsciiArt(const AsciiArt *art) {
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            printf("%c", art->data[y * MAX_WIDTH + x]);
        }
        printf("\n");
    }
}

int main() {
    char *text = "Hello, World!";
    AsciiArt *art = generateAsciiArt(text);
    printAsciiArt(art);
    free(art->data);
    free(art);
    return 0;
}