//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Ensuring that the struct is packed with 1-byte alignment
typedef struct {
    unsigned short bfType;      // Magic number for file
    unsigned int bfSize;        // Size of file
    unsigned short bfReserved1; // Reserved
    unsigned short bfReserved2; // Reserved
    unsigned int bfOffBits;     // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;          // Size of this header
    int biWidth;                  // Width of image
    int biHeight;                 // Height of image
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;    // Compression type
    unsigned int biSizeImage;     // Size of image data
    int biXPelsPerMeter;           // Pixels per meter in X
    int biYPelsPerMeter;           // Pixels per meter in Y
    unsigned int biClrUsed;       // Number of colors used
    unsigned int biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    unsigned char blue;          // Blue color value
    unsigned char green;         // Green color value
    unsigned char red;           // Red color value
} RGBTRIPLE;

void applyGrayscale(RGBTRIPLE *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char gray = (pixels[i].red + pixels[i].green + pixels[i].blue) / 3;
        pixels[i].red = gray;
        pixels[i].green = gray;
        pixels[i].blue = gray;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL) {
        printf("Could not open input file %s\n", argv[1]);
        return 1;
    }

    // Read the bitmap file header
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, inputFile);

    // Read the bitmap info header
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Image dimensions
    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

    // Allocate memory for pixel data
    RGBTRIPLE *pixels = malloc(width * height * sizeof(RGBTRIPLE));
    if (pixels == NULL) {
        printf("Memory allocation failed\n");
        fclose(inputFile);
        return 1;
    }

    // Read pixel data from the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pixels[i * width + j], sizeof(RGBTRIPLE), 1, inputFile);
        }
        fseek(inputFile, padding, SEEK_CUR); // Skip padding
    }
    fclose(inputFile); // Close input file

    // Apply grayscale effect
    applyGrayscale(pixels, width, height);

    // Write to output file
    FILE *outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL) {
        printf("Could not open output file %s\n", argv[2]);
        free(pixels);
        return 1;
    }

    // Write the bitmap file header
    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, outputFile);
    // Write the bitmap info header
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, outputFile);

    // Write pixel data to the new image
    for (int i = 0; i < height; i++) {
        fwrite(&pixels[i * width], sizeof(RGBTRIPLE), width, outputFile);
        // Write padding to output file
        for (int p = 0; p < padding; p++) {
            fputc(0x00, outputFile);
        }
    }

    // Cleanup
    fclose(outputFile);
    free(pixels);
    printf("Grayscale effect applied and saved to %s\n", argv[2]);

    return 0;
}