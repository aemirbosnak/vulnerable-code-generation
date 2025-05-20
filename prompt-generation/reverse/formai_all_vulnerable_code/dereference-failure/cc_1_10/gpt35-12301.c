//FormAI DATASET v1.0 Category: Image Steganography ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54 // BMP header size
#define BYTE_SIZE 8 // byte size
#define BITMAP_SIZE_OFFSET 2 // location of bitmap size data in BMP header
#define BITS_PER_PIXEL_OFFSET 28 // location of bits per pixel data in BMP header

// function to convert a decimal number to binary
void decimal_to_binary(int decimal_num, int *binary_num) {
    int index = 0;
    while (decimal_num > 0) {
        binary_num[index] = decimal_num % 2;
        decimal_num /= 2;
        index++;
    }
}

// function to convert a binary number array to a decimal number
int binary_to_decimal(int *binary_num, int size) {
    int decimal_num = 0;
    for (int i = size - 1; i >= 0; i--) {
        decimal_num += binary_num[i] * (1 << (size - 1 - i));
    }
    return decimal_num;
}

// function to hide a message in the least significant bit of each pixel
void hide_message(char *message, char *in_filename, char *out_filename) {
    FILE *fp_in = fopen(in_filename, "rb");
    if (!fp_in) {
        printf("Cannot open input file\n");
        exit(1);
    }

    FILE *fp_out = fopen(out_filename, "wb");
    if (!fp_out) {
        printf("Cannot open output file\n");
        exit(1);
    }

    // read BMP header
    unsigned char bmp_header[HEADER_SIZE];
    fread(bmp_header, sizeof(unsigned char), HEADER_SIZE, fp_in);
    fwrite(bmp_header, sizeof(unsigned char), HEADER_SIZE, fp_out);

    // get original bitmap size and bits per pixel
    int bitmap_size = *(int *)&bmp_header[BITMAP_SIZE_OFFSET];
    int bits_per_pixel = *(int *)&bmp_header[BITS_PER_PIXEL_OFFSET];

    // calculate maximum message length
    int max_msg_length = bitmap_size / BYTE_SIZE - HEADER_SIZE;

    int msg_length = strlen(message);
    if (msg_length > max_msg_length) {
        printf("Message is too long to hide in this image\n");
        exit(1);
    }

    printf("Hiding message: %s\n", message);

    // write message length as the first 4 bytes of pixel data
    int binary_msg_length[32];
    decimal_to_binary(msg_length, binary_msg_length);
    unsigned char pixel_data[4];
    for (int i = 0; i < 4; i++) {
        if (i < 3) {
            pixel_data[i] = binary_msg_length[i];
        } else {
            pixel_data[i] = 0; // set alpha channel byte to 0
        }
    }
    fwrite(pixel_data, sizeof(unsigned char), 4, fp_out);

    int bmp_pixel_size = bits_per_pixel / BYTE_SIZE; // BMP pixel size in bytes
    unsigned char pixel[bmp_pixel_size];
    int binary_pixel[bmp_pixel_size * BYTE_SIZE];

    // read pixels and modify least significant bit of each color channel
    int msg_index = 0;
    while (ftell(fp_in) < bitmap_size) {
        fread(pixel, sizeof(unsigned char), bmp_pixel_size, fp_in);

        // convert pixel data to binary
        for (int i = 0; i < bmp_pixel_size; i++) {
            decimal_to_binary(pixel[i], &binary_pixel[i * BYTE_SIZE]);
        }

        // hide message in least significant bit of each color channel
        for (int i = 0; i < bmp_pixel_size * BYTE_SIZE && msg_index < msg_length * BYTE_SIZE; i++) {
            binary_pixel[i] &= ~1; // set least significant bit to 0
            binary_pixel[i] |= (message[msg_index / BYTE_SIZE] >> (msg_index % BYTE_SIZE)) & 1; // set least significant bit to next bit of message
            msg_index++;
        }

        // convert binary data back to pixel data
        for (int i = 0; i < bmp_pixel_size; i++) {
            pixel[i] = (unsigned char)binary_to_decimal(&binary_pixel[i * BYTE_SIZE], BYTE_SIZE);
        }

        fwrite(pixel, sizeof(unsigned char), bmp_pixel_size, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
}

// function to retrieve a message from the least significant bit of each pixel
void retrieve_message(char *out_filename, int msg_length) {
    FILE *fp_out = fopen(out_filename, "rb");
    if (!fp_out) {
        printf("Cannot open output file\n");
        exit(1);
    }

    // read BMP header
    unsigned char bmp_header[HEADER_SIZE];
    fread(bmp_header, sizeof(unsigned char), HEADER_SIZE, fp_out);

    // get bitmap size and bits per pixel
    int bitmap_size = *(int *)&bmp_header[BITMAP_SIZE_OFFSET];
    int bits_per_pixel = *(int *)&bmp_header[BITS_PER_PIXEL_OFFSET];

    int bmp_pixel_size = bits_per_pixel / BYTE_SIZE; // BMP pixel size in bytes
    unsigned char pixel[bmp_pixel_size];
    int binary_pixel[bmp_pixel_size * BYTE_SIZE];
    int binary_msg_length[32];

    // read message length from first 4 bytes of pixel data
    fread(pixel, sizeof(unsigned char), 4, fp_out);
    for (int i = 0; i < 3; i++) {
        binary_to_decimal(&binary_pixel[i * BYTE_SIZE], BYTE_SIZE);
    }

    int msg_length_retrieve = binary_to_decimal(binary_msg_length, 32);
    printf("Retrieving message...\n");

    // read pixels and retrieve least significant bit of each color channel
    int msg_index = 0;
    char message[msg_length_retrieve + 1];
    message[msg_length_retrieve] = '\0';
    while (ftell(fp_out) < bitmap_size && msg_index < msg_length_retrieve * BYTE_SIZE) {
        fread(pixel, sizeof(unsigned char), bmp_pixel_size, fp_out);

        // convert pixel data to binary
        for (int i = 0; i < bmp_pixel_size; i++) {
            decimal_to_binary(pixel[i], &binary_pixel[i * BYTE_SIZE]);
        }

        // retrieve message from least significant bit of each color channel
        for (int i = 0; i < bmp_pixel_size * BYTE_SIZE && msg_index < msg_length_retrieve * BYTE_SIZE; i++) {
            message[msg_index / BYTE_SIZE] |= (binary_pixel[i] & 1) << (msg_index % BYTE_SIZE);
            msg_index++;
        }
    }

    printf("Retrieved message: %s\n", message);
}

int main() {
    char message[] = "Hello, world! This is a test message.";
    hide_message(message, "input.bmp", "output.bmp");
    retrieve_message("output.bmp", strlen(message));
    return 0;
}