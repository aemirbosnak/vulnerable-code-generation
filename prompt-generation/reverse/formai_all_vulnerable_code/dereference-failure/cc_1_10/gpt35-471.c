//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    int pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} image_t;

int read_image(image_t *image, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return -1;

    char buffer[1024];
    int row = 0;
    while(fgets(buffer, 1024, file)) {
        char *ptr = buffer;

        while(*ptr) {
            if (isspace(*ptr)) {
                ptr++;
                continue;
            }

            if (*ptr == '#') {
                while (*ptr) ptr++;
                break;
            }

            int pixel = strtol(ptr, &ptr, 10);

            if (pixel < 0 || pixel > 255) {
                fclose(file);
                return -1;
            }

            if (row >= image->height) {
                fclose(file);
                return -1;
            }

            image->pixels[row][image->height - 1] = pixel;
        }

        row++;
    }

    fclose(file);

    return 0;
}

int write_image(const image_t *image, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) return -1;

    fprintf(file, "P2\n%d %d\n255\n", image->width, image->height);

    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            fprintf(file, "%d ", image->pixels[col][image->height - row - 1]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    return 0;
}

void invert(image_t *image) {
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            image->pixels[col][row] = 255 - image->pixels[col][row];
        }
    }
}

void grayscale(image_t *image) {
    for (int row = 0; row < image->height; row++) {
        for (int col = 0; col < image->width; col++) {
            int value = image->pixels[col][row];
            image->pixels[col][row] = (value * 0.3) + (value * 0.59) + (value * 0.11);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return -1;
    }

    image_t image;
    if (read_image(&image, argv[1]) != 0) {
        printf("Error reading input file '%s'.\n", argv[1]);
        return -1;
    }

    invert(&image);
    grayscale(&image);

    if (write_image(&image, argv[2]) != 0) {
        printf("Error writing output file '%s'.\n", argv[2]);
        return -1;
    }

    printf("Done.\n");

    return 0;
}