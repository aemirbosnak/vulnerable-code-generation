//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

void init_image(Image *img, int width, int height, int channels) {
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = (unsigned char *)malloc(width * height * channels);
}

void free_image(Image *img) {
    free(img->data);
}

void set_pixel(Image *img, int x, int y, int channel, int value) {
    int offset = (y * img->width + x) * img->channels + channel;
    img->data[offset] = value;
}

int get_pixel(Image *img, int x, int y, int channel) {
    int offset = (y * img->width + x) * img->channels + channel;
    return img->data[offset];
}

void apply_filter(Image *img, int filter_type) {
    int width = img->width;
    int height = img->height;
    int channels = img->channels;
    unsigned char *data = img->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            for (int c = 0; c < channels; c++) {
                int value = get_pixel(img, x, y, c);
                switch (filter_type) {
                    case 1: // Grayscale
                        value = (int)(0.299 * value + 0.587 * value + 0.114 * value);
                        break;
                    case 2: // Sepia
                        value = (int)(0.393 * value + 0.769 * value + 0.189 * value);
                        break;
                    case 3: // Invert
                        value = 255 - value;
                        break;
                    default:
                        break;
                }
                set_pixel(img, x, y, c, value);
            }
        }
    }
}

int main() {
    Image img;
    init_image(&img, 512, 512, 3);

    // Fill image with random values
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            for (int c = 0; c < img.channels; c++) {
                set_pixel(&img, x, y, c, rand() % 256);
            }
        }
    }

    // Apply filter
    apply_filter(&img, 1);

    // Save image to file
    FILE *fp = fopen("image.bmp", "wb");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fprintf(fp, "BM");
    fwrite(&(img.width), sizeof(int), 1, fp);
    fwrite(&(img.height), sizeof(int), 1, fp);
    fwrite(&(img.channels), sizeof(int), 1, fp);
    fwrite(&(img.data), sizeof(unsigned char), img.width * img.height * img.channels, fp);

    fclose(fp);

    return 0;
}