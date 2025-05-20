//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;
typedef struct {
    int width;
    int height;
    BYTE *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness_contrast(Image *img, int brightness, float contrast);
void free_image(Image *img);

int main() {
    const char *input_filename = "input.bmp";
    const char *output_filename = "output.bmp";
    
    Image *image = load_image(input_filename);
    if (!image) {
        fprintf(stderr, "Failed to load image.\n");
        return 1;
    }

    flip_image(image);
    adjust_brightness_contrast(image, 50, 1.5);

    save_image(output_filename, image);
    free_image(image);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 18, SEEK_SET); // Skip header to get width
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    
    fseek(file, 54, SEEK_SET); // Skip to pixel data
    BYTE *data = (BYTE*)malloc(width * height * 3);
    fread(data, 3, width * height, file);
    fclose(file);

    Image *img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = data;

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    // Writing a simple BMP header for now (not complete)
    BYTE bmpHeader[54] = {
        0x42, 0x4D, 54 + img->width * img->height * 3, 0, 0, 0, 0, 0, 0, 0,
        0x36, 0, 0, 0, 0x28, 0, 0, 0, 0, 0, 0, 0, 
        0x01, 0x00, 0x18, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    *(int*)&bmpHeader[18] = img->width;
    *(int*)&bmpHeader[22] = img->height;
    fwrite(bmpHeader, sizeof(BYTE), 54, file);

    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    BYTE *flipped_data = (BYTE*)malloc(width * height * 3);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_index = (y * width + x) * 3;
            int dest_index = (y * width + (width - x - 1)) * 3;
            flipped_data[dest_index] = img->data[src_index];     // Blue
            flipped_data[dest_index + 1] = img->data[src_index + 1]; // Green
            flipped_data[dest_index + 2] = img->data[src_index + 2]; // Red
        }
    }
    
    free(img->data);
    img->data = flipped_data;
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    int width = img->width;
    int height = img->height;

    for (int i = 0; i < width * height * 3; i++) {
        int value = img->data[i];
        value += brightness;
        value = (int)((((value - 128) * contrast) + 128));
        if (value < 0) value = 0;
        if (value > 255) value = 255;
        img->data[i] = (BYTE)value;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}