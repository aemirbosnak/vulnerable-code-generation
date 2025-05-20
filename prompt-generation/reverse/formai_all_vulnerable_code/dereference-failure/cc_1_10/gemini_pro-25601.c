//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512

void hide(char *image, char *secret) {
    int imageSize = 0;
    int secretSize = 0;
    FILE *imageFile = fopen(image, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return;
    }
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    rewind(imageFile);
    FILE *secretFile = fopen(secret, "rb");
    if (secretFile == NULL) {
        printf("Error opening secret file.\n");
        return;
    }
    fseek(secretFile, 0, SEEK_END);
    secretSize = ftell(secretFile);
    rewind(secretFile);
    if (imageSize < secretSize) {
        printf("Image file is too small to hide secret.\n");
        return;
    }
    int i, j;
    for (i = 0; i < secretSize; i++) {
        unsigned char byte;
        fread(&byte, 1, 1, secretFile);
        for (j = 0; j < 8; j++) {
            unsigned char bit = (byte >> j) & 1;
            unsigned char pixel;
            fread(&pixel, 1, 1, imageFile);
            pixel = (pixel & ~1) | bit;
            fseek(imageFile, -1, SEEK_CUR);
            fwrite(&pixel, 1, 1, imageFile);
        }
    }
    fclose(imageFile);
    fclose(secretFile);
}

void reveal(char *image, char *secret) {
    int imageSize = 0;
    FILE *imageFile = fopen(image, "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return;
    }
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    rewind(imageFile);
    FILE *secretFile = fopen(secret, "wb");
    if (secretFile == NULL) {
        printf("Error opening secret file.\n");
        return;
    }
    int i, j;
    for (i = 0; i < imageSize; i++) {
        unsigned char pixel;
        fread(&pixel, 1, 1, imageFile);
        for (j = 0; j < 8; j++) {
            unsigned char bit = pixel & 1;
            fwrite(&bit, 1, 1, secretFile);
            pixel >>= 1;
        }
    }
    fclose(imageFile);
    fclose(secretFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [hide/reveal] [image file] [secret file]\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "hide") == 0) {
        hide(argv[2], argv[3]);
    } else if (strcmp(argv[1], "reveal") == 0) {
        reveal(argv[2], argv[3]);
    } else {
        printf("Invalid operation.\n");
        return 1;
    }
    return 0;
}