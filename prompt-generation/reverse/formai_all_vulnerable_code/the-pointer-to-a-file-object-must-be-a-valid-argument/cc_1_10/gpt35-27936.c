//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void print_ascii_art(int ascii_image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_chars[ascii_image[i][j]]);
        }
        printf("\n");
    }
}

void convert_image_to_ascii(const char *filename, int ascii_image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *fp;
    fp = fopen(filename, "r");

    char buffer[MAX_WIDTH];
    int row = 0;
    int col;

    while (fgets(buffer, MAX_WIDTH, fp) != NULL) {
        col = 0;
        for (int i = 0; buffer[i] != '\n'; i++) {
            if (isprint(buffer[i])) {
                ascii_image[row][col] = ((buffer[i] - 33) * 10) / 222 + 1;
            }
            col++;
        }
        if (col > *width) {
            *width = col;
        }
        row++;
    }
    *height = row;

    fclose(fp);
}

int main() {
    int ascii_image[MAX_HEIGHT][MAX_WIDTH];
    int width = 0, height = 0;

    convert_image_to_ascii("image.txt", ascii_image, &width, &height);
    print_ascii_art(ascii_image, width, height);

    return 0;
}