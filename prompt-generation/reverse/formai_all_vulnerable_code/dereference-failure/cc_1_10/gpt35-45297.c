//FormAI DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct image {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return NULL;
    }

    char magic[3];
    if (fscanf(file, "%2s", magic) != 1) {
        fprintf(stderr, "Error: Could not read magic number\n");
        fclose(file);
        return NULL;
    }

    if (strcmp(magic, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported file format '%s'\n", magic);
        fclose(file);
        return NULL;
    }

    int width = 0, height = 0, maxval = 0;
    if (fscanf(file, "%d %d %d", &width, &height, &maxval) != 3) {
        fprintf(stderr, "Error: Could not read image width/height/maxval\n");
        fclose(file);
        return NULL;
    }

    if (maxval != 255) {
        fprintf(stderr, "Error: Unsupported maxval %d\n", maxval);
        fclose(file);
        return NULL;
    }

    if (fgetc(file) != '\n') {
        fprintf(stderr, "Error: Could not read newline character\n");
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel *)malloc(sizeof(Pixel) * width * height);

    if (fread(image->pixels, sizeof(Pixel), width * height, file) != width * height) {
        fprintf(stderr, "Error: Could not read all pixels\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fclose(file);
    return image;
}

// Function to write an image to a file
void write_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", image->width, image->height, 255);

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

// Function to flip an image horizontally
void flip_image_horizontally(Image *image) {
    Pixel *temp_row = (Pixel *)malloc(sizeof(Pixel) * image->width);
    for (int y = 0; y < image->height; y++) {
        int left = 0, right = image->width - 1;
        while (left < right) {
            temp_row[left] = image->pixels[y * image->width + left];
            image->pixels[y * image->width + left] = image->pixels[y * image->width + right];
            image->pixels[y * image->width + right] = temp_row[left];
            left++;
            right--;
        }
    }
    free(temp_row);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s infile outfile\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    flip_image_horizontally(image);

    write_image(argv[2], image);

    free(image->pixels);
    free(image);

    printf("Image flipped horizontally and saved to '%s'\n", argv[2]);

    return 0;
}