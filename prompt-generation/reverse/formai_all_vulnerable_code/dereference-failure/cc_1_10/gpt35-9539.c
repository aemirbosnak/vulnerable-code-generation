//FormAI DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_MSG_LENGTH 100
#define ENCODED_TXT_FILE "encoded.txt"
#define DECODED_TXT_FILE "decoded.txt"

// Function to get the bit value of a given byte
unsigned char getBit(unsigned char byte, int bitIndex) {
    return (byte >> bitIndex) & 1;
}

// Function to set the bit value of a given byte
void setBit(unsigned char* byte, int bitIndex, int bitValue) {
    if (bitValue == 1) {
        *byte |= (1 << bitIndex);
    } else {
        *byte &= ~(1 << bitIndex);
    }
}

// Function to encode the given message in the given image file
int encode(char* fileName, char* message) {
    FILE* imgFile = fopen(fileName, "rb");
    if (imgFile == NULL) {
        printf("Error: Could not open image file.\n");
        return -1;
    }

    // Get the length of the message
    int msgLen = strlen(message);
    if (msgLen >= MAX_MSG_LENGTH) {
        printf("Error: Message is too long.\n");
        return -1;
    }

    // Create a new file to store the encoded image
    char newFileName[MAX_FILENAME_LENGTH];
    strcpy(newFileName, "encoded_");
    strcat(newFileName, fileName);
    FILE* encodedFile = fopen(newFileName, "wb");
    if (encodedFile == NULL) {
        printf("Error: Could not create encoded image file.\n");
        return -1;
    }

    // Read and copy the bitmap file header
    unsigned char bitmapFileHeader[14];
    fread(bitmapFileHeader, sizeof(unsigned char), 14, imgFile);
    fwrite(bitmapFileHeader, sizeof(unsigned char), 14, encodedFile);

    // Read and copy the dib header
    unsigned char dibHeader[40];
    fread(dibHeader, sizeof(unsigned char), 40, imgFile);
    fwrite(dibHeader, sizeof(unsigned char), 40, encodedFile);

    // Move the cursor to the pixel data
    fseek(imgFile, *(int*)&bitmapFileHeader[10], SEEK_SET);

    // Copy the pixel data and modify the least significant bit of each byte to encode the message
    unsigned char pixelData;
    int bitIndex = 0, msgIndex = 0;
    while(fread(&pixelData, sizeof(unsigned char), 1, imgFile) == 1) {
        if (msgIndex < msgLen) {
            setBit(&pixelData, bitIndex, getBit(message[msgIndex], bitIndex));
            bitIndex = (bitIndex + 1) % 8;
            if (bitIndex == 0) {
                msgIndex++;
            }
        }
        fwrite(&pixelData, sizeof(unsigned char), 1, encodedFile);
    }

    // Copy the rest of the image data
    unsigned char restData;
    while(fread(&restData, sizeof(unsigned char), 1, imgFile) == 1) {
        fwrite(&restData, sizeof(unsigned char), 1, encodedFile);
    }

    // Close the files
    fclose(imgFile);
    fclose(encodedFile);

    printf("Successfully encoded message in %s.\n", fileName);

    return 0;
}

// Function to decode the encoded message from the given image file
int decode(char* fileName) {
    FILE* imgFile = fopen(fileName, "rb");
    if (imgFile == NULL) {
        printf("Error: Could not open image file.\n");
        return -1;
    }

    // Create a new file to store the decoded message
    FILE* decodedFile = fopen(DECODED_TXT_FILE, "w");
    if (decodedFile == NULL) {
        printf("Error: Could not create decoded text file.\n");
        return -1;
    }

    // Read the bitmap file header
    unsigned char bitmapFileHeader[14];
    fread(bitmapFileHeader, sizeof(unsigned char), 14, imgFile);

    // Read the dib header
    unsigned char dibHeader[40];
    fread(dibHeader, sizeof(unsigned char), 40, imgFile);

    // Move the cursor to the pixel data
    fseek(imgFile, *(int*)&bitmapFileHeader[10], SEEK_SET);

    // Decode the message from the least significant bit of each byte
    unsigned char pixelData, msgChar = 0;
    int bitIndex = 0;
    while(fread(&pixelData, sizeof(unsigned char), 1, imgFile) == 1) {
        if (bitIndex == 8) {
            bitIndex = 0;
            fwrite(&msgChar, sizeof(unsigned char), 1, decodedFile);
            msgChar = 0;
        }
        setBit(&msgChar, bitIndex, getBit(pixelData, 0));
        bitIndex++;
    }

    // Close the files
    fclose(imgFile);
    fclose(decodedFile);

    printf("Successfully decoded message from %s.\n", fileName);
    printf("Message:\n");
    char cmd[MAX_MSG_LENGTH + 10];
    sprintf(cmd, "cat %s", DECODED_TXT_FILE);
    system(cmd);

    return 0;
}

int main() {
    char fileName[MAX_FILENAME_LENGTH], message[MAX_MSG_LENGTH];
    int choice;

    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the message to be encoded: ");
    getchar();
    fgets(message, MAX_MSG_LENGTH, stdin);

    printf("\n1. Encode\n2. Decode\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            encode(fileName, message);
            break;
        case 2:
            decode(fileName);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}