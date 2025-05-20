//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode a message into an image
void encode_image(const char *input_image, const char *output_image, const char *message) {
    // Open the input image for reading
    FILE *input = fopen(input_image, "rb");
    if (!input) {
        perror("Unable to open input image for reading");
        exit(EXIT_FAILURE);
    }
    
    // Open the output image for writing
    FILE *output = fopen(output_image, "wb");
    if (!output) {
        fclose(input);
        perror("Unable to open output image for writing");
        exit(EXIT_FAILURE);
    }
    
    // Read the original image into a buffer
    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    fseek(input, 0, SEEK_SET);
    
    unsigned char *buffer = (unsigned char *)malloc(input_size);
    fread(buffer, sizeof(unsigned char), input_size, input);
    
    // Find the end of the image data by skipping the header (assuming BMP format)
    int header_size = 54; // Common BMP Header Size
    int message_length = strlen(message);
    
    // Ensure message can fit within the image data
    if (message_length * 8 > (input_size - header_size)) {
        printf("Message is too large to encode in this image\n");
        free(buffer);
        fclose(input);
        fclose(output);
        exit(EXIT_FAILURE);
    }
    
    // Insert the message into the image data
    int data_index = header_size;
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            // Get the bit we need to hide
            unsigned char bit = (message[i] >> (7 - j)) & 1;
            // Clear the least significant bit of the current byte
            buffer[data_index] &= 0xFE; // Clear LSB
            // Set the LSB to the message bit
            buffer[data_index] |= bit;  // Set LSB to the message bit
            
            data_index++;
        }
    }
    
    // Write the modified buffer to the output image
    fwrite(buffer, sizeof(unsigned char), input_size, output);
    
    // Clean up
    free(buffer);
    fclose(input);
    fclose(output);
}

// Function to decode a message from an image
void decode_image(const char *image_path, char *output_message, size_t max_length) {
    // Open the image for reading
    FILE *input = fopen(image_path, "rb");
    if (!input) {
        perror("Unable to open image for reading");
        exit(EXIT_FAILURE);
    }
    
    // Read the original image into a buffer
    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    fseek(input, 0, SEEK_SET);
    
    unsigned char *buffer = (unsigned char *)malloc(input_size);
    fread(buffer, sizeof(unsigned char), input_size, input);
    
    // Find the end of the image data
    int header_size = 54; // Common BMP Header Size
    int message_length = 0;

    // Extract the message bit by bit
    for (int data_index = header_size; data_index < input_size; data_index++) {
        if (message_length >= max_length - 1) break; // Prevent buffer overflow (space for '\0')
        
        unsigned char byte = 0;
        for (int j = 0; j < 8; j++) {
            // Get the least significant bit
            byte <<= 1;
            byte |= (buffer[data_index] & 1);
            data_index++;
        }
        
        output_message[message_length++] = byte;
    }
    
    output_message[message_length] = '\0'; // Null terminate the output message

    // Clean up
    free(buffer);
    fclose(input);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <encode/decode> <input_image> <output_image/message.txt> <message (for encode only)>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    if (strcmp(argv[1], "encode") == 0) {
        encode_image(argv[2], argv[3], argv[4]);
        printf("Message encoded successfully into %s\n", argv[3]);
    } else if (strcmp(argv[1], "decode") == 0) {
        char output_message[1000]; // Assuming the message will be less than 1000 chars
        decode_image(argv[2], output_message, sizeof(output_message));
        printf("Decoded message: %s\n", output_message);
    } else {
        printf("Invalid operation. Please use 'encode' or 'decode'.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}