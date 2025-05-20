//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

void flip_image(unsigned char *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char temp = image[x + width * y];
            image[x + width * y] = image[width * height - 1 - (y + width * x)];
            image[width * height - 1 - (y + width * x)] = temp;
        }
    }
}

void change_brightness(unsigned char *image, int width, int height, float factor) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            unsigned char red = image[index];
            unsigned char green = image[index + 1];
            unsigned char blue = image[index + 2];

            int new_red = (int)(red * factor);
            int new_green = (int)(green * factor);
            int new_blue = (int)(blue * factor);

            image[index] = new_red;
            image[index + 1] = new_green;
            image[index + 2] = new_blue;
        }
    }
}

void change_contrast(unsigned char *image, int width, int height, float factor) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            unsigned char red = image[index];
            unsigned char green = image[index + 1];
            unsigned char blue = image[index + 2];

            int new_red = (int)((red * factor) + (factor - 1));
            int new_green = (int)((green * factor) + (factor - 1));
            int new_blue = (int)((blue * factor) + (factor - 1));

            image[index] = new_red;
            image[index + 1] = new_green;
            image[index + 2] = new_blue;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <image_path> <width> <height>\n", argv[0]);
        return 1;
    }

    const char *image_path = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    unsigned char *image = (unsigned char *)malloc(width * height * 3);
    FILE *file = fopen(image_path, "rb");

    if (!file) {
        printf("Error opening file: %s\n", image_path);
        return 1;
    }

    fread(image, sizeof(unsigned char), width * height * 3, file);
    fclose(file);

    flip_image(image, width, height);
    change_brightness(image, width, height, 1.5);
    change_contrast(image, width, height, 1.2);

    FILE *output_file = fopen("output.ppm", "wb");
    if (!output_file) {
        printf("Error opening output file: output.ppm\n");
        return 1;
    }

    fprintf(output_file, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height * 3, output_file);

    fclose(output_file);

    free(image);

    return 0;
}