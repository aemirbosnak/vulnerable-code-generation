//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void encode(char *image, char *message) {
    FILE *fp = fopen(image, "rb+");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }
    
    // Get the size of the image
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    
    // Get the size of the message
    long msgsize = strlen(message);
    
    // Check if the image is large enough to hold the message
    if (size < msgsize) {
        fprintf(stderr, "Error: Image is too small to hold the message\n");
        exit(1);
    }
    
    // Read the image into a buffer
    unsigned char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }
    fread(buffer, 1, size, fp);
    
    // Encode the message into the image
    for (int i = 0; i < msgsize; i++) {
        unsigned char byte = buffer[i];
        byte = byte & 0xFE;  // Clear the least significant bit
        byte = byte | ((message[i] >> 7) & 0x01);  // Set the least significant bit to the most significant bit of the message byte
        buffer[i] = byte;
    }
    
    // Write the encoded image back to the file
    fseek(fp, 0, SEEK_SET);
    fwrite(buffer, 1, size, fp);
    fclose(fp);
    free(buffer);
}

void decode(char *image) {
    FILE *fp = fopen(image, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        exit(1);
    }
    
    // Get the size of the image
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    
    // Read the image into a buffer
    unsigned char *buffer = malloc(size);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }
    fread(buffer, 1, size, fp);
    
    // Decode the message from the image
    char *message = malloc(size);
    if (message == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        unsigned char byte = buffer[i];
        message[i] = (byte & 0x01) << 7;  // Get the most significant bit of the message byte
    }
    
    // Print the message
    printf("%s\n", message);
    fclose(fp);
    free(buffer);
    free(message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image> <encode/decode> <message>\n", argv[0]);
        exit(1);
    }
    
    char *image = argv[1];
    char *mode = argv[2];
    char *message = argv[3];
    
    if (strcmp(mode, "encode") == 0) {
        encode(image, message);
    } else if (strcmp(mode, "decode") == 0) {
        decode(image);
    } else {
        fprintf(stderr, "Error: Invalid mode\n");
        exit(1);
    }
    
    return 0;
}