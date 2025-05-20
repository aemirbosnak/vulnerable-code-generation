//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "DigitalWatermarking2019"

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

void writeWatermark(Image *image) {
    int i, j, len;
    Pixel pixel;
    len = strlen(WATERMARK);
    for (i = 0; i < len; i++) {
        pixel = image->pixels[i];
        pixel.red = (pixel.red & ~1) | ((WATERMARK[i] >> 7) & 1);
        pixel.green = (pixel.green & ~1) | ((WATERMARK[i] >> 6) & 1);
        pixel.blue = (pixel.blue & ~3) | ((WATERMARK[i] >> 4) & 3);
        image->pixels[i] = pixel;
    }
}

char *readWatermark(Image *image) {
    int i, len;
    char *watermark;
    Pixel pixel;
    len = strlen(WATERMARK);
    watermark = (char *)malloc((len + 1) * sizeof(char));
    for (i = 0; i < len; i++) {
        pixel = image->pixels[i];
        watermark[i] = ((pixel.red & 1) << 7) | ((pixel.green & 1) << 6) | ((pixel.blue & 3) << 4);
    }
    watermark[len] = '\0';
    return watermark;
}

int main() {
    Image image;
    char *watermark;
    FILE *file;
    int i, len;

    // Read image from file
    file = fopen("image.bmp", "rb");
    fseek(file, 18, SEEK_SET);
    fread(&image.width, sizeof(int), 1, file);
    fread(&image.height, sizeof(int), 1, file);
    fseek(file, 28, SEEK_CUR);
    image.pixels = (Pixel *)malloc(image.width * image.height * sizeof(Pixel));
    fread(image.pixels, sizeof(Pixel), image.width * image.height, file);
    fclose(file);

    // Embed watermark
    len = strlen(WATERMARK);
    if (len > image.width * image.height) {
        printf("Watermark is too large for image\n");
        return 1;
    }
    writeWatermark(&image);

    // Write image with watermark to file
    file = fopen("watermarked.bmp", "wb");
    fwrite(image.pixels, sizeof(Pixel), image.width * image.height, file);
    fclose(file);

    // Read watermark from image
    file = fopen("watermarked.bmp", "rb");
    fseek(file, 18, SEEK_SET);
    fread(&image.width, sizeof(int), 1, file);
    fread(&image.height, sizeof(int), 1, file);
    fseek(file, 28, SEEK_CUR);
    image.pixels = (Pixel *)malloc(image.width * image.height * sizeof(Pixel));
    fread(image.pixels, sizeof(Pixel), image.width * image.height, file);
    fclose(file);
    watermark = readWatermark(&image);
    printf("Watermark: %s\n", watermark);
    free(watermark);

    // Free memory
    free(image.pixels);

    return 0;
}