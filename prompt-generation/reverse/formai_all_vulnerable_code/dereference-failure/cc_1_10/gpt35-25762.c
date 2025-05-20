//FormAI DATASET v1.0 Category: Fractal Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATIONS 1000
#define COLOR_DEPTH 255

void set_pixel(int x, int y, int r, int g, int b, unsigned char *image){
    int index = (y * WIDTH + x) * 3;
    image[index] = r;
    image[index + 1] = g;
    image[index + 2] = b;
}

void fractal(int x, int y, int size, double angle, unsigned char *image){
    if(size == 0) return;
    int i, j, mx, my, c = (sin(angle) + 1.0) * COLOR_DEPTH / 2.0;
    double a = M_PI / 3.0;

    for(i = 0; i < size; ++i){
        for(j = 0; j < size; ++j){
            mx = WIDTH / 2 - size / 2 + i + x;
            my = HEIGHT / 2 - size / 2 + j + y;
            if((mx >= 0) && (mx < WIDTH) && (my >= 0) && (my < HEIGHT)){
                set_pixel(mx, my, c, 2 * c / 3, c / 3, image);
            }
        }
    }

    int new_size = size / 2;
    fractal(x + size / 4, y - new_size / 2, new_size, angle + a, image);
    fractal(x - size / 4, y - new_size / 2, new_size, angle - a, image);
}

int main(){
    unsigned char *image = (unsigned char*)malloc(WIDTH * HEIGHT * 3 * sizeof(unsigned char));
    int i, j, idx;

    for(i = 0; i < WIDTH; ++i){
        for(j = 0; j < HEIGHT; ++j){
            idx = (j * WIDTH + i) * 3;
            image[idx] = 0;
            image[idx + 1] = 0;
            image[idx + 2] = 0;
        }
    }

    fractal(0, 0, 400, M_PI / 2.0, image);

    FILE *f = fopen("fractal.ppm", "wb");
    fprintf(f, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, COLOR_DEPTH);
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT * 3, f);
    fclose(f);

    free(image);

    return 0;
}