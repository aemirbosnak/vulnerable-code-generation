//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        return NULL;
    }

    // Read the header
    uint16_t magic, width, height;
    fread(&magic, sizeof(magic), 1, fp);
    fread(&width, sizeof(width), 1, fp);
    fread(&height, sizeof(height), 1, fp);

    // Check the header
    if (magic != 0x4d42) {
        fprintf(stderr, "Error: invalid file format\n");
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);

    // Read the pixels
    fread(image->pixels, sizeof(Pixel), width * height, fp);

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file %s\n", filename);
        return;
    }

    // Write the header
    uint16_t magic = 0x4d42;
    fwrite(&magic, sizeof(magic), 1, fp);
    fwrite(&image->width, sizeof(image->width), 1, fp);
    fwrite(&image->height, sizeof(image->height), 1, fp);

    // Write the pixels
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        // Get the pixel
        Pixel *pixel = &image->pixels[i];

        // Hide the message in the least significant bit of each color channel
        pixel->red &= ~1;
        pixel->red |= ((message[message_index] >> 6) & 1);
        pixel->green &= ~1;
        pixel->green |= ((message[message_index] >> 4) & 1);
        pixel->blue &= ~1;
        pixel->blue |= ((message[message_index] >> 2) & 1);

        message_index++;

        // If we have hidden the entire message, stop
        if (message_index == message_length) {
            break;
        }
    }
}

char *extract_message(const Image *image) {
    int message_length = 0;
    int message_index = 0;

    // Count the number of bits in the message
    for (int i = 0; i < image->width * image->height; i++) {
        // Get the pixel
        const Pixel *pixel = &image->pixels[i];

        // Extract the message from the least significant bit of each color channel
        message_length |= ((pixel->red & 1) << 6);
        message_length |= ((pixel->green & 1) << 4);
        message_length |= ((pixel->blue & 1) << 2);

        message_index++;

        // If we have extracted the entire message, stop
        if (message_index == message_length) {
            break;
        }
    }

    // Allocate memory for the message
    char *message = malloc(message_length + 1);

    // Extract the message from the image
    message_index = 0;
    for (int i = 0; i < image->width * image->height; i++) {
        // Get the pixel
        const Pixel *pixel = &image->pixels[i];

        // Extract the message from the least significant bit of each color channel
        message[message_index++] = ((pixel->red & 1) << 6) | ((pixel->green & 1) << 4) | ((pixel->blue & 1) << 2);

        // Stop if we have extracted the entire message
        if (message_index == message_length) {
            break;
        }
    }

    // Null-terminate the message
    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Hide the message in the image
    hide_message(image, argv[3]);

    // Write the output image
    write_image(image, argv[2]);

    // Free the image
    free(image->pixels);
    free(image);

    return 0;
}