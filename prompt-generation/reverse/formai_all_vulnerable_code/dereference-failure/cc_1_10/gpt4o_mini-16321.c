//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Ensure the struct is packed without padding

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

void printUsage() {
    printf("Usage: image_editor <input.bmp> <output.bmp> <operation>\n");
    printf("Operations:\n");
    printf("  grayscale - Convert the image to grayscale\n");
    printf("  invert - Invert the colors of the image\n");
}

void applyGrayscale(unsigned char *buffer, int width, int height) {
    for (int i = 0; i < width * height * 3; i += 3) {
        unsigned char gray = (buffer[i] + buffer[i + 1] + buffer[i + 2]) / 3;
        buffer[i] = gray;     // Red
        buffer[i + 1] = gray; // Green
        buffer[i + 2] = gray; // Blue
    }
}

void invertColors(unsigned char *buffer, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        buffer[i] = 255 - buffer[i]; // Invert the color
    }
}

void processImage(const char *inputFile, const char *outputFile, const char *operation) {
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        fprintf(stderr, "Unable to open input file %s\n", inputFile);
        return;
    }

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, input);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, input);

    if (bfh.bfType != 0x4D42) { // Check if it is a BMP file
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(input);
        return;
    }

    unsigned char *buffer = (unsigned char *)malloc(bih.biSizeImage);
    fseek(input, bfh.bfOffBits, SEEK_SET);
    fread(buffer, bih.biSizeImage, 1, input);
    fclose(input);

    if (strcmp(operation, "grayscale") == 0) {
        applyGrayscale(buffer, bih.biWidth, bih.biHeight);
    } else if (strcmp(operation, "invert") == 0) {
        invertColors(buffer, bih.biWidth, bih.biHeight);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        free(buffer);
        return;
    }

    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        fprintf(stderr, "Unable to open output file %s\n", outputFile);
        free(buffer);
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output);
    fseek(output, bfh.bfOffBits, SEEK_SET);
    fwrite(buffer, bih.biSizeImage, 1, output);
    fclose(output);
    free(buffer);

    printf("Processing completed. Output saved to %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printUsage();
        return 1;
    }
    
    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *operation = argv[3];

    processImage(inputFile, outputFile, operation);
    return 0;
}