//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void hide_message(char* filename, char* message);
void retrieve_message(char* filename);

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Error: Please provide arguments in the following order:\n");
        printf("1. Input image filename\n");
        printf("2. Output image filename\n");
        printf("3. Message to hide\n");
        return 1;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];
    char* message = argv[3];

    // Hide the message in the input image
    hide_message(input_filename, message);

    // Retrieve the message from the output image
    retrieve_message(output_filename);

    return 0;
}

void hide_message(char* filename, char* message) {
    // Open the image file for reading in binary mode
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Compute the size of the file
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file data
    unsigned char* file_data = (unsigned char*)malloc(file_size);
    if (!file_data) {
        printf("Error: Could not allocate memory for file data\n");
        fclose(file);
        return;
    }

    // Read the file into memory
    fread(file_data, 1, file_size, file);
    fclose(file);

    // Check if the file is large enough to hold the message
    int message_len = strlen(message);
    if ((message_len + 1) * 8 > file_size) {
        printf("Error: File is not large enough to hold the message\n");
        free(file_data);
        return;
    }

    // Loop through the message and change the least significant bit of each byte in the file data
    int bit = 0;
    for (int i = 0; i < message_len; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            // Get the current bit of the character
            int char_bit = (c >> j) & 1;
            // Set the least significant bit of the file byte to the current character bit
            file_data[i * 8 + j] = (file_data[i * 8 + j] & ~1) | char_bit;
            // Keep track of the total number of bits modified
            bit++;
        }
    }

    // Write the modified file data to the output file
    FILE* output_file = fopen("output.png", "wb");
    if (!output_file) {
        printf("Error: Could not open output file for writing\n");
        free(file_data);
        return;
    }

    fwrite(file_data, 1, file_size, output_file);
    fclose(output_file);
    free(file_data);

    printf("Message hidden successfully: %d bits modified\n", bit);
}

void retrieve_message(char* filename) {
    // Open the image file for reading in binary mode
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Compute the size of the file
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file data
    unsigned char* file_data = (unsigned char*)malloc(file_size);
    if (!file_data) {
        printf("Error: Could not allocate memory for file data\n");
        fclose(file);
        return;
    }

    // Read the file into memory
    fread(file_data, 1, file_size, file);
    fclose(file);

    // Loop through the file data and retrieve the least significant bit of each byte
    int bit = 0;
    char message[1024] = "";
    char c = 0;
    for (int i = 0; i < file_size; i++) {
        // Get the least significant bit of the current file byte
        int file_bit = file_data[i] & 1;
        // Set the current bit of the character to the current file bit
        c |= file_bit << bit;
        bit++;
        // If we have read 8 bits, add the current character to the message
        if (bit == 8) {
            bit = 0;
            strncat(message, &c, 1);
            c = 0;
        }
    }

    // Output the retrieved message
    printf("Retrieved message: %s\n", message);

    free(file_data);
}