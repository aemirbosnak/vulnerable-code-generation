//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function to load a PPM image
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Invalid PPM file format\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file); // Read the newline character after the max color value

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
    return img;
}

// Function to save a PPM image
void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    
    fclose(file);
}

// Function to flip an image horizontally
void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - x - 1;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + opposite_x];
            img->data[y * img->width + opposite_x] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i].r + value;
        int g = img->data[i].g + value;
        int b = img->data[i].b + value;
        
        img->data[i].r = (r < 0) ? 0 : (r > 255) ? 255 : r;
        img->data[i].g = (g < 0) ? 0 : (g > 255) ? 255 : g;
        img->data[i].b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    }
}

// Function to change the contrast of an image
void change_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = (int)(img->data[i].r * factor);
        int g = (int)(img->data[i].g * factor);
        int b = (int)(img->data[i].b * factor);

        img->data[i].r = (r < 0) ? 0 : (r > 255) ? 255 : r;
        img->data[i].g = (g < 0) ? 0 : (g > 255) ? 255 : g;
        img->data[i].b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    }
}

// Function to free the image memory
void free_image(Image *img) {
    free(img->data);
    free(img);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_change> <contrast_factor>\n", argv[0]);
        return 1;
    }

    int brightness_change = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);
    
    Image *img = load_image(argv[1]);
    if (!img) return 1;

    printf("Loaded image: %s %dx%d\n", argv[1], img->width, img->height);
    
    flip_image(img);
    printf("Image flipped horizontally.\n");
    
    change_brightness(img, brightness_change);
    printf("Brightness changed by %d.\n", brightness_change);
    
    change_contrast(img, contrast_factor);
    printf("Contrast changed by factor: %.2f.\n", contrast_factor);

    save_image(argv[2], img);
    printf("Saved modified image: %s\n", argv[2]);

    free_image(img);
    
    return 0;
}