//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct image {
    int width;
    int height;
    int channels;
    unsigned char *data;
};

// Function for loading an image from a file
struct image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error! Could not open file: %s\n", filename);
        return NULL;
    }

    char format[3];
    int width, height, channels;
    if (fscanf(file, "%2s %d %d %d\n", format, &width, &height, &channels) != 4) {
        printf("Error! Invalid file format: %s\n", filename);
        fclose(file);
        return NULL;
    }

    if (format[0] != 'P' || format[1] != '6') {
        printf("Error! Invalid image format: %s\n", filename);
        fclose(file);
        return NULL;
    }

    unsigned char *data = (unsigned char *)malloc(width * height * channels);
    if (!data) {
        printf("Error! Failed to allocate memory\n");
        fclose(file);
        return NULL;
    }

    if (fread(data, channels, width * height, file) != width * height) {
        printf("Error! Unexpected end of file\n");
        free(data);
        fclose(file);
        return NULL;
    }

    fclose(file);

    struct image *img = (struct image *)malloc(sizeof(struct image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = data;

    return img;
}

// Function for saving an image to a file
void save_image(const char *filename, struct image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error! Could not open file: %s\n", filename);
        return;
    }

    fprintf(file, "P6 %d %d %d\n", img->width, img->height, img->channels);
    fwrite(img->data, img->channels, img->width * img->height, file);

    fclose(file);
}

// Function for flipping an image horizontally
void flip_horizontal(struct image *img) {
    unsigned char temp[3];
    int i, j, k;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            for (k = 0; k < img->channels; k++) {
                temp[k] = img->data[(i * img->width + j) * img->channels + k];
                img->data[(i * img->width + j) * img->channels + k] = img->data[(i * img->width + img->width - j - 1) * img->channels + k];
                img->data[(i * img->width + img->width - j - 1) * img->channels + k] = temp[k];
            }
        }
    }
}

// Function for changing the brightness of an image
void adjust_brightness(struct image *img, int value) {
    int i, j, k;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < img->channels; k++) {
                int index = (i * img->width + j) * img->channels + k;
                int pixel = img->data[index] + value;
                img->data[index] = pixel > 255 ? 255 : pixel < 0 ? 0 : pixel;
            }
        }
    }
}

// Function for changing the contrast of an image
void adjust_contrast(struct image *img, int value) {
    int i, j, k;
    float factor = ((float)(value + 100)) / 100.0;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < img->channels; k++) {
                int index = (i * img->width + j) * img->channels + k;
                float pixel = ((float)img->data[index]) / 255.0;
                float new_pixel = factor * (pixel - 0.5) + 0.5;
                img->data[index] = (unsigned char)(new_pixel * 255.0);
            }
        }
    }
}

int main() {
    // Load an image from a file
    struct image *img = load_image("input.ppm");

    // Flip the image horizontally
    flip_horizontal(img);

    // Increase the brightness of the image
    adjust_brightness(img, 50);

    // Increase the contrast of the image
    adjust_contrast(img, 50);

    // Save the modified image to a file
    save_image("output.ppm", img);

    // Free the memory
    free(img->data);
    free(img);

    return 0;
}