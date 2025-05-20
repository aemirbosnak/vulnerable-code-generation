//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_ART_FILE "ascii_art.txt"

typedef struct {
    char *text;
    int width;
    int height;
} AsciiArt;

AsciiArt loadAsciiArt(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    AsciiArt art = {NULL, 0, 0};

    char line[MAX_WIDTH + 1];
    int chars = 0;
    while (fgets(line, MAX_WIDTH, file)!= NULL) {
        int len = strlen(line);
        if (len > art.width) {
            art.width = len;
        }
        chars += len;
        if (chars > MAX_HEIGHT) {
            printf("Error: ascii art is too large\n");
            exit(1);
        }
    }

    art.height = chars;
    art.text = malloc(art.width * art.height + 1);
    if (art.text == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    rewind(file);
    chars = 0;
    while (fgets(line, MAX_WIDTH, file)!= NULL) {
        int len = strlen(line);
        memcpy(art.text + chars, line, len);
        chars += len;
    }

    art.text[chars] = '\0';

    fclose(file);

    return art;
}

void printAsciiArt(const AsciiArt *art) {
    for (int y = 0; y < art->height; y++) {
        for (int x = 0; x < art->width; x++) {
            printf("%c", art->text[y * art->width + x]);
        }
        printf("\n");
    }
}

int main() {
    AsciiArt art = loadAsciiArt(ASCII_ART_FILE);
    printAsciiArt(&art);

    free(art.text);
    return 0;
}