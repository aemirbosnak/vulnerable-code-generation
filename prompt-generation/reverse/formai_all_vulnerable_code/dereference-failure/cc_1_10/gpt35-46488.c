//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image structure
struct image {
    int width;
    int height;
    unsigned char* data;
};

// Function to read a PPM file and return an image struct
struct image read_ppm(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open %s for reading\n", filename);
        exit(1);
    }

    // Read the image header
    char magic[3];
    fscanf(fp, "%2s\n", magic);
    if (strcmp(magic, "P6") != 0) {
        fprintf(stderr, "Error: unsupported file format\n");
        exit(1);
    }

    int width, height, maxval;
    fscanf(fp, "%d %d\n%d\n", &width, &height, &maxval);

    // Allocate memory for the image data
    unsigned char* data = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    // Read the image data
    size_t bytes_read = fread(data, sizeof(unsigned char), width * height * 3, fp);
    if (bytes_read < width * height * 3) {
        fprintf(stderr, "Error: could not read image data\n");
        exit(1);
    }

    fclose(fp);

    // Create and return the image struct
    struct image img;
    img.width = width;
    img.height = height;
    img.data = data;
    return img;
}

// Function to write an image struct to a PPM file
void write_ppm(const char* filename, const struct image* img) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open %s for writing\n", filename);
        exit(1);
    }

    // Write the image header
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);

    // Write the image data
    size_t bytes_written = fwrite(img->data, sizeof(unsigned char), img->width * img->height * 3, fp);
    if (bytes_written < img->width * img->height * 3) {
        fprintf(stderr, "Error: could not write image data\n");
        exit(1);
    }

    fclose(fp);
}

// Function to invert the colors of an image
void invert_colors(struct image* img) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        img->data[i] = 255 - img->data[i];
    }
}

// Function to grayscale an image
void grayscale(struct image* img) {
    for (int i = 0; i < img->width * img->height * 3; i += 3) {
        unsigned char r = img->data[i];
        unsigned char g = img->data[i + 1];
        unsigned char b = img->data[i + 2];
        unsigned char gray = (r + g + b) / 3;
        img->data[i] = gray;
        img->data[i + 1] = gray;
        img->data[i + 2] = gray;
    }
}

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.ppm output.ppm\n", argv[0]);
        exit(1);
    }

    // Read the input image file
    struct image img = read_ppm(argv[1]);

    // Apply image processing functions
    invert_colors(&img);
    grayscale(&img);

    // Write the output image file
    write_ppm(argv[2], &img);

    // Free allocated memory
    free(img.data);

    printf("Image processing complete.\n");

    return 0;
}