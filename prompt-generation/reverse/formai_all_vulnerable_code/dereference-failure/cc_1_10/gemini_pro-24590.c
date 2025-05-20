//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Pixel struct for representing a pixel in the image
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Image struct for representing an image
typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Read the header of the image
    unsigned char header[14];
    fread(header, sizeof(unsigned char), 14, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: Invalid BMP file\n");
        fclose(file);
        return NULL;
    }

    // Read the width and height of the image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixels of the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);
    fread(image->pixels, sizeof(Pixel), width * height, file);

    fclose(file);

    return image;
}

// Function to write an image to a file
void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write the header of the image
    unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    fwrite(header, sizeof(unsigned char), 14, file);

    // Write the width and height of the image
    int width = image->width;
    int height = image->height;
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);

    // Write the pixels of the image
    fwrite(image->pixels, sizeof(Pixel), width * height, file);

    fclose(file);
}

// Function to embed a message in an image
void embed_message(Image *image, const char *message) {
    int message_length = strlen(message);

    // Calculate the number of bits required to represent the message
    int num_bits = message_length * 8;

    // Embed the message in the least significant bits of the pixels
    int bit_index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        for (int j = 0; j < 3; j++) {
            // Get the current pixel
            Pixel *pixel = &image->pixels[i];

            // Get the least significant bit of the pixel
            unsigned char bit = pixel->red & 1;

            // Set the least significant bit of the pixel to the next bit of the message
            if (bit_index < num_bits) {
                pixel->red = (pixel->red & ~1) | ((message[bit_index / 8] >> (7 - (bit_index % 8))) & 1);
                bit_index++;
            }
        }
    }
}

// Function to extract a message from an image
char *extract_message(const Image *image) {
    // Calculate the number of bits required to represent the message
    int num_bits = image->width * image->height * 3;

    // Extract the message from the least significant bits of the pixels
    int bit_index = 0;
    char *message = malloc(num_bits / 8 + 1);
    for (int i = 0; i < image->width * image->height; i++) {
        for (int j = 0; j < 3; j++) {
            // Get the current pixel
            const Pixel *pixel = &image->pixels[i];

            // Get the least significant bit of the pixel
            unsigned char bit = pixel->red & 1;

            // Set the least significant bit of the message to the extracted bit
            if (bit_index < num_bits) {
                message[bit_index / 8] |= (bit << (7 - (bit_index % 8)));
                bit_index++;
            }
        }
    }
    message[num_bits / 8] = '\0';

    return message;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <message> <output_image>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Embed the message in the image
    embed_message(image, argv[2]);

    // Write the output image
    write_image(image, argv[3]);

    // Free the image
    free(image->pixels);
    free(image);

    return 0;
}