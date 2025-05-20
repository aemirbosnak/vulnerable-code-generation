//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to read a PPM image file
Image* readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s.\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Error: Unsupported image format.\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxColor;
    fscanf(file, "%d %d %d", &width, &height, &maxColor);
    fgetc(file); // Skip the newline after maxColor

    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel*)malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

// Function to write a PPM image file
void writePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip the image vertically
void flipImageVertically(Image *img) {
    for (int y = 0; y < img->height / 2; ++y) {
        for (int x = 0; x < img->width; ++x) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - 1 - y) * img->width + x];
            img->data[(img->height - 1 - y) * img->width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (img->data[i].r + value > 255) ? 255 : (img->data[i].r + value < 0) ? 0 : img->data[i].r + value;
        img->data[i].g = (img->data[i].g + value > 255) ? 255 : (img->data[i].g + value < 0) ? 0 : img->data[i].g + value;
        img->data[i].b = (img->data[i].b + value > 255) ? 255 : (img->data[i].b + value < 0) ? 0 : img->data[i].b + value;
    }
}

// Function to change the contrast of an image
void changeContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (unsigned char)(img->data[i].r * factor);
        img->data[i].g = (unsigned char)(img->data[i].g * factor);
        img->data[i].b = (unsigned char)(img->data[i].b * factor);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_value> <contrast_factor>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    int brightnessValue = atoi(argv[3]);
    float contrastFactor = atof(argv[4]);

    // Read the image
    Image *img = readPPM(inputFile);
    if (!img) return 1;

    // Flip the image vertically
    flipImageVertically(img);

    // Change brightness
    changeBrightness(img, brightnessValue);
    
    // Change contrast
    changeContrast(img, contrastFactor);

    // Write the modified image to file
    writePPM(outputFile, img);

    // Free allocated memory
    free(img->data);
    free(img);
    
    printf("Image processing completed successfully. Output saved to %s\n", outputFile);
    
    return 0;
}