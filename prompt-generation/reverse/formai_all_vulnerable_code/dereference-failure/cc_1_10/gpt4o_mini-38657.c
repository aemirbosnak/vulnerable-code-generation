//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    char header[3]; // PPM Header: "P6"
    int width;
    int height;
    int max_value;
    Pixel *data;
} Image;

Image *load_ppm(const char *filename);
void save_ppm(const char *filename, const Image *img);
void flip_image(Image *img);
void change_brightness(Image *img, int value);
void change_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image *img = load_ppm(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    flip_image(img);
    change_brightness(img, atoi(argv[3]));
    change_contrast(img, atof(argv[4]));
    save_ppm(argv[2], img);
    
    free_image(img);
    return 0;
}

Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    if (!img) {
        fclose(file);
        perror("Could not allocate memory for Image");
        return NULL;
    }

    fgets(img->header, sizeof(img->header), file);
    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &img->max_value);
    fgetc(file); // Consume the newline after max_value

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fprintf(file, "%s\n%d %d\n%d\n", img->header, img->width, img->height, img->max_value);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    Pixel *flipped_data = malloc(width * height * sizeof(Pixel));
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            flipped_data[y * width + x] = img->data[y * width + (width - 1 - x)];
        }
    }

    free(img->data);
    img->data = flipped_data;
}

void change_brightness(Image *img, int value) {
    int width = img->width;
    int height = img->height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *pixel = &img->data[y * width + x];
            pixel->r = (pixel->r + value > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : (pixel->r + value < 0) ? 0 : (pixel->r + value);
            pixel->g = (pixel->g + value > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : (pixel->g + value < 0) ? 0 : (pixel->g + value);
            pixel->b = (pixel->b + value > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : (pixel->b + value < 0) ? 0 : (pixel->b + value);
        }
    }
}

void change_contrast(Image *img, float factor) {
    int width = img->width;
    int height = img->height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Pixel *pixel = &img->data[y * width + x];
            pixel->r = (int)((((float)pixel->r / MAX_COLOR_VALUE) - 0.5) * factor + 0.5) * MAX_COLOR_VALUE;
            pixel->g = (int)((((float)pixel->g / MAX_COLOR_VALUE) - 0.5) * factor + 0.5) * MAX_COLOR_VALUE;
            pixel->b = (int)((((float)pixel->b / MAX_COLOR_VALUE) - 0.5) * factor + 0.5) * MAX_COLOR_VALUE;

            // Clamp values to [0, 255]
            pixel->r = pixel->r < 0 ? 0 : (pixel->r > MAX_COLOR_VALUE ? MAX_COLOR_VALUE : pixel->r);
            pixel->g = pixel->g < 0 ? 0 : (pixel->g > MAX_COLOR_VALUE ? MAX_COLOR_VALUE : pixel->g);
            pixel->b = pixel->b < 0 ? 0 : (pixel->b > MAX_COLOR_VALUE ? MAX_COLOR_VALUE : pixel->b);
        }
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}