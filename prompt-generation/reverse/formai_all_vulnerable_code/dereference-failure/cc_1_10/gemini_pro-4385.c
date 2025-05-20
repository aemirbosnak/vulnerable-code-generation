//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

void embed(const char *image, const char *secret, char *output) {
    FILE *img = fopen(image, "rb");
    FILE *sec = fopen(secret, "rb");
    FILE *out = fopen(output, "wb");

    if (!img || !sec || !out) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    size_t img_size, sec_size;
    fseek(img, 0, SEEK_END);
    fseek(sec, 0, SEEK_END);
    img_size = ftell(img);
    sec_size = ftell(sec);

    rewind(img);
    rewind(sec);

    if (img_size < sec_size) {
        fprintf(stderr, "Error: Image too small to embed secret\n");
        exit(EXIT_FAILURE);
    }

    byte buf[1024];
    size_t n, i, j;

    for (i = 0; i < img_size / 1024; i++) {
        n = fread(buf, 1, 1024, img);
        for (j = 0; j < n; j++) {
            if (j < sec_size) {
                byte c = fgetc(sec);
                buf[j] = (buf[j] & 0xF0) | (c & 0x0F);
            }
        }
        fwrite(buf, 1, n, out);
    }

    n = fread(buf, 1, img_size % 1024, img);
    for (j = 0; j < n; j++) {
        if (j < sec_size) {
            byte c = fgetc(sec);
            buf[j] = (buf[j] & 0xF0) | (c & 0x0F);
        }
    }
    fwrite(buf, 1, n, out);

    fclose(img);
    fclose(sec);
    fclose(out);

    printf("Secret embedded in image\n");
}

void extract(const char *image, char *output) {
    FILE *img = fopen(image, "rb");
    FILE *out = fopen(output, "wb");

    if (!img || !out) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    size_t img_size;
    fseek(img, 0, SEEK_END);
    img_size = ftell(img);

    rewind(img);

    byte buf[1024];
    size_t n, i, j;

    for (i = 0; i < img_size / 1024; i++) {
        n = fread(buf, 1, 1024, img);
        for (j = 0; j < n; j++) {
            byte c = buf[j] & 0x0F;
            if (c) {
                fputc(c, out);
            }
        }
    }

    n = fread(buf, 1, img_size % 1024, img);
    for (j = 0; j < n; j++) {
        byte c = buf[j] & 0x0F;
        if (c) {
            fputc(c, out);
        }
    }

    fclose(img);
    fclose(out);

    printf("Secret extracted from image\n");
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <command> <image> <secret> <output>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *command = argv[1];
    const char *image = argv[2];
    const char *secret = argv[3];
    const char *output = argv[4];

    if (!strcmp(command, "embed")) {
        embed(image, secret, output);
    } else if (!strcmp(command, "extract")) {
        extract(image, output);
    } else {
        fprintf(stderr, "Invalid command\n");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}