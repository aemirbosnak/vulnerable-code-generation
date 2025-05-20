//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT 8
#define PIXELS 3
#define PIXEL_SIZE (1 << BIT)

void encode(unsigned char *image, unsigned char *secret, int width, int height, int channels) {
    int i, j, k;
    unsigned char *pixels = (unsigned char *)malloc(PIXEL_SIZE * width * height * channels);

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            for (k = 0; k < channels; k++) {
                pixels[i * width * channels + j * channels + k] = image[i * width * channels + j * channels + k];
            }
        }
    }

    for (i = 0; i < width * height * channels; i++) {
        pixels[i] ^= secret[i % strlen(secret)];
    }

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            for (k = 0; k < channels; k++) {
                image[i * width * channels + j * channels + k] = pixels[i * width * channels + j * channels + k];
            }
        }
    }

    free(pixels);
}

void decode(unsigned char *image, unsigned char *secret, int width, int height, int channels) {
    int i, j, k;
    unsigned char *pixels = (unsigned char *)malloc(PIXEL_SIZE * width * height * channels);

    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            for (k = 0; k < channels; k++) {
                pixels[i * width * channels + j * channels + k] = image[i * width * channels + j * channels + k];
            }
        }
    }

    for (i = 0; i < width * height * channels; i++) {
        secret[i % strlen(secret)] ^= pixels[i];
    }

    printf("Secret message: %s\n", secret);

    free(pixels);
}

int main() {
    char *secret = "HELLO WORLD";
    unsigned char *image = (unsigned char *)malloc(PIXEL_SIZE * 100 * 100 * 3);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 3; k++) {
                image[(i * 100 * 3) + (j * 3) + k] = (k + 1) % 255;
            }
        }
    }

    encode(image, secret, 100, 100, 3);

    decode(image, secret, 100, 100, 3);

    free(image);

    return 0;
}