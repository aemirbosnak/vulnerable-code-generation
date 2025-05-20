//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_ASCII_WIDTH 80
#define MAX_ASCII_HEIGHT 24

typedef struct {
    int width;
    int height;
    char **data;
} ASCIIArt;

ASCIIArt *create_ascii_art(int width, int height) {
    ASCIIArt *ascii_art = malloc(sizeof(ASCIIArt));
    ascii_art->width = width;
    ascii_art->height = height;
    ascii_art->data = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        ascii_art->data[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            ascii_art->data[i][j] = ' ';
        }
    }
    return ascii_art;
}

void destroy_ascii_art(ASCIIArt *ascii_art) {
    for (int i = 0; i < ascii_art->height; i++) {
        free(ascii_art->data[i]);
    }
    free(ascii_art->data);
    free(ascii_art);
}

int main() {
    char text[MAX_TEXT_LENGTH];
    printf("Enter text: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    int text_width = strlen(text);
    int text_height = 1;
    for (int i = 0; i < text_width; i++) {
        if (text[i] == '\n') {
            text_height++;
        }
    }

    int ascii_width = ceil(text_width * 7.0 / 4.0);
    int ascii_height = ceil(text_height * 9.0 / 8.0);

    ASCIIArt *ascii_art = create_ascii_art(ascii_width, ascii_height);

    int ascii_x = 0;
    int ascii_y = 0;
    int text_x = 0;
    int text_y = 0;
    while (text_y < text_height) {
        while (text_x < text_width) {
            if (text[text_x] == '\n') {
                text_y++;
                text_x = 0;
            } else {
                int char_width = 7;
                int char_height = 9;
                int char_x = text_x * char_width;
                int char_y = text_y * char_height;

                for (int i = char_x; i < char_x + char_width; i++) {
                    for (int j = char_y; j < char_y + char_height; j++) {
                        if (i >= 0 && i < ascii_width && j >= 0 && j < ascii_height) {
                            ascii_art->data[j][i] = 'X';
                        }
                    }
                }

                text_x++;
            }
        }
    }

    for (int i = 0; i < ascii_height; i++) {
        for (int j = 0; j < ascii_width; j++) {
            printf("%c", ascii_art->data[i][j]);
        }
        printf("\n");
    }

    destroy_ascii_art(ascii_art);

    return 0;
}