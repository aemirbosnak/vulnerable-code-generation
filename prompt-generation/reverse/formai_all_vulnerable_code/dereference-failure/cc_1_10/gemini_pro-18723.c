//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_LAYERS 16

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel pixels[MAX_WIDTH * MAX_HEIGHT];
} Layer;

typedef struct {
    int num_layers;
    Layer layers[MAX_LAYERS];
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->num_layers = 0;
    for (int i = 0; i < MAX_LAYERS; i++) {
        image->layers[i].width = width;
        image->layers[i].height = height;
        memset(image->layers[i].pixels, 0, sizeof(Pixel) * width * height);
    }
    return image;
}

void free_image(Image *image) {
    free(image);
}

void add_layer(Image *image) {
    if (image->num_layers < MAX_LAYERS) {
        image->num_layers++;
    }
}

void remove_layer(Image *image, int index) {
    if (index >= 0 && index < image->num_layers) {
        for (int i = index + 1; i < image->num_layers; i++) {
            image->layers[i - 1] = image->layers[i];
        }
        image->num_layers--;
    }
}

void set_pixel(Image *image, int layer, int x, int y, Pixel pixel) {
    if (layer >= 0 && layer < image->num_layers && x >= 0 && x < image->layers[layer].width && y >= 0 && y < image->layers[layer].height) {
        image->layers[layer].pixels[y * image->layers[layer].width + x] = pixel;
    }
}

Pixel get_pixel(Image *image, int layer, int x, int y) {
    if (layer >= 0 && layer < image->num_layers && x >= 0 && x < image->layers[layer].width && y >= 0 && y < image->layers[layer].height) {
        return image->layers[layer].pixels[y * image->layers[layer].width + x];
    }
    return (Pixel) { 0, 0, 0 };
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }
    fprintf(file, "P6\n%d %d\n255\n", image->layers[0].width, image->layers[0].height);
    for (int i = 0; i < image->layers[0].width * image->layers[0].height; i++) {
        Pixel pixel = get_pixel(image, 0, i % image->layers[0].width, i / image->layers[0].width);
        fwrite(&pixel, sizeof(Pixel), 1, file);
    }
    fclose(file);
}

int main() {
    Image *image = new_image(MAX_WIDTH, MAX_HEIGHT);
    add_layer(image);
    set_pixel(image, 0, 0, 0, (Pixel) { 255, 0, 0 });
    set_pixel(image, 0, 100, 100, (Pixel) { 0, 255, 0 });
    set_pixel(image, 0, 200, 200, (Pixel) { 0, 0, 255 });
    save_image(image, "image.ppm");
    free_image(image);
    return 0;
}