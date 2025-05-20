//MISTRAL-7B DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define BPP 3

typedef uint8_t pixel[BPP];

void read_pgm(const char *filename, pixel **image, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    char magic_number[3];
    fgets(magic_number, sizeof(magic_number), fp);
    if (strncmp(magic_number, "P5", 2) != 0) {
        printf("Invalid PGm file.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d\n", width, height);
    *image = (pixel *) malloc(*width * *height * sizeof(pixel));
    fread(*image, *width * *height * BPP, 1, fp);
    fclose(fp);
}

void write_pgm(const char *filename, const pixel *image, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", width, height);
    fwrite(image, width * height * BPP, 1, fp);
    fclose(fp);
}

void embed_watermark(const char *watermark, pixel *image, int width, int height) {
    int x, y, index;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            index = y * width + x;
            if (image[index][0] > image[index][1] && image[index][0] > image[index][2]) {
                image[index][BPP - 1] ^= watermark[index % strlen(watermark)];
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s input.pgm watermark.txt output.pgm\n", argv[0]);
        return EXIT_FAILURE;
    }

    pixel *image;
    int width, height;
    read_pgm(argv[1], &image, &width, &height);

    const char *watermark = argv[2];
    embed_watermark(watermark, image, width, height);

    write_pgm(argv[3], image, width, height);

    free(image);

    printf("Watermark embedded successfully.\n");

    return EXIT_SUCCESS;
}