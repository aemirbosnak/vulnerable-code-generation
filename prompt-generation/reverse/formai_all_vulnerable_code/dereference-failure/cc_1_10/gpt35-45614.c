//FormAI DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get binary representation of a number
void decToBinary(int num, int binary[], int size) {
    int i, rem;
    for (i = 0; i < size; i++) {
        binary[i] = 0;
    }
    i = 0;
    while (num > 0) {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }
}

// Function to retrieve the hidden message from a byte array
char* retrieveMessage(unsigned char bytes[], int size) {
    // Get the size of the message
    int messageSize = 0;
    int i, j;
    for (i = 0; i < 8; i++) {
        messageSize += bytes[i] << (i*8);
    }

    // Allocate memory for the message
    char* message = (char*) malloc(messageSize * sizeof(char));

    // Retrieve the message from the byte array
    int messageIndex = 0;
    int binaryIndex = 8;
    int binary[8];
    for (i = 0; i < messageSize; i++) {
        for (j = 0; j < 8; j++) {
            binary[binaryIndex++] = (bytes[i+8] >> j) & 1;
            // Retrieve the byte when we reach the end of the binary representation
            if (binaryIndex == 16) {
                binaryIndex = 8;
                int byte = 0;
                for (int k = 0; k < 8; k++) {
                    byte += binary[k] << k;
                }
                message[messageIndex++] = (char) byte;
            }
        }
    }

    // Null-terminate the message
    message[messageSize] = '\0';

    return message;
}

// Function to hide a message in a byte array
void hideMessage(unsigned char bytes[], char* message) {
    // Get the size of the message and its binary representation
    int messageSize = strlen(message);
    int binarySize = messageSize * 8;

    // Get the binary representation of the message size
    int binaryMessageSize[32];
    decToBinary(messageSize, binaryMessageSize, 32);

    // Replace the first 32 bytes of the byte array with the binary message size
    for (int i = 0; i < 32; i++) {
        int byte = bytes[i];
        byte = (byte & ~1) | binaryMessageSize[i];
        bytes[i] = (unsigned char) byte;
    }

    // Convert the message to a byte array
    int messageIndex = 0;
    int binary[8];
    for (int i = 0; i < messageSize; i++) {
        int byte = (int) message[i];
        decToBinary(byte, binary, 8);
        for (int j = 0; j < 8; j++) {
            int byteIndex = (i * 8) + j + 8;
            int oldByte = bytes[byteIndex];
            oldByte = (oldByte & ~1) | binary[j];
            bytes[byteIndex] = (unsigned char) oldByte;
        }
    }
}

int main() {
    // Open the image file
    FILE* filePointer;
    filePointer = fopen("image.bmp", "rb");
    if (filePointer == NULL) {
        printf("Error: Unable to open image file.\n");
        return 0;
    }

    // Get the size of the file and allocate memory for the byte array
    fseek(filePointer, 0, SEEK_END);
    int fileSize = ftell(filePointer);
    unsigned char* bytes = (unsigned char*) malloc(fileSize * sizeof(unsigned char));
    fseek(filePointer, 0, SEEK_SET);

    // Copy the file contents to the byte array
    fread(bytes, sizeof(unsigned char), fileSize, filePointer);
    fclose(filePointer);

    // Retrieve the message hidden in the byte array
    char* message = retrieveMessage(bytes, fileSize);

    // Print the message hidden in the image
    printf("Message: %s\n", message);

    // Hide a new message in the byte array
    char* newMessage = "This is a secret message hidden in an image.";
    hideMessage(bytes, newMessage);

    // Write the modified byte array to the file
    filePointer = fopen("image_stego.bmp", "wb");
    if (filePointer == NULL) {
        printf("Error: Unable to open output file.\n");
        return 0;
    }
    fwrite(bytes, sizeof(unsigned char), fileSize, filePointer);
    fclose(filePointer);

    // Free memory
    free(bytes);
    free(message);

    return 0;
}