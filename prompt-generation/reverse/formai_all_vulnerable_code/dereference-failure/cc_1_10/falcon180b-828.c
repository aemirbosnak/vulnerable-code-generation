//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int x;
    int y;
    char c;
    int bg;
} pixel;

void print_pixel(pixel p) {
    if (p.bg) {
        printf("\033[48;5;%dm\033[38;5;%dm ", p.bg, p.bg);
    } else {
        printf("\033[0m ");
    }
}

void print_line(pixel *line, int width) {
    for (int i = 0; i < width; i++) {
        print_pixel(line[i]);
    }
    printf("\n");
}

void print_ascii_art(pixel *art, int width, int height) {
    for (int y = 0; y < height; y++) {
        print_line(art + y * width, width);
    }
}

pixel *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Failed to open image file.\n");
        exit(1);
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    pixel *art = malloc(width * height * sizeof(pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int c = fgetc(fp);
            art[y * width + x].x = x;
            art[y * width + x].y = y;
            art[y * width + x].c = c;
            art[y * width + x].bg = 0;
        }
    }

    fclose(fp);
    return art;
}

int main() {
    const char *filename = "example.bmp";
    pixel *art = load_image(filename);

    int width = art[0].x;
    int height = art[0].y;

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image dimensions exceed the maximum supported size.\n");
        exit(1);
    }

    print_ascii_art(art, width, height);

    free(art);
    return 0;
}