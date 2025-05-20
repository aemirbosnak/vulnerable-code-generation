//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} RGB;

typedef struct {
    int width;
    int height;
    RGB *data;
} Image;

Image* load_image(const char* filename);
void save_image(const char* filename, Image* img);
Image* flip_image_horizontal(Image* img);
void change_brightness_contrast(Image* img, int brightness, float contrast);
void free_image(Image* img);

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_image> <output_image> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    printf("Image loaded: %d x %d\n", img->width, img->height);
    
    int brightness = atoi(argv[3]);
    float contrast = (float)atof(argv[4]);

    Image* flipped_img = flip_image_horizontal(img);
    change_brightness_contrast(flipped_img, brightness, contrast);
    save_image(argv[2], flipped_img);

    free_image(img);
    free_image(flipped_img);
    
    printf("Processed image saved as: %s\n", argv[2]);

    return 0;
}

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    // Basic BMP header parsing (assuming 24-bit uncompressed BMP)
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(RGB));
    
    fseek(file, 54, SEEK_SET); // Skip to the pixel data
    fread(img->data, sizeof(RGB), width * height, file);
    
    fclose(file);
    return img;
}

void save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) return;

    // Write a basic BMP header for a 24-bit uncompressed BMP
    uint16_t bmp_header[27] = {
        0x4D42, // BMP magic number
        0, 0, // File size (to be filled in later)
        0, 0, // Reserved
        54, // Pixel data offset
        40, // DIB header size
        (uint32_t) img->width, (uint32_t) img->height,
        1,  // Number of color planes
        24, // Bits per pixel
        0, 0, 0, 0, // Compression settings
        0, 0, 0, 0, // Image size
        0, 0, 0, 0, // Horizontal resolution
        0, 0, 0, 0, // Vertical resolution
        0, 0, 0, 0, // Number of colors
        0, 0, 0, 0  // Important colors
    };

    uint32_t file_size = 54 + img->width * img->height * sizeof(RGB);
    bmp_header[2] = file_size;
    bmp_header[10] = 54;

    fwrite(bmp_header, sizeof(bmp_header), 1, file);
    fwrite(img->data, sizeof(RGB), img->width * img->height, file);

    fclose(file);
}

Image* flip_image_horizontal(Image* img) {
    Image* flipped_img = malloc(sizeof(Image));
    flipped_img->width = img->width;
    flipped_img->height = img->height;
    flipped_img->data = malloc(img->width * img->height * sizeof(RGB));

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            flipped_img->data[y * img->width + (img->width - x - 1)] = img->data[y * img->width + x];
        }
    }

    return flipped_img;
}

void change_brightness_contrast(Image* img, int brightness, float contrast) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            RGB *pixel = &img->data[y * img->width + x];
            int r = pixel->r + brightness;
            int g = pixel->g + brightness;
            int b = pixel->b + brightness;

            r = (int)((r - 128) * contrast + 128);
            g = (int)((g - 128) * contrast + 128);
            b = (int)((b - 128) * contrast + 128);

            pixel->r = (r < 0) ? 0 : (r > 255) ? 255 : r;
            pixel->g = (g < 0) ? 0 : (g > 255) ? 255 : g;
            pixel->b = (b < 0) ? 0 : (b > 255) ? 255 : b;
        }
    }
}

void free_image(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}