//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t *data;
    int width;
    int height;
    int channels;
} Image;

Image *create_image(int width, int height, int channels) {
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * channels);
    image->width = width;
    image->height = height;
    image->channels = channels;
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void set_pixel(Image *image, int x, int y, int channel, uint8_t value) {
    image->data[(y * image->width + x) * image->channels + channel] = value;
}

uint8_t get_pixel(Image *image, int x, int y, int channel) {
    return image->data[(y * image->width + x) * image->channels + channel];
}

void save_image(Image *image, const char *filename) {
    FILE *f = fopen(filename, "wb");
    fwrite(image->data, 1, image->width * image->height * image->channels, f);
    fclose(f);
}

int main() {
    Image *image = create_image(512, 512, 3);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            set_pixel(image, x, y, 0, (uint8_t) (255 * (double) x / (image->width - 1)));
            set_pixel(image, x, y, 1, (uint8_t) (255 * (double) y / (image->height - 1)));
            set_pixel(image, x, y, 2, (uint8_t) (255 * (double) (x + y) / (image->width + image->height - 2)));
        }
    }

    save_image(image, "gradient.ppm");
    destroy_image(image);

    return 0;
}