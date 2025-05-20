//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 512
#define WATERMARK_SIZE 32

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGBPixel;

typedef struct {
    int width;
    int height;
    RGBPixel *data;
} Image;

Image *loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    image->data = malloc(image->width * image->height * sizeof(RGBPixel));
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(RGBPixel), image->width * image->height, file);

    fclose(file);

    return image;
}

void saveImage(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    fwrite(image->data, sizeof(RGBPixel), image->width * image->height, file);

    fclose(file);
}

Image *createWatermark(const char *text, int size) {
    Image *watermark = malloc(sizeof(Image));
    if (watermark == NULL) {
        fprintf(stderr, "Error allocating memory for watermark\n");
        return NULL;
    }

    watermark->width = size;
    watermark->height = size;

    watermark->data = malloc(watermark->width * watermark->height * sizeof(RGBPixel));
    if (watermark->data == NULL) {
        fprintf(stderr, "Error allocating memory for watermark data\n");
        free(watermark);
        return NULL;
    }

    for (int i = 0; i < watermark->width; i++) {
        for (int j = 0; j < watermark->height; j++) {
            watermark->data[i + j * watermark->width].red = (i + j) % 256;
            watermark->data[i + j * watermark->width].green = (i + j) % 256;
            watermark->data[i + j * watermark->width].blue = (i + j) % 256;
        }
    }

    return watermark;
}

void embedWatermark(Image *image, Image *watermark) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            image->data[i + j * image->width].red = (image->data[i + j * image->width].red & 0xF8) | (watermark->data[i % watermark->width + j % watermark->height * watermark->width].red >> 3);
            image->data[i + j * image->width].green = (image->data[i + j * image->width].green & 0xF8) | (watermark->data[i % watermark->width + j % watermark->height * watermark->width].green >> 3);
            image->data[i + j * image->width].blue = (image->data[i + j * image->width].blue & 0xF8) | (watermark->data[i % watermark->width + j % watermark->height * watermark->width].blue >> 3);
        }
    }
}

Image *extractWatermark(Image *image, Image *watermark) {
    Image *extractedWatermark = malloc(sizeof(Image));
    if (extractedWatermark == NULL) {
        fprintf(stderr, "Error allocating memory for extracted watermark\n");
        return NULL;
    }

    extractedWatermark->width = watermark->width;
    extractedWatermark->height = watermark->height;

    extractedWatermark->data = malloc(extractedWatermark->width * extractedWatermark->height * sizeof(RGBPixel));
    if (extractedWatermark->data == NULL) {
        fprintf(stderr, "Error allocating memory for extracted watermark data\n");
        free(extractedWatermark);
        return NULL;
    }

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            extractedWatermark->data[i % watermark->width + j % watermark->height * watermark->width].red = (image->data[i + j * image->width].red & 0x07) << 3;
            extractedWatermark->data[i % watermark->width + j % watermark->height * watermark->width].green = (image->data[i + j * image->width].green & 0x07) << 3;
            extractedWatermark->data[i % watermark->width + j % watermark->height * watermark->width].blue = (image->data[i + j * image->width].blue & 0x07) << 3;
        }
    }

    return extractedWatermark;
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <watermark text> <watermark size>\n", argv[0]);
        return 1;
    }

    Image *image = loadImage(argv[1]);
    if (image == NULL) {
        return 1;
    }

    Image *watermark = createWatermark(argv[3], atoi(argv[4]));
    if (watermark == NULL) {
        free(image);
        return 1;
    }

    embedWatermark(image, watermark);

    saveImage(image, argv[2]);

    free(image);
    free(watermark);

    return 0;
}