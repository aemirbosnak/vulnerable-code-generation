//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMPInfoHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;
#pragma pack(pop)

// Function for checking if the BMP format is valid
int isValidBMP(BMPHeader *header) {
    if (header->type != 0x4D42) { // 'BM'
        printf("Not a valid BMP file!\n");
        return 0;
    }
    return 1;
}

// Function to hide a message in the BMP image
void hideMessage(const char *message, const char *inputFile, const char *outputFile) {
    FILE *bmpFile = fopen(inputFile, "rb+");
    if (!bmpFile) {
        perror("Unable to open input BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);
    
    if (!isValidBMP(&bmpHeader)) {
        fclose(bmpFile);
        return;
    }

    // Seek to pixel data location
    fseek(bmpFile, bmpHeader.offset, SEEK_SET);
    
    // Calculate message length
    size_t msgLen = strlen(message);
    unsigned char *msgBits = (unsigned char*)message;

    // Hide the message into the pixel data
    for (size_t i = 0; i < msgLen; ++i) {
        // Process each character bit by bit
        for (int bit = 0; bit < 8; ++bit) {
            // Read a pixel
            RGB pixel;
            fread(&pixel, sizeof(RGB), 1, bmpFile);
            
            // Modify the least significant bit of the blue component
            pixel.blue = (pixel.blue & ~1) | ((msgBits[i] >> (7 - bit)) & 1);
            
            // Write the modified pixel back
            fseek(bmpFile, -sizeof(RGB), SEEK_CUR);
            fwrite(&pixel, sizeof(RGB), 1, bmpFile);
        }
    }

    // Write the modified image to a new file
    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        perror("Unable to create output BMP file");
        fclose(bmpFile);
        return;
    }

    // Go to the beginning of the BMP file
    fseek(bmpFile, 0, SEEK_SET);
    
    // Copy the entire BMP file content to the output file
    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), bmpFile)) > 0) {
        fwrite(buffer, 1, bytes, outFile);
    }

    fclose(bmpFile);
    fclose(outFile);
    printf("Message hidden and output BMP created successfully!\n");
}

// Function to retrieve the hidden message from the BMP image
void retrieveMessage(const char *inputFile) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (!bmpFile) {
        perror("Unable to open BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);
    
    if (!isValidBMP(&bmpHeader)) {
        fclose(bmpFile);
        return;
    }

    // Seek to pixel data location
    fseek(bmpFile, bmpHeader.offset, SEEK_SET);
    
    unsigned char message[1024];
    size_t msgIdx = 0;

    // Retrieve the hidden message
    while (msgIdx < sizeof(message) && !feof(bmpFile)) {
        unsigned char ch = 0;
        for (int bit = 0; bit < 8; ++bit) {
            RGB pixel;
            fread(&pixel, sizeof(RGB), 1, bmpFile);
            ch |= ((pixel.blue & 1) << (7 - bit));
        }
        if (ch == 0) break; // Null character indicates end of message
        message[msgIdx++] = ch;
    }

    message[msgIdx] = '\0'; // Null-terminate the string
    fclose(bmpFile);
    printf("Retrieved message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s hide <input_bmp> <output_bmp> <message>\n", argv[0]);
        fprintf(stderr, "       %s retrieve <input_bmp>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessage(argv[4], argv[2], argv[3]);
    } else if (strcmp(argv[1], "retrieve") == 0) {
        retrieveMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'hide' or 'retrieve'.\n");
    }

    return 0;
}