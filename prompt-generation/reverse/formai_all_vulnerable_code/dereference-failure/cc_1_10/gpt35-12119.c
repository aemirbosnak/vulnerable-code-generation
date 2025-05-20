//FormAI DATASET v1.0 Category: Image Steganography ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Hide the message in the image
void hide_message(char* input_image_path, char* output_image_path, char* message) {

    // Open image file
    FILE* input_image = fopen(input_image_path, "rb");
    if (input_image == NULL) {
        printf("Failed to open image file %s\n", input_image_path);
        return;
    }

    // Create output file
    FILE* output_image = fopen(output_image_path, "wb");
    if (output_image == NULL) {
        printf("Failed to create output file %s\n", output_image_path);
        return;
    }

    // Copy the header information to the output file
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_image);
    fwrite(header, sizeof(unsigned char), 54, output_image);

    // Get the image size from the header
    int image_size = *(int*)&header[2];

    // Allocate memory for the image data
    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
    fread(image_data, sizeof(unsigned char), image_size, input_image);

    // Get the size of the message to be hidden
    int message_size = 0;
    char* message_ptr = message;
    while (*message_ptr++ != '\0') {
        message_size++;
    }

    // Check if the message is too big to be hidden in the image
    if (message_size > image_size / 8) {
        printf("Message is too big to be hidden in the image\n");
        return;
    }

    // Hide the message in the image
    for (int i = 0; i < message_size; i++) {
        char byte = message[i];
        for (int j = 0; j < 8; j++) {
            int bit = (byte >> j) & 1;
            if (bit) {
                image_data[i * 8 + j] |= 1;
            } else {
                image_data[i * 8 + j] &= 0xFE;
            }
        }
    }

    // Write the modified image data to the output file
    fwrite(image_data, sizeof(unsigned char), image_size, output_image);

    // Free memory and close files
    free(image_data);
    fclose(input_image);
    fclose(output_image);

    printf("Message hidden successfully in %s\n", output_image_path);
}

// Extract the message from the image
void extract_message(char* input_image_path, char* output_text_path) {

    // Open image file
    FILE* input_image = fopen(input_image_path, "rb");
    if (input_image == NULL) {
        printf("Failed to open image file %s\n", input_image_path);
        return;
    }

    // Create output file
    FILE* output_text = fopen(output_text_path, "w");
    if (output_text == NULL) {
        printf("Failed to create output file %s\n", output_text_path);
        return;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_image);

    // Get the image size from the header
    int image_size = *(int*)&header[2];

    // Allocate memory for the image data
    unsigned char* image_data = (unsigned char*)malloc(sizeof(unsigned char) * image_size);
    fread(image_data, sizeof(unsigned char), image_size, input_image);

    // Extract the message from the image
    int message_size = image_size / 8;
    char* message = (char*)malloc(sizeof(char) * message_size);
    for (int i = 0; i < message_size; i++) {
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= (image_data[i * 8 + j] & 1) << j;
        }
        message[i] = byte;
    }

    // Write the message to the output file
    fprintf(output_text, "Extracted Message from %s:", input_image_path);
    for (int i = 0; i < message_size; i++) {
        fprintf(output_text, "%c", message[i]);
    }

    // Free memory and close files
    free(image_data);
    free(message);
    fclose(input_image);
    fclose(output_text);

    printf("Message extracted successfully to %s\n", output_text_path);
}

// Main function to test image steganography
int main() {

    // Hide message in image
    hide_message("input.bmp", "output.bmp", "Hello, this is a secret message hidden in an image!");

    // Extract message from image
    extract_message("output.bmp", "output.txt");

    return 0;
}