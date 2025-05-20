//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 640
#define HEIGHT 480
#define BPP 3
#define PALETTE_SIZE 256

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel palette[PALETTE_SIZE];
unsigned char *pixels;

void write_ppm(char *filename, int width, int height, unsigned char *pixels) {
    FILE *fp;
    int row;

    fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    for (row = 0; row < height; row++)
        fwrite(pixels + row * width * BPP, width * BPP, 1, fp);
    fclose(fp);
}

void read_ppm(char *filename, int *width, int *height, pixel *palette) {
    FILE *fp;
    int i;

    fp = fopen(filename, "rb");
    fscanf(fp, "P6\n%d %d\n%d\n", width, height, NULL);
    for (i = 0; i < PALETTE_SIZE && fgetc(fp) != '\n'; i++) {
        palette[i].r = getc(fp);
        palette[i].g = getc(fp);
        palette[i].b = getc(fp);
    }
    fseek(fp, 2 * (*width) * (*height) * BPP, SEEK_CUR);
}

void generate_palette() {
    int i;

    for (i = 0; i < PALETTE_SIZE; i++) {
        palette[i].r = (i >> 0) & 0xFF;
        palette[i].g = (i >> 5) & 0xFF;
        palette[i].b = (i >> 10) & 0xFF;
    }
}

void generate_pixel_art(int x, int y, int size, int color) {
    int i, j;

    for (i = y; i < y + size; i++)
        for (j = x; j < x + size; j++)
            pixels[i * WIDTH + j * BPP] = color;
}

int main() {
    int i, j;
    char filename[256];

    pixels = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_WRITE | PROT_READ, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    memset(pixels, 0, WIDTH * HEIGHT * BPP);

    generate_palette();

    generate_pixel_art(100, 100, 20, 0);
    generate_pixel_art(300, 300, 30, 255);

    sprintf(filename, "output.ppm");
    write_ppm(filename, WIDTH, HEIGHT, pixels);

    munmap(pixels, WIDTH * HEIGHT * BPP);

    return 0;
}