//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *load_ppm(const char *filename);
void save_ppm(const char *filename, Image *image);
void apply_grayscale(Image *image);
void free_image(Image *image);
void print_usage();

int main(int argc, char **argv) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];

    Image *image = load_ppm(input_filename);
    if (!image) {
        printf("Error loading image\n");
        return 1;
    }

    if (strcmp(operation, "grayscale") == 0) {
        apply_grayscale(image);
    } else {
        printf("Unknown operation: %s\n", operation);
        free_image(image);
        return 1;
    }

    save_ppm(output_filename, image);
    free_image(image);

    return 0;
}

void print_usage() {
    printf("Usage: image_editor input.ppm output.ppm operation\n");
    printf("Operation: grayscale\n");
}

Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    if (strcmp(buffer, "P3\n") != 0) {
        fclose(file);
        printf("Unsupported PPM format\n");
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }

    fscanf(file, "%d %d", &image->width, &image->height);
    fscanf(file, "%*d"); // Ignore max color value

    image->data = (Pixel *)malloc(image->width * image->height * sizeof(Pixel));
    if (!image->data) {
        free(image);
        fclose(file);
        perror("Memory allocation failed");
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &image->data[i].r, &image->data[i].g, &image->data[i].b);
    }

    fclose(file);
    return image;
}

void save_ppm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");

    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%d %d %d\n", image->data[i].r, image->data[i].g, image->data[i].b);
    }

    fclose(file);
}

void apply_grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}