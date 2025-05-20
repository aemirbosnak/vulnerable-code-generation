//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[HEIGHT][WIDTH];
} Image;

void load_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }
    fread(img, sizeof(Image), 1, file);
    fclose(file);
}

void save_image(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Cannot save file %s\n", filename);
        exit(1);
    }
    fwrite(img, sizeof(Image), 1, file);
    fclose(file);
}

void flip_image_horizontal(Image *img) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            Pixel temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][WIDTH - x - 1];
            img->pixels[y][WIDTH - x - 1] = temp;
        }
    }
}

void change_brightness(Image *img, int brightness) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[y][x].r = (uint8_t)fmin(fmax(img->pixels[y][x].r + brightness, 0), 255);
            img->pixels[y][x].g = (uint8_t)fmin(fmax(img->pixels[y][x].g + brightness, 0), 255);
            img->pixels[y][x].b = (uint8_t)fmin(fmax(img->pixels[y][x].b + brightness, 0), 255);
        }
    }
}

void change_contrast(Image *img, float factor) {
    float contrast = (factor + 255) / (255 * (1 - factor));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[y][x].r = (uint8_t)fmin(fmax((contrast * (img->pixels[y][x].r - 128) + 128), 0), 255);
            img->pixels[y][x].g = (uint8_t)fmin(fmax((contrast * (img->pixels[y][x].g - 128) + 128), 0), 255);
            img->pixels[y][x].b = (uint8_t)fmin(fmax((contrast * (img->pixels[y][x].b - 128) + 128), 0), 255);
        }
    }
}

void print_image_info(const Image *img) {
    printf("Image size: %dx%d\n", WIDTH, HEIGHT);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input> <output> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(argv[1], &img);

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    print_image_info(&img);
    
    printf("Flipping image horizontally...\n");
    flip_image_horizontal(&img);
    
    printf("Changing brightness by %d...\n", brightness);
    change_brightness(&img, brightness);
    
    printf("Changing contrast by factor of %.2f...\n", contrast);
    change_contrast(&img, contrast);

    save_image(argv[2], &img);
    printf("Processed image saved to %s\n", argv[2]);
    
    return 0;
}