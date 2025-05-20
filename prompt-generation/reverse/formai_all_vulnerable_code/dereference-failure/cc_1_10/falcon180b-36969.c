//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    srand(time(NULL));
    int **pixels = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        pixels[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            pixels[i][j] = (r << 16) | (g << 8) | b;
        }
    }

    FILE *fp = fopen("pixel_art.bmp", "wb");
    if (!fp) {
        printf("Error creating file\n");
        return 1;
    }

    fwrite("BM", 2, 1, fp);
    fwrite(&(int){54 + 3 * WIDTH * HEIGHT}, 4, 1, fp);
    fwrite(&(int){40}, 4, 1, fp);
    fwrite(&(int){WIDTH}, 4, 1, fp);
    fwrite(&(int){HEIGHT}, 4, 1, fp);
    fwrite(&(int){1}, 2, 1, fp);
    fwrite(&(int){24}, 2, 1, fp);

    for (int i = 0; i < HEIGHT; i++) {
        fwrite(pixels[i], 3, WIDTH, fp);
    }

    fclose(fp);

    for (int i = 0; i < HEIGHT; i++) {
        free(pixels[i]);
    }
    free(pixels);

    return 0;
}