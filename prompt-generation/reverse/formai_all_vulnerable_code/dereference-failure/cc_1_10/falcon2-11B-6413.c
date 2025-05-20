//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Function to encode secret message in an image
void encode(unsigned char* secret, int secret_len, unsigned char* image) {
    int num_bits = secret_len * 8;
    int num_pixels = 0;
    int pixel_size = 3; // Assuming RGB format
    int num_bytes = num_pixels * pixel_size;

    // Calculate the number of bits that can be hidden in each pixel
    int bits_per_pixel = num_bits / num_bytes;

    // Find the number of bits that can be hidden in each byte
    int bits_per_byte = bits_per_pixel * pixel_size;

    // Divide the secret message into bits and hide them in the image
    unsigned char* bits = (unsigned char*)malloc(num_bits * sizeof(char));
    int i = 0;
    for (int j = 0; j < num_pixels; j++) {
        for (int k = 0; k < pixel_size; k++) {
            int index = j * pixel_size + k;
            int bit_index = index * bits_per_byte;
            int byte_index = bit_index / bits_per_pixel;
            int bit_index_within_byte = bit_index % bits_per_pixel;

            // Get the byte from the image
            unsigned char byte = image[byte_index];

            // Hide the bit in the byte
            if (bit_index_within_byte == 0) {
                byte |= (1 << (7 - bit_index % 8));
            } else if (bit_index_within_byte == 7) {
                byte &= ~(1 << (bit_index % 8));
            } else {
                byte ^= (1 << (bit_index % 8));
            }

            // Store the modified byte in the image
            image[byte_index] = byte;

            // Store the bit in the secret message
            bits[i] = (char)byte;
            i++;
        }
    }

    // Free the memory allocated for the secret message
    free(bits);
}

// Function to decode the secret message from an image
unsigned char* decode(unsigned char* image) {
    int num_pixels = 0;
    int pixel_size = 3; // Assuming RGB format
    int num_bytes = num_pixels * pixel_size;
    int bits_per_pixel = 8;
    int bits_per_byte = bits_per_pixel * pixel_size;
    int num_bits = num_bytes * bits_per_byte;
    unsigned char* bits = (unsigned char*)malloc(num_bits * sizeof(char));

    // Find the number of bits that can be hidden in each pixel
    int bit_index = 0;
    for (int i = 0; i < num_pixels; i++) {
        for (int j = 0; j < pixel_size; j++) {
            int index = i * pixel_size + j;
            int byte_index = index / bits_per_pixel;
            int bit_index_within_byte = index % bits_per_pixel;
            unsigned char byte = image[byte_index];

            // Get the bit from the byte
            int bit = byte & (1 << bit_index_within_byte);

            // Store the bit in the secret message
            bits[bit_index] = bit;
            bit_index++;
        }
    }

    // Convert the secret message from bits to a character array
    int num_chars = num_bits / 8;
    unsigned char* secret = (unsigned char*)malloc(num_chars * sizeof(char));
    for (int i = 0; i < num_chars; i++) {
        secret[i] = (char)bits[i * 8];
    }

    return secret;
}

// Main function
int main() {
    // Generate a random secret message
    char secret[] = "Hello, world!";
    int secret_len = strlen(secret);

    // Generate a random image
    int width = 512;
    int height = 512;
    unsigned char* image = (unsigned char*)malloc(width * height * sizeof(char));
    for (int i = 0; i < width * height; i++) {
        image[i] = rand() % 256;
    }

    // Encode the secret message in the image
    encode(secret, secret_len, image);

    // Decode the secret message from the image
    unsigned char* secret_message = decode(image);

    // Print the secret message
    printf("%s\n", secret_message);

    // Free the memory allocated for the image
    free(image);

    // Free the memory allocated for the secret message
    free(secret_message);

    return 0;
}