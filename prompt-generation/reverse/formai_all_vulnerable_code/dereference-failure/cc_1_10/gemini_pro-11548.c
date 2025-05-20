//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Image {
    unsigned int width, height, channels;
    unsigned char *data;
};

struct Image *create_image(unsigned int w, unsigned int h, unsigned int c) {
    struct Image *image = malloc(sizeof(struct Image));
    image->width = w;
    image->height = h;
    image->channels = c;
    image->data = malloc(w * h * c);
    return image;
}

void free_image(struct Image *image) {
    free(image->data);
    free(image);
}

unsigned char get_pixel(const struct Image *image, unsigned int x, unsigned int y, unsigned int c) {
    return image->data[y * image->width * image->channels + x * image->channels + c];
}

void set_pixel(struct Image *image, unsigned int x, unsigned int y, unsigned int c, unsigned char value) {
    image->data[y * image->width * image->channels + x * image->channels + c] = value;
}

void invert_image(struct Image *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            for (unsigned int c = 0; c < image->channels; c++) {
                unsigned char pixel = get_pixel(image, x, y, c);
                set_pixel(image, x, y, c, 255 - pixel);
            }
        }
    }
}

void grayscale_image(struct Image *image) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            unsigned char r = get_pixel(image, x, y, 0);
            unsigned char g = get_pixel(image, x, y, 1);
            unsigned char b = get_pixel(image, x, y, 2);
            unsigned char gray = (r + g + b) / 3;
            set_pixel(image, x, y, 0, gray);
            set_pixel(image, x, y, 1, gray);
            set_pixel(image, x, y, 2, gray);
        }
    }
}

void rotate_image(struct Image *image, double angle) {
    double radians = angle * M_PI / 180;
    double sine = sin(radians);
    double cosine = cos(radians);
    unsigned int w = image->width;
    unsigned int h = image->height;
    struct Image *rotated = create_image(w, h, image->channels);
    for (unsigned int y = 0; y < h; y++) {
        for (unsigned int x = 0; x < w; x++) {
            for (unsigned int c = 0; c < image->channels; c++) {
                int rx = (int)round((x - w / 2) * cosine - (y - h / 2) * sine + w / 2);
                int ry = (int)round((x - w / 2) * sine + (y - h / 2) * cosine + h / 2);
                if (rx >= 0 && rx < w && ry >= 0 && ry < h) {
                    unsigned char pixel = get_pixel(image, rx, ry, c);
                    set_pixel(rotated, x, y, c, pixel);
                }
            }
        }
    }
    free_image(image);
    *image = *rotated;
    free_image(rotated);
}

void blur_image(struct Image *image, unsigned int radius) {
    unsigned int w = image->width;
    unsigned int h = image->height;
    struct Image *blurred = create_image(w, h, image->channels);
    for (unsigned int y = 0; y < h; y++) {
        for (unsigned int x = 0; x < w; x++) {
            for (unsigned int c = 0; c < image->channels; c++) {
                int sum = 0;
                int count = 0;
                for (int dy = -radius; dy <= radius; dy++) {
                    for (int dx = -radius; dx <= radius; dx++) {
                        int rx = x + dx;
                        int ry = y + dy;
                        if (rx >= 0 && rx < w && ry >= 0 && ry < h) {
                            unsigned char pixel = get_pixel(image, rx, ry, c);
                            sum += pixel;
                            count++;
                        }
                    }
                }
                unsigned char average = sum / count;
                set_pixel(blurred, x, y, c, average);
            }
        }
    }
    free_image(image);
    *image = *blurred;
    free_image(blurred);
}

int main() {
    struct Image *image = create_image(512, 512, 3);
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            set_pixel(image, x, y, 0, x);
            set_pixel(image, x, y, 1, y);
            set_pixel(image, x, y, 2, (x + y) % 256);
        }
    }
    invert_image(image);
    grayscale_image(image);
    rotate_image(image, 45);
    blur_image(image, 5);
    free_image(image);
    return 0;
}