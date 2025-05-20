//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)
#define MAX_BYTES (MAX_PIXELS * 3)

typedef struct {
    int width;
    int height;
    unsigned char *pixels;
} image_t;

image_t *create_image(int width, int height)
{
    image_t *img = malloc(sizeof(image_t));
    img->width = width;
    img->height = height;
    img->pixels = malloc(MAX_BYTES);
    assert(img->pixels!= NULL);
    memset(img->pixels, 0, MAX_BYTES);
    return img;
}

void destroy_image(image_t *img)
{
    free(img->pixels);
    free(img);
}

void set_pixel(image_t *img, int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    int offset = (y * img->width + x) * 3;
    img->pixels[offset] = r;
    img->pixels[offset + 1] = g;
    img->pixels[offset + 2] = b;
}

void save_image(image_t *img, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    assert(fp!= NULL);
    fwrite(img->pixels, 1, MAX_BYTES, fp);
    fclose(fp);
}

int main()
{
    srand(time(NULL));

    image_t *img = create_image(MAX_WIDTH, MAX_HEIGHT);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            unsigned char r = rand() % 256;
            unsigned char g = rand() % 256;
            unsigned char b = rand() % 256;
            set_pixel(img, x, y, r, g, b);
        }
    }

    save_image(img, "random.bmp");

    destroy_image(img);

    return 0;
}