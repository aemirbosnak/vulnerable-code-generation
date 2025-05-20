//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: careful
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
} BITMAPFILEHEADER;

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
} BITMAPINFOHEADER;
#pragma pack(pop)

void embedMessage(const char *inputImage, const char *outputImage, const char *message) {
    FILE *input = fopen(inputImage, "rb");
    FILE *output = fopen(outputImage, "wb");
    
    if (!input || !output) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;

    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, input);
    
    fwrite(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, output);

    int pixelArrayOffset = bmpFileHeader.bfOffBits;
    fseek(input, pixelArrayOffset, SEEK_SET);
    fseek(output, pixelArrayOffset, SEEK_SET);
    
    int messageLength = strlen(message);
    unsigned char *messageBits = (unsigned char *) malloc(messageLength * 8 + 1);
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            messageBits[i * 8 + j] = (message[i] >> (7 - j)) & 1;
        }
    }
    messageBits[messageLength * 8] = 0; // Null terminator

    int currentBit = 0;
    unsigned char byte;
    
    for (int y = 0; y < bmpInfoHeader.biHeight; y++) {
        for (int x = 0; x < bmpInfoHeader.biWidth * (bmpInfoHeader.biBitCount / 8); x++) {
            fread(&byte, sizeof(unsigned char), 1, input);
            if (currentBit < messageLength * 8) {
                byte = (byte & 0xFE) | messageBits[currentBit++];
            }
            fwrite(&byte, sizeof(unsigned char), 1, output);
        }
    }

    free(messageBits);
    fclose(input);
    fclose(output);
}

void extractMessage(const char *inputImage) {
    FILE *input = fopen(inputImage, "rb");
    
    if (!input) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }
    
    BITMAPFILEHEADER bmpFileHeader;
    BITMAPINFOHEADER bmpInfoHeader;
    
    fread(&bmpFileHeader, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bmpInfoHeader, sizeof(BITMAPINFOHEADER), 1, input);
    
    fseek(input, bmpFileHeader.bfOffBits, SEEK_SET);
    
    unsigned char byte;
    char extractedMessage[256];
    int currentBit = 0;
    int messageLength = 0;
    
    while (currentBit < 256 * 8) {
        fread(&byte, sizeof(unsigned char), 1, input);
        extractedMessage[messageLength] = (byte & 1) + '0';
        
        if (extractedMessage[messageLength] == '0' && currentBit % 8 == 7) {
            break;
        }
        
        messageLength += (currentBit % 8 == 7) ? 1 : 0;
        currentBit++;
    }
    
    extractedMessage[messageLength] = '\0'; // Null terminator
    printf("Extracted Message: %s\n", extractedMessage);
    
    fclose(input);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <image.bmp> <message/output_image.bmp>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embedMessage(argv[2], argv[3], argv[4]);
        printf("Message embedded successfully into %s\n", argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extractMessage(argv[2]);
    } else {
        printf("Invalid option. Use 'embed' or 'extract'.\n");
    }

    return 0;
}