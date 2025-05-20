//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX_WIDTH 80

typedef struct {
    int id;
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

typedef struct {
    int id;
    int x;
    int y;
} Point;

const char *CHARS = " .:-=+*#%@";

void print_ascii_art(const char *text, int width) {
    int text_len = strlen(text);
    if (width < text_len) {
        printf("Error: Width must be greater than or equal to text length.\n");
        return;
    }

    int num_cols = ceil((double)text_len / width);
    int num_rows = ceil((double)text_len / num_cols);

    int char_index = 0;
    for (int row = 0; row < num_rows; row++) {
        for (int col = 0; col < num_cols; col++) {
            int pos = row * num_cols + col;
            if (pos < text_len) {
                printf("%c", text[pos]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_ascii_art(const char *text, int width, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    print_ascii_art(text, width);
    fprintf(file, "%s\n", CHARS);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <text> <width> [<filename>]\n", argv[0]);
        return 1;
    }

    const char *text = argv[1];
    int width = atoi(argv[2]);
    const char *filename = "ascii_art.txt";
    if (argc > 3) {
        filename = argv[3];
    }

    generate_ascii_art(text, width, filename);

    return 0;
}