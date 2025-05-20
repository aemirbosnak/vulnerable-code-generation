//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1) // Pack the structures to avoid padding

typedef struct {
    uint16_t bfType;      // Signature
    uint32_t bfSize;      // File size in bytes
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to bitmap data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Image size
    int32_t  biXPelsPerMeter;   // Horizontal resolution
    int32_t  biYPelsPerMeter;   // Vertical resolution
    uint32_t biClrUsed;        // Number of colors in the color palette
    uint32_t biClrImportant;    // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;  // Blue component
    uint8_t green; // Green component
    uint8_t red;   // Red component
} PIXEL;

// Function to load the bitmap file
PIXEL* load_bmp(const char* filename, BITMAPFILEHEADER* bfh, BITMAPINFOHEADER* bih) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    fread(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, file);

    // Allocate memory for pixels
    int pixel_data_size = bih->biWidth * bih->biHeight * sizeof(PIXEL);
    PIXEL* pixels = (PIXEL*)malloc(pixel_data_size);
    fseek(file, bfh->bfOffBits, SEEK_SET);
    fread(pixels, pixel_data_size, 1, file);

    fclose(file);
    return pixels;
}

// Function to save the bitmap file
void save_bmp(const char* filename, const BITMAPFILEHEADER* bfh, const BITMAPINFOHEADER* bih, PIXEL* pixels) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not create file");
        return;
    }

    fwrite(bfh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(bih, sizeof(BITMAPINFOHEADER), 1, file);
    
    // Write pixel data
    int pixel_data_size = bih->biWidth * bih->biHeight * sizeof(PIXEL);
    fwrite(pixels, pixel_data_size, 1, file);
    
    fclose(file);
}

// Function to flip the image vertically
void flip_image(PIXEL* pixels, int width, int height) {
    PIXEL temp;
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[(height - 1 - i) * width + j];
            pixels[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to change brightness
void adjust_brightness(PIXEL* pixels, int width, int height, int value) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = (uint8_t) fmin(fmax(pixels[i].red + value, 0), 255);
        pixels[i].green = (uint8_t) fmin(fmax(pixels[i].green + value, 0), 255);
        pixels[i].blue = (uint8_t) fmin(fmax(pixels[i].blue + value, 0), 255);
    }
}

// Function to change contrast
void adjust_contrast(PIXEL* pixels, int width, int height, float factor) {
    float contrast_value = (factor + 1.0f) / (1.0f + (0.5f * factor));
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = (uint8_t) fmin(fmax(contrast_value * (pixels[i].red - 128) + 128, 0), 255);
        pixels[i].green = (uint8_t) fmin(fmax(contrast_value * (pixels[i].green - 128) + 128, 0), 255);
        pixels[i].blue = (uint8_t) fmin(fmax(contrast_value * (pixels[i].blue - 128) + 128, 0), 255);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s input.bmp output.bmp\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    PIXEL* pixels = load_bmp(argv[1], &bfh, &bih);
    if (!pixels) {
        return 1;
    }

    // Flip image
    flip_image(pixels, bih.biWidth, bih.biHeight);
    
    // Adjust brightness
    adjust_brightness(pixels, bih.biWidth, bih.biHeight, 50);
    
    // Adjust contrast
    adjust_contrast(pixels, bih.biWidth, bih.biHeight, 1.5f); // Factor of 1.5 for enhancing contrast

    // Save result
    save_bmp(argv[2], &bfh, &bih, pixels);

    // Clean up
    free(pixels);
    printf("Processing complete! Output saved as %s\n", argv[2]);
    return 0;
}