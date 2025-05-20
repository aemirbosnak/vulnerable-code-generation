//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    Image *img = (Image *)malloc(sizeof(Image));
    if (!img) {
        fclose(file);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    
    fseek(file, 54, SEEK_SET); // Skip headers
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Cannot save file %s\n", filename);
        return;
    }

    uint8_t bmpHeader[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0,
        0, 0, 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0
    };

    int rowSize = (3 * img->width + 3) / 4 * 4; // Row size padded to multiple of 4 bytes
    int imageSize = rowSize * img->height;
    
    *(int *)&bmpHeader[2] = 54 + imageSize;   // file size
    *(int *)&bmpHeader[18] = img->width;      // width
    *(int *)&bmpHeader[22] = img->height;     // height

    fwrite(bmpHeader, sizeof(bmpHeader), 1, file);
    for (int y = img->height - 1; y >= 0; y--) {
        for (int x = 0; x < img->width; x++) {
            Pixel p = img->pixels[y * img->width + x];
            fwrite(&p, sizeof(Pixel), 1, file);
        }
        uint8_t padding[3] = {0, 0, 0};
        fwrite(padding, rowSize - (img->width * sizeof(Pixel)), 1, file);
    }
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + (img->width - 1 - x)];
            img->pixels[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r + adjustment > 255) ? 255 : img->pixels[i].r + adjustment;
        img->pixels[i].g = (img->pixels[i].g + adjustment > 255) ? 255 : img->pixels[i].g + adjustment;
        img->pixels[i].b = (img->pixels[i].b + adjustment > 255) ? 255 : img->pixels[i].b + adjustment;
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (uint8_t)fmin(fmax((img->pixels[i].r - 128) * factor + 128, 0), 255);
        img->pixels[i].g = (uint8_t)fmin(fmax((img->pixels[i].g - 128) * factor + 128, 0), 255);
        img->pixels[i].b = (uint8_t)fmin(fmax((img->pixels[i].b - 128) * factor + 128, 0), 255);
    }
}

void free_image(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <1 for flip, 2 for adjust brightness, 3 for contrast adjust>\n",
                argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    int task = atoi(argv[3]);

    switch (task) {
        case 1:
            flip_image(img);
            break;
        case 2:
            adjust_brightness(img, 50); // Brightness increase
            break;
        case 3:
            adjust_contrast(img, 1.2); // Increasing contrast
            break;
        default:
            fprintf(stderr, "Invalid task\n");
            free_image(img);
            return 1;
    }

    save_image(argv[2], img);
    free_image(img);
    return 0;
}