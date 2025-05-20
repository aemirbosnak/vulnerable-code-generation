//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    int channels;
    float *data;
} Image;

Image *new_image(int width, int height, int channels) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels * sizeof(float));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void get_pixel(Image *image, int x, int y, float *r, float *g, float *b) {
    int index = (y * image->width + x) * image->channels;
    *r = image->data[index];
    *g = image->data[index + 1];
    *b = image->data[index + 2];
}

void set_pixel(Image *image, int x, int y, float r, float g, float b) {
    int index = (y * image->width + x) * image->channels;
    image->data[index] = r;
    image->data[index + 1] = g;
    image->data[index + 2] = b;
}

float mean(float *data, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

float variance(float *data, int n) {
    float mean_value = mean(data, n);
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (data[i] - mean_value) * (data[i] - mean_value);
    }
    return sum / n;
}

float standard_deviation(float *data, int n) {
    return sqrt(variance(data, n));
}

Image *gaussian_blur(Image *image, float sigma) {
    int kernel_size = 2 * round(2 * sigma) + 1;
    float *kernel = malloc(kernel_size * sizeof(float));
    for (int i = 0; i < kernel_size; i++) {
        float x = (i - kernel_size / 2) / (2 * sigma);
        kernel[i] = exp(-x * x / 2) / (2 * M_PI * sigma * sigma);
    }
    Image *blurred_image = new_image(image->width, image->height, image->channels);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            float r = 0, g = 0, b = 0;
            for (int ky = -kernel_size / 2; ky <= kernel_size / 2; ky++) {
                for (int kx = -kernel_size / 2; kx <= kernel_size / 2; kx++) {
                    int ix = x + kx;
                    int iy = y + ky;
                    if (ix < 0 || ix >= image->width || iy < 0 || iy >= image->height) {
                        continue;
                    }
                    float weight = kernel[kx + kernel_size / 2] * kernel[ky + kernel_size / 2];
                    float pr, pg, pb;
                    get_pixel(image, ix, iy, &pr, &pg, &pb);
                    r += pr * weight;
                    g += pg * weight;
                    b += pb * weight;
                }
            }
            set_pixel(blurred_image, x, y, r, g, b);
        }
    }
    free(kernel);
    return blurred_image;
}

int main() {
    Image *image = new_image(512, 512, 3);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            float r = (float)x / image->width;
            float g = (float)y / image->height;
            float b = 0.5;
            set_pixel(image, x, y, r, g, b);
        }
    }
    Image *blurred_image = gaussian_blur(image, 10);
    free_image(image);
    free_image(blurred_image);
    return 0;
}