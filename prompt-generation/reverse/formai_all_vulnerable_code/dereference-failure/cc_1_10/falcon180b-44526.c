//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_COLOR 256

int main(void) {
    int width, height, max_color;
    int **pixels;
    int i, j, k;
    FILE *fp;

    // Read input from file
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d %d %d", &width, &height, &max_color);
    fclose(fp);

    // Allocate memory for pixel array
    pixels = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        pixels[i] = (int *)malloc(width * sizeof(int));
    }

    // Generate pixel art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = rand() % max_color;
            pixels[i][j] = k;
        }
    }

    // Save pixel art to file
    fp = fopen("output.bmp", "wb");
    fprintf(fp, "BM\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "%d\n", 0);
    fprintf(fp, "%d\n", 54 + 40 * (3 - 1));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%c", pixels[i][j] % 16 + '0');
        }
    }
    fprintf(fp, "\n");
    fclose(fp);

    // Free memory
    for (i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}