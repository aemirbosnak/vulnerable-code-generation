//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int r, g, b;
} color;

void generate_pixel(int *image_data, int width, int height) {
    srand(time(0));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            image_data[y * width + x] = (r << 16) | (g << 8) | b;
        }
    }
}

color generate_color(int r, int g, int b) {
    return (color) {.r = r,.g = g,.b = b};
}

void read_image(char *filename, int **image_data, int *width, int *height) {
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Error opening image file: %s\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);

    if (size % 3!= 0) {
        printf("Error: Invalid image file\n");
        return;
    }

    *image_data = malloc(size / 3);
    *width = size / 3;
    *height = 1;

    fread(*image_data, size / 3, 1, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int *image_data;
    int width, height;

    read_image(filename, &image_data, &width, &height);

    if (image_data == NULL) {
        printf("Error allocating memory for image data\n");
        return 1;
    }

    int *output_pixel = malloc(width * height * 3);
    memset(output_pixel, 0, width * height * 3);

    generate_pixel(image_data, width, height);

    free(output_pixel);

    printf("Pixel Art Generator complete\n");

    return 0;
}