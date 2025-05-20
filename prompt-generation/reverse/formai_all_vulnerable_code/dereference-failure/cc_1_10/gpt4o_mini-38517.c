//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: beginner-friendly
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
    int xPelsPerMeter;
    int yPelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

void hideMessageInBMP(const char *inputBMPFile, const char *outputBMPFile, const char *message) {
    FILE *inputFile = fopen(inputBMPFile, "rb");
    if (inputFile == NULL) {
        perror("Unable to open input BMP file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);
    
    if (bmpHeader.type != 0x4D42) {
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Prepare the message
    char *messageWithEnd = (char *)malloc(strlen(message) + 1);
    strcpy(messageWithEnd, message);
    strcat(messageWithEnd, "$"); // Use '$' to denote the end of the message.

    size_t messageLength = strlen(messageWithEnd);
    if (messageLength > (bmpInfoHeader.sizeImage / 3)) {
        fprintf(stderr, "Error: Message is too long for the given BMP file.\n");
        free(messageWithEnd);
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Move to the pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);
    
    unsigned char pixel[3];
    for (size_t i = 0; i < messageLength; i++) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);

        // Modify the least significant bit of the blue channel
        pixel[0] = (pixel[0] & 0xFE) | ((messageWithEnd[i] >> 0) & 0x01);
        pixel[1] = (pixel[1] & 0xFE) | ((messageWithEnd[i] >> 1) & 0x01);
        pixel[2] = (pixel[2] & 0xFE) | ((messageWithEnd[i] >> 2) & 0x01);

        // Write modified pixel back
        fseek(inputFile, -3, SEEK_CUR);
        fwrite(pixel, sizeof(unsigned char), 3, inputFile);
    }

    // Close files
    free(messageWithEnd);
    fclose(inputFile);
    
    // Save the output BMP file
    FILE *outputFile = fopen(outputBMPFile, "wb");
    if (outputFile == NULL) {
        perror("Unable to open output BMP file");
        exit(EXIT_FAILURE);
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);

    // Open the input file again to read pixel data and write to output file
    inputFile = fopen(inputBMPFile, "rb");
    fseek(inputFile, bmpHeader.offset, SEEK_SET);
    unsigned char byte;
    while (fread(&byte, sizeof(unsigned char), 1, inputFile)) {
        fwrite(&byte, sizeof(unsigned char), 1, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void revealMessageInBMP(const char *inputBMPFile) {
    FILE *inputFile = fopen(inputBMPFile, "rb");
    if (inputFile == NULL) {
        perror("Unable to open input BMP file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpHeader.type != 0x4D42) {
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    printf("Hidden message: ");
    
    // Move to the pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);

    unsigned char pixel[3];
    char revealedMessage[256];
    size_t index = 0;

    while (1) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);
        char character = 0;

        // Extract the least significant bits
        character |= (pixel[0] & 0x01) << 0;
        character |= (pixel[1] & 0x01) << 1;
        character |= (pixel[2] & 0x01) << 2;

        if (character == '$') {
            break;
        }

        revealedMessage[index++] = character;
    }

    revealedMessage[index] = '\0';
    printf("%s\n", revealedMessage);

    fclose(inputFile);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <hide|reveal> <inputBMP> <outputBMP/message> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "hide") == 0) {
        hideMessageInBMP(argv[2], argv[3], argv[4]);
        printf("Message hidden successfully!\n");
    } else if (strcmp(argv[1], "reveal") == 0) {
        revealMessageInBMP(argv[2]);
    } else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}