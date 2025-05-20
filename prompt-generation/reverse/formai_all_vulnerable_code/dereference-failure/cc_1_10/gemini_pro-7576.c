//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the ASCII character set
char *charset = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

// Get the average brightness of a pixel
double get_brightness(unsigned char *pixel) {
    return (pixel[0] + pixel[1] + pixel[2]) / 3.0;
}

// Convert a pixel to an ASCII character
char get_ascii_char(double brightness) {
    int index = (int)round(brightness / 255.0 * (strlen(charset) - 1));
    return charset[index];
}

// Convert an image to ASCII art
char *image_to_ascii(unsigned char *image, int width, int height) {
    char *ascii_art = malloc(width * height + 1);
    int index = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char *pixel = image + (y * width + x) * 3;
            double brightness = get_brightness(pixel);
            char ascii_char = get_ascii_char(brightness);
            ascii_art[index++] = ascii_char;
        }
        ascii_art[index++] = '\n';
    }
    ascii_art[index] = '\0';
    return ascii_art;
}

// Load an image from a file
unsigned char *load_image(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    if (fread(header, 18, 1, file) != 1) {
        fprintf(stderr, "Error reading header\n");
        fclose(file);
        return NULL;
    }

    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a BMP image\n");
        fclose(file);
        return NULL;
    }

    // Get the width and height of the image
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Read the image data
    int data_size = *(int *)&header[2];
    unsigned char *data = malloc(data_size);
    if (fread(data, data_size, 1, file) != 1) {
        fprintf(stderr, "Error reading image data\n");
        fclose(file);
        return NULL;
    }

    fclose(file);
    return data;
}

// Save an image to a file
void save_image(char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0
    };

    *(int *)&header[2] = sizeof(header) + width * height * 3;
    *(int *)&header[18] = width;
    *(int *)&header[22] = height;

    fwrite(header, 18, 1, file);

    // Write the image data
    fwrite(image, width * height * 3, 1, file);

    fclose(file);
}

// Print the ASCII art to the console
void print_ascii_art(char *ascii_art) {
    printf("%s", ascii_art);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    int width, height;
    unsigned char *image = load_image(argv[1], &width, &height);
    if (image == NULL) {
        return 1;
    }

    char *ascii_art = image_to_ascii(image, width, height);
    free(image);

    print_ascii_art(ascii_art);
    free(ascii_art);

    return 0;
}