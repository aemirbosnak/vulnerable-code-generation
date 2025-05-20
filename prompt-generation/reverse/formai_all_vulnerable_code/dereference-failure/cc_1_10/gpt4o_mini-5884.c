//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t fileSize;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offsetData;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t imgSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t clrUsed;
    uint32_t importantClr;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

void apply_grayscale(RGB *pixel) {
    uint8_t gray = (uint8_t)(0.3 * pixel->red + 0.59 * pixel->green + 0.11 * pixel->blue);
    pixel->red = gray;
    pixel->green = gray;
    pixel->blue = gray;
}

void load_bmp(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, RGB **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    *pixels = malloc(infoHeader->width * infoHeader->height * sizeof(RGB));
    fseek(file, fileHeader->offsetData, SEEK_SET);
    fread(*pixels, sizeof(RGB), infoHeader->width * infoHeader->height, file);

    fclose(file);
}

void save_bmp(const char *filename, BITMAPFILEHEADER fileHeader, BITMAPINFOHEADER infoHeader, RGB *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(RGB), infoHeader.width * infoHeader.height, file);

    fclose(file);
}

void edit_image(const char *inputFile, const char *outputFile) {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    RGB *pixels;

    // Load the image
    load_bmp(inputFile, &fileHeader, &infoHeader, &pixels);
    printf("Loaded image %s with dimensions %dx%d\n", inputFile, infoHeader.width, infoHeader.height);

    // Apply grayscale filter
    for (int i = 0; i < infoHeader.width * infoHeader.height; i++) {
        apply_grayscale(&pixels[i]);
    }
    printf("Applied grayscale filter.\n");

    // Save the new image
    save_bmp(outputFile, fileHeader, infoHeader, pixels);
    printf("Saved edited image to %s\n", outputFile);

    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    edit_image(argv[1], argv[2]);
    printf("Image editing completed successfully!\n");
    return EXIT_SUCCESS;
}