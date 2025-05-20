//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char header[54];
    unsigned int width;
    unsigned int height;
    unsigned short bitsPerPixel;
} BMPHeader;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;
#pragma pack(pop)

void setLSB(unsigned char *byte, unsigned char bit) {
    // Set the least significant bit of byte to bit
    if (bit == 1) {
        *byte |= 1;  // Set LSB to 1
    } else {
        *byte &= ~1; // Set LSB to 0
    }
}

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inFile = fopen(inputImage, "rb");
    if (!inFile) {
        fprintf(stderr, "Cannot open input image file.\n");
        exit(1);
    }
    
    FILE *outFile = fopen(outputImage, "wb");
    if (!outFile) {
        fclose(inFile);
        fprintf(stderr, "Cannot open output image file.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    
    // Copy header
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    
    // Calculate the number of pixels
    unsigned int pixelCount = bmpHeader.width * bmpHeader.height;
    Pixel *pixels = (Pixel *)malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, inFile);
    
    // Determine the message length and ensure it fits
    int messageLength = strlen(message);
    if (messageLength * 8 > pixelCount * 3) {
        fprintf(stderr, "Message is too long to fit in the image.\n");
        fclose(inFile);
        fclose(outFile);
        free(pixels);
        exit(1);
    }
    
    // Embed the message into the LSB of the image pixels
    for (int i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            unsigned char currentBit = (message[i] >> (7 - bit)) & 1;
            // Embed the bit into the pixel
            int pixelIndex = (i * 8 + bit);
            if (pixelIndex < pixelCount) {
                setLSB(&pixels[pixelIndex].r, currentBit);
            }
        }
    }
    
    // Write the modified pixels to the output image file
    fwrite(pixels, sizeof(Pixel), pixelCount, outFile);

    // Clean up
    free(pixels);
    fclose(inFile);
    fclose(outFile);
    printf("Message embedded successfully!\n");
}

void extractMessage(const char *inputImage, char *outputMessage, int maxLength) {
    FILE *inFile = fopen(inputImage, "rb");
    if (!inFile) {
        fprintf(stderr, "Cannot open input image file.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);
    
    // Calculate the number of pixels
    unsigned int pixelCount = bmpHeader.width * bmpHeader.height;
    Pixel *pixels = (Pixel *)malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, inFile);
    
    // Extract the message from LSBs
    int messageIndex = 0;
    for (int i = 0; i < pixelCount && messageIndex < maxLength; i++) {
        unsigned char currentChar = 0;
        for (int bit = 0; bit < 8; bit++) {
            currentChar <<= 1;
            currentChar |= (pixels[i].r & 1); // Get LSB from red channel
        }
        if (currentChar == '\0') {
            break;  // Stop if we reach null terminator
        }
        outputMessage[messageIndex++] = currentChar;
    }

    outputMessage[messageIndex] = '\0'; // Null-terminate the output message
    // Clean up
    free(pixels);
    fclose(inFile);
}

int main() {
    // Define file names and message
    const char *inputImage = "input.bmp";
    const char *outputImage = "output.bmp";
    const char *message = "Hello, Steganography!";

    // Embed the message
    embedMessage(inputImage, outputImage, message);

    // Prepare to extract message
    char extractedMsg[100];
    extractMessage(outputImage, extractedMsg, sizeof(extractedMsg));

    printf("Extracted Message: %s\n", extractedMsg);

    return 0;
}