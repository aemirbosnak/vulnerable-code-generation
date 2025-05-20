//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1) // Ensure structures are packed with no padding

// BMP file header structure
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPFileHeader;

// BMP info header structure
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

void embedMessage(const char *imagePath, const char *message, const char *outputPath);
void extractMessage(const char *imagePath);

int main() {
    char imagePath[100], message[256], outputPath[100];
    int choice;

    printf("Welcome to the Creative Image Steganography Program!\n");
    printf("Choose an option:\n");
    printf("1. Embed a Message into an Image\n");
    printf("2. Extract a Message from an Image\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    if (choice == 1) {
        printf("Enter the input BMP image path: ");
        fgets(imagePath, sizeof(imagePath), stdin);
        strtok(imagePath, "\n"); // Remove newline character

        printf("Enter the secret message (max 255 characters): ");
        fgets(message, sizeof(message), stdin);
        strtok(message, "\n"); // Remove newline character

        printf("Enter the output BMP image path: ");
        fgets(outputPath, sizeof(outputPath), stdin);
        strtok(outputPath, "\n"); // Remove newline character

        embedMessage(imagePath, message, outputPath);
        printf("Your message has been successfully embedded in the image!\n");

    } else if (choice == 2) {
        printf("Enter the BMP image path to extract message from: ");
        fgets(imagePath, sizeof(imagePath), stdin);
        strtok(imagePath, "\n"); // Remove newline character

        extractMessage(imagePath);
    } else {
        printf("Invalid choice. Please run the program again.\n");
    }

    return 0;
}

void embedMessage(const char *imagePath, const char *message, const char *outputPath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        perror("Could not open image file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, imageFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    // Check if the image is 24-bit
    if (infoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(imageFile);
        return;
    }

    // Calculate pixel array size
    int pixelArraySize = fileHeader.bfSize - fileHeader.bfOffBits;

    // Allocate memory for pixel data
    unsigned char *pixelData = (unsigned char *)malloc(pixelArraySize);
    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), pixelArraySize, imageFile);
    fclose(imageFile);

    // Append null character to the message
    char *messageWithDelimiter = (char *)malloc(strlen(message) + 2);
    sprintf(messageWithDelimiter, "%s~", message); // Use ~ as delimiter

    int messageLength = strlen(messageWithDelimiter);
    for (int i = 0; i < messageLength && i < pixelArraySize; i += 3) {
        pixelData[i] = (pixelData[i] & 0xFE) | ((messageWithDelimiter[i / 3] & 0x1) ? 0x01 : 0x00);
    }

    // Write modified pixel data to output image
    FILE *outputFile = fopen(outputPath, "wb");
    if (!outputFile) {
        perror("Could not open output file");
        free(pixelData);
        free(messageWithDelimiter);
        exit(EXIT_FAILURE);
    }

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, outputFile);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(pixelData, sizeof(unsigned char), pixelArraySize, outputFile);

    free(pixelData);
    free(messageWithDelimiter);
    fclose(outputFile);
}

void extractMessage(const char *imagePath) {
    FILE *imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        perror("Could not open image file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, imageFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, imageFile);

    if (infoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(imageFile);
        return;
    }

    int pixelArraySize = fileHeader.bfSize - fileHeader.bfOffBits;
    unsigned char *pixelData = (unsigned char *)malloc(pixelArraySize);
    fseek(imageFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), pixelArraySize, imageFile);
    fclose(imageFile);

    char extractedMessage[256] = "";
    int j = 0;
    for (int i = 0; i < pixelArraySize && j < 255; i += 3) {
        extractedMessage[j++] = ((pixelData[i] & 0x01) ? '1' : '0');
        if (extractedMessage[j - 1] == '~') {
            break;
        }
    }
    extractedMessage[j] = '\0';

    printf("The extracted message is: %s\n", extractedMessage);
    free(pixelData);
}