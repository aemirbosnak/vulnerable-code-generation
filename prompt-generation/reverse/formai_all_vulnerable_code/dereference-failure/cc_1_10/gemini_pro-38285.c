//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_BUF 1024

void hide(uint8_t *img, size_t img_size, const char *msg, size_t msg_size) {
    if (img_size < msg_size * 8) {
        fprintf(stderr, "Error: Image size too small to hide message.\n");
        return;
    }

    for (size_t i = 0; i < msg_size; i++) {
        for (size_t j = 0; j < 8; j++) {
            uint8_t bit = (msg[i] >> j) & 1;
            img[i * 8 + j] = (img[i * 8 + j] & ~1) | bit;
        }
    }
}

void reveal(const uint8_t *img, size_t img_size, size_t msg_size) {
    char msg[msg_size + 1];
    memset(msg, 0, msg_size + 1);

    for (size_t i = 0; i < msg_size; i++) {
        for (size_t j = 0; j < 8; j++) {
            msg[i] |= (img[i * 8 + j] & 1) << j;
        }
    }

    printf("Hidden message: %s\n", msg);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <message> <msg_size>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb+");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 0, SEEK_END);
    size_t img_size = ftell(fp);
    rewind(fp);

    uint8_t *img = malloc(img_size);
    if (img == NULL) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }

    fread(img, 1, img_size, fp);

    size_t msg_size = atoi(argv[3]);
    char *msg = malloc(msg_size);
    if (msg == NULL) {
        perror("malloc");
        free(img);
        fclose(fp);
        return EXIT_FAILURE;
    }

    strcpy(msg, argv[2]);

    hide(img, img_size, msg, msg_size);

    fseek(fp, 0, SEEK_SET);
    fwrite(img, 1, img_size, fp);

    free(img);
    free(msg);
    fclose(fp);

    printf("Hidden message successfully.\n");

    return EXIT_SUCCESS;
}