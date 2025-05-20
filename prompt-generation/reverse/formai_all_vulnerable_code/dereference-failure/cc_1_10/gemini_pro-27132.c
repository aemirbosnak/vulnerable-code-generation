//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the file header
    uint16_t magic_number;
    fread(&magic_number, sizeof(uint16_t), 1, file);
    if (magic_number != 0x4D42) {
        fprintf(stderr, "Error: Invalid file format\n");
        fclose(file);
        return NULL;
    }

    // Read the file dimensions
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));
    if (image->pixels == NULL) {
        fprintf(stderr, "Error allocating memory for image pixels\n");
        free(image);
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(image->pixels, sizeof(Pixel), width * height, file);

    // Close the file
    fclose(file);

    return image;
}

void free_image(Image *image) {
    if (image != NULL) {
        free(image->pixels);
        free(image);
    }
}

void hide_message(Image *image, const char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    // Iterate over the image pixels
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the current pixel
            Pixel *pixel = &image->pixels[y * image->width + x];

            // Embed the next bit of the message in the pixel's blue channel
            pixel->blue &= 0b11111110;
            pixel->blue |= (message[message_index] >> (7 - (message_index % 8))) & 1;

            // Increment the message index
            message_index++;

            // If we have embedded the entire message, break out of the loop
            if (message_index == message_length) {
                break;
            }
        }

        // If we have embedded the entire message, break out of the loop
        if (message_index == message_length) {
            break;
        }
    }
}

char *extract_message(Image *image) {
    int message_length = 0;

    // Iterate over the image pixels
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the current pixel
            Pixel *pixel = &image->pixels[y * image->width + x];

            // Extract the next bit of the message from the pixel's blue channel
            message_length |= (pixel->blue & 1) << (7 - (message_length % 8));

            // Increment the message length
            message_length++;

            // If we have extracted the entire message, break out of the loop
            if (message_length == 8) {
                break;
            }
        }

        // If we have extracted the entire message, break out of the loop
        if (message_length == 8) {
            break;
        }
    }

    // Allocate memory for the message
    char *message = malloc(message_length + 1);
    if (message == NULL) {
        fprintf(stderr, "Error allocating memory for message\n");
        return NULL;
    }

    // Extract the message from the image
    for (int i = 0; i < message_length; i++) {
        message[i] = (char) (((image->pixels[i].blue >> 1) & 1) << 7);
        if ((i + 1) % 8 == 0) {
            message[i] |= (char) (((image->pixels[i].green & 1) << 6));
        } else {
            message[i] |= (char) (((image->pixels[i].green << 1) & 1) << 5);
        }
        if ((i + 1) % 8 == 3) {
            message[i] |= (char) (((image->pixels[i].red & 1) << 4));
        } else {
            message[i] |= (char) (((image->pixels[i].red >> 1) & 1) << 3);
        }
        if ((i + 1) % 8 == 4) {
            message[i] |= (char) (((image->pixels[i].blue & 1) << 2));
        } else {
            message[i] |= (char) (((image->pixels[i].blue >> 1) & 1) << 1);
        }
    }

    // Null-terminate the message
    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <message> <output_image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Hide the message in the image
    hide_message(image, argv[2]);

    // Save the output image
    FILE *file = fopen(argv[3], "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[3]);
        free_image(image);
        return 1;
    }

    // Write the file header
    uint16_t magic_number = 0x4D42;
    fwrite(&magic_number, sizeof(uint16_t), 1, file);

    // Write the file dimensions
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    // Close the file
    fclose(file);

    // Free the image data
    free_image(image);

    return 0;
}