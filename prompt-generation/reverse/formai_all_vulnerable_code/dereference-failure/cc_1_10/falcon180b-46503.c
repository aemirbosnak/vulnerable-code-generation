//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60
#define CHAR_SET ".,:;oxOX*#@"

typedef struct {
    int x, y;
} Point;

void print_char(char c) {
    printf("%c", c);
}

void print_row(char *row, int n) {
    for (int i = 0; i < n; i++) {
        print_char(row[i]);
    }
}

void draw_ascii(char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c = image[y * width + x];
            int index = c - '0';
            if (index < 0 || index >= strlen(CHAR_SET)) {
                index = 0;
            }
            print_char(CHAR_SET[index]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        return 1;
    }

    fseek(fp, 18, SEEK_SET); // skip BMP header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    char *image = (char *)malloc(width * height);
    fread(image, sizeof(char), width * height, fp);

    fclose(fp);

    draw_ascii(image, width, height);

    free(image);

    return 0;
}