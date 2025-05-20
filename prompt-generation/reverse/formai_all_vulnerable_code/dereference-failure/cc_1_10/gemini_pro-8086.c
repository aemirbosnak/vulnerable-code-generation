//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    unsigned int width;
    unsigned int height;
    unsigned int channels;
} Image;

Image *create_image(unsigned int width, unsigned int height, unsigned int channels) {
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

void flip_image(Image *image, bool horizontal) {
    unsigned int i, j, k;
    unsigned int *data = (unsigned int *)image->data;
    for (i = 0; i < image->height; i++) {
        unsigned int *row = data + i * image->width;
        for (j = (horizontal ? 0 : image->width - 1); (horizontal ? j < image->width : j >= 0); (horizontal ? j++ : j--)) {
            for (k = 0; k < image->channels; k++) {
                unsigned int temp = row[j * image->channels + k];
                row[j * image->channels + k] = row[(image->width - 1 - j) * image->channels + k];
                row[(image->width - 1 - j) * image->channels + k] = temp;
            }
        }
    }
}

void adjust_brightness_contrast(Image *image, float brightness, float contrast) {
    unsigned int i, j, k;
    unsigned int *data = (unsigned int *)image->data;
    for (i = 0; i < image->height; i++) {
        unsigned int *row = data + i * image->width;
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                float value = row[j * image->channels + k] / 255.0f;
                value = (value - 0.5f) * contrast + 0.5f;
                value = value * brightness;
                value = fmax(0.0f, fmin(1.0f, value));
                row[j * image->channels + k] = (unsigned char)(value * 255.0f);
            }
        }
    }
}

int main() {
    Image *image = create_image(512, 512, 3);

    // Fill the image with a gradient
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                image->data[i * image->width * image->channels + j * image->channels + k] = (unsigned char)(255 * (float)i / (image->height - 1));
            }
        }
    }

    printf("Original image:\n");
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                printf("%3d ", image->data[i * image->width * image->channels + j * image->channels + k]);
            }
        }
        printf("\n");
    }

    flip_image(image, true);

    printf("Horizontally flipped image:\n");
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                printf("%3d ", image->data[i * image->width * image->channels + j * image->channels + k]);
            }
        }
        printf("\n");
    }

    flip_image(image, false);

    printf("Vertically flipped image:\n");
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                printf("%3d ", image->data[i * image->width * image->channels + j * image->channels + k]);
            }
        }
        printf("\n");
    }

    adjust_brightness_contrast(image, 1.5f, 1.2f);

    printf("Adjusted brightness and contrast image:\n");
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                printf("%3d ", image->data[i * image->width * image->channels + j * image->channels + k]);
            }
        }
        printf("\n");
    }

    destroy_image(image);

    return 0;
}