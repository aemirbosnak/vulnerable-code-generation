//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
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

void embedMessage(char *imagePath, char *message) {
    FILE *image = fopen(imagePath, "rb+");
    if (!image) {
        perror("Failed to open the image file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, image);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, image);

    // Move to pixel data
    fseek(image, bmpHeader.bfOffBits, SEEK_SET);

    int messageLength = strlen(message);
    if (messageLength > bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3) {
        printf("Message is too long to hide in this image.\n");
        fclose(image);
        return;
    }

    // Embed message length at the start
    for (int i = 0; i < messageLength; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, image);
        
        // Alter the least significant bit to embed the message
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 7) & 0x01);
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 6) & 0x01);
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 5) & 0x01);
        
        // Move back to write modified pixel
        fseek(image, -3, SEEK_CUR);
        fwrite(pixel, sizeof(unsigned char), 3, image);
    }

    fclose(image);
    printf("Message embedded successfully!\n");
}

void extractMessage(char *imagePath) {
    FILE *image = fopen(imagePath, "rb");
    if (!image) {
        perror("Failed to open the image file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, image);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, image);

    // Move to pixel data
    fseek(image, bmpHeader.bfOffBits, SEEK_SET);

    int messageLength = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3 / 3; // assuming max size
    char *message = (char *)malloc(messageLength + 1);
    if (!message) {
        perror("Memory allocation failed");
        fclose(image);
        return;
    }
    
    for (int i = 0; i < messageLength; i++) {
        unsigned char pixel[3];
        fread(pixel, sizeof(unsigned char), 3, image);
        
        // Read the least significant bits
        message[i] = ((pixel[0] & 0x01) << 7) | ((pixel[1] & 0x01) << 6) | ((pixel[2] & 0x01) << 5);
    }
    
    message[messageLength] = '\0';
    printf("Extracted message: %s\n", message);
    
    free(message);
    fclose(image);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <embed/extract> <image_path> [message]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 4) {
            printf("To embed a message, provide the message as the third argument.\n");
            return 1;
        }
        embedMessage(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid command. Use 'embed' or 'extract'.\n");
    }

    return 0;
}