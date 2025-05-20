//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_PIXELS WIDTH * HEIGHT

int main() {
    srand(time(NULL));

    int *pixels = (int *)malloc(NUM_PIXELS * sizeof(int));

    for (int i = 0; i < NUM_PIXELS; i++) {
        pixels[i] = rand() % 256;
    }

    FILE *file = fopen("pixel_art.bmp", "wb");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    fwrite("BM", 2, 1, file);
    fwrite(&(int){54 + 3 * WIDTH}, 4, 1, file);
    fwrite(&(int){HEIGHT}, 4, 1, file);
    fwrite(&(int){1}, 4, 1, file);
    fwrite(&(int){24}, 4, 1, file);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;

            if (x % 2 == 0 && y % 2 == 0) {
                // Even pixels
                int r = pixels[index] >> 16 & 0xFF;
                int g = pixels[index] >> 8 & 0xFF;
                int b = pixels[index] & 0xFF;

                fwrite(&b, 1, 1, file);
                fwrite(&g, 1, 1, file);
                fwrite(&r, 1, 1, file);
            } else {
                // Odd pixels
                int r = pixels[index - 1] >> 16 & 0xFF;
                int g = pixels[index - 1] >> 8 & 0xFF;
                int b = pixels[index - 1] & 0xFF;

                fwrite(&b, 1, 1, file);
                fwrite(&g, 1, 1, file);
                fwrite(&r, 1, 1, file);
            }
        }
    }

    fclose(file);

    free(pixels);

    return 0;
}