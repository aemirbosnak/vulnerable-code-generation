//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness_contrast(Image *img, int brightness, float contrast);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Load the image
    Image *image = load_ppm(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Could not load image.\n");
        return EXIT_FAILURE;
    }
    
    // Flip the image
    flip_image(image);
    save_ppm("flipped.ppm", image);
    printf("Flipped image saved as flipped.ppm\n");

    // Adjust brightness and contrast
    int brightness = 50; // Increase brightness
    float contrast = 1.5; // Increase contrast
    adjust_brightness_contrast(image, brightness, contrast);
    save_ppm("brightness_contrast.ppm", image);
    printf("Image with adjusted brightness and contrast saved as brightness_contrast.ppm\n");

    // Clean up
    free_image(image);
    return EXIT_SUCCESS;
}

Image* load_ppm(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Cannot open file");
        return NULL;
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), fp)) {
        perror("Reading PPM header");
        return NULL;
    }
    if (buffer[0] != 'P' || buffer[1] != '3') {
        fprintf(stderr, "Unsupported PPM format (only P3 supported).\n");
        return NULL;
    }

    int width, height, max_color;
    fscanf(fp, "%d %d %d", &width, &height, &max_color);
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    for (int i = 0; i < width * height; i++) {
        fscanf(fp, "%hhu %hhu %hhu", &img->data[i].r, &img->data[i].g, &img->data[i].b);
    }
    fclose(fp);
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Cannot open file");
        return;
    }

    fprintf(fp, "P3\n%d %d\n255\n", img->width, img->height);
    for (int i = 0; i < img->width * img->height; i++) {
        fprintf(fp, "%d %d %d ", img->data[i].r, img->data[i].g, img->data[i].b);
    }
    fclose(fp);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            Pixel temp = img->data[y * width + x];
            img->data[y * width + x] = img->data[(height - 1 - y) * width + x];
            img->data[(height - 1 - y) * width + x] = temp;
        }
    }
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = fmin(255, fmax(0, img->data[i].r + brightness));
        img->data[i].g = fmin(255, fmax(0, img->data[i].g + brightness));
        img->data[i].b = fmin(255, fmax(0, img->data[i].b + brightness));

        img->data[i].r = fmin(255, fmax(0, (int)((((img->data[i].r / 255.0) - 0.5) * contrast + 0.5) * 255)));
        img->data[i].g = fmin(255, fmax(0, (int)((((img->data[i].g / 255.0) - 0.5) * contrast + 0.5) * 255)));
        img->data[i].b = fmin(255, fmax(0, (int)((((img->data[i].b / 255.0) - 0.5) * contrast + 0.5) * 255)));
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}