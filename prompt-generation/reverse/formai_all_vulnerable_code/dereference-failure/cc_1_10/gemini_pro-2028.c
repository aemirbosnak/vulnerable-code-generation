//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <image> <payload>\n", argv[0]);
        return 1;
    }

    FILE *image = fopen(argv[1], "rb");
    if (image == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", argv[1]);
        return 1;
    }

    FILE *payload = fopen(argv[2], "rb");
    if (payload == NULL) {
        fprintf(stderr, "Error opening payload file: %s\n", argv[2]);
        fclose(image);
        return 1;
    }

    fseek(image, 0, SEEK_END);
    long image_size = ftell(image);
    rewind(image);

    fseek(payload, 0, SEEK_END);
    long payload_size = ftell(payload);
    rewind(payload);

    if (image_size < payload_size) {
        fprintf(stderr, "Error: Image file is too small to hold the payload\n");
        fclose(image);
        fclose(payload);
        return 1;
    }

    byte *image_data = malloc(image_size);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(image);
        fclose(payload);
        return 1;
    }

    fread(image_data, 1, image_size, image);
    fclose(image);

    byte *payload_data = malloc(payload_size);
    if (payload_data == NULL) {
        fprintf(stderr, "Error allocating memory for payload data\n");
        fclose(payload);
        free(image_data);
        return 1;
    }

    fread(payload_data, 1, payload_size, payload);
    fclose(payload);

    for (long i = 0; i < payload_size; i++) {
        for (int j = 0; j < 8; j++) {
            byte bit = (payload_data[i] >> j) & 1;
            image_data[i * 8 + j] = (image_data[i * 8 + j] & ~1) | bit;
        }
    }

    FILE *stego = fopen("stego.bmp", "wb");
    if (stego == NULL) {
        fprintf(stderr, "Error opening stego file: stego.bmp\n");
        free(image_data);
        free(payload_data);
        return 1;
    }

    fwrite(image_data, 1, image_size, stego);
    fclose(stego);

    free(image_data);
    free(payload_data);

    return 0;
}