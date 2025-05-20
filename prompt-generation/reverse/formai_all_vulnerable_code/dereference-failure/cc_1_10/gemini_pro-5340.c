//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Image structure */
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

/* Load an image from a file */
Image *load_image(char *filename) {
    Image *image = malloc(sizeof(Image));

    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    image->data = malloc(image->width * image->height);
    fread(image->data, 1, image->width * image->height, file);

    fclose(file);

    return image;
}

/* Save an image to a file */
void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->data, 1, image->width * image->height, file);

    fclose(file);
}

/* Flip an image horizontally */
void flip_horizontal(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

/* Flip an image vertically */
void flip_vertical(Image *image) {
    int i, j;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

/* Change the brightness of an image */
void change_brightness(Image *image, int brightness) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] += brightness;
        }
    }
}

/* Change the contrast of an image */
void change_contrast(Image *image, float contrast) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (image->data[i * image->width + j] - 128) * contrast + 128;
        }
    }
}

/* Apply a filter to an image */
void apply_filter(Image *image, float *filter, int filter_size) {
    int i, j, k, l;
    Image *temp = malloc(sizeof(Image));
    temp->width = image->width;
    temp->height = image->height;
    temp->data = malloc(image->width * image->height);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            float sum = 0;
            for (k = -filter_size / 2; k <= filter_size / 2; k++) {
                for (l = -filter_size / 2; l <= filter_size / 2; l++) {
                    if (i + k >= 0 && i + k < image->height && j + l >= 0 && j + l < image->width) {
                        sum += image->data[(i + k) * image->width + (j + l)] * filter[(k + filter_size / 2) * filter_size + (l + filter_size / 2)];
                    }
                }
            }
            temp->data[i * image->width + j] = sum;
        }
    }

    memcpy(image->data, temp->data, image->width * image->height);
    free(temp->data);
    free(temp);
}

/* Main function */
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    /* Flip the image horizontally */
    flip_horizontal(image);

    /* Flip the image vertically */
    flip_vertical(image);

    /* Change the brightness of the image */
    change_brightness(image, 30);

    /* Change the contrast of the image */
    change_contrast(image, 1.5);

    /* Apply a filter to the image */
    float filter[] = {
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0
    };
    apply_filter(image, filter, 3);

    /* Save the image to a file */
    save_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}