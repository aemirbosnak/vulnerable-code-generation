//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Define the maximum number of bits per pixel
#define MAX_BITS_PER_PIXEL 8

// Define the maximum size of the secret image
#define MAX_SECRET_SIZE 1024

// Define the maximum size of the cover image
#define MAX_COVER_SIZE 1024

// Define the maximum number of bits to hide in each pixel
#define MAX_HIDDEN_BITS 8

// Function to read a byte from a file
unsigned char readByte(FILE* file) {
    unsigned char byte;
    fread(&byte, 1, 1, file);
    return byte;
}

// Function to write a byte to a file
void writeByte(FILE* file, unsigned char byte) {
    fwrite(&byte, 1, 1, file);
}

// Function to read an image
unsigned char* readImage(FILE* file) {
    unsigned char* image = (unsigned char*) malloc(MAX_COVER_SIZE * MAX_COVER_SIZE * 3);
    int width = MAX_COVER_SIZE;
    int height = MAX_COVER_SIZE;
    int size = width * height * 3;
    unsigned char* pixel = image;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char red = readByte(file);
            unsigned char green = readByte(file);
            unsigned char blue = readByte(file);
            pixel[3 * x + 0] = red;
            pixel[3 * x + 1] = green;
            pixel[3 * x + 2] = blue;
            pixel += 3;
        }
    }
    return image;
}

// Function to write an image
void writeImage(FILE* file, unsigned char* image, int width, int height) {
    int size = width * height * 3;
    unsigned char* pixel = image;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            writeByte(file, pixel[3 * x + 0]);
            writeByte(file, pixel[3 * x + 1]);
            writeByte(file, pixel[3 * x + 2]);
            pixel += 3;
        }
    }
}

// Function to hide a secret image within another image
void hideImage(FILE* cover, FILE* secret, unsigned char* cover_image, int cover_width, int cover_height) {
    // Read the secret image
    unsigned char* secret_image = readImage(secret);
    int secret_width = MAX_SECRET_SIZE;
    int secret_height = MAX_SECRET_SIZE;

    // Loop through each pixel in the cover image
    for (int y = 0; y < cover_height; y++) {
        for (int x = 0; x < cover_width; x++) {
            // Get the pixel value at the current position
            unsigned char* pixel = cover_image + (3 * x + 0);

            // Get the secret pixel value at the same position
            unsigned char* secret_pixel = secret_image + (3 * x + 0);

            // Set the secret pixel value as the cover pixel value
            memcpy(secret_pixel, pixel, 3);
        }
    }

    // Write the modified cover image to the file
    writeImage(cover, cover_image, cover_width, cover_height);

    // Free the memory used for the secret image
    free(secret_image);
}

// Function to extract the secret image from a cover image
void extractImage(FILE* cover, unsigned char* cover_image, int cover_width, int cover_height, unsigned char* secret_image, int secret_width, int secret_height) {
    // Loop through each pixel in the cover image
    for (int y = 0; y < cover_height; y++) {
        for (int x = 0; x < cover_width; x++) {
            // Get the pixel value at the current position
            unsigned char* pixel = cover_image + (3 * x + 0);

            // Copy the secret pixel value to the secret image
            memcpy(secret_image + (3 * x + 0), pixel, 3);
        }
    }
}

// Function to display the cover image
void displayCover(unsigned char* cover_image, int cover_width, int cover_height) {
    // Loop through each pixel in the cover image
    for (int y = 0; y < cover_height; y++) {
        for (int x = 0; x < cover_width; x++) {
            // Get the pixel value at the current position
            unsigned char* pixel = cover_image + (3 * x + 0);

            // Print the pixel value
            printf("%02X ", pixel[0]);
        }
        printf("\n");
    }
}

// Function to display the secret image
void displaySecret(unsigned char* secret_image, int secret_width, int secret_height) {
    // Loop through each pixel in the secret image
    for (int y = 0; y < secret_height; y++) {
        for (int x = 0; x < secret_width; x++) {
            // Get the pixel value at the current position
            unsigned char* pixel = secret_image + (3 * x + 0);

            // Print the pixel value
            printf("%02X ", pixel[0]);
        }
        printf("\n");
    }
}

int main() {
    // Open the cover and secret images
    FILE* cover = fopen("cover.png", "r");
    FILE* secret = fopen("secret.png", "r");

    // Read the cover image
    unsigned char* cover_image = readImage(cover);

    // Read the secret image
    unsigned char* secret_image = readImage(secret);

    // Close the cover and secret images
    fclose(cover);
    fclose(secret);

    // Get the dimensions of the cover image
    int cover_width = MAX_COVER_SIZE;
    int cover_height = MAX_COVER_SIZE;

    // Get the dimensions of the secret image
    int secret_width = MAX_SECRET_SIZE;
    int secret_height = MAX_SECRET_SIZE;

    // Hide the secret image within the cover image
    hideImage(cover, secret, cover_image, cover_width, cover_height);

    // Display the cover image
    printf("Cover Image:\n");
    displayCover(cover_image, cover_width, cover_height);

    // Extract the secret image from the cover image
    extractImage(cover, cover_image, cover_width, cover_height, secret_image, secret_width, secret_height);

    // Display the secret image
    printf("Secret Image:\n");
    displaySecret(secret_image, secret_width, secret_height);

    // Free the memory used for the cover image
    free(cover_image);

    // Close the cover image
    fclose(cover);

    return 0;
}