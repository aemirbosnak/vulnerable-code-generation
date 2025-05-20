//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54

void embedMessage(const char *imagePath, const char *message, const char *outputPath) {
    FILE *image = fopen(imagePath, "rb");
    if (image == NULL) {
        fprintf(stderr, "Could not open input image file.\n");
        return;
    }

    FILE *outputImage = fopen(outputPath, "wb");
    if (outputImage == NULL) {
        fclose(image);
        fprintf(stderr, "Could not open output image file.\n");
        return;
    }

    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, image);
    fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, outputImage);

    // Get the size of the message and append a terminating null character
    size_t messageLength = strlen(message);
    unsigned char *msgWithTerminator = malloc(messageLength + 1);
    strcpy((char *)msgWithTerminator, message);
    msgWithTerminator[messageLength] = '\0'; // append null terminate

    // Embed the message into the image
    size_t pixelsToModify = (messageLength + 1) * 8; // including null terminator
    unsigned char byte;
    size_t pixelCounter = 0;
    
    // Loop until we've embedded all bits of the message
    for (size_t i = 0; i < pixelsToModify; ++i) {
        size_t byteIndex = i / 8;
        size_t bitIndex = i % 8;

        if (byteIndex >= (messageLength + 1)) break; // No more message bits

        byte = msgWithTerminator[byteIndex] & (1 << (7 - bitIndex));
        
        // Determine the pixel to modify
        fseek(image, BMP_HEADER_SIZE + pixelCounter * 3, SEEK_SET); // Seeking to the pixel
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, image);

        // Modify the LSB of the blue component
        if (byte) {
            pixel[0] |= 1; // Set LSB to 1
        } else {
            pixel[0] &= 0xFE; // Set LSB to 0
        }

        fseek(outputImage, BMP_HEADER_SIZE + pixelCounter * 3, SEEK_SET); // Seek to write back
        fwrite(pixel, sizeof(unsigned char), 3, outputImage);
        pixelCounter++;
    }

    free(msgWithTerminator);
    fclose(image);
    fclose(outputImage);

    printf("Message embedded successfully into %s\n", outputPath);
}

void extractMessage(const char *imagePath) {
    FILE *image = fopen(imagePath, "rb");
    if (image == NULL) {
        fprintf(stderr, "Could not open input image file.\n");
        return;
    }

    unsigned char header[BMP_HEADER_SIZE];
    fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, image);

    unsigned char message[1024]; // buffer to hold the message
    size_t index = 0;

    // Read pixels from the image to extract the message
    for (size_t pixelCounter = 0; pixelCounter < 1024 * 8; ++pixelCounter) {
        fseek(image, BMP_HEADER_SIZE + pixelCounter * 3, SEEK_SET);
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, image);
        
        // Get the LSB of the blue component
        if (pixel[0] & 1) {
            message[index / 8] |= (1 << (7 - (index % 8)));
        }
        
        index++;

        // Stop if we hit the null terminator
        if (index % 8 == 0 && message[index / 8 - 1] == '\0') break;
    }

    fclose(image);

    printf("Extracted Message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image.bmp> <message> <output.bmp>\n", argv[0]);
        return 1;
    }

    embedMessage(argv[1], argv[2], argv[3]);
    extractMessage(argv[3]);
    
    return 0;
}