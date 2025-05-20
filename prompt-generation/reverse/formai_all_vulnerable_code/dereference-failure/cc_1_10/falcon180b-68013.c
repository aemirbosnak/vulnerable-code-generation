//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 100000
#define MAX_COLORS 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <output_file> <width> <height> <color_scheme>\n", argv[0]);
        exit(1);
    }

    char *output_file = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int color_scheme = atoi(argv[4]);

    FILE *fp = fopen(output_file, "wb");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    Pixel *pixels = (Pixel *)malloc(sizeof(Pixel) * MAX_PIXELS);
    if (pixels == NULL) {
        printf("Error allocating memory for pixels.\n");
        exit(1);
    }

    int num_pixels = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = 0, g = 0, b = 0;

            switch (color_scheme) {
                case 1: // grayscale
                    r = g = b = (int)(255 * x / (width - 1));
                    break;
                case 2: // red-green gradient
                    r = (int)(255 * x / (width - 1));
                    g = (int)(255 * y / (height - 1));
                    b = 0;
                    break;
                case 3: // blue-yellow gradient
                    r = 0;
                    g = (int)(255 * x / (width - 1));
                    b = (int)(255 * y / (height - 1));
                    break;
                default:
                    printf("Invalid color scheme.\n");
                    exit(1);
            }

            pixels[num_pixels].x = x;
            pixels[num_pixels].y = y;
            pixels[num_pixels].r = r;
            pixels[num_pixels].g = g;
            pixels[num_pixels].b = b;

            num_pixels++;

            if (num_pixels >= MAX_PIXELS) {
                printf("Error: Maximum number of pixels exceeded.\n");
                exit(1);
            }
        }
    }

    fwrite(pixels, sizeof(Pixel), num_pixels, fp);
    fclose(fp);

    free(pixels);
    return 0;
}