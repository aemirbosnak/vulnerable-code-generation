//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    char header[54];
    fread(header, sizeof(char), 54, fp);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int channels = *(int *)&header[28];

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels);
    fread(image->data, sizeof(unsigned char), width * height * channels, fp);
    fclose(fp);

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    char header[54] = {
        0x42, 0x4D, 0x36, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(int *)&header[28] = image->channels;

    fwrite(header, sizeof(char), 54, fp);
    fwrite(image->data, sizeof(unsigned char), image->width * image->height * image->channels, fp);
    fclose(fp);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                unsigned char temp = image->data[y * image->width * image->channels + x * image->channels + c];
                image->data[y * image->width * image->channels + x * image->channels + c] = image->data[(image->height - y - 1) * image->width * image->channels + x * image->channels + c];
                image->data[(image->height - y - 1) * image->width * image->channels + x * image->channels + c] = temp;
            }
        }
    }
}

void adjust_brightness(Image *image, double brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                image->data[y * image->width * image->channels + x * image->channels + c] = (unsigned char)fmin(255, fmax(0, image->data[y * image->width * image->channels + x * image->channels + c] + brightness));
            }
        }
    }
}

void adjust_contrast(Image *image, double contrast) {
    double factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                image->data[y * image->width * image->channels + x * image->channels + c] = (unsigned char)fmin(255, fmax(0, factor * (image->data[y * image->width * image->channels + x * image->channels + c] - 128) + 128));
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <command>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(image);
    } else if (strcmp(argv[3], "brightness") == 0) {
        adjust_brightness(image, atof(argv[4]));
    } else if (strcmp(argv[3], "contrast") == 0) {
        adjust_contrast(image, atof(argv[4]));
    } else {
        fprintf(stderr, "Error: unknown command '%s'\n", argv[3]);
        return 1;
    }

    write_image(argv[2], image);
    free(image->data);
    free(image);

    return 0;
}