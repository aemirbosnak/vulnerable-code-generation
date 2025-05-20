//FormAI DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decToBin(int num, int bin[], int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
}

// Function to convert binary to decimal
int binToDec(int bin[], int size) {
    int dec = 0, i;
    for (i = 0; i < size; i++) {
        dec += bin[i] * (1 << (size - i - 1));
    }
    return dec;
}

// Function to hide a message in an image
void hideMessage(char message[], char image[], char stegImage[]) {
    // Open input and output files
    FILE *inFile, *outFile;
    inFile = fopen(image, "rb");
    outFile = fopen(stegImage, "wb");
    if (inFile == NULL || outFile == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }

    // Calculate message length in bits
    int messageLength = strlen(message) * 8;

    // Copy header of input file to output file
    char header[54];
    fread(header, 1, 54, inFile);
    fwrite(header, 1, 54, outFile);

    // Hide message length in first 32 bytes of image data
    int messageLengthBin[32];
    decToBin(messageLength, messageLengthBin, 32);
    int i, j;
    fseek(outFile, 54, SEEK_SET);
    for (i = 0; i < 32; i++) {
        fread(header, 1, 1, inFile);
        for (j = 0; j < 8; j++) {
            header[j] &= 0xFE; // set last bit to 0
            header[j] |= messageLengthBin[i] >> (7 - j) & 0x01; // set last bit to message bit
        }
        fwrite(header, 1, 1, outFile);
    }

    // Hide message in remaining bytes of image data
    int messageBin[messageLength];
    for (i = 0; i < messageLength / 8; i++) {
        decToBin(message[i], &messageBin[i * 8], 8);
    }
    fseek(inFile, 54 + 32, SEEK_SET);
    for (i = 0; i < messageLength; i++) {
        fread(header, 1, 1, inFile);
        for (j = 0; j < 8; j++) {
            header[j] &= 0xFE; // set last bit to 0
            header[j] |= messageBin[i] >> (7 - j) & 0x01; // set last bit to message bit
        }
        fwrite(header, 1, 1, outFile);
    }

    // Copy remaining bytes of input file to output file
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, 1024, inFile)) > 0) {
        fwrite(buffer, 1, bytesRead, outFile);
    }

    // Close input and output files
    fclose(inFile);
    fclose(outFile);
}

// Function to extract a message from an image
char* extractMessage(char image[]) {
    // Open input file
    FILE *inFile = fopen(image, "rb");
    if (inFile == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Extract message length from first 32 bytes of image data
    int messageLengthBin[32];
    int i, j;
    fseek(inFile, 54, SEEK_SET);
    for (i = 0; i < 32; i++) {
        char byte;
        fread(&byte, 1, 1, inFile);
        messageLengthBin[i] = byte & 0x01; // get last bit
    }
    int messageLength = binToDec(messageLengthBin, 32);

    // Extract message from remaining bytes of image data
    char *message = malloc(messageLength / 8 + 1);
    int messageBin[messageLength];
    for (i = 0; i < messageLength; i++) {
        char byte;
        fread(&byte, 1, 1, inFile);
        messageBin[i] = byte & 0x01; // get last bit
    }
    for (i = 0; i < messageLength / 8; i++) {
        message[i] = binToDec(&messageBin[i * 8], 8);
    }
    message[messageLength / 8] = '\0';

    // Close input file
    fclose(inFile);

    // Return extracted message
    return message;
}

int main() {
    char *message = "Hello, world!";
    char *image = "original.bmp";
    char *stegImage = "steg.bmp";

    // Hide message in image
    hideMessage(message, image, stegImage);
    printf("Message hidden in image.\n");

    // Extract message from image
    char *extractedMessage = extractMessage(stegImage);
    printf("Extracted message: %s\n", extractedMessage);

    free(extractedMessage);
    return 0;
}