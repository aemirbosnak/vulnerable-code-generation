//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char b, g, r;
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
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPelsPerMeter;
    int yPelsPerMeter;
    unsigned int clrUsed;
    unsigned int clrImportant;
} BMPInfoHeader;

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *in = fopen(inputImage, "rb");
    FILE *out = fopen(outputImage, "wb");
    if (!in || !out) {
        fprintf(stderr, "Error opening files.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, in);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, in);

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, out);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, out);

    Pixel *pixels = (Pixel *)malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, in);

    // Prepare the message to embed
    size_t messageLength = strlen(message);
    char *messageWithTerminator = malloc(messageLength + 1);
    strcpy(messageWithTerminator, message);
    messageWithTerminator[messageLength] = '\0';
    
    // Embed length of the message in the first pixel
    pixels[0].b = messageLength;

    for (size_t i = 0; i < messageLength; ++i) {
        pixels[i + 1].b = messageWithTerminator[i]; // Use the blue channel for simplicity
    }

    fwrite(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, out);

    free(pixels);
    free(messageWithTerminator);
    fclose(in);
    fclose(out);
}

void extractMessage(const char *inputImage) {
    FILE *in = fopen(inputImage, "rb");
    if (!in) {
        fprintf(stderr, "Error opening file.\n");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, in);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, in);

    Pixel *pixels = (Pixel *)malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, in);

    // Read the length of the message from the first pixel
    size_t messageLength = pixels[0].b;
    char *extractedMessage = malloc(messageLength + 1);
    for (size_t i = 0; i < messageLength; ++i) {
        extractedMessage[i] = pixels[i + 1].b;
    }
    extractedMessage[messageLength] = '\0';

    printf("Extracted Message: %s\n", extractedMessage);

    free(pixels);
    free(extractedMessage);
    fclose(in);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message_to_embed>\n", argv[0]);
        return 1;
    }

    const char *inputImage = argv[1];
    const char *outputImage = argv[2];

    // Embed the message when enough arguments are provided
    embedMessage(inputImage, outputImage, argv[3]);

    // Extract the message from the output image for verification
    extractMessage(outputImage);

    return 0;
}