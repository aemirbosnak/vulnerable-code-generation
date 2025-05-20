//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;      // Magic number for BMP files
    unsigned int bfSize;       // Size of the file in bytes
    unsigned short bfReserved1; 
    unsigned short bfReserved2; 
    unsigned int bfOffBits;    // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;       // Size of BITMAPINFOHEADER
    int biWidth;               // Width of the image
    int biHeight;              // Height of the image
    unsigned short biPlanes;   
    unsigned short biBitCount;  
    unsigned int biCompression; 
    unsigned int biSizeImage;   
    int biXPelsPerMeter;        
    int biYPelsPerMeter;        
    unsigned int biClrUsed;     
    unsigned int biClrImportant; 
} BMPInfoHeader;
#pragma pack(pop)

void encodeMessage(const char *message, const char *inputImage, const char *outputImage) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        printf("Could not open input image file.\n");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpHeader.bfType != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    // Calculate the size of the message
    size_t messageLength = strlen(message);
    int maxMessageSize = (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3) / 8;
    if (messageLength > maxMessageSize) {
        printf("Message is too long for the image capacity.\n");
        fclose(inputFile);
        return;
    }

    unsigned char *imageData = malloc(bmpInfoHeader.biSizeImage);
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(imageData, bmpInfoHeader.biSizeImage, 1, inputFile);
    fclose(inputFile);

    // Encode the message by altering the least significant bits
    for (size_t i = 0; i < messageLength; ++i) {
        for (int j = 0; j < 8; ++j) {
            imageData[i * 8 + j] = (imageData[i * 8 + j] & 0xFE) | ((message[i] >> (7 - j)) & 0x01);
        }
    }

    // Write the modified image back to a new file
    FILE *outputFile = fopen(outputImage, "wb");
    if (!outputFile) {
        printf("Could not open output image file.\n");
        free(imageData);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(imageData, bmpInfoHeader.biSizeImage, 1, outputFile);
    fclose(outputFile);
    free(imageData);
    printf("Message encoded successfully!\n");
}

void decodeMessage(const char *inputImage) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        printf("Could not open input image file.\n");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpHeader.bfType != 0x4D42) {
        printf("Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    unsigned char *imageData = malloc(bmpInfoHeader.biSizeImage);
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);
    fread(imageData, bmpInfoHeader.biSizeImage, 1, inputFile);
    fclose(inputFile);

    // Decode the message from the least significant bits
    char message[256] = {0}; // Assume max message size is 256 bytes
    for (size_t i = 0; i < 256; ++i) {
        for (int j = 0; j < 8; ++j) {
            message[i] = (message[i] << 1) | (imageData[i * 8 + j] & 0x01);
        }
        if (message[i] == '\0') break; // End of message
    }

    printf("Decoded message: %s\n", message);
    free(imageData);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s encode|decode <input_image> <output_image|message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encodeMessage(argv[3], argv[2], "output.bmp");
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessage(argv[2]);
    } else {
        printf("Invalid command. Use 'encode' or 'decode'.\n");
    }

    return 0;
}