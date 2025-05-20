//GEMINI-pro DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define SWIDTH 640
#define SHEIGHT 480

#define MAX_ITER 100

typedef struct {
    double x, y;
} complex;

complex c;

complex square(complex z) {
    z.x = z.x * z.x - z.y * z.y;
    z.y = 2 * z.x * z.y;
    return z;
}

int main() {
    int x, y;
    FILE *fp;
    unsigned char *image;

    image = malloc(SWIDTH * SHEIGHT);
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        return EXIT_FAILURE;
    }

    fp = fopen("fractal.ppm", "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file for writing\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "P6\n%d %d\n255\n", SWIDTH, SHEIGHT);

    for (y = 0; y < SHEIGHT; y++) {
        for (x = 0; x < SWIDTH; x++) {
            double cx = 3.5 * (x - SWIDTH / 2) / (SWIDTH / 2);
            double cy = 2.5 * (y - SHEIGHT / 2) / (SHEIGHT / 2);
            complex z = (complex){.x = 0, .y = 0};
            int i;

            for (i = 0; i < MAX_ITER; i++) {
                if (z.x * z.x + z.y * z.y > 4) {
                    break;
                }
                z = square(z);
                z.x += cx;
                z.y += cy;
            }

            image[y * SWIDTH + x] = i * 255 / MAX_ITER;
        }
    }

    fwrite(image, 1, SWIDTH * SHEIGHT, fp);
    fclose(fp);
    free(image);

    return EXIT_SUCCESS;
}