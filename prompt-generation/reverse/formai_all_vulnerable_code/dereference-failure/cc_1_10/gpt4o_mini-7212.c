//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPFileHeader;

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
} BMPInfoHeader;

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
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
}

void adjustBrightness(Pixel **image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (image[i][j].red + brightness > 255) ? 255 : 
                              (image[i][j].red + brightness < 0) ? 0 : 
                              image[i][j].red + brightness;
            image[i][j].green = (image[i][j].green + brightness > 255) ? 255 : 
                               (image[i][j].green + brightness < 0) ? 0 : 
                               image[i][j].green + brightness;
            image[i][j].blue = (image[i][j].blue + brightness > 255) ? 255 : 
                              (image[i][j].blue + brightness < 0) ? 0 : 
                              image[i][j].blue + brightness;
        }
    }
}

void adjustContrast(Pixel **image, int width, int height, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].red = (unsigned char)((((float)image[i][j].red - 128) * contrast) + 128);
            image[i][j].green = (unsigned char)((((float)image[i][j].green - 128) * contrast) + 128);
            image[i][j].blue = (unsigned char)((((float)image[i][j].blue - 128) * contrast) + 128);
        }
    }
}

void readBMP(const char *filename, Pixel ***image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }
    
    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    *width = infoHeader.biWidth;
    *height = abs(infoHeader.biHeight);

    *image = malloc(*height * sizeof(Pixel*));
    for (int i = 0; i < *height; i++) {
        (*image)[i] = malloc(*width * sizeof(Pixel));
        fread((*image)[i], sizeof(Pixel), *width, file);
    }

    fclose(file);
}

void writeBMP(const char *filename, Pixel **image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error creating file");
        exit(1);
    }

    BMPFileHeader fileHeader = {0x4D42, sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + width * height * sizeof(Pixel), 0, 0, sizeof(BMPFileHeader) + sizeof(BMPInfoHeader)};
    BMPInfoHeader infoHeader = {sizeof(BMPInfoHeader), width, height, 1, 24, 0, 0, 0, 0, 0, 0};

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, file);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    for (int i = 0; i < height; i++) {
        fwrite(image[i], sizeof(Pixel), width, file);
        free(image[i]); // Freeing each row
    }
    free(image); // Finally freeing the image array
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Pixel **image;
    int width, height;

    readBMP(inputFile, &image, &width, &height);
    
    flipImageVertically(image, width, height);
    adjustBrightness(image, width, height, brightness);
    adjustContrast(image, width, height, contrast);
    
    writeBMP(outputFile, image, width, height);
    
    printf("Image processing complete!\n");

    return 0;
}