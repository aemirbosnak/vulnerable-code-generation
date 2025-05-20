//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 512
#define HEIGHT 512

typedef unsigned char BYTE;

void writeBytes(BYTE* image, BYTE* secret, int i, int j) {
    BYTE* p = &image[i * WIDTH + j];
    int k = 0;
    while (secret[k]!= 0) {
        p[k] = secret[k];
        k++;
    }
}

void restoreBytes(BYTE* secret, BYTE* image, int i, int j) {
    BYTE* p = &image[i * WIDTH + j];
    int k = 0;
    while (secret[k]!= 0) {
        secret[k] = p[k];
        k++;
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <cover_image> <secret_message>\n", argv[0]);
        exit(1);
    }

    const char* cover_image = argv[1];
    const char* secret_message = argv[2];

    BYTE* cover = (BYTE*)malloc(WIDTH * HEIGHT * sizeof(BYTE));
    BYTE* secret = (BYTE*)malloc(strlen(secret_message) * sizeof(BYTE));
    FILE* fp = fopen(cover_image, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open %s.\n", cover_image);
        exit(1);
    }
    fread(cover, sizeof(BYTE), WIDTH * HEIGHT, fp);
    fclose(fp);

    writeBytes(cover, secret, 0, 0);

    fp = fopen(secret_message, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open %s.\n", secret_message);
        exit(1);
    }
    fwrite(cover, sizeof(BYTE), WIDTH * HEIGHT, fp);
    fclose(fp);

    free(cover);
    free(secret);

    return 0;
}