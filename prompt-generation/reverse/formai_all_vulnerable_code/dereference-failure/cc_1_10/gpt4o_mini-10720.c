//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert integer to binary string
void intToBinary(int n, char *binary) {
    for (int i = 0; i < 8; i++) {
        binary[7 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

// Function to hide text in the least significant bits of the pixel values
void encodeMessageInImage(const char *inputImagePath, const char *outputImagePath, const char *message) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    if (!inputFile) {
        perror("Could not open input image file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputImagePath, "wb");
    if (!outputFile) {
        perror("Could not open output image file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read the input image header and write it to the output image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);
    fwrite(header, sizeof(unsigned char), 54, outputFile);
    
    // Convert the message to binary
    char binaryMessage[8 * strlen(message) + 1];
    for (size_t i = 0; i < strlen(message); i++) {
        intToBinary((unsigned char)message[i], &binaryMessage[i * 8]);
    }
    binaryMessage[8 * strlen(message)] = '\0';

    // Indicate the end of the message with a separator
    const char *separator = "END";
    for (size_t i = 0; i < strlen(separator); i++) {
        intToBinary((unsigned char)separator[i], &binaryMessage[(strlen(message) + i) * 8]);
    }
    binaryMessage[(strlen(message) + strlen(separator)) * 8] = '\0';

    // Read the pixel data and hide the message in the least significant bits
    size_t msgLength = strlen(binaryMessage);
    size_t pixelIndex = 0;
    unsigned char pixel;

    while (fread(&pixel, sizeof(unsigned char), 1, inputFile) && pixelIndex < msgLength) {
        // Modify the least significant bit
        pixel = (pixel & 0xFE) | (binaryMessage[pixelIndex] - '0');
        fwrite(&pixel, sizeof(unsigned char), 1, outputFile);
        pixelIndex++;
    }

    // Copy the remaining pixel data unchanged
    while (fread(&pixel, sizeof(unsigned char), 1, inputFile)) {
        fwrite(&pixel, sizeof(unsigned char), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decodeMessageFromImage(const char *imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        perror("Could not open image file");
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);

    // Decode the message
    unsigned char pixel;
    char binaryMessage[1000] = {0}; // assume message is less than 1000 bits
    size_t msgIndex = 0;

    while (fread(&pixel, sizeof(unsigned char), 1, inputFile)) {
        binaryMessage[msgIndex++] = (pixel & 1) + '0';
        // Check if we reached the end separator 'END'
        if (msgIndex >= 24 && !strncmp(&binaryMessage[msgIndex - 24], "01000101010011100110000101001110", 24)) {
            break;
        }
    }

    // Convert binary message back to characters
    printf("Decoded message: ");
    for (size_t i = 0; i < msgIndex / 8; i++) {
        char byte[9] = {0};
        strncpy(byte, &binaryMessage[i * 8], 8);
        printf("%c", (char)strtol(byte, NULL, 2));
    }
    printf("\n");

    fclose(inputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4 && argc != 3) {
        fprintf(stderr, "Usage: %s <encode/decode> <image_path> [message]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessageInImage(argv[2], "output_image.bmp", argv[3]);
        printf("Message encoded into output_image.bmp\n");
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessageFromImage(argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encode' or 'decode'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}