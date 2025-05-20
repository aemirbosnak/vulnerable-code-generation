//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (!image->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

void write_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

void change_brightness(Image *image, float brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = (unsigned char)(image->data[y * image->width + x] * brightness);
        }
    }
}

void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = (unsigned char)(127.5 * (1.0 - contrast) + image->data[y * image->width + x] * contrast);
        }
    }
}

void surrealize(Image *image) {
    // Flip the image
    flip_image(image);

    // Change the brightness
    change_brightness(image, 0.5);

    // Change the contrast
    change_contrast(image, 2.0);

    // Swirl the image
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int dx = x - image->width / 2;
            int dy = y - image->height / 2;
            float r = sqrt(dx * dx + dy * dy);
            float theta = atan2(dy, dx);
            float new_r = r * 0.5 * (1.0 + sin(theta * 5.0));
            float new_x = image->width / 2 + new_r * cos(theta);
            float new_y = image->height / 2 + new_r * sin(theta);
            int new_x_int = (int)new_x;
            int new_y_int = (int)new_y;
            if (new_x_int >= 0 && new_x_int < image->width && new_y_int >= 0 && new_y_int < image->height) {
                image->data[y * image->width + x] = image->data[new_y_int * image->width + new_x_int];
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    surrealize(image);

    write_image(image, argv[2]);

    free(image->data);
    free(image);
    return 0;
}