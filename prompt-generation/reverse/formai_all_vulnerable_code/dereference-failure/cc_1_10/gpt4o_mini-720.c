//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename) {
    Image *img = malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    
    fseek(file, 18, SEEK_SET);
    fread(&(img->width), sizeof(int), 1, file);
    fread(&(img->height), sizeof(int), 1, file);
    
    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fseek(file, 54, SEEK_SET);
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Write BMP Header 
    unsigned char header[54] = {
        0x42, 0x4D, 0,0,0,0, 0,0, 0,0, 0x36,0,0,0, 
        0x28,0,0,0, 0,0,0,0, 0,0,0,0, 0x01,0,0x18,0 
    };
    
    int rowSize = (img->width * 3 + 3) & (~3);
    int fileSize = 54 + rowSize * img->height;
    
    header[2] = (unsigned char)(fileSize);
    header[3] = (unsigned char)(fileSize >> 8);
    header[4] = (unsigned char)(fileSize >> 16);
    header[5] = (unsigned char)(fileSize >> 24);
    
    header[18] = (unsigned char)(img->width);
    header[19] = (unsigned char)(img->width >> 8);
    header[20] = (unsigned char)(img->width >> 16);
    header[21] = (unsigned char)(img->width >> 24);
    
    header[22] = (unsigned char)(img->height);
    header[23] = (unsigned char)(img->height >> 8);
    header[24] = (unsigned char)(img->height >> 16);
    header[25] = (unsigned char)(img->height >> 24);
    
    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height / 2; ++y) {
        for (int x = 0; x < img->width; ++x) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
            img->data[(img->height - y - 1) * img->width + x] = temp;
        }
    }
}

void adjust_brightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (img->data[i].r + adjustment > 255) ? 255 : (img->data[i].r + adjustment < 0) ? 0 : img->data[i].r + adjustment;
        img->data[i].g = (img->data[i].g + adjustment > 255) ? 255 : (img->data[i].g + adjustment < 0) ? 0 : img->data[i].g + adjustment;
        img->data[i].b = (img->data[i].b + adjustment > 255) ? 255 : (img->data[i].b + adjustment < 0) ? 0 : img->data[i].b + adjustment;
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (unsigned char)(factor * (img->data[i].r - 128) + 128);
        img->data[i].g = (unsigned char)(factor * (img->data[i].g - 128) + 128);
        img->data[i].b = (unsigned char)(factor * (img->data[i].b - 128) + 128);
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

int main() {
    const char *input = "input.bmp";
    const char *output_flip = "flipped_output.bmp";
    const char *output_bright = "bright_output.bmp";
    const char *output_contrast = "contrast_output.bmp";
    
    Image *img = load_image(input);
    if (!img) {
        return EXIT_FAILURE;
    }
    
    flip_image(img);
    save_image(output_flip, img);
    
    adjust_brightness(img, 20);
    save_image(output_bright, img);
    
    adjust_contrast(img, 1.2);
    save_image(output_contrast, img);
    
    free_image(img);
    
    return EXIT_SUCCESS;
}