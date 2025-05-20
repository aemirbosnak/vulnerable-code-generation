//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define BYTES_TO_BITS 8

#define READ_BMP_HEADER_SUCCESS 0
#define READ_BMP_HEADER_FAILURE 1

typedef struct __attribute__((__packed__)) {
    uint16_t s_type;
    uint32_t filesize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMP_HEADER;

int read_bmp_header(const char *file_path, BMP_HEADER *bmp_hdr) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        return READ_BMP_HEADER_FAILURE;
    }
    fread(bmp_hdr, sizeof(BMP_HEADER), 1, fp);
    fclose(fp);
    return READ_BMP_HEADER_SUCCESS;
}

int toggle_lsb(unsigned char *c, char bit) {
    if ((*c & 0x01) ^ bit) {
        *c ^= 0x01;
        return 1;
    }
    return 0;
}

int check_lsb(unsigned char *c) {
    return (*c & 0x01);
}

int main() {
    const char *input_image_path = "input.bmp";
    const char *output_image_path = "output.bmp";
    const char *message = "This is my secret message to be stored on the image";
    uint32_t message_length = strlen(message);
    BMP_HEADER bmp_hdr;
    int read_bmp_hdr_status = read_bmp_header(input_image_path, &bmp_hdr);
    if (read_bmp_hdr_status == READ_BMP_HEADER_FAILURE) {
        fprintf(stderr, "Error: Could not read BMP header\n");
        return 1;
    }

    FILE *input_fp = fopen(input_image_path, "r");
    if (input_fp == NULL) {
        fprintf(stderr, "Error: Could not open input BMP file\n");
        return 1;
    }
    FILE *output_fp = fopen(output_image_path, "w");
    if (output_fp == NULL) {
        fprintf(stderr, "Error: Could not create output BMP file\n");
        return 1;
    }

    // Write header of input image to output image
    fseek(input_fp, 0L, SEEK_SET);
    for (uint32_t i = 0; i < bmp_hdr.offset; i++) {
        fputc(fgetc(input_fp), output_fp);
    }

    // Write message length to least significant bits of image pixels
    uint32_t *message_length_bits = (uint32_t *) &message_length;
    uint32_t pixel_count = (bmp_hdr.filesize - bmp_hdr.offset) / 3;
    for (uint32_t i = 0; i < 4; i++) {
        unsigned char red = fgetc(input_fp);
        unsigned char green = fgetc(input_fp);
        unsigned char blue = fgetc(input_fp);

        // Toggle red, green and blue least significant bit to store message length
        toggle_lsb(&red, *(message_length_bits + i * BYTES_TO_BITS + 0));
        toggle_lsb(&green, *(message_length_bits + i * BYTES_TO_BITS + 1));
        toggle_lsb(&blue, *(message_length_bits + i * BYTES_TO_BITS + 2));

        // Write red, green and blue pixels to output image
        fputc(red, output_fp);
        fputc(green, output_fp);
        fputc(blue, output_fp);
    }

    // Write message to least significant bits of image pixels
    uint32_t message_byte_index = 0;
    for (uint32_t i = 0; i < pixel_count; i++) {
        unsigned char red = fgetc(input_fp);
        unsigned char green = fgetc(input_fp);
        unsigned char blue = fgetc(input_fp);

        // Toggle red, green and blue least significant bit to store message
        for (uint8_t j = 0; j < BYTES_TO_BITS; j++) {
            if (message_byte_index * BYTES_TO_BITS + j < message_length * BYTES_TO_BITS) {
                toggle_lsb(&red, *(message + message_byte_index * BYTES_TO_BITS + j));
            }
            if (message_byte_index * BYTES_TO_BITS + j + BYTES_TO_BITS < message_length * BYTES_TO_BITS) {
                toggle_lsb(&green, *(message + message_byte_index * BYTES_TO_BITS + j + BYTES_TO_BITS));
            }
            if (message_byte_index * BYTES_TO_BITS + j + 2 * BYTES_TO_BITS < message_length * BYTES_TO_BITS) {
                toggle_lsb(&blue, *(message + message_byte_index * BYTES_TO_BITS + j + 2 * BYTES_TO_BITS));
            }
        }
        message_byte_index++;

        // Write red, green and blue pixels to output image
        fputc(red, output_fp);
        fputc(green, output_fp);
        fputc(blue, output_fp);
    }

    // Copy remaining bytes of input image to output image
    int c;
    while ((c = fgetc(input_fp)) != EOF) {
        fputc(c, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
    return 0;
}