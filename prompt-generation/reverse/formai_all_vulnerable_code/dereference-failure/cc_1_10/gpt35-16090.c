//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54

typedef struct {
    unsigned char B, G, R;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function prototypes
Image *read_bmp(char *filename);
void write_bmp(char *filename, Image *image);
void flip_image(Image *image);
void adjust_brightness(Image *image, int adjust_value);
void adjust_contrast(Image *image, float contrast);

int main()
{
    Image *image = read_bmp("test_image.bmp");

    flip_image(image);
    adjust_brightness(image, 50);
    adjust_contrast(image, 1.5);

    write_bmp("processed_image.bmp", image);

    free(image->pixels);
    free(image);

    return 0;
}

Image *read_bmp(char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (!file) {
        printf("Error: could not open file %s.", filename);
        exit(1);
    }

    unsigned char bmp_header[BMP_HEADER_SIZE];
    fread(bmp_header, sizeof(unsigned char), BMP_HEADER_SIZE, file);

    int width = *(int*)&bmp_header[18];
    int height = *(int*)&bmp_header[22];
    int padding = 0;

    while ((width * 3 + padding) % 4 != 0) {
        padding++;
    }

    int row_size = width * 3 + padding;

    unsigned char *data = (unsigned char*)malloc(row_size * height);
    fread(data, sizeof(unsigned char), row_size * height, file);

    fclose(file);

    Image *image = (Image*)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel*)malloc(width * height * sizeof(Pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * row_size + x * 3;
            image->pixels[y * width + x].B = data[index];
            image->pixels[y * width + x].G = data[index + 1];
            image->pixels[y * width + x].R = data[index + 2];
        }
    }

    free(data);

    return image;
}

void write_bmp(char *filename, Image *image)
{
    int padding = 0;

    while ((image->width * 3 + padding) % 4 != 0) {
        padding++;
    }

    int row_size = image->width * 3 + padding;
    int file_size = BMP_HEADER_SIZE + row_size * image->height;

    unsigned char *data = (unsigned char*)malloc(row_size * image->height);
    memset(data, 0, row_size * image->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = y * row_size + x * 3;
            data[index] = image->pixels[y * image->width + x].B;
            data[index + 1] = image->pixels[y * image->width + x].G;
            data[index + 2] = image->pixels[y * image->width + x].R;
        }
    }

    FILE *file = fopen(filename, "wb");

    if (!file) {
        printf("Error: could not create file %s.", filename);
        exit(1);
    }

    unsigned char bmp_header[BMP_HEADER_SIZE] = {
        'B', 'M',
        0, 0, 0, 0,
        0, 0,
        0, 0,
        BMP_HEADER_SIZE % 256, BMP_HEADER_SIZE / 256, 0, 0,
        40, 0, 0, 0,
        0, 0, 0, 0,
        image->width % 256, image->width / 256, 0, 0,
        image->height % 256, image->height / 256, 0, 0,
        1, 0,
        24, 0
    };

    *(int*)&bmp_header[2] = file_size;
    *(int*)&bmp_header[10] = BMP_HEADER_SIZE;

    fwrite(bmp_header, sizeof(unsigned char), BMP_HEADER_SIZE, file);
    fwrite(data, sizeof(unsigned char), row_size * image->height, file);

    fclose(file);

    free(data);
}

void flip_image(Image *image)
{
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[(image->height - y - 1) * image->width + x];
            image->pixels[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

void adjust_brightness(Image *image, int adjust_value)
{
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->pixels[y * image->width + x].B += adjust_value;
            image->pixels[y * image->width + x].G += adjust_value;
            image->pixels[y * image->width + x].R += adjust_value;
        }
    }
}

void adjust_contrast(Image *image, float contrast)
{
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->pixels[y * image->width + x].B = (unsigned char)(factor * (image->pixels[y * image->width + x].B - 128) + 128);
            image->pixels[y * image->width + x].G = (unsigned char)(factor * (image->pixels[y * image->width + x].G - 128) + 128);
            image->pixels[y * image->width + x].R = (unsigned char)(factor * (image->pixels[y * image->width + x].R - 128) + 128);
        }
    }
}