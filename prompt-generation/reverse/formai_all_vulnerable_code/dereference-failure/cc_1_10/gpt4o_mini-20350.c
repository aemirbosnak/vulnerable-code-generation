//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

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
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

void hide_message(const char *imagePath, const char *message, const char *outputPath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        printf("Oh no! Could not open the image file %s.\n", imagePath);
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    
    if (bmpHeader.type != 0x4D42) {
        printf("Oops! Only BMP files are supported.\n");
        fclose(inputFile);
        return;
    }

    int messageLength = strlen(message);
    int pixelCount = (bmpInfoHeader.width * bmpInfoHeader.height);
    if (pixelCount < messageLength + 1) {
        printf("Yikes! Image too small to hide the message.\n");
        fclose(inputFile);
        return;
    }

    Pixel *pixels = malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, inputFile);
    fclose(inputFile);
    
    for (int i = 0; i < messageLength; i++) {
        pixels[i].red = (pixels[i].red & ~1) | (message[i] & 1);
        pixels[i].green = (pixels[i].green & ~1) | ((message[i] >> 1) & 1);
        pixels[i].blue = (pixels[i].blue & ~1) | ((message[i] >> 2) & 1);
    }
    
    // Hide the null terminator
    pixels[messageLength].red = (pixels[messageLength].red & ~1) | (0 & 1);
    pixels[messageLength].green = (pixels[messageLength].green & ~1) | ((0 >> 1) & 1);
    pixels[messageLength].blue = (pixels[messageLength].blue & ~1) | ((0 >> 2) & 1);
    
    FILE *outputFile = fopen(outputPath, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(pixels, sizeof(Pixel), pixelCount, outputFile);
    
    printf("Yay! Your message has been hidden in the image!\n");
    free(pixels);
    fclose(outputFile);
}

void reveal_message(const char *imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        printf("Oh no! Could not open the image file %s.\n", imagePath);
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    
    if (bmpHeader.type != 0x4D42) {
        printf("Oops! Only BMP files are supported.\n");
        fclose(inputFile);
        return;
    }

    int pixelCount = (bmpInfoHeader.width * bmpInfoHeader.height);
    Pixel *pixels = malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, inputFile);
    fclose(inputFile);

    char message[100];
    int index = 0;

    // Retrieve the message bit by bit.
    while (index < sizeof(message) - 1) {
        char ch = 0;
        ch |= (pixels[index].red & 1);
        ch |= ((pixels[index].green & 1) << 1);
        ch |= ((pixels[index].blue & 1) << 2);

        if (ch == '\0') break;
        message[index] = ch;
        index++;
    }
    message[index] = '\0';

    printf("Here is the hidden message: \"%s\"\n", message);
    free(pixels);
}

int main() {
    printf("🎉 Welcome to Image Steganography! 🎉\n");
    int choice;
    char imagePath[100], outputPath[100], message[100];

    printf("What would you like to do?\n");
    printf("1. Hide a message in an image\n");
    printf("2. Reveal a message from an image\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // To consume the newline character

    if (choice == 1) {
        printf("Enter the path of the image file: ");
        fgets(imagePath, sizeof(imagePath), stdin);
        strtok(imagePath, "\n"); // Remove the newline character

        printf("Enter your message (max 99 characters): ");
        fgets(message, sizeof(message), stdin);
        strtok(message, "\n"); // Remove the newline character

        printf("Enter the path for output image: ");
        fgets(outputPath, sizeof(outputPath), stdin);
        strtok(outputPath, "\n"); // Remove the newline character

        hide_message(imagePath, message, outputPath);
    } else if (choice == 2) {
        printf("Enter the path of the image file to reveal the message: ");
        fgets(imagePath, sizeof(imagePath), stdin);
        strtok(imagePath, "\n"); // Remove the newline character

        reveal_message(imagePath);
    } else {
        printf("Oops! Please choose a valid option.\n");
    }

    printf("🎉 Thank you for using the Steganography Tool! 🎉\n");
    return 0;
}