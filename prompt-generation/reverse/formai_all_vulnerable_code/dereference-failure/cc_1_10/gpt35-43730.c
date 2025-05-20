//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIT_SET(a,b) ((a) |= (1<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))

void encode(char *carrier_image_path, char *secret_image_path, char *output_image_path) {
    FILE *carrier_image_file = fopen(carrier_image_path, "rb");
    FILE *secret_image_file = fopen(secret_image_path, "rb");
    FILE *output_image_file = fopen(output_image_path, "wb");

    if (!carrier_image_file || !secret_image_file || !output_image_file) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    unsigned char carrier[512][512][3];
    unsigned char secret[512][512][3];

    fread(carrier, sizeof(unsigned char), 512*512*3, carrier_image_file);
    fread(secret, sizeof(unsigned char), 512*512*3, secret_image_file);

    int r_bit, g_bit, b_bit;
    int secret_bit_index = 0;
    unsigned char secret_byte = secret[0][0][0];

    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            if (secret_bit_index == 8) {
                secret_bit_index = 0;
                secret_byte = secret[i][j][0];
            }

            r_bit = secret_byte & 0x80 ? 1 : 0;
            secret_byte <<= 1;

            if (secret_bit_index == 8) {
                secret_bit_index = 0;
                secret_byte = secret[i][j][1];
            }

            g_bit = secret_byte & 0x80 ? 1 : 0;
            secret_byte <<= 1;

            if (secret_bit_index == 8) {
                secret_bit_index = 0;
                secret_byte = secret[i][j][2];
            }

            b_bit = secret_byte & 0x80 ? 1 : 0;
            secret_byte <<= 1;

            if (r_bit) {
                BIT_SET(carrier[i][j][0], 0);
            } else {
                BIT_CLEAR(carrier[i][j][0], 0);
            }

            if (g_bit) {
                BIT_SET(carrier[i][j][1], 0);
            } else {
                BIT_CLEAR(carrier[i][j][1], 0);
            }

            if (b_bit) {
                BIT_SET(carrier[i][j][2], 0);
            } else {
                BIT_CLEAR(carrier[i][j][2], 0);
            }

            secret_bit_index++;
        }
    }

    fwrite(carrier, sizeof(unsigned char), 512*512*3, output_image_file);

    printf("Steganography complete\n");

    fclose(carrier_image_file);
    fclose(secret_image_file);
    fclose(output_image_file);
}

void decode(char *stego_image_path, char *output_image_path) {
    FILE *stego_image_file = fopen(stego_image_path, "rb");
    FILE *output_image_file = fopen(output_image_path, "wb");

    if (!stego_image_file || !output_image_file) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    unsigned char stego[512][512][3];

    fread(stego, sizeof(unsigned char), 512*512*3, stego_image_file);

    unsigned char secret[512][512][3];

    for (int i = 0; i < 512; i++) {
        for (int j = 0; j < 512; j++) {
            if (stego[i][j][0] & 0x1) {
                BIT_SET(secret[i][j][0], 7);
            } else {
                BIT_CLEAR(secret[i][j][0], 7);
            }

            if (stego[i][j][1] & 0x1) {
                BIT_SET(secret[i][j][1], 7);
            } else {
                BIT_CLEAR(secret[i][j][1], 7);
            }

            if (stego[i][j][2] & 0x1) {
                BIT_SET(secret[i][j][2], 7);
            } else {
                BIT_CLEAR(secret[i][j][2], 7);
            }

        }
    }

    fwrite(secret, sizeof(unsigned char), 512*512*3, output_image_file);

    printf("Steganography complete\n");

    fclose(stego_image_file);
    fclose(output_image_file);
}

int main() {
    char *carrier_image_path = "example/carrier.bmp";
    char *secret_image_path = "example/secret.bmp";
    char *output_image_path = "example/output.bmp";

    encode(carrier_image_path, secret_image_path, output_image_path);
    decode(output_image_path, "example/output_secret.bmp");

    return 0;
}