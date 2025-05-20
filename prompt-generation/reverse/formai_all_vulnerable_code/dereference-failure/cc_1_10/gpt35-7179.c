//FormAI DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1000000 // maximum image size is 1 megabyte
#define MAX_MESSAGE_SIZE 1000 // maximum message size is 1000 characters
#define BYTE_SIZE 8 // each byte has 8 bits

void steg_encode(unsigned char* image_data, int image_size, char* message, int message_size) {
    int image_index = 0, bit_index = 0;
    for (int i = 0; i < message_size; i++) {
        for (int j = 0; j < BYTE_SIZE; j++) {
            if (bit_index == 8) {
                bit_index = 0;
                image_index++;
            }
            if (image_index >= image_size) {
                printf("Image size too small to encode message\n");
                exit(EXIT_FAILURE);
            }
            unsigned char bit = (message[i] >> (BYTE_SIZE - 1 - j)) & 1;
            image_data[image_index] = (image_data[image_index] & (~1)) | bit;
            bit_index++;
        }
    }
}

char* steg_decode(unsigned char* image_data, int image_size) {
    int message_size = 0, bit_index = 0;
    bool end_of_message = false;
    char* message = (char*) malloc(MAX_MESSAGE_SIZE * sizeof(char));
    memset(message, 0, MAX_MESSAGE_SIZE);
    for (int i = 0; i < image_size; i++) {
        if (bit_index == 8) {
            bit_index = 0;
            message_size++;
        }
        if (message_size >= MAX_MESSAGE_SIZE) {
            printf("Message size too large\n");
            exit(EXIT_FAILURE);
        }
        unsigned char bit = image_data[i] & 1;
        message[message_size - 1] = (message[message_size - 1] << 1) | bit;
        if (message[message_size - 1] == '\0') {
            end_of_message = true;
            break;
        }
        bit_index++;
    }
    if (!end_of_message) {
        printf("Message not found\n");
        exit(EXIT_FAILURE);
    }
    return message;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <image_file> <message_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* image_file = fopen(argv[1], "rb");
    if (!image_file) {
        printf("Unable to open image file\n");
        exit(EXIT_FAILURE);
    }
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    if (image_size > MAX_IMAGE_SIZE) {
        printf("Image size too large\n");
        exit(EXIT_FAILURE);
    }
    unsigned char* image_data = (unsigned char*) malloc(image_size * sizeof(unsigned char));
    fseek(image_file, 0, SEEK_SET);
    fread(image_data, image_size, 1, image_file);
    fclose(image_file);

    FILE* message_file = fopen(argv[2], "r");
    if (!message_file) {
        printf("Unable to open message file\n");
        exit(EXIT_FAILURE);
    }
    char* message = (char*) malloc(MAX_MESSAGE_SIZE * sizeof(char));
    memset(message, 0, MAX_MESSAGE_SIZE);
    fgets(message, MAX_MESSAGE_SIZE, message_file);
    fclose(message_file);

    steg_encode(image_data, image_size, message, strlen(message));

    FILE* output_file = fopen(argv[3], "wb");
    if (!output_file) {
        printf("Unable to open output file\n");
        exit(EXIT_FAILURE);
    }
    fwrite(image_data, image_size, 1, output_file);
    fclose(output_file);

    unsigned char* decoded_data = (unsigned char*) malloc(image_size * sizeof(unsigned char));
    memcpy(decoded_data, image_data, image_size);
    char* decoded_message = steg_decode(decoded_data, image_size);

    printf("Original message: %s\n", message);
    printf("Decoded message: %s\n", decoded_message);

    free(image_data);
    free(message);
    free(decoded_data);
    free(decoded_message);

    return 0;
}