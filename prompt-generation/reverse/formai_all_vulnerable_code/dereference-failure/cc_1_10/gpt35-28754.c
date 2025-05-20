//FormAI DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define FILE_HEADER_SIZE 54
#define MAX_IMAGE_SIZE 1000000

// Function for inserting message into image
void insertMessage(char* image_filename, char* message) {
    char* image_data = (char*)malloc(MAX_IMAGE_SIZE);
    FILE* image_file = fopen(image_filename, "rb");
    if(image_file == NULL) {
        printf("Error: Cannot open image file\n");
        exit(1);
    }
    fread(image_data, sizeof(char), MAX_IMAGE_SIZE, image_file); // Reading image data
    fclose(image_file);
    int message_length = strlen(message);
    if(message_length > (MAX_IMAGE_SIZE - FILE_HEADER_SIZE)/8) {
        printf("Error: Message is too large to be embedded into the image\n");
        exit(1);
    }
    int bit_index = 0, byte_index = FILE_HEADER_SIZE; // Indexing variables for message and image data
    while(bit_index < message_length*8) {
        // Extracting bits of character from message
        int bit = message[bit_index/8] & (1 << (bit_index % 8));
        // Ectracting bit of current image byte
        int image_bit = image_data[byte_index] & 1;
        // Replacing image bit with message bit
        if(image_bit != bit) {
            image_data[byte_index] ^= 1;
        }
        bit_index++;
        if(bit_index % 8 == 0) {
            byte_index++;
        }
    }
    FILE* stego_image = fopen("stego_image.bmp", "wb");
    if(stego_image == NULL) {
        printf("Error: Cannot create stego image file\n");
        exit(1);
    }
    fwrite(image_data, sizeof(char), MAX_IMAGE_SIZE, stego_image); // Writing stego image data
    fclose(stego_image);
    printf("Stego image created successfully\n");
    free(image_data);
}

// Function for retrieving message from image
void retrieveMessage(char* stego_image_filename) {
    char* stego_image_data = (char*)malloc(MAX_IMAGE_SIZE);
    FILE* stego_image_file = fopen(stego_image_filename, "rb");
    if(stego_image_file == NULL) {
        printf("Error: Cannot open stego image file\n");
        exit(1);
    }
    fread(stego_image_data, sizeof(char), MAX_IMAGE_SIZE, stego_image_file); // Reading stego image data
    fclose(stego_image_file);
    int message_length = 0, bit_index = 0, byte_index = FILE_HEADER_SIZE; // Indexing variables for message and image data
    char* message = (char*)malloc(1);
    while(1) {
        // Extracting bit of current image byte
        int image_bit = stego_image_data[byte_index] & 1;
        // Adding extracted bit to message length
        message_length |= (image_bit << (bit_index % 8));
        bit_index++;
        if(bit_index % 8 == 0) {
            byte_index++;
        }
        // Stop condition for message length retrieval
        if(bit_index == 32) {
            message = (char*)realloc(message, message_length + 1);
            message[message_length] = '\0';
            break;
        }
    }
    // Retrieving message bits
    for(int i = 0; i < message_length*8; i++) {
        // Extracting bit of current image byte
        int image_bit = stego_image_data[byte_index] & 1;
        // Adding extracted bit to message characters
        message[i/8] |= (image_bit << (i % 8));
        bit_index++;
        if(bit_index % 8 == 0) {
            byte_index++;
        }
    }
    printf("Retrieved message: %s\n", message);
    free(stego_image_data);
    free(message);
}

int main() {
    insertMessage("image.bmp", "This is a secret message!"); // Inserting message into image
    retrieveMessage("stego_image.bmp"); // Retrieving message from stego image
    return 0;
}