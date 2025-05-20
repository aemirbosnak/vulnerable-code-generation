//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    char format[3];
    int width;
    int height;
    int maxColorValue;
    Pixel *data;
} Image;

Image* readImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }
    
    Image *img = malloc(sizeof(Image));
    fgets(img->format, sizeof(img->format), file);
    fscanf(file, "%d %d\n%d\n", &img->width, &img->height, &img->maxColorValue);
    img->data = malloc(img->width * img->height * sizeof(Pixel));
    
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void writeImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return;
    }
    
    fprintf(file, "%s", img->format);
    fprintf(file, "%d %d\n%d\n", img->width, img->height, img->maxColorValue);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width / 2; j++) {
            Pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + (img->width - j - 1)];
            img->data[i * img->width + (img->width - j - 1)] = temp;
        }
    }
}

void adjustBrightnessContrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = fmin(fmax((img->data[i].red * contrast) + brightness, 0), img->maxColorValue);
        img->data[i].green = fmin(fmax((img->data[i].green * contrast) + brightness, 0), img->maxColorValue);
        img->data[i].blue = fmin(fmax((img->data[i].blue * contrast) + brightness, 0), img->maxColorValue);
    }
}

void freeImage(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image.ppm> <output_image.ppm> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *inputImagePath = argv[1];
    const char *outputImagePath = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);
    
    Image *img = readImage(inputImagePath);
    if (!img) {
        return EXIT_FAILURE;
    }
    
    flipImage(img);
    adjustBrightnessContrast(img, brightness, contrast);
    
    writeImage(outputImagePath, img);
    
    freeImage(img);
    
    printf("Image processing completed. Flipped and adjusted brightness/contrast.\n");
    return EXIT_SUCCESS;
}