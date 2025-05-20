//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensure no padding is used in structs
typedef struct {
    unsigned char magic[2]; // 'BM'
    unsigned int size;
    unsigned int reserved1;
    unsigned int reserved2;
    unsigned int offset; // Offset to pixel data
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

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;
#pragma pack(pop)

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        perror("Failed to open the input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpHeader.magic[0] != 'B' || bmpHeader.magic[1] != 'M') {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Calculate total number of pixels
    int totalPixels = bmpInfoHeader.width * bmpInfoHeader.height;
    int messageLength = strlen(message);
    if (totalPixels < messageLength * 8 + 1) {
        fprintf(stderr, "Message is too long to embed in this image.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Move the file pointer to the start of pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);

    Pixel pixel;
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            fread(&pixel, sizeof(Pixel), 1, inputFile);
            // Alter the least significant bit to embed the message bit
            if ((message[i] >> (7 - j)) & 1) {
                pixel.red |= 1; // Set LSB to 1
            } else {
                pixel.red &= ~1; // Set LSB to 0
            }
            fwrite(&pixel, sizeof(Pixel), 1, inputFile);
        }
    }
    // Embed a null terminator for the message
    for (int j = 0; j < 8; j++) {
        fread(&pixel, sizeof(Pixel), 1, inputFile);
        if (0 >> (7 - j) & 1) {
            pixel.red |= 1;
        } else {
            pixel.red &= ~1;
        }
        fwrite(&pixel, sizeof(Pixel), 1, inputFile);
    }

    fclose(inputFile);
    printf("Message embedded successfully in %s\n", outputImage);
}

void extractMessage(const char *inputImage) {
    FILE *inputFile = fopen(inputImage, "rb");
    if (!inputFile) {
        perror("Failed to open the input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    if (bmpHeader.magic[0] != 'B' || bmpHeader.magic[1] != 'M') {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Move the file pointer to the start of pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);

    Pixel pixel;
    char message[1024] = {0}; // Buffer for the message
    int messageLength = 0;

    // Read until we find the null character or we reach buffer limit
    while (messageLength < 1024 - 1) {
        for (int j = 0; j < 8; j++) {
            fread(&pixel, sizeof(Pixel), 1, inputFile);
            if (feof(inputFile)) {
                goto end_of_message_extraction; // Gracefully exit if the end of file is reached
            }
            // Extract the least significant bit
            message[messageLength] |= ((pixel.red & 1) << (7 - j));
        }
        if (message[messageLength] == '\0') {
            goto end_of_message_extraction;
        }
        messageLength++;
    }

end_of_message_extraction:
    message[messageLength] = '\0';
    printf("Extracted message: %s\n", message);

    fclose(inputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <embed|extract> <image> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[2], argv[3]); // Embedding into the same image
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        fprintf(stderr, "Invalid command. Use 'embed' or 'extract'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}