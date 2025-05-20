//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generate_ascii_art(const char *text) {
    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->data = strdup(text);
    art->width = strlen(text);
    art->height = 1;

    return art;
}

void print_ascii_art(const AsciiArt *art) {
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            printf("%c", art->data[y * art->width + x]);
        }
        printf("\n");
    }
}

void free_ascii_art(AsciiArt *art) {
    free(art->data);
    free(art);
}

int main() {
    const char *text = "Hello, World!";
    AsciiArt *art = generate_ascii_art(text);

    printf("Original text:\n");
    printf("%s\n", text);

    printf("ASCII art:\n");
    print_ascii_art(art);

    free_ascii_art(art);

    return 0;
}