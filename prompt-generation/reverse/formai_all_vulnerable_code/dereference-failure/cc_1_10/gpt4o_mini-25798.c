//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: brave
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
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;
#pragma pack(pop)

void hideMessage(const char *imagePath, const char *message) {
    FILE *imageFile = fopen(imagePath, "r+b");
    if (!imageFile) {
        perror("Failed to open image file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    // Ensure the image is a 24-bit BMP
    if (bmpHeader.type != 0x4D42 || bmpInfoHeader.bitsPerPixel != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(imageFile);
        return;
    }

    // Calculate the size of the message and ensure it fits
    int messageLength = strlen(message);
    if (messageLength > (bmpInfoHeader.width * bmpInfoHeader.height * 3) / 8) {
        printf("Message is too long to hide in this image.\n");
        fclose(imageFile);
        return;
    }

    // Move to the offset position to begin hiding
    fseek(imageFile, bmpHeader.offset, SEEK_SET);

    // Hide the message in the least significant bits
    for (int i = 0; i < messageLength; i++) {
        unsigned char byte = message[i];
        for (int bit = 0; bit < 8; bit++) {
            unsigned char pixel[3];
            fread(pixel, 3, 1, imageFile); // Read a pixel

            // Replace the least significant bit with the message bit
            pixel[0] = (pixel[0] & 0xFE) | ((byte >> (7 - bit)) & 0x01);

            // Write the modified pixel back
            fseek(imageFile, -3, SEEK_CUR); // Move back to overwrite
            fwrite(pixel, 3, 1, imageFile);
        }
    }

    // Indicate the end of the message with a delimiter (0x00)
    for (int bit = 0; bit < 8; bit++) {
        unsigned char pixel[3];
        fread(pixel, 3, 1, imageFile);

        pixel[0] = (pixel[0] & 0xFE) | ((0x00 >> (7 - bit)) & 0x01);
        fseek(imageFile, -3, SEEK_CUR);
        fwrite(pixel, 3, 1, imageFile);
    }

    printf("Message hidden successfully!\n");
    fclose(imageFile);
}

void extractMessage(const char *imagePath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        perror("Failed to open image file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, imageFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    // Ensure the image is a 24-bit BMP
    if (bmpHeader.type != 0x4D42 || bmpInfoHeader.bitsPerPixel != 24) {
        printf("Only 24-bit BMP files are supported.\n");
        fclose(imageFile);
        return;
    }

    // Move to the pixel data
    fseek(imageFile, bmpHeader.offset, SEEK_SET);

    char message[256];
    int messageLength = 0;

    while (messageLength < 255) {
        char byte = 0;

        // Read 8 bits for the next character
        for (int bit = 0; bit < 8; bit++) {
            unsigned char pixel[3];
            fread(pixel, 3, 1, imageFile);

            // Extract the least significant bit
            byte |= ((pixel[0] & 0x01) << (7 - bit));
        }

        if (byte == 0) {
            break; // End of message
        }

        message[messageLength++] = byte;
    }
    message[messageLength] = '\0';

    printf("Extracted message: %s\n", message);
    fclose(imageFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s hide|extract image.bmp [message]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "hide") == 0) {
        if (argc < 4) {
            printf("Please provide a message to hide.\n");
            return 1;
        }
        hideMessage(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid command. Use 'hide' or 'extract'.\n");
        return 1;
    }

    return 0;
}