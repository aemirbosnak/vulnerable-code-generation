//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the image header information
#pragma pack(push, 1) // Ensure no padding is added
typedef struct {
    unsigned short bfType;       // Bitmap file type
    unsigned long bfSize;       // Size of the file in bytes
    unsigned short bfReserved1;  // Reserved, must be 0
    unsigned short bfReserved2;  // Reserved, must be 0
    unsigned long bfOffBits;     // Offset to the start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned long biSize;        // Size of the info header
    long biWidth;               // Width of the image
    long biHeight;              // Height of the image
    unsigned short biPlanes;     // Number of color planes, must be 1
    unsigned short biBitCount;   // Number of bits per pixel
    unsigned long biCompression;  // Compression method
    unsigned long biSizeImage;   // Size of the image data
    long biXPelsPerMeter;        // Horizontal resolution
    long biYPelsPerMeter;        // Vertical resolution
    unsigned long biClrUsed;     // Number of colors used
    unsigned long biClrImportant; // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

// Function declarations
void embedMessage(const char *inputFile, const char *outputFile, const char *message);
void extractMessage(const char *inputFile, char *outputMessage, int maxMessageSize);
void writeBMP(const char *filename, BITMAPFILEHEADER bfHeader, BITMAPINFOHEADER biHeader, unsigned char *pixelData);
unsigned char *readBMP(const char *filename, BITMAPFILEHEADER *bfHeader, BITMAPINFOHEADER *biHeader);

int main() {
    char inputFile[256], outputFile[256], message[256];
    int choice;

    printf("Image Steganography Program\n");
    printf("1. Embed Message\n");
    printf("2. Extract Message\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar(); // Clear the newline character from input buffer

    if (choice == 1) {
        printf("Enter input BMP file path: ");
        fgets(inputFile, sizeof(inputFile), stdin);
        inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline
        printf("Enter output BMP file path: ");
        fgets(outputFile, sizeof(outputFile), stdin);
        outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline
        printf("Enter message to embed: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline

        embedMessage(inputFile, outputFile, message);
        printf("Message embedded successfully!\n");
    } else if (choice == 2) {
        printf("Enter input BMP file path: ");
        fgets(inputFile, sizeof(inputFile), stdin);
        inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline
        char extractedMessage[256] = {0};

        extractMessage(inputFile, extractedMessage, sizeof(extractedMessage));
        printf("Extracted Message: %s\n", extractedMessage);
    } else {
        printf("Invalid option selected.\n");
    }

    return 0;
}

// Function to embed a message into the BMP file
void embedMessage(const char *inputFile, const char *outputFile, const char *message) {
    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;
    unsigned char *pixelData = readBMP(inputFile, &bfHeader, &biHeader);

    if (pixelData == NULL) {
        fprintf(stderr, "Error reading BMP file.\n");
        return;
    }

    size_t messageLength = strlen(message);
    if (messageLength > ((bfHeader.bfSize - bfHeader.bfOffBits) / 8) - 1) {
        fprintf(stderr, "Message is too long to embed in this image.\n");
        free(pixelData);
        return;
    }

    // Embed the message in the least significant bits of the pixel data
    for (size_t i = 0; i < messageLength; i++) {
        pixelData[i * 8] = (pixelData[i * 8] & 0xFE) | (message[i] & 0x01); // LSB for character
        for (int j = 1; j < 8; j++) {
            pixelData[i * 8 + j] = (pixelData[i * 8 + j] & 0xFE) | ((message[i] >> j) & 0x01); // LSB for each bit
        }
    }

    // Add a delimiter at the end of the message
    pixelData[messageLength * 8] = '\0';

    writeBMP(outputFile, bfHeader, biHeader, pixelData);
    free(pixelData);
}

// Function to extract the hidden message from the BMP file
void extractMessage(const char *inputFile, char *outputMessage, int maxMessageSize) {
    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;
    unsigned char *pixelData = readBMP(inputFile, &bfHeader, &biHeader);

    if (pixelData == NULL) {
        fprintf(stderr, "Error reading BMP file.\n");
        return;
    }

    size_t i;
    for (i = 0; i < maxMessageSize - 1; i++) {
        unsigned char character = 0;
        for (int j = 0; j < 8; j++) {
            character |= ((pixelData[i * 8 + j] & 0x01) << j); // Extract bits to form character
        }
        outputMessage[i] = character;
        if (character == '\0') break; // End of message
    }
    outputMessage[i] = '\0'; // Null terminate the extracted message
    free(pixelData);
}

// Function to write pixel data and headers back to BMP file
void writeBMP(const char *filename, BITMAPFILEHEADER bfHeader, BITMAPINFOHEADER biHeader, unsigned char *pixelData) {
    FILE *outputFile = fopen(filename, "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        return;
    }

    fwrite(&bfHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&biHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);
    fwrite(pixelData, 1, bfHeader.bfSize - bfHeader.bfOffBits, outputFile);
    fclose(outputFile);
}

// Function to read BMP file headers and pixel data
unsigned char *readBMP(const char *filename, BITMAPFILEHEADER *bfHeader, BITMAPINFOHEADER *biHeader) {
    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return NULL;
    }

    fread(bfHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(biHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    unsigned char *pixelData = (unsigned char *)malloc(bfHeader->bfSize - bfHeader->bfOffBits);
    fseek(inputFile, bfHeader->bfOffBits, SEEK_SET);
    fread(pixelData, 1, bfHeader->bfSize - bfHeader->bfOffBits, inputFile);
    fclose(inputFile);
    return pixelData;
}