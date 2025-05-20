//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_COLOR 255

int main() {
    srand(time(NULL));

    FILE *fp = fopen("pixelart.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int width = WIDTH;
    int height = HEIGHT;
    int bitmap_size = 54 + 3 * width * height;

    fwrite(&bitmap_size, 4, 1, fp);
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);
    fwrite("BM", 2, 1, fp);

    int bitmap_data_size = 3 * width * height;
    int padding = (4 - (bitmap_data_size % 4)) % 4;
    int total_size = bitmap_data_size + padding;

    fwrite(&total_size, 4, 1, fp);
    fwrite(&padding, 4, 1, fp);

    int *pixels = malloc(sizeof(int) * width * height);
    if (pixels == NULL) {
        printf("Error: Could not allocate memory.\n");
        return 2;
    }

    for (int i = 0; i < width * height; i++) {
        pixels[i] = rand() % MAX_COLOR;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            fwrite(&pixels[index], 1, 1, fp);
        }
    }

    fclose(fp);

    printf("Pixel art generated successfully!\n");

    return 0;
}