//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold RGB pixel data
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Function prototypes
void encode_message(const char *input_image, const char *output_image, const char *message);
void decode_message(const char *input_image);
void set_bits(Pixel *pixel, char bit, int position);
char get_bit(Pixel pixel, int position);
void print_usage();

// Main entry point of the program
int main(int argc, char *argv[]) {
    if (argc < 4) {
        print_usage();
        return 1;
    }

    char *action = argv[1];
    if (strcmp(action, "encode") == 0) {
        encode_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(action, "decode") == 0) {
        decode_message(argv[2]);
    } else {
        print_usage();
    }

    return 0;
}

// Function to encode a message into an image
void encode_message(const char *input_image, const char *output_image, const char *message) {
    FILE *inFile = fopen(input_image, "rb");
    if (inFile == NULL) {
        fprintf(stderr, "Cannot open input image file %s!\n", input_image);
        exit(1);
    }

    FILE *outFile = fopen(output_image, "wb");
    if (outFile == NULL) {
        fprintf(stderr, "Cannot open output image file %s!\n", output_image);
        fclose(inFile);
        exit(1);
    }

    // Copy header from input image to output image (assumed to be a simple BMP file for this example)
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inFile);
    fwrite(header, sizeof(unsigned char), 54, outFile);

    // Message length and null termination
    int message_len = strlen(message);
    fprintf(stderr, "Encoding message of length %d\n", message_len);
    fwrite(&message_len, sizeof(int), 1, outFile);

    // Read pixels and embed message bits
    Pixel pixel;
    for (int i = 0; i < message_len * 8; i++) {
        fread(&pixel, sizeof(Pixel), 1, inFile);
        char bit = (message[i / 8] >> (7 - (i % 8))) & 1;
        set_bits(&pixel, bit, 0);
        fwrite(&pixel, sizeof(Pixel), 1, outFile);
    }

    // Write the rest of the pixels unmodified
    while (fread(&pixel, sizeof(Pixel), 1, inFile)) {
        fwrite(&pixel, sizeof(Pixel), 1, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    fprintf(stderr, "Message encoded and saved in %s\n", output_image);
}

// Function to decode a message from an image
void decode_message(const char *input_image) {
    FILE *inFile = fopen(input_image, "rb");
    if (inFile == NULL) {
        fprintf(stderr, "Cannot open image file %s!\n", input_image);
        exit(1);
    }

    // Read and skip the header
    fseek(inFile, 54, SEEK_SET);

    int message_len;
    fread(&message_len, sizeof(int), 1, inFile);
    fprintf(stderr, "Decoding message of length %d\n", message_len);

    char *message = malloc(message_len + 1);
    memset(message, 0, message_len + 1);

    // Read pixels and extract message bits
    Pixel pixel;
    for (int i = 0; i < message_len * 8; i++) {
        fread(&pixel, sizeof(Pixel), 1, inFile);
        char bit = get_bit(pixel, 0);
        message[i / 8] |= (bit << (7 - (i % 8)));
    }

    fclose(inFile);
    fprintf(stdout, "Decoded message: %s\n", message);
    free(message);
}

// Function to set a specific bit in a pixel
void set_bits(Pixel *pixel, char bit, int position) {
    if (bit) {
        pixel->b |= (1 << position);
    } else {
        pixel->b &= ~(1 << position);
    }
}

// Function to get a specific bit from a pixel
char get_bit(Pixel pixel, int position) {
    return (pixel.b >> position) & 1;
}

// Function to print usage instructions
void print_usage() {
    fprintf(stderr, "Usage: ./stegano encode <input_image> <output_image> <message>\n");
    fprintf(stderr, "       ./stegano decode <input_image>\n");
}