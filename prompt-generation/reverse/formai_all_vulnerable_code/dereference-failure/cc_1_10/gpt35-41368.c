//FormAI DATASET v1.0 Category: Fractal Generation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Woah! I just generated a fractal!\n");
    int width = 80;
    int height = 24;
    int max_iteration = 1000;
    double x_min = -2.0;
    double x_max = 2.0;
    double y_min = -1.5;
    double y_max = 1.5;
    double x_range = x_max - x_min;
    double y_range = y_max - y_min;

    char *pixel = (char*) malloc(sizeof(char) * width * height);
    int i, j, k;

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            double c_re = (double) j / width * x_range + x_min;
            double c_im = (double) i / height * y_range + y_min;
            double z_re = 0;
            double z_im = 0;

            for(k = 0; k < max_iteration; k++) {
                double z_re2 = z_re * z_re;
                double z_im2 = z_im * z_im;
                if(z_re2 + z_im2 > 4) break;

                z_im = 2 * z_re * z_im + c_im;
                z_re = z_re2 - z_im2 + c_re;
            }

            if(k == max_iteration) {
                pixel[i * width + j] = '@';
            } else {
                pixel[i * width + j] = ' ';
            }
        }
    }

    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%c", pixel[i * width + j]);
        }
        printf("\n");
    }

    free(pixel);
    return 0;
}