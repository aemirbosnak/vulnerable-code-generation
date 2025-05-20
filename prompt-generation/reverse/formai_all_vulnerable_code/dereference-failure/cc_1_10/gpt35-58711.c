//FormAI DATASET v1.0 Category: Fractal Generation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Complex {
    float real;
    float imaginary;
} Complex;

int main() {

    int width = 80, height = 50;
    Complex c, z, temp;
    int i, j, k, iter;
    float zoom = 1;
    float moveX = -0.5, moveY = 0;
    float fiveOverWidth = 5.0 / (float)width;
    float twoOverHeight = 2.0 / (float)height;
    float x, y;
    char *image = (char *)malloc(sizeof(char) * width * height);

    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            x = fiveOverWidth * (float)j - (5.0 / 2.0);
            y = twoOverHeight * (float)i - 1.0;

            z.real = 0;
            z.imaginary = 0;
            c.real = (1 / zoom) * x - moveX;
            c.imaginary = (1 / zoom) * y - moveY;

            iter = 0;
            while (z.real * z.real + z.imaginary * z.imaginary < 4 && iter < 50) {
                temp.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
                temp.imaginary = 2 * z.real * z.imaginary + c.imaginary;
                z = temp;
                ++iter;
            }

            if (iter == 50) {
                image[i * width + j] = '.';
            }
            else {
                image[i * width + j] = '#';
            }
        }
    }

    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            putchar(image[i * width + j]);
        }
        putchar('\n');
    }

    free(image);
    return 0;
}