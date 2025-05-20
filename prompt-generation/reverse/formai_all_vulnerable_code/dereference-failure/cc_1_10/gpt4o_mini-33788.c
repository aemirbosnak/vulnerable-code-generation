//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void encodeMessage(const char* message, const char* inputImage, const char* outputImage) {
    FILE *inFile = fopen(inputImage, "rb");
    FILE *outFile = fopen(outputImage, "wb");
    
    if (!inFile || !outFile) {
        perror("Error opening file");
        return;
    }
    
    char header[20];
    fgets(header, sizeof(header), inFile); // Read PPM header (P6)
    fprintf(outFile, "%s", header);

    int width, height, maxColor;
    fscanf(inFile, "%d %d %d", &width, &height, &maxColor);
    fprintf(outFile, "%d %d\n%d\n", width, height, maxColor);
    
    // Allocate memory for pixels
    Pixel *pixels = malloc(sizeof(Pixel) * width * height);
    fread(pixels, sizeof(Pixel), width * height, inFile);

    // Encode the message length in the first pixel
    int messageLen = strlen(message);
    pixels[0].r = (pixels[0].r & 0xFE) | ((messageLen >> 0) & 0x01);
    pixels[0].g = (pixels[0].g & 0xFE) | ((messageLen >> 1) & 0x01);
    pixels[0].b = (pixels[0].b & 0xFE) | ((messageLen >> 2) & 0x01);

    for (int i = 0; i < messageLen; ++i) {
        pixels[i + 1].r = (pixels[i + 1].r & 0xFE) | ((message[i] >> 0) & 0x01);
        pixels[i + 1].g = (pixels[i + 1].g & 0xFE) | ((message[i] >> 1) & 0x01);
        pixels[i + 1].b = (pixels[i + 1].b & 0xFE) | ((message[i] >> 2) & 0x01);
    }

    fwrite(pixels, sizeof(Pixel), width * height, outFile);
    
    free(pixels);
    fclose(inFile);
    fclose(outFile);
}

void decodeMessage(const char* inputImage) {
    FILE *inFile = fopen(inputImage, "rb");
    
    if (!inFile) {
        perror("Error opening file");
        return;
    }
    
    char header[20];
    fgets(header, sizeof(header), inFile);
    
    int width, height, maxColor;
    fscanf(inFile, "%d %d %d", &width, &height, &maxColor);
    
    Pixel *pixels = malloc(sizeof(Pixel) * width * height);
    fread(pixels, sizeof(Pixel), width * height, inFile);

    // Extract the message length from the first pixel
    int messageLen = 0;
    messageLen |= (pixels[0].r & 0x01) << 0;
    messageLen |= (pixels[0].g & 0x01) << 1;
    messageLen |= (pixels[0].b & 0x01) << 2;

    // Read the message
    char *message = malloc(messageLen + 1);
    for (int i = 0; i < messageLen; ++i) {
        message[i] = 0;
        message[i] |= (pixels[i + 1].r & 0x01) << 0;
        message[i] |= (pixels[i + 1].g & 0x01) << 1;
        message[i] |= (pixels[i + 1].b & 0x01) << 2;
    }
    message[messageLen] = '\0';
    
    printf("Decoded message: %s\n", message);
    
    free(message);
    free(pixels);
    fclose(inFile);
}

int main() {
    const char* inputImage = "input.ppm";
    const char* outputImage = "output.ppm";
    const char* secretMessage = "Hello, World!";
    
    printf("Encoding message into image...\n");
    encodeMessage(secretMessage, inputImage, outputImage);
    
    printf("Decoding message from image...\n");
    decodeMessage(outputImage);
    
    return 0;
}