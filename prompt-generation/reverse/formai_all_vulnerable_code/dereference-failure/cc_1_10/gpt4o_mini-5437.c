//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

typedef struct {
    unsigned char r, g, b;
} Color;

Color getColor(int iter) {
    Color color;
    if (iter == MAX_ITER) {
        color.r = color.g = color.b = 0; // Black
    } else {
        color.r = (iter * 9) % 256;
        color.g = (iter * 3) % 256;
        color.b = (iter * 7) % 256;
    }
    return color;
}

void renderFractal(double left, double right, double top, double bottom) {
    FILE *fp = fopen("cyber_fractal.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    unsigned char *image = malloc(WIDTH * HEIGHT * 3);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = 1.0 * x / WIDTH * (right - left) + left;
            double zy = 1.0 * y / HEIGHT * (bottom - top) + top;
            int iter = 0;

            while (iter < MAX_ITER && zx * zx + zy * zy < 4.0) {
                double tmp = zx * zx - zy * zy + (left + right) / 2;
                zy = 2.0 * zx * zy + (top + bottom) / 2;
                zx = tmp;
                iter++;
            }

            Color color = getColor(iter);
            image[(y * WIDTH + x) * 3 + 0] = color.r;
            image[(y * WIDTH + x) * 3 + 1] = color.g;
            image[(y * WIDTH + x) * 3 + 2] = color.b;
        }
    }

    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);
    free(image);
}

void displayFractal() {
    printf("\033[1;32m[INFO]\033[0m Rendering the Cyberpunk fractal...\n");
    renderFractal(-2.0, 2.0, -2.0, 2.0);
    printf("\033[1;32m[SUCCESS]\033[0m Fractal generated. Check the file cyber_fractal.ppm\n");
}

int main() {
    printf("\033[1;34m--- Cyberpunk Fractal Generator ---\033[0m\n");
    displayFractal();
    
    // Simulate CPU loading in a cyberpunk environment
    for (int i = 0; i < 5; i++) {
        printf("\033[1;35m[LOADING]\033[0m System reconfiguring...\n");
        sleep(1);
    }

    printf("\033[1;36m[END]\033[0m Fractal generation completed.\n");
    return 0;
}