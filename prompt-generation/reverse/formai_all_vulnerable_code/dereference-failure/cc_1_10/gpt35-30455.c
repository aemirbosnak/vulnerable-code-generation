//FormAI DATASET v1.0 Category: Image Steganography ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void hide_data(char* cover_image, char* secret_data_file, char* stego_image_file)
{
    // Open cover image file
    FILE* cover_image_fp = fopen(cover_image, "rb");
    if (cover_image_fp == NULL) {
        perror("Opening cover image failed");
        exit(EXIT_FAILURE);
    }

    // Open secret data file
    FILE* secret_data_fp = fopen(secret_data_file, "rb");
    if (secret_data_fp == NULL) {
        perror("Opening secret data file failed");
        exit(EXIT_FAILURE);
    }

    // Open stego image file
    FILE* stego_image_fp = fopen(stego_image_file, "wb");
    if (stego_image_fp == NULL) {
        perror("Opening stego image failed");
        exit(EXIT_FAILURE);
    }

    // Get size of cover image
    fseek(cover_image_fp, 0, SEEK_END);
    long cover_image_size = ftell(cover_image_fp);
    rewind(cover_image_fp);

    // Allocate memory for cover image
    unsigned char* cover_image_data = (unsigned char*)malloc(sizeof(unsigned char) * cover_image_size);
    if (cover_image_data == NULL) {
        perror("Allocating memory for cover image failed");
        exit(EXIT_FAILURE);
    }

    // Read cover image data into memory
    size_t result = fread(cover_image_data, sizeof(unsigned char), cover_image_size, cover_image_fp);
    if (result != cover_image_size) {
        perror("Reading cover image failed");
        exit(EXIT_FAILURE);
    }

    // Get size of secret data file
    fseek(secret_data_fp, 0, SEEK_END);
    long secret_data_size = ftell(secret_data_fp);
    rewind(secret_data_fp);

    // Allocate memory for secret data
    unsigned char* secret_data = (unsigned char*)malloc(sizeof(unsigned char) * secret_data_size);
    if (secret_data == NULL) {
        perror("Allocating memory for secret data failed");
        exit(EXIT_FAILURE);
    }

    // Read secret data into memory
    result = fread(secret_data, sizeof(unsigned char), secret_data_size, secret_data_fp);
    if (result != secret_data_size) {
        perror("Reading secret data failed");
        exit(EXIT_FAILURE);
    }

    // Check if secret data can fit in cover image
    if (secret_data_size > cover_image_size / 8) {
        perror("Cover image too small to hide secret data");
        exit(EXIT_FAILURE);
    }

    // Get least significant bit of each byte in cover image
    for (int i=0; i<cover_image_size; i++) {
        cover_image_data[i] &= 0xFE;
    }

    // Embed secret data in cover image
    int secret_data_index = 0;
    for (int i=0; i<cover_image_size; i+=8) {
        for (int j=0; j<8; j++) {
            if (secret_data_index >= secret_data_size) {
                break;
            }
            int secret_bit = (secret_data[secret_data_index] >> j) & 1;
            cover_image_data[i+j] |= secret_bit;
        }
        secret_data_index++;
    }

    // Write stego image data to stego image file
    result = fwrite(cover_image_data, sizeof(unsigned char), cover_image_size, stego_image_fp);
    if (result != cover_image_size) {
        perror("Writing stego image failed");
        exit(EXIT_FAILURE);
    }

    // Cleanup
    free(cover_image_data);
    free(secret_data);
    fclose(cover_image_fp);
    fclose(secret_data_fp);
    fclose(stego_image_fp);
}

void extract_data(char* stego_image_file, char* output_file)
{
    // Open stego image file
    FILE* stego_image_fp = fopen(stego_image_file, "rb");
    if (stego_image_fp == NULL) {
        perror("Opening stego image failed");
        exit(EXIT_FAILURE);
    }

    // Get size of stego image file
    fseek(stego_image_fp, 0, SEEK_END);
    long stego_image_size = ftell(stego_image_fp);
    rewind(stego_image_fp);

    // Allocate memory for stego image
    unsigned char* stego_image_data = (unsigned char*)malloc(sizeof(unsigned char) * stego_image_size);
    if (stego_image_data == NULL) {
        perror("Allocating memory for stego image failed");
        exit(EXIT_FAILURE);
    }

    // Read stego image data into memory
    size_t result = fread(stego_image_data, sizeof(unsigned char), stego_image_size, stego_image_fp);
    if (result != stego_image_size) {
        perror("Reading stego image failed");
        exit(EXIT_FAILURE);
    }

    // Extract secret data from stego image
    unsigned char* secret_data = (unsigned char*)malloc(sizeof(unsigned char) * (stego_image_size/8));
    int secret_data_index = 0;
    for (int i=0; i<stego_image_size; i+=8) {
        unsigned char secret_byte = 0;
        for (int j=0; j<8; j++) {
            if (i+j >= stego_image_size) {
                break;
            }
            unsigned char stego_bit = stego_image_data[i+j] & 1;
            secret_byte |= stego_bit << j;
        }
        secret_data[secret_data_index] = secret_byte;
        secret_data_index++;
    }

    // Open output file for writing secret data
    FILE* output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        perror("Opening output file failed");
        exit(EXIT_FAILURE);
    }

    // Write secret data to output file
    result = fwrite(secret_data, sizeof(unsigned char), stego_image_size/8, output_fp);
    if (result != stego_image_size/8) {
        perror("Writing output file failed");
        exit(EXIT_FAILURE);
    }

    // Cleanup
    free(stego_image_data);
    free(secret_data);
    fclose(stego_image_fp);
    fclose(output_fp);
}

int main()
{
    char* cover_image = "cover.jpg";
    char* secret_data_file = "secret.txt";
    char* stego_image_file = "stego.jpg";
    char* output_file = "output.txt";

    // Hide secret data in cover image and save as stego image
    hide_data(cover_image, secret_data_file, stego_image_file);

    // Extract secret data from stego image and save to output file
    extract_data(stego_image_file, output_file);

    printf("Program executed successfully");

    return 0;
}