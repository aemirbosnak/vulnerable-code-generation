//FormAI DATASET v1.0 Category: Image Steganography ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>

// Constants for the image file header
#define HEADER_SIZE 54
#define BITS_PER_PIXEL_OFFSET 28
#define WIDTH_OFFSET 18
#define HEIGHT_OFFSET 22
#define NO_OF_COLOR_PLANES_OFFSET 26
#define COMPRESSION_METHOD_OFFSET 30
#define IMAGE_SIZE_OFFSET 34
#define HORIZONTAL_RESOLUTION_OFFSET 38
#define VERTICAL_RESOLUTION_OFFSET 42

#define MAX_MESSAGE_LENGTH 1000

// Function to convert integer to binary
char *int_to_binary(int x) {
    char *binary = malloc(9 * sizeof(char));
    for(int i=7; i>=0; i--) {
        binary[7-i] = ((x>>i) & 1) + '0';
    }
    binary[8] = '\0';
    return binary;
}

// Function to get the nth bit of an integer
int get_bit(uint8_t byte, int n) {
    return ((byte>>n) & 1);
}

// Function to set the nth bit of an integer to 1 or 0
void set_bit(uint8_t *byte, int n, int bit) {
    if(bit == 1) {
        *byte |= (1<<n);
    }
    else {
        *byte &= ~(1<<n);
    }
}

// Function to hide the message in the image
void hide_message(char *filename, char *message, char *output_filename) {
    // Open image file in read binary mode
    FILE *file = fopen(filename, "rb");
    if(!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    // Read image file header information
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, file);

    // Check if image is 24-bit BMP image
    if(header[0] != 'B' || header[1] != 'M' || *(int*)&(header[0x1E]) != 0 || *(int*)&(header[0x1C]) != 24) {
        printf("Unsupported file format.\n");
        fclose(file);
        return;
    }

    // Get image dimensions and size
    int width = *(int*)&(header[WIDTH_OFFSET]);
    int height = *(int*)&(header[HEIGHT_OFFSET]);
    int image_size = *(int*)&(header[IMAGE_SIZE_OFFSET]);

    // Check if message can be hidden in image
    int max_message_length = image_size / 8;
    if(strlen(message) > max_message_length) {
        printf("Image is too small to hide the message.\n");
        fclose(file);
        return;
    }

    // Copy input image data to output image
    uint8_t input_image[image_size];
    fread(input_image, sizeof(uint8_t), image_size, file);

    // Close input image file
    fclose(file);

    // Open output image file in write binary mode
    FILE *output_file = fopen(output_filename, "wb");

    // Write image file header to output image file
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output_file);

    // Iterate through the message one character at a time
    for(int i=0; i<strlen(message); i++) {
        char *binary_char = int_to_binary(message[i]);

        // Iterate through each bit of the binary representation of the character
        for(int j=0; j<8; j++) {
            // Get nth bit of input image byte
            int bit = get_bit(input_image[(i*8)+j], 0);

            // Set nth bit of the binary representation of the character to bit
            int binary_char_length = strlen(binary_char);
            char *new_binary_char = malloc((binary_char_length+1) * sizeof(char));
            strcpy(new_binary_char, binary_char);
            new_binary_char[binary_char_length-j-1] = (bit + '0');

            // Convert binary representation back to integer
            int new_char = strtol(new_binary_char, NULL, 2);

            // Write new integer value to output image byte
            input_image[(i*8)+j] = new_char;
            fwrite(&input_image[(i*8)+j], sizeof(uint8_t), 1, output_file);
        }
    }

    // Write remaining input image data to output image
    for(int i=strlen(message)*8; i<image_size; i++) {
        fwrite(&input_image[i], sizeof(uint8_t), 1, output_file);
    }

    // Close output image file
    fclose(output_file);
}

// Function to extract the hidden message from the image
char *extract_message(char *filename) {
    // Open image file in read binary mode
    FILE *file = fopen(filename, "rb");
    if(!file) {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }

    // Read image file header information
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, file);

    // Check if image is 24-bit BMP image
    if(header[0] != 'B' || header[1] != 'M' || *(int*)&(header[0x1E]) != 0 || *(int*)&(header[0x1C]) != 24) {
        printf("Unsupported file format.\n");
        fclose(file);
        return NULL;
    }

    // Get image dimensions and size
    int width = *(int*)&(header[WIDTH_OFFSET]);
    int height = *(int*)&(header[HEIGHT_OFFSET]);
    int image_size = *(int*)&(header[IMAGE_SIZE_OFFSET]);

    // Allocate memory for extracted message string
    char *message = malloc((MAX_MESSAGE_LENGTH+1) * sizeof(char));
    message[0] = '\0';

    // Iterate through image bytes one at a time
    char char_buffer[2];
    char_buffer[1] = '\0';
    for(int i=0; i<image_size; i++) {
        // Read input image byte
        uint8_t input_byte;
        fread(&input_byte, sizeof(uint8_t), 1, file);

        // Check if message length limit has been reached
        if(strlen(message) >= MAX_MESSAGE_LENGTH) {
            printf("Message length limit reached. Stopping extraction.\n");
            break;
        }

        // Get the least significant bit of the input byte
        int bit = get_bit(input_byte, 0);

        // Add the bit to the binary character buffer
        char *binary_char = int_to_binary(char_buffer[0]);
        char *new_binary_char = malloc(9 * sizeof(char));
        sprintf(new_binary_char, "%c%s", (bit+'0'), binary_char);
        int new_char = strtol(new_binary_char, NULL, 2);
        char_buffer[0] = new_char;

        // Check if the binary character buffer now contains a full character
        if(strlen(char_buffer) == 8) {
            // Add the full character to the extracted message string
            strncat(message, char_buffer, 1);
            char_buffer[0] = '\0';
        }
    }

    // Close input image file
    fclose(file);

    return message;
}

// Main function
int main() {
    char *filename = "image.bmp";
    char *message = "This is a secret message!";
    char *output_filename = "output.bmp";

    printf("Hiding message in image...\n");
    hide_message(filename, message, output_filename);
    printf("Message hidden successfully!\n");

    printf("Extracting message from image...\n");
    char *extracted_message = extract_message(output_filename);
    if(extracted_message) {
        printf("Extracted message: %s\n", extracted_message);
    }

    return 0;
}