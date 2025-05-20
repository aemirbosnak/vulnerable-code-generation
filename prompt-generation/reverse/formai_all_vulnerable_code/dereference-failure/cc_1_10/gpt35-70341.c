//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push,1)
typedef struct {
    uint16_t signature;
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
} BMPHeader;

typedef struct {
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitDepth;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
} BMPInfo;
#pragma pack(pop)

void flipImage(uint8_t* image, int width, int height) {
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width / 2; c++) {
            uint8_t temp = image[r * width + c];
            image[r * width + c] = image[r * width + width - c - 1];
            image[r * width + width - c - 1] = temp;
        }
    }
}

void adjustBrightness(uint8_t* image, int width, int height, int brightness) {
    for (int i = 0; i < width * height; i++) {
        int pixel = image[i] + brightness;
        if (pixel < 0) {
            pixel = 0;
        } else if (pixel > 255) {
            pixel = 255;
        }
        image[i] = pixel;
    }
}

void adjustContrast(uint8_t* image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < width * height; i++) {
        int pixel = factor * (image[i] - 128) + 128;
        if (pixel < 0) {
            pixel = 0;
        } else if (pixel > 255) {
            pixel = 255;
        }
        image[i] = pixel;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s input.bmp output.bmp brightness contrast\n", argv[0]);
        return 1;
    }

    char* inputFile = argv[1];
    char* outputFile = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = 1.0;

    FILE* inFile = fopen(inputFile, "rb");
    if (!inFile) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    BMPHeader header;
    if (fread(&header, sizeof(header), 1, inFile) != 1) {
        printf("Error: invalid header.\n");
        return 1;
    }

    BMPInfo info;
    if (fread(&info, sizeof(info), 1, inFile) != 1) {
        printf("Error: invalid info header.\n");
        return 1;
    }

    if (info.bitDepth != 8) {
        printf("Error: unsupported image format.\n");
        return 1;
    }

    uint8_t* image = (uint8_t*) malloc(info.width * info.height);
    if (!image) {
        printf("Error: out of memory.\n");
        return 1;
    }

    fseek(inFile, header.dataOffset, SEEK_SET);
    if (fread(image, info.width * info.height, 1, inFile) != 1) {
        printf("Error: file truncated.\n");
        return 1;
    }

    flipImage(image, info.width, info.height);
    adjustBrightness(image, info.width, info.height, brightness);
    adjustContrast(image, info.width, info.height, contrast);

    FILE* outFile = fopen(outputFile, "wb");
    if (!outFile) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    if (fwrite(&header, sizeof(header), 1, outFile) != 1) {
        printf("Error: could not write header.\n");
        return 1;
    }

    if (fwrite(&info, sizeof(info), 1, outFile) != 1) {
        printf("Error: could not write info header.\n");
        return 1;
    }

    fseek(outFile, header.dataOffset, SEEK_SET);
    if (fwrite(image, info.width * info.height, 1, outFile) != 1) {
        printf("Error: could not write image data.\n");
        return 1;
    }

    fclose(inFile);
    fclose(outFile);
    free(image);

    printf("Finished processing image.\n");

    return 0;
}