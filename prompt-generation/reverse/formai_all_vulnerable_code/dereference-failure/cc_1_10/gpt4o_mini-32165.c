//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: thoughtful
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
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Skip the BMP header
    fseek(file, 54, SEEK_SET);
    
    Image *img = (Image *)malloc(sizeof(Image));
    if (!img) {
        perror("Unable to allocate memory for image");
        fclose(file);
        return NULL;
    }

    img->width = 800;  // Placeholder value, replace with actual BMP parsing
    img->height = 600; // Placeholder value, replace with actual BMP parsing
    img->data = (Pixel *)malloc(sizeof(Pixel) * img->width * img->height);
    
    if (!img->data) {
        perror("Unable to allocate memory for pixel data");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save file");
        return;
    }

    // Writing a simple BMP header (without compression)
    unsigned char bmpfileheader[54] = {
        'B', 'M',  // Magic
        0, 0, 0, 0,  // File size (we'll update later)
        0, 0, 0, 0,  // Reserved
        54, 0, 0, 0,  // Offset to start of pixel data
        40, 0, 0, 0,  // Size of this header
        0, 0, 0, 0,  // Width (we'll update later)
        0, 0, 0, 0,  // Height (we'll update later)
        1, 0,       // Planes
        24, 0,      // Bits per pixel
        0, 0, 0, 0, // Compression
        0, 0, 0, 0, // Image size (guaranteed to be zero for uncompressed)
        0, 0, 0, 0, // X pixels per meter (print resolution)
        0, 0, 0, 0, // Y pixels per meter (print resolution)
        0, 0, 0, 0, // Total colors
        0, 0, 0, 0  // Important colors
    };

    int filesize = 54 + img->width * img->height * 3; // 3 bytes per pixel
    bmpfileheader[2] = (unsigned char)(filesize);
    bmpfileheader[3] = (unsigned char)(filesize >> 8);
    bmpfileheader[4] = (unsigned char)(filesize >> 16);
    bmpfileheader[5] = (unsigned char)(filesize >> 24);
    
    bmpfileheader[18] = (unsigned char)(img->width);
    bmpfileheader[19] = (unsigned char)(img->width >> 8);
    bmpfileheader[20] = (unsigned char)(img->width >> 16);
    bmpfileheader[21] = (unsigned char)(img->width >> 24);
    
    bmpfileheader[22] = (unsigned char)(img->height);
    bmpfileheader[23] = (unsigned char)(img->height >> 8);
    bmpfileheader[24] = (unsigned char)(img->height >> 16);
    bmpfileheader[25] = (unsigned char)(img->height >> 24);
    
    fwrite(bmpfileheader, sizeof(bmpfileheader), 1, file);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

Image* flip_image(Image *img) {
    Image *flipped = (Image *)malloc(sizeof(Image));
    flipped->width = img->width;
    flipped->height = img->height;
    flipped->data = (Pixel *)malloc(sizeof(Pixel) * flipped->width * flipped->height);

    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            flipped->data[(img->height - 1 - i) * img->width + j] = img->data[i * img->width + j];
        }
    }

    return flipped;
}

void change_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax(img->data[i].r + value, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax(img->data[i].g + value, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax(img->data[i].b + value, 0), 255);
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax((img->data[i].r - 128) * factor + 128, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax((img->data[i].g - 128) * factor + 128, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax((img->data[i].b - 128) * factor + 128, 0), 255);
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

int main() {
    Image *img = load_image("input.bmp");
    if (!img) {
        return 1;
    }

    Image *flipped = flip_image(img);
    save_image("flipped_output.bmp", flipped);
    change_brightness(img, 50);
    save_image("brightness_output.bmp", img);
    adjust_contrast(img, 1.5);
    save_image("contrast_output.bmp", img);

    free_image(img);
    free_image(flipped);

    return 0;
}