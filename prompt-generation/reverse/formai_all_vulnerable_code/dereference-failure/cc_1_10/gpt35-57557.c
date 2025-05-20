//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HEADER_SIZE 54

// Function to convert decimal to binary
void decimalToBinary(int n, int binary[], int num_bits) { 
    for(int i = num_bits-1 ; i >= 0 ; i--) { 
        int k = n >> i; 
        if (k & 1) 
            binary[num_bits-i-1] = 1; 
        else
            binary[num_bits-i-1] = 0; 
    } 
} 

// Function to convert binary to decimal
int binaryToDecimal(int binary[], int num_bits) { 
    int n = 0; 
    for (int i = 0; i < num_bits; i++) { 
        n = n << 1; 
        if (binary[i] == 1) 
            n = n | 1; 
        else
            n = n | 0; 
    } 
    return n; 
}

// Function to hide a message in an image using steganography
void hideMessageInImage(char* image_path, char* message, char* output_path) {
    FILE* image_file = fopen(image_path, "rb");
    FILE* output_file = fopen(output_path, "wb");

    if (image_file == NULL || output_file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    // Read header from image file
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, image_file);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, output_file);

    // Read image data from image file
    int width, height;
    memcpy(&width, header+18, sizeof(int));
    memcpy(&height, header+22, sizeof(int));
    int pixel_bytes = 3;
    int row_size = width*pixel_bytes;
    uint8_t* image_data = (uint8_t*) malloc(row_size*height);
    uint8_t* output_data = (uint8_t*) malloc(row_size*height);
    fread(image_data, sizeof(unsigned char), row_size*height, image_file);
    fclose(image_file);

    // Split message into bytes and convert to binary
    int message_length = strlen(message);
    int message_bits[message_length*8];
    int i = 0;
    for (i = 0; i < message_length; i++) {
        int byte = message[i];
        decimalToBinary(byte, &message_bits[i*8], 8);
    }

    // Add message to image data
    i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < row_size; x += pixel_bytes) {
            if (i < message_length*8) {
                int r = image_data[y*row_size + x + 2];
                int g = image_data[y*row_size + x + 1];
                int b = image_data[y*row_size + x];

                decimalToBinary(r, &output_data[y*row_size + x + 2], 8);
                output_data[y*row_size + x + 2] = (output_data[y*row_size + x + 2] & 0xFE) | message_bits[i];
                i++;

                decimalToBinary(g, &output_data[y*row_size + x + 1], 8);
                output_data[y*row_size + x + 1] = (output_data[y*row_size + x + 1] & 0xFE) | message_bits[i];
                i++;

                decimalToBinary(b, &output_data[y*row_size + x], 8);
                output_data[y*row_size + x] = (output_data[y*row_size + x] & 0xFE) | message_bits[i];
                i++;
            } else {
                output_data[y*row_size + x + 2] = image_data[y*row_size + x + 2];
                output_data[y*row_size + x + 1] = image_data[y*row_size + x + 1];
                output_data[y*row_size + x] = image_data[y*row_size + x];
            }
        }
    }

    // Write output image file
    fwrite(output_data, sizeof(unsigned char), row_size*height, output_file);
    fclose(output_file);
    printf("Message hidden successfully!\n");
}

// Function to extract a message from an image using steganography
void extractMessageFromImage(char* image_path) {
    FILE* image_file = fopen(image_path, "rb");

    if (image_file == NULL) {
        printf("Could not open file.\n");
        return;
    }

    // Read header from image file
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, image_file);

    // Read image data from image file
    int width, height;
    memcpy(&width, header+18, sizeof(int));
    memcpy(&height, header+22, sizeof(int));
    int pixel_bytes = 3;
    int row_size = width*pixel_bytes;
    uint8_t* image_data = (uint8_t*) malloc(row_size*height);
    fread(image_data, sizeof(unsigned char), row_size*height, image_file);
    fclose(image_file);

    // Extract message from image data
    int message_length = 0;
    char message[1024] = "";
    int message_bits[1024*8];
    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < row_size; x += pixel_bytes) {
            if (i < 1024*8) {
                int r = image_data[y*row_size + x + 2];
                int g = image_data[y*row_size + x + 1];
                int b = image_data[y*row_size + x];

                message_bits[i] = r & 1;
                i++;

                if (i < 1024*8) {
                    message_bits[i] = g & 1;
                    i++;
                }

                if (i < 1024*8) {
                    message_bits[i] = b & 1;
                    i++;
                }
            }
        }
    }
    message_length = i/8;

    // Convert binary message to chars
    for (i = 0; i < message_length; i++) {
        int char_bits[8];
        for (int j = 0; j < 8; j++) {
            char_bits[j] = message_bits[i*8 + j];
        }
        message[i] = binaryToDecimal(char_bits, 8);
    }

    printf("Hidden message: %s\n", message);
}

int main(int argc, char* argv[]) {
    char* image_path = "cyberpunk_image.bmp";
    char* output_path = "cyberpunk_image_with_message.bmp";
    char* message = "We are the ghosts in the machines.";

    hideMessageInImage(image_path, message, output_path);
    extractMessageFromImage(output_path);

    return 0;
}