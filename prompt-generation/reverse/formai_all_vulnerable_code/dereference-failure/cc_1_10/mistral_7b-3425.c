//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 64
#define PALETTE_SIZE 16

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

Pixel palette[PALETTE_SIZE];
Pixel *image;

void init_palette() {
    int i;
    palette[0].r = 0;
    palette[0].g = 0;
    palette[0].b = 0;
    for (i = 1; i < PALETTE_SIZE; i++) {
        palette[i].r = (i & 1) * 32;
        palette[i].g = (i & 2) * 32;
        palette[i].b = (i & 4) * 32;
    }
}

void generate_pixel(int x, int y) {
    Pixel p;
    p.r = palette[x % PALETTE_SIZE].r;
    p.g = palette[y % PALETTE_SIZE].g;
    p.b = palette[(x + y) % PALETTE_SIZE].b;
    image[y * WIDTH + x] = p;
}

void generate_image() {
    int i, j;
    srand(time(NULL));
    image = malloc(WIDTH * HEIGHT * sizeof(Pixel));
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            generate_pixel(i, j);
        }
    }
}

void save_image(char *filename) {
    FILE *fp;
    int i;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    fwrite("PM\n", 2, 1, fp);
    fwrite("64 64 255\n", 9, 1, fp);
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        fwrite(&image[i].r, 1, 1, fp);
        fwrite(&image[i].g, 1, 1, fp);
        fwrite(&image[i].b, 1, 1, fp);
    }
    fclose(fp);
}

int main() {
    init_palette();
    generate_image();
    save_image("output.png");
    free(image);
    return 0;
}