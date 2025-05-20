//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
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
} BitmapFileHeader;

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
} BitmapInfoHeader;
#pragma pack(pop)

void hideMessageInImage(const char *imagePath, const char *message, const char *outputImage) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        printf("Error: Cannot open the input image file.\n");
        return;
    }

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BitmapFileHeader), 1, inputFile);
    fread(&infoHeader, sizeof(BitmapInfoHeader), 1, inputFile);

    if (fileHeader.bfType != 0x4D42) {
        printf("Error: Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    // Calculate the size of the message and ensure there's enough space in the image
    size_t messageLength = strlen(message);
    size_t maxLength = (infoHeader.biWidth * infoHeader.biHeight * infoHeader.biBitCount / 8) - 54; // exclude headers

    if (messageLength > maxLength) {
        printf("Error: Message is too long to fit in the image.\n");
        fclose(inputFile);
        return;
    }

    // Create a buffer for the image data
    unsigned char *imageData = (unsigned char *)malloc(infoHeader.biSizeImage);
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, sizeof(unsigned char), infoHeader.biSizeImage, inputFile);
    fclose(inputFile);

    // Hide the message in the image data (least significant bit method)
    for (size_t i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            imageData[i * 8 + j] = (imageData[i * 8 + j] & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }

    // Append a delimiter at the end of the message
    for (int j = 0; j < 8; j++) {
        imageData[messageLength * 8 + j] = (imageData[messageLength * 8 + j] & ~1) | ((0 >> (7 - j)) & 1);
    }

    // Write the modified image data to the output file
    FILE *outputFile = fopen(outputImage, "wb");
    if (!outputFile) {
        printf("Error: Cannot open the output image file.\n");
        free(imageData);
        return;
    }

    fwrite(&fileHeader, sizeof(BitmapFileHeader), 1, outputFile);
    fwrite(&infoHeader, sizeof(BitmapInfoHeader), 1, outputFile);
    fwrite(imageData, sizeof(unsigned char), infoHeader.biSizeImage, outputFile);
    
    fclose(outputFile);
    free(imageData);
    printf("Message hidden successfully in %s\n", outputImage);
}

void revealMessageInImage(const char *imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        printf("Error: Cannot open the input image file.\n");
        return;
    }

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BitmapFileHeader), 1, inputFile);
    fread(&infoHeader, sizeof(BitmapInfoHeader), 1, inputFile);

    if (fileHeader.bfType != 0x4D42) {
        printf("Error: Not a valid BMP file.\n");
        fclose(inputFile);
        return;
    }

    unsigned char *imageData = (unsigned char *)malloc(infoHeader.biSizeImage);
    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, sizeof(unsigned char), infoHeader.biSizeImage, inputFile);
    fclose(inputFile);

    printf("Revealed message: ");
    for (size_t i = 0; ; i++) {
        char character = 0;
        for (int j = 0; j < 8; j++) {
            character |= ((imageData[i * 8 + j] & 1) << (7 - j));
        }

        if (character == 0) {
            break; // End of message detected
        }
        
        printf("%c", character);
    }
    printf("\n");

    free(imageData);
}

int main() {
    int choice;
    char imagePath[100];
    char message[100];
    char outputImage[100];

    printf("1. Hide Message in Image\n");
    printf("2. Reveal Message from Image\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    getchar(); // Clear newline character from input buffer

    if (choice == 1) {
        printf("Enter input BMP image path: ");
        fgets(imagePath, 100, stdin);
        strtok(imagePath, "\n"); // Remove the newline character

        printf("Enter message to hide: ");
        fgets(message, 100, stdin);
        strtok(message, "\n");

        printf("Enter output BMP image path: ");
        fgets(outputImage, 100, stdin);
        strtok(outputImage, "\n");

        hideMessageInImage(imagePath, message, outputImage);
    } else if (choice == 2) {
        printf("Enter input BMP image path: ");
        fgets(imagePath, 100, stdin);
        strtok(imagePath, "\n");

        revealMessageInImage(imagePath);
    } else {
        printf("Invalid option!\n");
    }

    return 0;
}