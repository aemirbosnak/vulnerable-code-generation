//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)  // Ensuring correct structure packing
typedef struct {
    unsigned short bfType;      // Magic number for BMP files
    unsigned int bfSize;        // Size of the BMP file
    unsigned short bfReserved1; // Reserved, must be 0
    unsigned short bfReserved2; // Reserved, must be 0
    unsigned int bfOffBits;     // Offset to start of pixel data
} BMPHeader;

typedef struct {
    unsigned int biSize;        // Size of this header (40 bytes)
    int biWidth;                // Width of the image
    int biHeight;               // Height of the image
    unsigned short biPlanes;     // Number of color planes, must be 1
    unsigned short biBitCount;   // Number of bits per pixel
    unsigned int biCompression;  // Compression method (0 = none)
    unsigned int biSizeImage;    // Size of image data (can be 0 for uncompressed)
    int biXPelsPerMeter;         // Horizontal resolution (pixels per meter)
    int biYPelsPerMeter;         // Vertical resolution (pixels per meter)
    unsigned int biClrUsed;       // Number of colors in the color palette (0 = default)
    unsigned int biClrImportant;   // Important colors (0 = all)
} BMPInfoHeader;
#pragma pack(pop)

void encodeMessage(const char* inputImagePath, const char* outputImagePath, const char* message) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    FILE *outputFile = fopen(outputImagePath, "wb");
    if (!inputFile || !outputFile) {
        perror("File opening failed");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    // Calculating the image size
    unsigned int imageSize = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * (bmpInfoHeader.biBitCount / 8);
    unsigned char *imageData = malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, inputFile);

    // Hiding the message in the image
    unsigned int messageLength = strlen(message);
    for (unsigned int i = 0; i < messageLength; ++i) {
        for (int j = 0; j < 8; ++j) {
            int index = (i * 8 + j) * 3; // Each pixel has 3 colors (RGB)
            if (index >= imageSize) break;
            imageData[index] = (imageData[index] & ~1) | ((message[i] >> (7 - j)) & 1);
        }
    }

    // Append a delimiter (NULL character)
    for (int j = 0; j < 8; ++j) {
        int index = (messageLength * 8 + j) * 3;
        if (index >= imageSize) break;
        imageData[index] = (imageData[index] & ~1) | ((0 >> (7 - j)) & 1);
    }

    // Writing the modified image back out
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fwrite(imageData, sizeof(unsigned char), imageSize, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    free(imageData);
    printf("Message encoded successfully into %s\n", outputImagePath);
}

void decodeMessage(const char* imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        perror("File opening failed");
        return;
    }
    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    unsigned int imageSize = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * (bmpInfoHeader.biBitCount / 8);
    unsigned char *imageData = malloc(imageSize);
    fread(imageData, sizeof(unsigned char), imageSize, inputFile);

    // Decoding the message from the image
    char message[256] = {0};
    unsigned int messageIndex = 0;
    
    for (unsigned int i = 0; i < imageSize; ++i) {
        if (i % 3 == 0) { // Each pixel has 3 values RGB
            message[messageIndex / 8] |= (imageData[i] & 1) << (7 - (messageIndex % 8));
            messageIndex++;
            if (messageIndex % 8 == 0 && message[messageIndex / 8 - 1] == '\0') {
                break; // Stop at NULL character
            }
        }
    }

    printf("Decoded message: %s\n", message);
    fclose(inputFile);
    free(imageData);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <encode/decode> <image> [<output_image/message>]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        if (argc < 4) {
            printf("Usage: %s encode <input_image> <output_image> <message>\n", argv[0]);
            return 1;
        }
        encodeMessage(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessage(argv[2]);
    } else {
        printf("Unknown operation: %s\n", argv[1]);
    }

    return 0;
}