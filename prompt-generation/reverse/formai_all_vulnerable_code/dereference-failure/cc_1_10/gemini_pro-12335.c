//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *pixels;
} image;

image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, 1, 18, fp);
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixels
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(pixel));
    fread(img->pixels, 1, width * height * sizeof(pixel), fp);

    fclose(fp);

    return img;
}

void write_image(char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    *(int *)&header[18] = img->width;
    *(int *)&header[22] = img->height;
    fwrite(header, 1, 18, fp);

    // Write the pixels
    fwrite(img->pixels, 1, img->width * img->height * sizeof(pixel), fp);

    fclose(fp);
}

void convert_image_to_ascii(image *img) {
    char *ascii = malloc(img->width * img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        pixel p = img->pixels[i];
        double y = 0.2126 * p.r + 0.7152 * p.g + 0.0722 * p.b;
        ascii[i] = " .,-~%#*+=-:.  "[(int)(y / 16.0)];
    }

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%c", ascii[i * img->width + j]);
        }
        printf("\n");
    }

    free(ascii);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    image *img = read_image(argv[1]);
    if (!img) {
        return 1;
    }

    convert_image_to_ascii(img);

    write_image("output.bmp", img);

    free(img->pixels);
    free(img);

    return 0;
}