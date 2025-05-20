//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET ".,-~:;=!*#@"

typedef struct {
    int width;
    int height;
    char *data;
} TextArt;

void generate_art(TextArt *art, const char *text) {
    int i, j;
    int len = strlen(text);
    int rows = (len + MAX_WIDTH - 1) / MAX_WIDTH;
    int cols = MAX_WIDTH;

    art->width = cols;
    art->height = rows;
    art->data = malloc(art->width * art->height);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int c = text[i * cols + j];
            if (c == '\n') {
                art->data[(i * cols) + j] = '\0';
            } else if (c >= 'A' && c <= 'Z') {
                art->data[(i * cols) + j] = CHAR_SET[c - 'A'];
            } else if (c >= 'a' && c <= 'z') {
                art->data[(i * cols) + j] = CHAR_SET[c - 'a'];
            } else {
                art->data[(i * cols) + j] = CHAR_SET[c - '0'];
            }
        }
    }
}

void print_art(const TextArt *art) {
    int i, j;

    for (i = 0; i < art->height; i++) {
        for (j = 0; j < art->width; j++) {
            printf("%c", art->data[i * art->width + j]);
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_WIDTH];
    TextArt art;

    printf("Enter some text to generate ASCII art:\n");
    fgets(input, MAX_WIDTH, stdin);
    generate_art(&art, input);
    print_art(&art);

    return 0;
}