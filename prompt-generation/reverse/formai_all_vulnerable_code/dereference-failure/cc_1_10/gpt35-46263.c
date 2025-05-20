//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* data;
} Image;

Image* loadImage(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("ERROR: Failed to open file \"%s\"\n", filename);
        return NULL;
    }

    // Read header information
    char magic[2];
    int width, height, maxval;
    fscanf(fp, "%2s\n", magic);
    if (magic[0] != 'P' || magic[1] != '6') {
        printf("ERROR: Invalid file format \"%s\"\n", magic);
        return NULL;
    }
    fscanf(fp, "%d %d\n", &width, &height);
    fscanf(fp, "%d\n", &maxval);
    if (maxval != 255) {
        printf("ERROR: Invalid maximum pixel value %d\n", maxval);
        return NULL;
    }

    // Allocate memory for image
    Image* image = malloc(sizeof(Image));
    if (!image) {
        printf("ERROR: Failed to allocate memory for image\n");
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(Pixel));
    if (!image->data) {
        printf("ERROR: Failed to allocate memory for pixels\n");
        free(image);
        return NULL;
    }

    // Read pixel data
    int i;
    for (i = 0; i < width * height; i++) {
        unsigned char r, g, b;
        fread(&r, 1, 1, fp);
        fread(&g, 1, 1, fp);
        fread(&b, 1, 1, fp);
        image->data[i].red = r;
        image->data[i].green = g;
        image->data[i].blue = b;
    }

    fclose(fp);
    return image;
}

void saveImage(const char* filename, const Image* image) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("ERROR: Failed to open file \"%s\"\n", filename);
        return;
    }

    // Write header information
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);

    // Write pixel data
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        fputc(image->data[i].red, fp);
        fputc(image->data[i].green, fp);
        fputc(image->data[i].blue, fp);
    }

    fclose(fp);
}

void flipImage(Image* image) {
    int row, col;
    Pixel temp;
    for (row = 0; row < image->height / 2; row++) {
        for (col = 0; col < image->width; col++) {
            temp = image->data[row * image->width + col];
            image->data[row * image->width + col] = image->data[(image->height - row - 1) * image->width + col];
            image->data[(image->height - row - 1) * image->width + col] = temp;
        }
    }
}

void adjustBrightness(Image* image, int delta) {
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        int r = image->data[i].red + delta;
        int g = image->data[i].green + delta;
        int b = image->data[i].blue + delta;
        if (r < 0) r = 0;
        if (r > 255) r = 255;
        if (g < 0) g = 0;
        if (g > 255) g = 255;
        if (b < 0) b = 0;
        if (b > 255) b = 255;
        image->data[i].red = r;
        image->data[i].green = g;
        image->data[i].blue = b;
    }
}

void adjustContrast(Image* image, double factor) {
    int i;
    for (i = 0; i < image->width * image->height; i++) {
        int r = (int)((double)(image->data[i].red - 128) * factor + 128);
        int g = (int)((double)(image->data[i].green - 128) * factor + 128);
        int b = (int)((double)(image->data[i].blue - 128) * factor + 128);
        if (r < 0) r = 0;
        if (r > 255) r = 255;
        if (g < 0) g = 0;
        if (g > 255) g = 255;
        if (b < 0) b = 0;
        if (b > 255) b = 255;
        image->data[i].red = r;
        image->data[i].green = g;
        image->data[i].blue = b;
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 0;
    }

    // Load image
    Image* image = loadImage(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip image
    flipImage(image);

    // Adjust brightness
    adjustBrightness(image, -50);

    // Adjust contrast
    adjustContrast(image, 1.5);

    // Save image
    saveImage("result.ppm", image);

    // Free memory
    free(image->data);
    free(image);

    return 0;
}