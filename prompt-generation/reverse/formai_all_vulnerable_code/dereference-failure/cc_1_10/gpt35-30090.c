//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint16_t type;                 
    uint32_t fileSize;             
    uint16_t reserved1, reserved2; 
    uint32_t offset;               
    uint32_t headerSize;           
    int32_t width, height;         
    uint16_t planes;               
    uint16_t bitsPerPixel;         
    uint32_t compression;          
    uint32_t imageSize;            
    int32_t xResolution, yResolution;
    uint32_t colorsUsed;           
    uint32_t importantColors;      
} BMPHeader;

typedef struct {
    uint8_t r, g, b, a;
} Pixel;

Pixel **allocateImageArray(int width, int height) {
    Pixel **array = malloc(sizeof(Pixel*) * height);
    for (int i = 0; i < height; i++) {
        array[i] = malloc(sizeof(Pixel) * width);
    }
    return array;
}

void readBMPHeader(FILE *file, BMPHeader *header) {
    fread(&header->type, 2, 1, file);
    fread(&header->fileSize, 4, 1, file);
    fread(&header->reserved1, 2, 1, file);
    fread(&header->reserved2, 2, 1, file);
    fread(&header->offset, 4, 1, file);
    fread(&header->headerSize, 4, 1, file);
    fread(&header->width, 4, 1, file);
    fread(&header->height, 4, 1, file);
    fread(&header->planes, 2, 1, file);
    fread(&header->bitsPerPixel, 2, 1, file);
    fread(&header->compression, 4, 1, file);
    fread(&header->imageSize, 4, 1, file);
    fread(&header->xResolution, 4, 1, file);
    fread(&header->yResolution, 4, 1, file);
    fread(&header->colorsUsed, 4, 1, file);
    fread(&header->importantColors, 4, 1, file);
}

void writeBMPHeader(FILE *file, BMPHeader *header) {
    fwrite(&header->type, 2, 1, file);
    fwrite(&header->fileSize, 4, 1, file);
    fwrite(&header->reserved1, 2, 1, file);
    fwrite(&header->reserved2, 2, 1, file);
    fwrite(&header->offset, 4, 1, file);
    fwrite(&header->headerSize, 4, 1, file);
    fwrite(&header->width, 4, 1, file);
    fwrite(&header->height, 4, 1, file);
    fwrite(&header->planes, 2, 1, file);
    fwrite(&header->bitsPerPixel, 2, 1, file);
    fwrite(&header->compression, 4, 1, file);
    fwrite(&header->imageSize, 4, 1, file);
    fwrite(&header->xResolution, 4, 1, file);
    fwrite(&header->yResolution, 4, 1, file);
    fwrite(&header->colorsUsed, 4, 1, file);
    fwrite(&header->importantColors, 4, 1, file);
}

void flipImage(Pixel **array, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        Pixel *row1 = array[i];
        Pixel *row2 = array[height - i - 1];
        for (int j = 0; j < width; j++) {
            Pixel temp = row1[j];
            row1[j] = row2[j];
            row2[j] = temp;
        }
    }
}

void adjustBrightness(Pixel **array, int width, int height, float brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j].r = (uint8_t)(array[i][j].r * brightness);
            array[i][j].g = (uint8_t)(array[i][j].g * brightness);
            array[i][j].b = (uint8_t)(array[i][j].b * brightness);
        }
    }
}

void adjustContrast(Pixel **array, int width, int height, float contrast) {
    float f = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            array[i][j].r = (uint8_t)(f * (array[i][j].r - 128) + 128);
            array[i][j].g = (uint8_t)(f * (array[i][j].g - 128) + 128);
            array[i][j].b = (uint8_t)(f * (array[i][j].b - 128) + 128);
        }
    }
}

int main() {
    // Read BMP file header
    BMPHeader header;
    FILE *file = fopen("input.bmp", "rb");
    if (file == NULL) {
        printf("Failed to open input BMP file.\n");
        return 1;
    }
    readBMPHeader(file, &header);

    // Allocate memory for image array
    Pixel **image = allocateImageArray(header.width, header.height);

    // Read BMP image data
    fseek(file, header.offset, SEEK_SET);
    for (int i = 0; i < header.height; i++) {
        for (int j = 0; j < header.width; j++) {
            fread(&image[i][j].b, 1, 1, file);
            fread(&image[i][j].g, 1, 1, file);
            fread(&image[i][j].r, 1, 1, file);
        }
        int padding = (4 - (header.width * 3) % 4) % 4;
        fseek(file, padding, SEEK_CUR);
    }

    // Flip image
    flipImage(image, header.width, header.height);

    // Adjust brightness and contrast
    adjustBrightness(image, header.width, header.height, 1.2f);
    adjustContrast(image, header.width, header.height, 50.0f);

    // Write output BMP file
    FILE *outputFile = fopen("output.bmp", "wb");
    if (outputFile == NULL) {
        printf("Failed to create output BMP file.\n");
        return 1;
    }
    writeBMPHeader(outputFile, &header);
    fseek(outputFile, header.offset, SEEK_SET);
    for (int i = 0; i < header.height; i++) {
        for (int j = 0; j < header.width; j++) {
            fwrite(&image[i][j].b, 1, 1, outputFile);
            fwrite(&image[i][j].g, 1, 1, outputFile);
            fwrite(&image[i][j].r, 1, 1, outputFile);
        }
        int padding = (4 - (header.width * 3) % 4) % 4;
        for (int k = 0; k < padding; k++) {
            fwrite("\0", 1, 1, outputFile);
        }
    }

    // Free memory and close files
    for (int i = 0; i < header.height; i++) {
        free(image[i]);
    }
    free(image);
    fclose(file);
    fclose(outputFile);

    printf("Image processing completed!\n");
    return 0;
}