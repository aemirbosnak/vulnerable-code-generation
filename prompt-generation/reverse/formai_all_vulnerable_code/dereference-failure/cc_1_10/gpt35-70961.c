//FormAI DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red, green, blue;
} Pixel;

typedef struct {
    int width, height;
    Pixel* pixels;
} Image;

void load_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "rb");

    if (!file) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    char magic[3];
    fscanf(file, "%s", magic);

    if (strcmp(magic, "P6") != 0) {
        printf("Error: %s is not a valid PPM file\n", filename);
        exit(1);
    }

    fscanf(file, "%d %d", &image->width, &image->height);

    int max_val;
    fscanf(file, "%d", &max_val);

    if (max_val != 255) {
        printf("Error: %s has an unsupported pixel format\n", filename);
        exit(1);
    }

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

void save_image(Image* image, const char* filename) {
    FILE* file = fopen(filename, "wb");

    if (!file) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    fprintf(file, "P6 %d %d 255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

void invert_image(Image* image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].red = 255 - image->pixels[i].red;
        image->pixels[i].green = 255 - image->pixels[i].green;
        image->pixels[i].blue = 255 - image->pixels[i].blue;
    }
}

void grayscale_image(Image* image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->pixels[i].red + image->pixels[i].green + image->pixels[i].blue) / 3;
        image->pixels[i].red = gray;
        image->pixels[i].green = gray;
        image->pixels[i].blue = gray;
    }
}

void blur_image(Image* image) {
    Pixel* new_pixels = malloc(image->width * image->height * sizeof(Pixel));

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            float avg_r = 0;
            float avg_g = 0;
            float avg_b = 0;

            int count = 0;

            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    int nx = i + x;
                    int ny = j + y;

                    if (nx >= 0 && ny >= 0 && nx < image->width && ny < image->height) {
                        avg_r += image->pixels[ny * image->width + nx].red;
                        avg_g += image->pixels[ny * image->width + nx].green;
                        avg_b += image->pixels[ny * image->width + nx].blue;
                        count++;
                    }
                }
            }

            new_pixels[j * image->width + i].red = avg_r / count;
            new_pixels[j * image->width + i].green = avg_g / count;
            new_pixels[j * image->width + i].blue = avg_b / count;
        }
    }

    free(image->pixels);
    image->pixels = new_pixels;
}

int main() {
    Image image;
    load_image(&image, "input.ppm");

    // Apply image filters here
    invert_image(&image);
    grayscale_image(&image);
    blur_image(&image);

    save_image(&image, "output.ppm");

    free(image.pixels);

    return 0;
}