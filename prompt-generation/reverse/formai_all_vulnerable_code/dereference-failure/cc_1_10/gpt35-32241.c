//FormAI DATASET v1.0 Category: Image Steganography ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 * This program demonstrates image steganography using LSB method. 
 * It hides a secret message inside an image by altering the least significant bit
 * of each pixel. 
 *
 * The program takes two command line arguments: the name of the input image file
 * and the name of the output image file. It also prompts the user to enter the 
 * secret message.
 */

#define MAX_SECRET_LEN 256 // Maximum characters in the secret message

void embed_message(uint8_t *img_data, uint32_t img_size, char *secret);

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_image_file output_image_file\n", argv[0]);
        exit(1);
    }

    char secret[MAX_SECRET_LEN];
    printf("Enter the secret message (max %d characters): ", MAX_SECRET_LEN);
    fgets(secret, MAX_SECRET_LEN, stdin);

    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        fprintf(stderr, "Error opening input image file %s\n", argv[1]);
        exit(1);
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        fprintf(stderr, "Error creating output image file %s\n", argv[2]);
        exit(1);
    }

    // Calculate file size
    fseek(in_file, 0, SEEK_END);
    uint32_t img_size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET);

    // Allocate memory for image data
    uint8_t *img_data = (uint8_t *) malloc(sizeof(uint8_t) * img_size);
    if (img_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        exit(1);
    }

    // Read image data from file
    size_t read_size = fread(img_data, sizeof(uint8_t), img_size, in_file);
    if (read_size != img_size) {
        fprintf(stderr, "Error reading input image file\n");
        exit(1);
    }

    embed_message(img_data, img_size, secret);

    // Write image data to file
    fwrite(img_data, sizeof(uint8_t), img_size, out_file);

    printf("Secret message embedded successfully in %s\n", argv[2]);

    // Free memory and close files
    free(img_data);
    fclose(in_file);
    fclose(out_file);

    return 0;
}

void embed_message(uint8_t *img_data, uint32_t img_size, char *secret) {
    uint32_t secret_len = strlen(secret);
    if (secret_len > MAX_SECRET_LEN) {
        fprintf(stderr, "Secret message exceeds maximum length\n");
        exit(1);
    }

    uint32_t i, j, k;
    uint8_t bit_val;
    char ch;

    // Embed secret message
    for (i = 0, j = 0; i < img_size && j < secret_len; i += 3, j++) {
        ch = secret[j];
        for (k = 0; k < 8; k++) {
            bit_val = (ch >> (7 - k)) & 0x01;
            img_data[i + k % 3] &= 0xFE; // Clear LSB
            img_data[i + k % 3] |= bit_val;
        }
    }
}