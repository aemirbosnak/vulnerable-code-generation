//FormAI DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

// Definition of a Pixel struct.
typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Definition of our Image struct.
typedef struct Image {
    int width;
    int height;
    Pixel* pixels;
} Image;

// Function to read an image from a PPM file.
void read_image(char* file_name, Image* img) {
    FILE* file = fopen(file_name, "r");
    char buffer[256];

    // Read the file header.
    if (!fgets(buffer, sizeof(buffer), file) || buffer[0] != 'P' || buffer[1] != '6') {
        fprintf(stderr, "Error: Invalid file format.\n");
        exit(1);
    }

    // Read file dimensions.
    if (!fgets(buffer, sizeof(buffer), file) || sscanf(buffer, "%d %d", &img->width, &img->height) != 2) {
        fprintf(stderr, "Error: Invalid file dimensions.\n");
        exit(1);
    }

    // Read the maximum color value.
    if (!fgets(buffer, sizeof(buffer), file)) {
        fprintf(stderr, "Error: Invalid color range.\n");
        exit(1);
    }

    // Allocate memory for the image.
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));

    // Read the pixel data.
    for (int i = 0; i < img->width * img->height; i++) {
        Pixel pixel;
        fread(&pixel, sizeof(pixel), 1, file);
        img->pixels[i] = pixel;
    }

    fclose(file);
}

// Function to write an image to a PPM file.
void write_image(char* file_name, Image* img) {
    FILE* file = fopen(file_name, "w");

    // Write the file header.
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);

    // Write the pixel data.
    for (int i = 0; i < img->width * img->height; i++) {
        fwrite(&img->pixels[i], sizeof(Pixel), 1, file);
    }

    fclose(file);
}

// Function to apply a grayscale filter to an image.
void grayscale_filter(Image* img) {
    for (int i = 0; i < img->width * img->height; i++) {
        Pixel pixel = img->pixels[i];

        // Calculate the average of the color channels.
        unsigned char average = (pixel.red + pixel.green + pixel.blue) / 3;

        // Set all color channels to the average.
        pixel.red = average;
        pixel.green = average;
        pixel.blue = average;

        img->pixels[i] = pixel;
    }
}

int main(int argc, char* argv[]) {
    // Check for the correct number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    // Load the image from file.
    Image img;
    read_image(argv[1], &img);

    // Apply a grayscale filter to the image.
    grayscale_filter(&img);

    // Write the modified image to file.
    write_image(argv[2], &img);

    free(img.pixels);

    return 0;
}