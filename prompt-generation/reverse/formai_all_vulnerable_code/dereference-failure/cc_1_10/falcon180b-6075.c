//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define BITS_PER_PIXEL 24
#define BYTES_PER_PIXEL 3
#define MAX_HIDDEN_BYTES 1024

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    uint8_t *data;
    int width, height;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t *data = malloc(size);
    if (!data) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fread(data, 1, size, fp);
    fclose(fp);

    Image img = {data, WIDTH, HEIGHT};
    return img;
}

void saveImage(const char *filename, const Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fwrite(img->data, 1, img->width * img->height * BYTES_PER_PIXEL, fp);
    fclose(fp);
}

void hideBytes(Image *img, const uint8_t *data, int numBytes) {
    int index = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int offset = (y * img->width + x) * BYTES_PER_PIXEL;
            if (index < numBytes) {
                img->data[offset] = data[index];
                index++;
            }
        }
    }
}

void extractBytes(const Image *img, uint8_t *data) {
    int index = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int offset = (y * img->width + x) * BYTES_PER_PIXEL;
            data[index] = img->data[offset];
            index++;
        }
    }
}

int main() {
    srand(time(NULL));

    Image cover = loadImage("cover.bmp");
    Image stego = loadImage("stego.bmp");

    uint8_t *message = malloc(MAX_HIDDEN_BYTES);
    for (int i = 0; i < MAX_HIDDEN_BYTES; i++) {
        message[i] = rand() % 256;
    }

    int numBytes = rand() % MAX_HIDDEN_BYTES;
    hideBytes(&stego, message, numBytes);

    saveImage("stego.bmp", &stego);

    printf("Successfully hid %d bytes of data in the image.\n", numBytes);

    return 0;
}