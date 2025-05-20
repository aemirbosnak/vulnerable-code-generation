//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BMP_HEADER_SIZE 54

#pragma pack(push, 1)
typedef struct {
    uint16_t file_type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPHeader;

typedef struct {
    uint32_t size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    uint32_t x_pixels_per_meter;
    uint32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
} BMPInfoHeader;
#pragma pack(pop)

void encode_message_to_bmp(const char *input_bmp, const char *message, const char *output_bmp) {
    FILE *bmp_file = fopen(input_bmp, "rb");
    FILE *output_file = fopen(output_bmp, "wb");
    if (!bmp_file || !output_file) {
        perror("Failed to open files");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, bmp_file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, bmp_file);
    
    // Check if the BMP is 24 bits per pixel
    if (bmp_info_header.bit_count != 24) {
        fprintf(stderr, "This program only works on 24-bit BMP images.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, output_file);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, output_file);

    // Calculate the size of the message and encode it in the BMP
    size_t message_len = strlen(message);
    size_t padded_message_len = message_len + 1; // include null terminator
    fseek(output_file, BMP_HEADER_SIZE + bmp_info_header.size_image, SEEK_SET);
    
    // Write the message length as the first 4 bytes in the image
    fwrite(&padded_message_len, sizeof(size_t), 1, output_file);
    fwrite(message, sizeof(char), padded_message_len, output_file);

    // Write original pixel data to new file
    uint8_t *pixel_data = (uint8_t *) malloc(bmp_info_header.size_image);
    fseek(bmp_file, bmp_header.offset_data, SEEK_SET);
    fread(pixel_data, 1, bmp_info_header.size_image, bmp_file);
    fwrite(pixel_data, 1, bmp_info_header.size_image, output_file);

    free(pixel_data);
    fclose(bmp_file);
    fclose(output_file);
}

void decode_message_from_bmp(const char *input_bmp) {
    FILE *bmp_file = fopen(input_bmp, "rb");
    if (!bmp_file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, bmp_file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, bmp_file);

    // Check if the BMP is 24 bits per pixel
    if (bmp_info_header.bit_count != 24) {
        fprintf(stderr, "This program only works on 24-bit BMP images.\n");
        exit(EXIT_FAILURE);
    }

    // Read the message length from the embedded data
    size_t message_len;
    fseek(bmp_file, bmp_info_header.size_image + BMP_HEADER_SIZE, SEEK_SET);
    fread(&message_len, sizeof(size_t), 1, bmp_file);

    char *message = (char *) malloc(message_len);
    fread(message, sizeof(char), message_len, bmp_file);

    printf("Decoded Message: %s\n", message);

    free(message);
    fclose(bmp_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode/decode> <input_bmp> <message/output_bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode_message_to_bmp(argv[2], argv[3], "output.bmp");
        printf("Message encoded successfully!\n");
    } else if (strcmp(argv[1], "decode") == 0) {
        decode_message_from_bmp(argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encode' or 'decode'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}