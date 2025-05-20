//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness_contrast(Image *img, int brightness, float contrast);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <flip (1/0)> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    int flip = atoi(argv[3]);
    int brightness = atoi(argv[4]);
    float contrast = atof(argv[5]);

    Image *image = load_ppm(input_filename);
    if (image == NULL) {
        fprintf(stderr, "Error loading image\n");
        return 1;
    }

    if (flip) {
        flip_image(image);
    }

    adjust_brightness_contrast(image, brightness, contrast);
    
    save_ppm(output_filename, image);
    free_image(image);

    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    if (strcmp(buffer, "P6\n") != 0) {
        fclose(file);
        fprintf(stderr, "Unsupported PPM format. Use P6 only.\n");
        return NULL;
    }

    fgets(buffer, sizeof(buffer), file);
    while (buffer[0] == '#') {
        fgets(buffer, sizeof(buffer), file);
    }

    int width, height;
    sscanf(buffer, "%d %d", &width, &height);
    fgets(buffer, sizeof(buffer), file);
    int max_color_value = atoi(buffer);
    
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (Pixel *)malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", img->width, img->height);
    fprintf(file, "%d\n", MAX_COLOR_VALUE);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - 1 - x;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + opposite_x];
            img->data[y * img->width + opposite_x] = temp;
        }
    }
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = fmin(fmax((int)(img->data[i].r + brightness) * contrast, 0), MAX_COLOR_VALUE);
        img->data[i].g = fmin(fmax((int)(img->data[i].g + brightness) * contrast, 0), MAX_COLOR_VALUE);
        img->data[i].b = fmin(fmax((int)(img->data[i].b + brightness) * contrast, 0), MAX_COLOR_VALUE);
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}