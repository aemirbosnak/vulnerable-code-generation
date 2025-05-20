//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHAR_SET "~!@#$%^&*()_+-=[]{}\\|;':\",./<>?"

typedef struct {
    char *data;
    int width;
    int height;
} AsciiArt;

AsciiArt *generate_ascii_art(int width, int height) {
    AsciiArt *art = malloc(sizeof(AsciiArt));
    art->data = malloc(sizeof(char) * width * height);
    art->width = width;
    art->height = height;

    for (int i = 0; i < width * height; i++) {
        art->data[i] = ASCII_CHAR_SET[rand() % strlen(ASCII_CHAR_SET)];
    }

    return art;
}

void print_ascii_art(AsciiArt *art) {
    for (int i = 0; i < art->height; i++) {
        for (int j = 0; j < art->width; j++) {
            printf("%c", art->data[i * art->width + j]);
        }
        printf("\n");
    }
}

void free_ascii_art(AsciiArt *art) {
    free(art->data);
    free(art);
}

int main() {
    int width, height;
    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);
    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);

    if (width <= 0 || height <= 0 || width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    AsciiArt *art = generate_ascii_art(width, height);
    print_ascii_art(art);
    free_ascii_art(art);

    return 0;
}