//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define BLOCK_SIZE 64

uint8_t *load_image(char *filename, uint32_t *width, uint32_t *height) {
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL) {
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    uint32_t size = ftell(fp) - 54;
    fseek(fp, 54, SEEK_SET);
    uint8_t *data = (uint8_t *)malloc(size);
    fread(data, 1, size, fp);

    *width = *(uint32_t *)&data[0x12];
    *height = *(uint32_t *)&data[0x16];

    fclose(fp);

    return data;
}

void convert_to_ascii(uint8_t *ptr, uint32_t width, uint32_t height) {
    const char *ascii_chars = "$@B%8&WM#*oahkbdpwmZO0QCJYXzcvnxsok.-^/~_:+*?<>i!lI;\",^`'. ";

    uint8_t *pixel = ptr;
    char ascii[BLOCK_SIZE * 2 + 2];

    for (uint32_t y = 0; y < height; y += 2) {
        for (uint32_t x = 0; x < width; x += 2) {
            uint32_t avg = 0;

            for (uint32_t j = 0; j < 4; j++) {
                avg += *pixel++;

            }
            avg /= 4;

            size_t index = avg * (strlen(ascii_chars) - 1) / 255;
            if (index >= strlen(ascii_chars)) {
                index = strlen(ascii_chars) - 1;
            }
            ascii[x / 2] = ascii_chars[index];
        }

        ascii[width / 2] = '\n';
        ascii[width / 2 + 1] = '\0';

        printf("%s", ascii);
    }
}


int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s image-path\n", argv[0]);
        return -1;
    }

    uint32_t width, height;
    uint8_t *data = load_image(argv[1], &width, &height);
    if(data == NULL) {
        printf("Could not load image\n");
        return -1;
    }

    convert_to_ascii(data, width, height);

    free(data);

    return 0;
}