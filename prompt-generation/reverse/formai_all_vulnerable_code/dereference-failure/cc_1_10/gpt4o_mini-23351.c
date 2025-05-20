//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)
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

void flipImageVertically(Pixel **image, int width, int height);
void changeBrightness(Pixel **image, int width, int height, int brightnessOffset);
void freeImage(Pixel **image, int height);
Pixel **loadBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader);
void saveBMP(const char *filename, Pixel **image, BMPHeader header, BMPInfoHeader infoHeader);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness_offset>\n", argv[0]);
        printf("The program flips an image vertically and changes brightness.\n");
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;
    Pixel **image = loadBMP(argv[1], &header, &infoHeader);
    if (!image) {
        fprintf(stderr, "Error loading the image!\n");
        return 1;
    }

    printf("Loaded BMP: %s [%dx%d]\n", argv[1], infoHeader.width, infoHeader.height);
    printf("Flipping image vertically...\n");
    flipImageVertically(image, infoHeader.width, infoHeader.height);

    int brightnessOffset = atoi(argv[3]);
    printf("Changing brightness by %d...\n", brightnessOffset);
    changeBrightness(image, infoHeader.width, infoHeader.height, brightnessOffset);

    saveBMP(argv[2], image, header, infoHeader);
    printf("Saved modified image as %s\n", argv[2]);

    freeImage(image, infoHeader.height);
    return 0;
}

Pixel **loadBMP(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (header->type != 0x4D42) { // 'BM'
        fclose(file);
        return NULL;
    }

    Pixel **image = malloc(infoHeader->height * sizeof(Pixel *));
    for (int i = 0; i < infoHeader->height; i++) {
        image[i] = malloc(infoHeader->width * sizeof(Pixel));
        fseek(file, header->offset + (infoHeader->width * i * sizeof(Pixel)), SEEK_SET);
        fread(image[i], sizeof(Pixel), infoHeader->width, file);
    }

    fclose(file);
    return image;
}

void saveBMP(const char *filename, Pixel **image, BMPHeader header, BMPInfoHeader infoHeader) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fwrite(&header, sizeof(BMPHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    for (int i = 0; i < infoHeader.height; i++) {
        fwrite(image[i], sizeof(Pixel), infoHeader.width, file);
        free(image[i]);
    }

    fclose(file);
}

void flipImageVertically(Pixel **image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            Pixel temp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
}

void changeBrightness(Pixel **image, int width, int height, int brightnessOffset) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (image[i][j].red + brightnessOffset > 255) ? 255 : (image[i][j].red + brightnessOffset < 0 ? 0 : image[i][j].red + brightnessOffset);
            image[i][j].green = (image[i][j].green + brightnessOffset > 255) ? 255 : (image[i][j].green + brightnessOffset < 0 ? 0 : image[i][j].green + brightnessOffset);
            image[i][j].blue = (image[i][j].blue + brightnessOffset > 255) ? 255 : (image[i][j].blue + brightnessOffset < 0 ? 0 : image[i][j].blue + brightnessOffset);
        }
    }
}

void freeImage(Pixel **image, int height) {
    free(image);
}