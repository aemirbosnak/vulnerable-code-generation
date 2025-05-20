//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

void readPPM(const char *filename, Pixel **pixels, int *width, int *height);
void writePPM(const char *filename, Pixel *pixels, int width, int height);
void flipImage(Pixel *pixels, int width, int height);
void changeBrightness(Pixel *pixels, int width, int height, int value);

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <input.ppm> <output.ppm> <flip (0/1)> <brightness>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int flip = atoi(argv[3]);
    int brightnessValue = atoi(argv[4]);

    Pixel *pixels = NULL;
    int width, height;

    readPPM(inputFile, &pixels, &width, &height);
    
    if (flip) {
        flipImage(pixels, width, height);
    }
    
    changeBrightness(pixels, width, height, brightnessValue);
    
    writePPM(outputFile, pixels, width, height);

    free(pixels);
    return 0;
}

void readPPM(const char *filename, Pixel **pixels, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char header[3];
    fscanf(fp, "%s", header);
    if (strcmp(header, "P6") != 0) {
        printf("Unsupported PPM format: %s\n", header);
        exit(1);
    }
    
    fscanf(fp, "%d %d", width, height);
    int maxValue;
    fscanf(fp, "%d", &maxValue);
    fgetc(fp); // Consume the newline after maxValue

    *pixels = malloc(*width * *height * sizeof(Pixel));
    fread(*pixels, sizeof(Pixel), (*width) * (*height), fp);
    fclose(fp);
}

void writePPM(const char *filename, Pixel *pixels, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", width, height);
    fwrite(pixels, sizeof(Pixel), width * height, fp);
    fclose(fp);
}

void flipImage(Pixel *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int index1 = y * width + x;
            int index2 = y * width + (width - 1 - x);
            Pixel temp = pixels[index1];
            pixels[index1] = pixels[index2];
            pixels[index2] = temp;
        }
    }
}

void changeBrightness(Pixel *pixels, int width, int height, int value) {
    for (int i = 0; i < width * height; i++) {
        int r = pixels[i].r + value;
        int g = pixels[i].g + value;
        int b = pixels[i].b + value;

        pixels[i].r = (r < 0) ? 0 : (r > 255) ? 255 : r;
        pixels[i].g = (g < 0) ? 0 : (g > 255) ? 255 : g;
        pixels[i].b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    }
}