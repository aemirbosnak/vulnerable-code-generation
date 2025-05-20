//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH  128
#define HEIGHT 128

#define PIXEL_SIZE 3
#define BYTES_PER_PIXEL (PIXEL_SIZE / 8)
#define HIDDEN_SIZE (WIDTH * HEIGHT * BYTES_PER_PIXEL)
#define HIDDEN_BITS (HIDDEN_SIZE * 8)
#define MAX_HIDDEN_BITS (BYTES_PER_PIXEL * WIDTH * HEIGHT)

int main() {
    FILE *fp = fopen("input.txt", "rb");
    if (fp == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    unsigned char buf[HIDDEN_SIZE];
    if (fread(buf, 1, HIDDEN_SIZE, fp)!= HIDDEN_SIZE) {
        printf("Failed to read data from file\n");
        fclose(fp);
        return 1;
    }
    fclose(fp);

    unsigned char* image = (unsigned char*)malloc(WIDTH * HEIGHT * PIXEL_SIZE);
    unsigned char* image_stego = (unsigned char*)malloc(WIDTH * HEIGHT * PIXEL_SIZE);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            for (int p = 0; p < PIXEL_SIZE; p++) {
                image_stego[(y * WIDTH + x) * PIXEL_SIZE + p] =
                    image[(y * WIDTH + x) * PIXEL_SIZE + p] ^ buf[x + (y * WIDTH) * HIDDEN_SIZE];
            }
        }
    }

    printf("Stego image generated successfully!\n");
    FILE *fp_out = fopen("output.bmp", "wb");
    if (fp_out == NULL) {
        printf("Unable to open output file\n");
        return 1;
    }

    fwrite(image_stego, 1, WIDTH * HEIGHT * PIXEL_SIZE, fp_out);
    fclose(fp_out);

    printf("Stego image saved as output.bmp\n");

    free(image);
    free(image_stego);

    return 0;
}