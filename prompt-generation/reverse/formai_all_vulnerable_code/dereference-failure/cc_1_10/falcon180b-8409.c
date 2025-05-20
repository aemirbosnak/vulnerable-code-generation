//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_LENGTH 1024

typedef struct {
    char *text;
    int width;
    int height;
    char *art;
} AsciiArt;

AsciiArt *generateAsciiArt(const char *text) {
    int length = strlen(text);
    int width = MAX_WIDTH;
    int height = (length + width - 1) / width;

    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->text = strdup(text);
    art->width = width;
    art->height = height;
    art->art = malloc(height * width);

    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = text[i++];
            if (c == '\n') {
                y++;
                x = 0;
            } else {
                art->art[y * width + x] = c;
            }
        }
    }

    return art;
}

void printAsciiArt(const AsciiArt *art) {
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            char c = art->art[y * art->width + x];
            printf("%c", c);
        }
        printf("\n");
    }
}

int main() {
    char *text = "Hello, world!";
    AsciiArt *art = generateAsciiArt(text);
    printAsciiArt(art);
    free(art->text);
    free(art->art);
    free(art);
    return 0;
}