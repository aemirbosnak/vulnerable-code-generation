//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    // Initialize image
    int **image = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int *)malloc(WIDTH * sizeof(int));
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = 0;
        }
    }

    // Generate fractal
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int x = j - WIDTH / 2;
            int y = i - HEIGHT / 2;
            double r = sqrt(x * x + y * y);
            double theta = atan2(y, x);
            double value = r / (r + 1.0);
            if (value > 0.5) {
                value = 1.0;
            } else {
                value = 0.0;
            }
            image[i][j] = value * 255;
        }
    }

    // Save image
    FILE *fp = fopen("image.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fputc(image[i][j], fp);
        }
    }
    fclose(fp);

    // Free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}