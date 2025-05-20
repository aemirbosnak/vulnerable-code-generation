//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image_horizontal(Image *img);
void grayscale_image(Image *img);
void free_image(Image *img);

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image.ppm> <output_image.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    printf("Loaded image: %s [%d x %d]\n", argv[1], img->width, img->height);

    // Perform image operations (e.g., flip and convert to grayscale)
    flip_image_horizontal(img);
    grayscale_image(img);

    // Save the processed image
    save_image(argv[2], img);
    printf("Saved processed image: %s\n", argv[2]);

    free_image(img);
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s\n", header);
    if (strcmp(header, "P6") != 0) {
        fclose(file);
        return NULL; // Only P6 format supported
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving image: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image_horizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - x - 1)];
            img->data[y * img->width + (img->width - x - 1)] = temp;
        }
    }
}

void grayscale_image(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        uint8_t gray = (uint8_t)(0.299 * img->data[i].r + 0.587 * img->data[i].g + 0.114 * img->data[i].b);
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}