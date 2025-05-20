//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "@%#*+=-:. " // Characters to represent pixels from darkest to lightest

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    Pixel **data;
    int width;
    int height;
} Image;

Image* loadImage(const char* filename);
void freeImage(Image *img);
void convertToASCII(Image *img, int newWidth);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return 1;
    }

    const char *filename = argv[1];
    int newWidth = atoi(argv[2]);

    if (newWidth < 1 || newWidth > MAX_WIDTH) {
        fprintf(stderr, "Width must be between 1 and %d.\n", MAX_WIDTH);
        return 1;
    }

    Image *img = loadImage(filename);
    if (img == NULL) {
        fprintf(stderr, "Error loading image: %s\n", filename);
        return 1;
    }

    convertToASCII(img, newWidth);
    freeImage(img);
    
    return 0;
}

void printUsage() {
    printf("Usage: image_to_ascii <image_file> <output_width>\n");
    printf("Example: image_to_ascii input.ppm 80\n");
}

Image* loadImage(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Read the PPM header
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "File format not supported (only P6 is supported).\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxColorValue;
    fscanf(file, "%d %d\n%d\n", &width, &height, &maxColorValue);
    
    if (maxColorValue != 255) {
        fprintf(stderr, "Only 8-bit PPM files are supported.\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    
    img->data = malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        img->data[i] = malloc(width * sizeof(Pixel));
    }

    // Read pixel data
    fread(img->data[0], sizeof(Pixel), width * height, file);
    fclose(file);
    
    return img;
}

void freeImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

int getGrayScale(Pixel pixel) {
    // Calculate luminance using the formula: 0.299 * R + 0.587 * G + 0.114 * B
    return (int)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
}

void convertToASCII(Image *img, int newWidth) {
    float aspectRatio = (float)img->height / (float)img->width;
    int newHeight = (int)(newWidth * aspectRatio / 2.0); // Adjust height due to character aspect ratio

    printf("Generating ASCII art of dimensions %d x %d...\n", newWidth, newHeight);
    
    // Scale the image and convert to ASCII
    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            // Calculate the location in the original image
            int origX = (int)((float)x / newWidth * img->width);
            int origY = (int)((float)y / newHeight * img->height);
            
            Pixel pixel = img->data[origY][origX];
            int gray = getGrayScale(pixel);
            char asciiChar = ASCII_CHARS[gray * (strlen(ASCII_CHARS) - 1) / 255]; // Map grayscale to ASCII
            
            putchar(asciiChar);
        }
        putchar('\n');
    }
}