//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // to ensure we don't have padding in our structures
typedef struct {
    unsigned char  signature[2]; // "BM"
    unsigned int   fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int   pixelDataOffset;
} BMPHeader;

typedef struct {
    unsigned int   headerSize;
    int            width;
    int            height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int   compression;
    unsigned int   imageSize;
    int            xPixelsPerMeter;
    int            yPixelsPerMeter;
    unsigned int   colorsUsed;
    unsigned int   importantColors;
} DIBHeader;

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

#pragma pack(pop)

void flipImageVertically(Pixel **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            Pixel temp = image[i][j];
            image[i][j] = image[height - i - 1][j];
            image[height - i - 1][j] = temp;
        }
    }
}

void changeBrightness(Pixel **image, int width, int height, int brightnessChange) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (image[i][j].red + brightnessChange > 255) ? 255 : (image[i][j].red + brightnessChange < 0 ? 0 : image[i][j].red + brightnessChange);
            image[i][j].green = (image[i][j].green + brightnessChange > 255) ? 255 : (image[i][j].green + brightnessChange < 0 ? 0 : image[i][j].green + brightnessChange);
            image[i][j].blue = (image[i][j].blue + brightnessChange > 255) ? 255 : (image[i][j].blue + brightnessChange < 0 ? 0 : image[i][j].blue + brightnessChange);
        }
    }
}

Pixel **readBMP(const char *filename, BMPHeader *bmpHeader, DIBHeader *dibHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return NULL;
    }
    
    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(dibHeader, sizeof(DIBHeader), 1, file);

    if (bmpHeader->signature[0] != 'B' || bmpHeader->signature[1] != 'M') {
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(file);
        return NULL;
    }

    Pixel **image = malloc(dibHeader->height * sizeof(Pixel *));
    for (int i = 0; i < dibHeader->height; i++) {
        image[i] = malloc(dibHeader->width * sizeof(Pixel));
    }

    fseek(file, bmpHeader->pixelDataOffset, SEEK_SET);
    for (int i = dibHeader->height - 1; i >= 0; i--) { // BMP stores pixels in reverse order
        fread(image[i], sizeof(Pixel), dibHeader->width, file);
    }

    fclose(file);
    return image;
}

void writeBMP(const char *filename, BMPHeader bmpHeader, DIBHeader dibHeader, Pixel **image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return;
    }
    
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&dibHeader, sizeof(DIBHeader), 1, file);

    fseek(file, bmpHeader.pixelDataOffset, SEEK_SET);
    for (int i = dibHeader.height - 1; i >= 0; i--) { // BMP stores pixels in reverse order
        fwrite(image[i], sizeof(Pixel), dibHeader.width, file);
    }

    fclose(file);
}

void freeImage(Pixel **image, int height) {
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
}

int main() {
    BMPHeader bmpHeader;
    DIBHeader dibHeader;
    char *inputFilename = "input.bmp";
    char *outputFilename = "output.bmp";

    Pixel **image = readBMP(inputFilename, &bmpHeader, &dibHeader);
    if (!image) {
        return 1;
    }

    // Flip the image vertically
    flipImageVertically(image, dibHeader.width, dibHeader.height);

    // Change brightness
    int brightnessChange = 50; // Increase brightness
    changeBrightness(image, dibHeader.width, dibHeader.height, brightnessChange);

    // Write out the modified image
    writeBMP(outputFilename, bmpHeader, dibHeader, image);

    // Free allocated memory
    freeImage(image, dibHeader.height);

    printf("Image processing complete. Saved to %s\n", outputFilename);
    return 0;
}