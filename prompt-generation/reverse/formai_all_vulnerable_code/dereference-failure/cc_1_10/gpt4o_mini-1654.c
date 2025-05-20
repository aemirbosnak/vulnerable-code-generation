//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d\n255\n", &image->width, &image->height);
    image->pixels = malloc(sizeof(Pixel) * image->width * image->height);
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);

    return image;
}

void savePPM(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void applyGrayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; ++i) {
        unsigned char gray = (image->pixels[i].r + image->pixels[i].g + image->pixels[i].b) / 3;
        image->pixels[i].r = gray;
        image->pixels[i].g = gray;
        image->pixels[i].b = gray;
    }
}

void freeImage(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];

    Image *image = loadPPM(inputFile);
    if (!image) {
        return EXIT_FAILURE;
    }

    applyGrayscale(image);
    savePPM(outputFile, image);
    freeImage(image);

    printf("Processed image saved as %s\n", outputFile);
    return EXIT_SUCCESS;
}