//FormAI DATASET v1.0 Category: Image Steganography ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BYTE_SIZE 8

// Function to get the size of file in bytes
unsigned long get_file_size(FILE* file) {
    fseek(file, 0L, SEEK_END);
    unsigned long file_size = ftell(file);
    rewind(file);
    return file_size;
}

// Function to get the bit value of a pixel
int get_bit(unsigned char pixel, int bit_position) {
    return (pixel >> bit_position) & 1;
}

// Function to set the bit value of a pixel
void set_bit(unsigned char* pixel, int bit_position, int bit_value) {
    *pixel ^= (-bit_value ^ *pixel) & (1UL << bit_position);
}

// Function to hide message within the image
void hide_message(FILE* fptr_image, FILE* fptr_message, FILE* fptr_steg_image) {
    unsigned long image_size = get_file_size(fptr_image);
    unsigned long message_size = get_file_size(fptr_message);
    unsigned char* image_data = (unsigned char*) malloc(sizeof(unsigned char) * image_size);
    unsigned char* message_data = (unsigned char*) malloc(sizeof(unsigned char) * message_size);
    unsigned char* steg_image_data = (unsigned char*) malloc(sizeof(unsigned char) * image_size);
    fread(image_data, sizeof(unsigned char), image_size, fptr_image);
    fread(message_data, sizeof(unsigned char), message_size, fptr_message);
    memcpy(steg_image_data, image_data, image_size);

    int bit_pos = 0;
    for (unsigned long i = 0; i < message_size; ++i) {
        for (int j = 0; j < BYTE_SIZE; ++j) {
            int bit_value = get_bit(message_data[i], j);
            set_bit(&steg_image_data[i * BYTE_SIZE + j], bit_pos, bit_value);
            ++bit_pos;
        }
    }

    fwrite(steg_image_data, sizeof(unsigned char), image_size, fptr_steg_image);
    free(image_data);
    free(message_data);
    free(steg_image_data);
}

// Function to retrieve message from the image
bool retrieve_message(FILE* fptr_steg_image, FILE* fptr_retrieved_message) {
    unsigned long steg_image_size = get_file_size(fptr_steg_image);
    unsigned char* steg_image_data = (unsigned char*) malloc(sizeof(unsigned char) * steg_image_size);
    fread(steg_image_data, sizeof(unsigned char), steg_image_size, fptr_steg_image);

    unsigned long message_size = steg_image_size / BYTE_SIZE;
    unsigned char* message_data = (unsigned char*) malloc(sizeof(unsigned char) * message_size);

    int bit_pos = 0;
    for (unsigned long i = 0; i < message_size; ++i) {
        for (int j = 0; j < BYTE_SIZE; ++j) {
            int bit_value = get_bit(steg_image_data[i * BYTE_SIZE + j], bit_pos);
            set_bit(&message_data[i], j, bit_value);
            ++bit_pos;
        }
    }

    fwrite(message_data, sizeof(unsigned char), message_size, fptr_retrieved_message);

    bool success = true;
    for (unsigned long i = 0; i < message_size; ++i) {
        if (message_data[i] == 0) {
            success = false;
            break;
        }
    }

    free(message_data);
    free(steg_image_data);
    return success;
}

int main() {
    FILE* fptr_image = fopen("image.bmp", "rb");
    FILE* fptr_message = fopen("secret.txt", "rb");
    FILE* fptr_steg_image = fopen("hidden_image.bmp", "wb");
    hide_message(fptr_image, fptr_message, fptr_steg_image);

    fclose(fptr_image);
    fclose(fptr_message);
    fclose(fptr_steg_image);

    fptr_steg_image = fopen("hidden_image.bmp", "rb");
    FILE* fptr_retrieved_message = fopen("retrieved_secret.txt", "wb");
    bool success = retrieve_message(fptr_steg_image, fptr_retrieved_message);

    if (success) {
        printf("Message successfully retrieved\n");
    } else {
        printf("Failed to retrieve message\n");
    }

    fclose(fptr_steg_image);
    fclose(fptr_retrieved_message);
    return 0;
}