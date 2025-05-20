//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel image[IMAGE_WIDTH][IMAGE_HEIGHT];

void read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    fread(image, sizeof(pixel), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);
}

void write_image(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(image, sizeof(pixel), IMAGE_WIDTH * IMAGE_HEIGHT, fp);
    fclose(fp);
}

void embed_watermark(const char *watermark, int watermark_size) {
    int i, j, k;

    for (i = 0; i < watermark_size; i++) {
        for (j = 0; j < 8; j++) {
            int bit = (watermark[i] >> j) & 1;

            for (k = 0; k < 4; k++) {
                int x = i * 4 + k;
                int y = j * 4 + k;

                if (bit) {
                    image[x][y].r |= 1;
                } else {
                    image[x][y].r &= ~1;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        exit(1);
    }

    read_image(argv[1]);
    embed_watermark(argv[2], strlen(argv[2]));
    write_image(argv[3]);

    return 0;
}