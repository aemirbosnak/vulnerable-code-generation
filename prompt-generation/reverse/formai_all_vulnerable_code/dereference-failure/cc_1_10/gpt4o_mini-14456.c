//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BMP Header Size
#define BMP_HEADER_SIZE 54

// Function prototypes
void embed_message(const char *input_image, const char *output_image, const char *message);
void extract_message(const char *input_image);

// Function to get the length of the message in bytes
int message_length(const char *message) {
    return strlen(message);
}

// Function to write the message as the LSB of the pixel data
void embed_message(const char *input_image, const char *output_image, const char *message) {
    FILE *infile, *outfile;
    unsigned char header[BMP_HEADER_SIZE];
    unsigned char *image_data;
    long image_size;
    int message_len = message_length(message);
    int message_length_with_null = message_len + 1; // For the null terminator

    infile = fopen(input_image, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Could not open input file %s\n", input_image);
        exit(EXIT_FAILURE);
    }

    // Read the BMP header
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, infile);
    
    // Go to the size of the image
    fseek(infile, 0, SEEK_END);
    image_size = ftell(infile) - BMP_HEADER_SIZE;
    fseek(infile, BMP_HEADER_SIZE, SEEK_SET);
    
    if (message_length_with_null * 8 > image_size) {
        fprintf(stderr, "Message is too long to embed in this BMP image.\n");
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the image data
    image_data = (unsigned char *)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, infile);
    fclose(infile);

    // Embed message into the LSB of the image data
    for (int i = 0; i < message_length_with_null; i++) {
        for (int j = 0; j < 8; j++) {
            // Set the LSB of the byte
            image_data[i * 8 + j] = (image_data[i * 8 + j] & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }

    outfile = fopen(output_image, "wb");
    if (outfile == NULL) {
        fprintf(stderr, "Could not open output file %s\n", output_image);
        free(image_data);
        exit(EXIT_FAILURE);
    }

    // Write the header and the modified image data
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, outfile);
    fwrite(image_data, sizeof(unsigned char), image_size, outfile);
    fclose(outfile);
    free(image_data);

    printf("Message embedded successfully!\n");
}

// Function to extract the hidden message from the BMP image
void extract_message(const char *input_image) {
    FILE *infile;
    unsigned char header[BMP_HEADER_SIZE];
    unsigned char *image_data;
    long image_size;
    char message[256];
    int i, j;
    
    infile = fopen(input_image, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Could not open input file %s\n", input_image);
        exit(EXIT_FAILURE);
    }

    // Read the BMP header
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, infile);
    
    // Go to the size of the image
    fseek(infile, 0, SEEK_END);
    image_size = ftell(infile) - BMP_HEADER_SIZE;
    fseek(infile, BMP_HEADER_SIZE, SEEK_SET);
    
    // Allocate memory for the image data
    image_data = (unsigned char *)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, infile);
    fclose(infile);

    // Extract message from the LSB of the image data
    for (i = 0; i < 256; i++) {
        message[i] = 0;
        for (j = 0; j < 8; j++) {
            message[i] |= (image_data[i * 8 + j] & 1) << (7 - j);
        }
        if (message[i] == 0) break; // Stop if null character found
    }

    printf("Extracted message: %s\n", message);
    free(image_data);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input BMP image> <output BMP image> <message>\n", argv[0]);
        fprintf(stderr, "Or: %s <input BMP image> extract\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[2], "extract") == 0) {
        extract_message(argv[1]);
    } else {
        embed_message(argv[1], argv[2], argv[3]);
    }

    return EXIT_SUCCESS;
}