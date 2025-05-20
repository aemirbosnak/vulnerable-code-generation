//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define BLOCK_SIZE 8
#define PADDING_SIZE 4

// Function to extract the message from the image file
bool extract_message(const char* file_name, char* message) {
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_name);
        return false;
    }

    // Read the image file into memory
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char* buffer = (char*) malloc(size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(fp);
        return false;
    }

    size_t bytes_read = fread(buffer, 1, size, fp);
    fclose(fp);

    if (bytes_read!= size) {
        fprintf(stderr, "Error reading file\n");
        free(buffer);
        return false;
    }

    buffer[size] = '\0'; // Null-terminate the buffer

    // Extract the message from the image file
    for (int i = 0; i < size - BLOCK_SIZE; i += BLOCK_SIZE) {
        uint8_t* block = (uint8_t*) (buffer + i);
        uint8_t* message_block = (uint8_t*) (message + i / BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (block[j]!= message_block[j]) {
                fprintf(stderr, "Error extracting message\n");
                free(buffer);
                free(message);
                return false;
            }
        }
    }

    free(buffer);
    return true;
}

// Function to hide a message in an image file
bool hide_message(const char* file_name, const char* message) {
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_name);
        return false;
    }

    // Read the image file into memory
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char* buffer = (char*) malloc(size + 1);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(fp);
        return false;
    }

    size_t bytes_read = fread(buffer, 1, size, fp);
    fclose(fp);

    if (bytes_read!= size) {
        fprintf(stderr, "Error reading file\n");
        free(buffer);
        return false;
    }

    buffer[size] = '\0'; // Null-terminate the buffer

    // Hide the message in the image file
    for (int i = 0; i < size - BLOCK_SIZE; i += BLOCK_SIZE) {
        uint8_t* block = (uint8_t*) (buffer + i);
        uint8_t* message_block = (uint8_t*) (message + i / BLOCK_SIZE);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            if (block[j]!= message_block[j]) {
                fprintf(stderr, "Error hiding message\n");
                free(buffer);
                return false;
            }
        }
    }

    free(buffer);
    return true;
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <image_file> <message>\n", argv[0]);
        return 1;
    }

    const char* image_file = argv[1];
    const char* message = argv[2];

    char message_buffer[256];

    if (!hide_message(image_file, message)) {
        fprintf(stderr, "Error hiding message\n");
        return 1;
    }

    if (!extract_message(image_file, message_buffer)) {
        fprintf(stderr, "Error extracting message\n");
        return 1;
    }

    printf("Message: %s\n", message_buffer);

    return 0;
}