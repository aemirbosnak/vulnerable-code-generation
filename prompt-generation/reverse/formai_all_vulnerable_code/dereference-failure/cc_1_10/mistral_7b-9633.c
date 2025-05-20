//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 8
#define HEIGHT 8

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void save_image(const char *filename, const Pixel image[WIDTH][HEIGHT]) {
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL) {
        fprintf(stderr, "Failed to open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }

    size_t size = WIDTH * HEIGHT;
    fwrite(image, sizeof(Pixel), size, fp);
    fclose(fp);
}

void print_usage() {
    printf("Usage: pxgen [width] [height] [pixel]\n");
    printf("Create a new pixel art image with the given width, height, and initial color.\n");
    printf("For example, to create a 10x10 image with a blue pixel as the initial color, use:\n");
    printf("  pxgen 10 10 0 0 255\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4 || (argc > 5 && argc % 2 != 1)) {
        print_usage();
        return EXIT_FAILURE;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || height <= 0) {
        print_usage();
        return EXIT_FAILURE;
    }

    Pixel initial_pixel = {.r = atoi(argv[3]), .g = atoi(argv[4]), .b = atoi(argv[5])};
    Pixel image[WIDTH][HEIGHT];

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            image[x][y] = initial_pixel;
        }
    }

    if (argc > 6) {
        int x = atoi(argv[6]);
        int y = atoi(argv[7]);

        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            image[x][y].r = atoi(argv[8]);
            image[x][y].g = atoi(argv[9]);
            image[x][y].b = atoi(argv[10]);
        } else {
            fprintf(stderr, "Invalid pixel position %d,%d.\n", x, y);
            return EXIT_FAILURE;
        }
    }

    save_image("output.raw", image);

    printf("Pixel art image created successfully! Check output.raw.\n");

    return EXIT_SUCCESS;
}