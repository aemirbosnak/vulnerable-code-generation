//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read header
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    // Allocate memory for data
    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        free(img);
        fclose(fp);
        return NULL;
    }

    // Read data
    fread(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void save_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write header
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    // Write data
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output ascii art>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    // Create ASCII art
    char *ascii_art = malloc(img->width * img->height * sizeof(char));
    if (!ascii_art) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        free_image(img);
        return 1;
    }

    for (int i = 0; i < img->width * img->height; i++) {
        pixel p = img->data[i];
        double brightness = (p.r + p.g + p.b) / 3.0;
        char c = brightness < 128 ? '.' : '#';
        ascii_art[i] = c;
    }

    // Save ASCII art
    save_image(argv[2], ascii_art);

    free_image(img);
    free(ascii_art);

    return 0;
}