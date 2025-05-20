//FormAI DATASET v1.0 Category: Image Steganography ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54
#define BYTE_SIZE 8

int readInt(char *arr) {
    return ((int) arr[3] << 24) | ((int) arr[2] << 16) | ((int) arr[1] << 8) | (int) arr[0];
}

void writeInt(int x, FILE *fp) {
    fputc((char) (x & 0xff), fp);
    fputc((char) ((x >> 8) & 0xff), fp);
    fputc((char) ((x >> 16) & 0xff), fp);
    fputc((char) ((x >> 24) & 0xff), fp);
}

int getBit(char byte, int index) {
    return (byte >> index) & 0x01;
}

void writeBit(char *byte, int index, int value) {
    if (value == 1) {
        *byte |= (1 << index);
    } else {
        *byte &= ~(1 << index);
    }
}

void hideMessage(char *message, char *fileName) {
    FILE *imageFile = fopen(fileName, "rb+");
    if (!imageFile) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Retrieve file size
    fseek(imageFile, 0L, SEEK_END);
    long int fileSize = ftell(imageFile);
    fseek(imageFile, 0L, SEEK_SET);

    // Read header
    char *header = (char *) malloc(HEADER_SIZE * sizeof(char));
    fread(header, sizeof(char), HEADER_SIZE, imageFile);

    // Read image bytes
    char *bytes = (char *) malloc((fileSize - HEADER_SIZE) * sizeof(char));
    fread(bytes, sizeof(char), fileSize - HEADER_SIZE, imageFile);

    // Get length of message in bits
    int messageLength = strlen(message) * BYTE_SIZE;

    // Check if message can fit in image
    if (messageLength > (fileSize - HEADER_SIZE) * BYTE_SIZE) {
        printf("Error: Message is too long for the selected image.\n");
        return;
    }

    // Write message size to header
    writeInt(messageLength, imageFile);

    // Iterate through message bytes
    for (int i = 0; i < strlen(message); i++) {
        char messageByte = message[i];

        // Iterate through message byte's bits
        for (int j = BYTE_SIZE - 1; j >= 0; j--) {
            int bit = getBit(messageByte, j);
            int index = (i * BYTE_SIZE) + BYTE_SIZE - j - 1;

            if (index >= messageLength) {
                break;
            }

            char *bytePtr = &bytes[index / BYTE_SIZE];
            writeBit(bytePtr, index % BYTE_SIZE, bit);
        }
    }

    // Write modified bytes to image
    fseek(imageFile, HEADER_SIZE, SEEK_SET);
    fwrite(bytes, sizeof(char), fileSize - HEADER_SIZE, imageFile);

    fclose(imageFile);
    free(header);
    free(bytes);
}

char *retrieveMessage(char *fileName) {
    FILE *imageFile = fopen(fileName, "rb");
    if (!imageFile) {
        printf("Error: Could not open file.\n");
        return NULL;
    }

    // Retrieve file size
    fseek(imageFile, 0L, SEEK_END);
    long int fileSize = ftell(imageFile);
    fseek(imageFile, 0L, SEEK_SET);

    // Read header
    char *header = (char *) malloc(HEADER_SIZE * sizeof(char));
    fread(header, sizeof(char), HEADER_SIZE, imageFile);

    // Retrieve message length from header
    int messageLength = readInt(header + 34);

    // Read image bytes
    char *bytes = (char *) malloc((fileSize - HEADER_SIZE) * sizeof(char));
    fread(bytes, sizeof(char), fileSize - HEADER_SIZE, imageFile);

    // Extract message bits
    char *message = (char *) malloc((messageLength / BYTE_SIZE) * sizeof(char));
    for (int i = 0; i < messageLength / BYTE_SIZE; i++) {
        char messageByte = 0;

        for (int j = BYTE_SIZE - 1; j >= 0; j--) {
            int bit = getBit(bytes[i * BYTE_SIZE + (BYTE_SIZE - j - 1)], 0);
            writeBit(&messageByte, j, bit);
        }

        message[i] = messageByte;
    }

    fclose(imageFile);
    free(header);
    free(bytes);

    return message;
}

int main() {
    char message[] = "This is a secret message.";
    char fileName[] = "image.bmp";

    hideMessage(message, fileName);

    char *retrievedMessage = retrieveMessage(fileName);
    printf("%s\n", retrievedMessage);

    free(retrievedMessage);

    return 0;
}