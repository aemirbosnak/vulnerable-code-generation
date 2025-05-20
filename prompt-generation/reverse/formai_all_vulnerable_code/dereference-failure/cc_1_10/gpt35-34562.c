//FormAI DATASET v1.0 Category: Fractal Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 1000

int main(void) {
    int x, y, i, j, iter;
    double cx, cy, zx, zy, temp;
    char *image;
    FILE *fp;
    
    image = (char*) calloc(WIDTH * HEIGHT, sizeof(char));
    
    // set up file for writing
    fp = fopen("fractal.ppm", "wb");
    fprintf(fp, "P5\n# CREATOR: Single-threaded Fractal Generation\n%d %d\n255\n", WIDTH, HEIGHT);
    
    // loop over all pixels
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            
            // convert pixel coordinates to complex plane coordinates
            cx = (((double) x) - (WIDTH/2)) * 4.0 / WIDTH;
            cy = (((double) y) - (HEIGHT/2)) * 4.0 / HEIGHT;
            
            // initialize variables for Mandelbrot set calculation
            zx = 0.0;
            zy = 0.0;
            iter = 0;
            
            // perform Mandelbrot set iteration
            while (iter < MAX_ITER) {
                temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                if ((zx * zx + zy * zy) > 4.0) {
                    break;
                }
                iter++;
            }
            
            // set pixel value based on number of iterations
            if (iter == MAX_ITER) {
                image[y * WIDTH + x] = 0;
            } else {
                image[y * WIDTH + x] = iter % 255;
            }
        }
    }
    
    // write pixel data to file
    fwrite(image, sizeof(char), WIDTH * HEIGHT, fp);
    
    // clean up
    free(image);
    fclose(fp);
    
    return 0;
}