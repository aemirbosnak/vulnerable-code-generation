//FormAI DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54
#define MAX_FILE_SIZE 10485760 // 10 MB
#define MAX_MESSAGE_LENGTH 1000000 // 1 MB

unsigned char *read_image(char *filename, long *size);
void write_image(char *filename, unsigned char *image, long size);
void encode_message(unsigned char *image, long size, char *message);
char *decode_message(unsigned char *image, long size);

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    char *input_image = argv[1];
    char *output_image = argv[2];
    char *message = argv[3];

    long image_size;
    unsigned char *image = read_image(input_image, &image_size);

    encode_message(image, image_size, message);
    write_image(output_image, image, image_size);

    printf("Message encoded successfully!\n");

    char *decoded_message = decode_message(image, image_size);
    printf("Decoded message: %s\n", decoded_message);

    free(image);
    free(decoded_message);

    return 0;
}

unsigned char *read_image(char *filename, long *size) {

    FILE *fp;
    unsigned char *buffer;

    // Open file for reading in binary mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return NULL;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the image buffer
    buffer = (unsigned char*) malloc(*size);
    if (buffer == NULL) {
        printf("Error: memory allocation failed\n");
        fclose(fp);
        return NULL;
    }

    // Read the image file into the buffer
    fread(buffer, 1, *size, fp);

    // Close the file
    fclose(fp);

    return buffer;
}

void write_image(char *filename, unsigned char *image, long size) {

    FILE *fp;

    // Open file for writing in binary mode
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return;
    }

    // Write the image to the file
    fwrite(image, 1, size, fp);

    // Close the file
    fclose(fp);
}

void encode_message(unsigned char *image, long size, char *message) {

    long message_length = strlen(message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: message is too long\n");
        return;
    }

    // Calculate the maximum number of bits that can be used to encode the message
    long max_bits = (size - HEADER_SIZE) * 8;
    if (message_length * 8 > max_bits) {
        printf("Error: message is too long to be encoded in this image\n");
        return;
    }

    // Encode the message length in the first 4 bytes of the image
    image[18] = (unsigned char) (message_length & 0xff);
    image[19] = (unsigned char) ((message_length >> 8) & 0xff);
    image[20] = (unsigned char) ((message_length >> 16) & 0xff);
    image[21] = (unsigned char) ((message_length >> 24) & 0xff);

    // Encode each message character in the LSB of each byte of the image pixel
    long message_index = 0;
    for (long i = HEADER_SIZE; i < size && message_index < message_length; i += 3) {
        unsigned char *pixel = image + i;

        for (int j = 0; j < 3 && message_index < message_length; j++) {
            unsigned char *channel = pixel + j;

            unsigned char bit = (message[message_index] >> (message_index % 8)) & 0x01;
            *channel = (*channel & 0xfe) | bit;

            message_index++;
        }
    }
}

char *decode_message(unsigned char *image, long size) {

    long message_length = (image[21] << 24) | (image[20] << 16) | (image[19] << 8) | image[18];
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: message is too long\n");
        return NULL;
    }

    char *message = (char*) malloc(message_length + 1);
    if (message == NULL) {
        printf("Error: memory allocation failed\n");
        return NULL;
    }

    // Decode each message character from the LSB of each byte of the image pixel
    long message_index = 0;
    for (long i = HEADER_SIZE; i < size && message_index < message_length; i += 3) {
        unsigned char *pixel = image + i;

        for (int j = 0; j < 3 && message_index < message_length; j++) {
            unsigned char *channel = pixel + j;

            unsigned char bit = (*channel & 0x01) << (message_index % 8);
            message[message_index / 8] |= bit;

            message_index++;
        }
    }

    // Null-terminate the message
    message[message_length] = '\0';

    return message;
}