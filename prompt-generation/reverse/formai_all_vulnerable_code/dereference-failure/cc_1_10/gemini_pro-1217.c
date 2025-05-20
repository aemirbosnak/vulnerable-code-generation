//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(unsigned int), 1, file);
    fread(&image->height, sizeof(unsigned int), 1, file);
    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->data, 1, image->width * image->height * 3, file);
    fclose(file);

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    fwrite(&image->width, sizeof(unsigned int), 1, file);
    fwrite(&image->height, sizeof(unsigned int), 1, file);
    fwrite(image->data, 1, image->width * image->height * 3, file);
    fclose(file);
}

void flip_image(Image *image) {
    for (unsigned int y = 0; y < image->height / 2; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            unsigned char *top = &image->data[(y * image->width + x) * 3];
            unsigned char *bottom = &image->data[((image->height - y - 1) * image->width + x) * 3];

            unsigned char temp = *top;
            *top = *bottom;
            *bottom = temp;

            temp = *(top + 1);
            *(top + 1) = *(bottom + 1);
            *(bottom + 1) = temp;

            temp = *(top + 2);
            *(top + 2) = *(bottom + 2);
            *(bottom + 2) = temp;
        }
    }
}

void rotate_image(Image *image) {
    unsigned int new_width = image->height;
    unsigned int new_height = image->width;
    unsigned char *new_data = malloc(new_width * new_height * 3);
    if (!new_data) {
        return;
    }

    for (unsigned int y = 0; y < new_height; y++) {
        for (unsigned int x = 0; x < new_width; x++) {
            unsigned char *new_pixel = &new_data[(y * new_width + x) * 3];
            unsigned char *old_pixel = &image->data[(x * image->width + y) * 3];

            *new_pixel = *old_pixel;
            *(new_pixel + 1) = *(old_pixel + 1);
            *(new_pixel + 2) = *(old_pixel + 2);
        }
    }

    free(image->data);
    image->data = new_data;
    image->width = new_width;
    image->height = new_height;
}

void adjust_brightness(Image *image, int brightness) {
    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            unsigned char *pixel = &image->data[(y * image->width + x) * 3];

            int new_red = *pixel + brightness;
            int new_green = *(pixel + 1) + brightness;
            int new_blue = *(pixel + 2) + brightness;

            if (new_red < 0) {
                new_red = 0;
            } else if (new_red > 255) {
                new_red = 255;
            }

            if (new_green < 0) {
                new_green = 0;
            } else if (new_green > 255) {
                new_green = 255;
            }

            if (new_blue < 0) {
                new_blue = 0;
            } else if (new_blue > 255) {
                new_blue = 255;
            }

            *pixel = new_red;
            *(pixel + 1) = new_green;
            *(pixel + 2) = new_blue;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error loading image\n");
        return 1;
    }

    flip_image(image);
    rotate_image(image);
    adjust_brightness(image, 50);
    save_image(image, "output.bmp");

    free(image->data);
    free(image);

    return 0;
}