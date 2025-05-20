//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *create_image(int width, int height);
void destroy_image(Image *image);
void flip_image(Image *image);
void adjust_brightness(Image *image, int level);
void adjust_contrast(Image *image, float level);

int main() {
    // create image
    Image *image = create_image(5, 4);

    // fill image with dummy data
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = i;
    }

    // print original image
    printf("Original Image:\n");
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%3d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }

    // flip image
    flip_image(image);

    // print flipped image
    printf("\nFlipped Image:\n");
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%3d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }

    // adjust brightness
    adjust_brightness(image, 50);

    // print adjusted brightness image
    printf("\nAdjusted Brightness Image:\n");
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%3d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }

    // adjust contrast
    adjust_contrast(image, 1.5);

    // print adjusted contrast image
    printf("\nAdjusted Contrast Image:\n");
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%3d ", image->data[y * image->width + x]);
        }
        printf("\n");
    }

    // free memory
    destroy_image(image);
}

Image *create_image(int width, int height) {
    Image *image = (Image *) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (unsigned char *) malloc(sizeof(unsigned char) * width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void flip_image(Image *image) {
    unsigned char temp;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + (image->width - 1 - x)];
            image->data[y * image->width + (image->width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(Image *image, int level) {
    for (int i = 0; i < image->width * image->height; i++) {
        int new_value = image->data[i] + level;
        if (new_value > MAX_PIXEL_VALUE) {
            image->data[i] = MAX_PIXEL_VALUE;
        } else if (new_value < 0) {
            image->data[i] = 0;
        } else {
            image->data[i] = new_value;
        }
    }
}

void adjust_contrast(Image *image, float level) {
    float factor = (259.0 * (level + 255.0)) / (255.0 * (259.0 - level));
    int new_value;
    for (int i = 0; i < image->width * image->height; i++) {
        new_value = (int) (factor * (image->data[i] - 128.0) + 128.0);
        if (new_value > MAX_PIXEL_VALUE) {
            image->data[i] = MAX_PIXEL_VALUE;
        } else if (new_value < 0) {
            image->data[i] = 0;
        } else {
            image->data[i] = new_value;
        }
    }
}