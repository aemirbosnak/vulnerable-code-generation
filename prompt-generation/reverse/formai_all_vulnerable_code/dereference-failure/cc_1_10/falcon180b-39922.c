//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_ART_FILE "ascii.art"

typedef struct {
    char *text;
    int width;
    int height;
} AsciiArt;

AsciiArt *generateAsciiArt(char *inputText) {
    AsciiArt *asciiArt = malloc(sizeof(AsciiArt));
    asciiArt->text = inputText;
    asciiArt->width = strlen(inputText);
    asciiArt->height = 1;

    return asciiArt;
}

void saveAsciiArtToFile(AsciiArt *asciiArt) {
    FILE *file = fopen(ASCII_ART_FILE, "w");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", ASCII_ART_FILE);
        exit(1);
    }

    fprintf(file, "P6\n%d %d\n255\n", asciiArt->width, asciiArt->height);

    for (int i = 0; i < asciiArt->height; i++) {
        for (int j = 0; j < asciiArt->width; j++) {
            char c = asciiArt->text[i * asciiArt->width + j];
            int red = c % 16 * 17;
            int green = (c / 16) % 16 * 17;
            int blue = (c / 256) % 16 * 17;

            fprintf(file, "%d %d %d ", red, green, blue);
        }
    }

    fclose(file);
}

int main() {
    char inputText[MAX_WIDTH * MAX_HEIGHT];

    printf("Enter your text:\n");
    fgets(inputText, MAX_WIDTH * MAX_HEIGHT, stdin);

    AsciiArt *asciiArt = generateAsciiArt(inputText);
    saveAsciiArtToFile(asciiArt);

    printf("Saved ascii art to file %s\n", ASCII_ART_FILE);

    return 0;
}