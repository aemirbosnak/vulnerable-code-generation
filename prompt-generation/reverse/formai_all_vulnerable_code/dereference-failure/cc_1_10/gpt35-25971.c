//FormAI DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int red;
    int green;
    int blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel* pixels;
} Image;

Image* create_image(int width, int height) {
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (pixel*) malloc(sizeof(pixel) * width * height);
    return image;
}

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    Image* image = create_image(width, height);
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(file, "%d %d %d", &(image->pixels[i * width + j].red), &(image->pixels[i * width + j].green), &(image->pixels[i * width + j].blue));
        }
    }
    fclose(file);
    return image;
}

void save_image(const Image* image, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: file could not be created.\n");
        exit(1);
    }
    fprintf(file, "%d %d\n", image->width, image->height);
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(file, "%d %d %d ", image->pixels[i * image->width + j].red, image->pixels[i * image->width + j].green, image->pixels[i * image->width + j].blue);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void negate_red(Image* image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j].red = 255 - image->pixels[i * image->width + j].red;
        }
    }
}

void grayscale(Image* image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int average = (image->pixels[i * image->width + j].red + image->pixels[i * image->width + j].green + image->pixels[i * image->width + j].blue) / 3;
            image->pixels[i * image->width + j].red = average;
            image->pixels[i * image->width + j].green = average;
            image->pixels[i * image->width + j].blue = average;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: image_editor input_image output_image\n");
        return 1;
    }
    Image* image = load_image(argv[1]);
    negate_red(image);
    grayscale(image);
    save_image(image, argv[2]);
    free(image->pixels);
    free(image);
    return 0;
}