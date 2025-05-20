//FormAI DATASET v1.0 Category: Image Steganography ; Style: Claude Shannon
/*
 * C Image Steganography Example Program
 * 
 * This program takes an image file and a message as input,
 * hides the message within the image using steganography, and
 * saves the modified image to a new file.
 * 
 * The steganography algorithm used is based on the concept
 * of least significant bit (LSB) substitution developed by
 * Claude Shannon.
 * 
 * Written by: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_MESSAGE_SIZE 10000

/* Function declarations */
void hide_message(char *image_path, char *message, char *output_path);
char *read_message(const char *message_path);
void modify_pixels(uint8_t *pixels, int num_pixels, char *message, int message_length);
void write_image(const char *output_path, uint8_t *pixels, int width, int height);

/* Main function */
int main(int argc, char **argv) {
    /* Check for correct number of command line arguments */
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input_image_path message_path output_image_path\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Read input values from command line arguments */
    char *image_path = argv[1];
    char *message_path = argv[2];
    char *output_path = argv[3];

    /* Read the message from file */
    char *message = read_message(message_path);

    /* Hide the message within the image */
    hide_message(image_path, message, output_path);

    /* Free the memory allocated for the message */
    free(message);

    return 0;
}

/* Hides the message within the image and saves it to a new file */
void hide_message(char *image_path, char *message, char *output_path) {
    /* Open the image file in binary mode */
    FILE *fp = fopen(image_path, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open image file %s\n", image_path);
        exit(EXIT_FAILURE);
    }

    /* Read the image header */
    uint8_t header[54];
    size_t bytes_read = fread(header, sizeof(uint8_t), 54, fp);
    if (bytes_read != 54) {
        fprintf(stderr, "Error reading image header from %s\n", image_path);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    /* Calculate the image dimensions and number of pixels */
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int num_pixels = width * height;

    /* Allocate memory for the pixel data */
    uint8_t *pixels = (uint8_t *)malloc(num_pixels * 3 * sizeof(uint8_t));

    /* Read the pixel data */
    bytes_read = fread(pixels, sizeof(uint8_t), num_pixels * 3, fp);
    if (bytes_read != num_pixels * 3) {
        fprintf(stderr, "Error reading pixel data from %s\n", image_path);
        fclose(fp);
        free(pixels);
        exit(EXIT_FAILURE);
    }

    /* Modify the pixel data to hide the message */
    int message_length = strlen(message);
    modify_pixels(pixels, num_pixels, message, message_length);

    /* Write the modified image to a new file */
    write_image(output_path, pixels, width, height);

    /* Close the image file and free the allocated memory */
    fclose(fp);
    free(pixels);
}

/* Reads the message from the input file and returns it as a string */
char *read_message(const char *message_path) {
    /* Open the message file in binary mode */
    FILE *fp = fopen(message_path, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open message file %s\n", message_path);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for the message */
    char *message = (char *)malloc(MAX_MESSAGE_SIZE * sizeof(char));

    /* Read the message */
    size_t bytes_read = fread(message, sizeof(char), MAX_MESSAGE_SIZE, fp);
    if (bytes_read == MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Message too large (max size is %d bytes)\n", MAX_MESSAGE_SIZE);
        fclose(fp);
        free(message);
        exit(EXIT_FAILURE);
    }
    message[bytes_read] = '\0';

    /* Close the message file and return the message */
    fclose(fp);
    return message;
}

/* Modifies the pixel data to hide the message using LSB substitution */
void modify_pixels(uint8_t *pixels, int num_pixels, char *message, int message_length) {
    /* Check that the message can be hidden within the image */
    int max_message_length = (num_pixels * 3) / 8;
    if (message_length > max_message_length) {
        fprintf(stderr, "Image is too small to hide message (max length is %d bytes)\n", max_message_length);
        exit(EXIT_FAILURE);
    }

    /* Iterate over each pixel and modify the least significant bit
       of each color component to store a bit of the message */
    int pixel_idx = 0, message_idx = 0;
    while (message_idx < message_length) {
        for (int i = 0; i < 8; i++) {
            uint8_t bit = (message[message_idx] >> i) & 0x01;
            pixels[pixel_idx] = (pixels[pixel_idx] & 0xFE) | bit;
            pixels[pixel_idx + 1] = (pixels[pixel_idx + 1] & 0xFE) | bit;
            pixels[pixel_idx + 2] = (pixels[pixel_idx + 2] & 0xFE) | bit;
            pixel_idx += 3;
        }
        message_idx++;
    }

    /* Fill any remaining pixels with zeros to indicate end of message */
    while (pixel_idx < num_pixels * 3) {
        pixels[pixel_idx] = (pixels[pixel_idx] & 0xFE);
        pixels[pixel_idx + 1] = (pixels[pixel_idx + 1] & 0xFE);
        pixels[pixel_idx + 2] = (pixels[pixel_idx + 2] & 0xFE);
        pixel_idx += 3;
    }
}

/* Writes the modified pixel data to a new image file */
void write_image(const char *output_path, uint8_t *pixels, int width, int height) {
    /* Open the output file in binary mode */
    FILE *fp = fopen(output_path, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open output file %s\n", output_path);
        exit(EXIT_FAILURE);
    }

    /* Write the image header */
    fwrite(pixels, sizeof(uint8_t), 54, fp);

    /* Write the modified pixel data */
    fwrite(pixels, sizeof(uint8_t), width * height * 3, fp);

    /* Close the output file */
    fclose(fp);
}