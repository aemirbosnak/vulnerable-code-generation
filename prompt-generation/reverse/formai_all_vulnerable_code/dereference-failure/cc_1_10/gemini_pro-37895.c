//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

unsigned char image[WIDTH * HEIGHT];
unsigned char watermark[WIDTH * HEIGHT / 4];

void read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fread(image, WIDTH * HEIGHT, 1, fp);
    fclose(fp);
}

void read_watermark(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fread(watermark, WIDTH * HEIGHT / 4, 1, fp);
    fclose(fp);
}

void write_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fwrite(image, WIDTH * HEIGHT, 1, fp);
    fclose(fp);
}

void embed_watermark() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (watermark[i / 4] & (1 << (i % 4))) {
            image[i] |= 1;
        } else {
            image[i] &= ~1;
        }
    }
}

void extract_watermark() {
    for (int i = 0; i < WIDTH * HEIGHT / 4; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 4; j++) {
            if (image[4 * i + j] & 1) {
                watermark[i] |= (1 << j);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <image> <watermark> <output> <embed/extract>\n", argv[0]);
        exit(1);
    }

    read_image(argv[1]);
    read_watermark(argv[2]);

    if (strcmp(argv[4], "embed") == 0) {
        embed_watermark();
    } else if (strcmp(argv[4], "extract") == 0) {
        extract_watermark();
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[4]);
        exit(1);
    }

    write_image(argv[3]);

    return 0;
}