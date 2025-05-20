//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function to load BMP image
Image* loadBMP(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    Image *img = malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    fseek(file, 54, SEEK_SET);  // Skip the BMP header
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
    return img;
}

// Function to save BMP image
void saveBMP(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Cannot save file %s\n", filename);
        return;
    }

    // BMP header
    unsigned char header[54] = {
        'B','M',  // BM Magic Number
        0,0,0,0,  // Size of the BMP file
        0,0,0,0,  // Reserved
        54,0,0,0, // Offset to pixel data
        40,0,0,0, // Header size
        0,0,0,0,  // Width
        0,0,0,0,  // Height
        1,0,      // color planes
        24,0,     // bits per pixel
        0,0,0,0,  // compression
        0,0,0,0,  // Image size (can be zero for uncompressed)
        0x13B,0x0,0,0, // horizontal resolution (pixels per meter)
        0x13B,0x0,0,0, // vertical resolution (pixels per meter)
        0,0,0,0,  // colors in color palette
        0,0,0,0   // important color count
    };
    
    // Update header with width and height
    *(int*)&header[18] = img->width;
    *(int*)&header[22] = img->height;
    *(int*)&header[2] = 54 + (img->width * img->height * sizeof(Pixel));

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

// Function to flip the image vertically
void flipImageVertically(Image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            // Swap pixels
            Pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[(img->height - 1 - y) * img->width + x];
            img->pixels[(img->height - 1 - y) * img->width + x] = temp;
        }
    }
}

// Function to change brightness
void changeBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char)fmin(fmax(img->pixels[i].r + value, 0), 255);
        img->pixels[i].g = (unsigned char)fmin(fmax(img->pixels[i].g + value, 0), 255);
        img->pixels[i].b = (unsigned char)fmin(fmax(img->pixels[i].b + value, 0), 255);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness_change>\n", argv[0]);
        return 1;
    }

    Image *img = loadBMP(argv[1]);
    if (!img) {
        return 1;
    }

    int brightness_change = atoi(argv[3]);

    // Apply image transformations
    printf("Adjusting brightness by %d...\n", brightness_change);
    changeBrightness(img, brightness_change);

    printf("Flipping image vertically...\n");
    flipImageVertically(img);

    // Save the modified image
    saveBMP(argv[2], img);

    printf("Image processing completed. Saved to %s\n", argv[2]);
    
    // Free allocated memory
    free(img->pixels);
    free(img);
    
    return 0;
}