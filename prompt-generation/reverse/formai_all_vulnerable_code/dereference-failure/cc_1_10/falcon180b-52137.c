//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET_SIZE 64

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

typedef struct {
    char *data;
    int size;
} AsciiArt;

void loadImage(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *buffer = malloc(filesize);
    fread(buffer, filesize, 1, fp);
    fclose(fp);

    image->data = buffer;
    image->width = *(int *)buffer;
    image->height = *(int *)(buffer + sizeof(int));
}

void saveAsciiArt(const char *filename, const AsciiArt *asciiArt) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open ASCII art file.\n");
        exit(1);
    }

    fwrite(asciiArt->data, asciiArt->size, 1, fp);
    fclose(fp);
}

void convertImageToAsciiArt(const Image *image, AsciiArt *asciiArt) {
    int width = image->width;
    int height = image->height;
    int bytesPerPixel = 3;
    int totalBytes = width * height * bytesPerPixel;

    unsigned char *buffer = malloc(totalBytes);
    memcpy(buffer, image->data + sizeof(int) * 2, totalBytes);

    int pixels[MAX_WIDTH * MAX_HEIGHT];
    int pixelCount = 0;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int offset = (y * width + x) * bytesPerPixel;
            int r = buffer[offset];
            int g = buffer[offset + 1];
            int b = buffer[offset + 2];

            int brightness = (int)((r + g + b) / 3.0);

            if (brightness < CHAR_SET_SIZE) {
                pixels[pixelCount++] = brightness;
            }
        }
    }

    asciiArt->data = malloc(pixelCount * 2);
    asciiArt->size = pixelCount * 2;

    int index = 0;
    for (int i = 0; i < pixelCount; i++) {
        int c = pixels[i];
        asciiArt->data[index++] = c;
        asciiArt->data[index++] = '\n';
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image image;
    loadImage(argv[1], &image);

    AsciiArt asciiArt;
    convertImageToAsciiArt(&image, &asciiArt);

    saveAsciiArt(argv[2], &asciiArt);

    printf("Conversion completed successfully.\n");
    return 0;
}