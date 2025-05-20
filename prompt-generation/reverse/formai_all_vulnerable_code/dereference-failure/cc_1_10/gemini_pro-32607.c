//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_LAYERS 16

typedef struct {
    unsigned char r, g, b, a;
} Pixel;

typedef struct {
    Pixel **pixels;
    unsigned int width, height;
} Layer;

typedef struct {
    Layer *layers[MAX_LAYERS];
    unsigned int num_layers;
} Image;

Image *new_image(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    image->num_layers = 0;

    for (unsigned int i = 0; i < MAX_LAYERS; i++) {
        image->layers[i] = NULL;
    }

    return image;
}

void free_image(Image *image) {
    for (unsigned int i = 0; i < image->num_layers; i++) {
        for (unsigned int j = 0; j < image->layers[i]->height; j++) {
            free(image->layers[i]->pixels[j]);
        }
        free(image->layers[i]->pixels);
        free(image->layers[i]);
    }

    free(image);
}

Layer *new_layer(unsigned int width, unsigned int height) {
    Layer *layer = malloc(sizeof(Layer));
    layer->width = width;
    layer->height = height;
    layer->pixels = malloc(sizeof(Pixel *) * height);

    for (unsigned int i = 0; i < height; i++) {
        layer->pixels[i] = malloc(sizeof(Pixel) * width);
    }

    return layer;
}

void free_layer(Layer *layer) {
    for (unsigned int i = 0; i < layer->height; i++) {
        free(layer->pixels[i]);
    }
    free(layer->pixels);
    free(layer);
}

void add_layer(Image *image, Layer *layer) {
    if (image->num_layers < MAX_LAYERS) {
        image->layers[image->num_layers++] = layer;
    }
}

void remove_layer(Image *image, unsigned int index) {
    if (index < image->num_layers) {
        free_layer(image->layers[index]);
        for (unsigned int i = index; i < image->num_layers - 1; i++) {
            image->layers[i] = image->layers[i + 1];
        }
        image->num_layers--;
    }
}

void set_pixel(Image *image, unsigned int layer, unsigned int x, unsigned int y, Pixel pixel) {
    if (layer < image->num_layers && x < image->layers[layer]->width && y < image->layers[layer]->height) {
        image->layers[layer]->pixels[y][x] = pixel;
    }
}

Pixel get_pixel(Image *image, unsigned int layer, unsigned int x, unsigned int y) {
    if (layer < image->num_layers && x < image->layers[layer]->width && y < image->layers[layer]->height) {
        return image->layers[layer]->pixels[y][x];
    }

    return (Pixel){0, 0, 0, 0};
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp != NULL) {
        fprintf(fp, "P3\n");
        fprintf(fp, "%d %d\n", image->layers[0]->width, image->layers[0]->height);
        fprintf(fp, "255\n");

        for (unsigned int y = 0; y < image->layers[0]->height; y++) {
            for (unsigned int x = 0; x < image->layers[0]->width; x++) {
                Pixel pixel = get_pixel(image, 0, x, y);
                fprintf(fp, "%d %d %d\n", pixel.r, pixel.g, pixel.b);
            }
        }

        fclose(fp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    Image *image = new_image(WIDTH, HEIGHT);
    Layer *layer = new_layer(WIDTH, HEIGHT);

    for (unsigned int y = 0; y < layer->height; y++) {
        for (unsigned int x = 0; x < layer->width; x++) {
            Pixel pixel = {0, 0, 0, 255};
            set_pixel(image, 0, x, y, pixel);
        }
    }

    add_layer(image, layer);

    save_image(image, argv[1]);

    free_image(image);

    return 0;
}