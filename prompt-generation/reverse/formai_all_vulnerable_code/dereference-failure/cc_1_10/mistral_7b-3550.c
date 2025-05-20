//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FONT_SIZE 8
#define FONT_WIDTH 8
#define FONT_HEIGHT 8

typedef struct {
    unsigned char data[FONT_WIDTH][FONT_HEIGHT];
} Font;

void load_font(const char *filename, Font *font) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open font file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < 128; i++) {
        fread(font->data[0], FONT_SIZE, 1, file);
        if (feof(file)) {
            fprintf(stderr, "Error: Premature end of file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void print_ascii_art(const char *text, Font *font) {
    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
        if (isalnum(text[i])) {
            int ascii = tolower(text[i]);
            for (j = 0; j < FONT_WIDTH; j++) {
                for (k = 0; k < FONT_HEIGHT; k++) {
                    putchar(font->data[ascii][k >> 3] & (1 << (7 & (j * 8 + k))));
                }
            }
        } else {
            putchar(text[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <text> <font>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Font font;
    load_font(argv[2], &font);

    print_ascii_art(argv[1], &font);

    return EXIT_SUCCESS;
}