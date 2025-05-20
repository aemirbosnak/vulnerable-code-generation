//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function prototypes
Image *load_ppm(const char *filename);
void save_ppm(const char *filename, const Image *img);
void flip_image(Image *img);
void change_brightness(Image *img, int adjustment);
void change_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <flip (0/1)> <brightness adjustment>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int flip = atoi(argv[3]);
    int brightness_adjustment = atoi(argv[4]); // Positive for brightness increase, negative for decrease

    Image *img = load_ppm(input_file);
    if (!img) {
        fprintf(stderr, "Could not load image %s\n", input_file);
        return 1;
    }

    if (flip) {
        flip_image(img);
    }
    
    // Change brightness
    change_brightness(img, brightness_adjustment);

    // Change contrast (example factor, can be modified)
    change_contrast(img, 1.5);

    save_ppm(output_file, img);
    free_image(img);

    return 0;
}

Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Unsupported PPM format\n");
        fclose(file);
        return NULL;
    }

    int width, height, max_color;
    fscanf(file, "%d %d %d", &width, &height, &max_color);
    fgetc(file);  // Read the newline after max_color

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("File opening failed");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int row_size = img->width;
    for (int i = 0; i < img->height; ++i) {
        for (int j = 0; j < row_size / 2; ++j) {
            Pixel temp = img->data[i * row_size + j];
            img->data[i * row_size + j] = img->data[i * row_size + (row_size - j - 1)];
            img->data[i * row_size + (row_size - j - 1)] = temp;
        }
    }
}

void change_brightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (img->data[i].r + adjustment > 255) ? 255 : (img->data[i].r + adjustment < 0) ? 0 : img->data[i].r + adjustment;
        img->data[i].g = (img->data[i].g + adjustment > 255) ? 255 : (img->data[i].g + adjustment < 0) ? 0 : img->data[i].g + adjustment;
        img->data[i].b = (img->data[i].b + adjustment > 255) ? 255 : (img->data[i].b + adjustment < 0) ? 0 : img->data[i].b + adjustment;
    }
}

void change_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (unsigned char)(fmin(255, fmax(0, factor * (img->data[i].r - 128) + 128)));
        img->data[i].g = (unsigned char)(fmin(255, fmax(0, factor * (img->data[i].g - 128) + 128)));
        img->data[i].b = (unsigned char)(fmin(255, fmax(0, factor * (img->data[i].b - 128) + 128)));
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}