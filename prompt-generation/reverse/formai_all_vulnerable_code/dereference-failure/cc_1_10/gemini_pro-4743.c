//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILENAME_LEN 256

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} image;

image *load_image(const char *filename) {
    FILE *fp;
    image *img;
    int ret;
    struct stat st;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return NULL;
    }

    ret = fstat(fileno(fp), &st);
    if (ret == -1) {
        fprintf(stderr, "Error getting file size: %s\n", strerror(errno));
        fclose(fp);
        return NULL;
    }

    img = malloc(sizeof(image));
    if (img == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    img->data = malloc(st.st_size);
    if (img->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(img);
        fclose(fp);
        return NULL;
    }

    ret = fread(img->data, 1, st.st_size, fp);
    if (ret != st.st_size) {
        fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        free(img->data);
        free(img);
        fclose(fp);
        return NULL;
    }

    fclose(fp);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char **argv) {
    image *img;
    uint32_t i, j, k;
    double r, g, b, a;
    uint8_t watermark[32];
    uint32_t watermark_len;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image file> <watermark> <embed/extract>\n", argv[0]);
        return EXIT_FAILURE;
    }

    img = load_image(argv[1]);
    if (img == NULL) {
        return EXIT_FAILURE;
    }

    watermark_len = strlen(argv[2]);
    if (watermark_len > 32) {
        fprintf(stderr, "Watermark too long (max 32 characters)\n");
        free_image(img);
        return EXIT_FAILURE;
    }

    strcpy((char *)watermark, argv[2]);

    if (strcmp(argv[3], "embed") == 0) {
        for (i = 0; i < img->height; i++) {
            for (j = 0; j < img->width; j++) {
                r = img->data[(i * img->width + j) * 4 + 0];
                g = img->data[(i * img->width + j) * 4 + 1];
                b = img->data[(i * img->width + j) * 4 + 2];
                a = img->data[(i * img->width + j) * 4 + 3];

                for (k = 0; k < watermark_len; k++) {
                    if ((i + j) % 2 == 0) {
                        r += (watermark[k] & (1 << (7 - k))) * 0.01;
                        g += (watermark[k] & (1 << (6 - k))) * 0.01;
                        b += (watermark[k] & (1 << (5 - k))) * 0.01;
                    } else {
                        r += (watermark[k] & (1 << (4 - k))) * 0.01;
                        g += (watermark[k] & (1 << (3 - k))) * 0.01;
                        b += (watermark[k] & (1 << (2 - k))) * 0.01;
                    }
                }

                img->data[(i * img->width + j) * 4 + 0] = r;
                img->data[(i * img->width + j) * 4 + 1] = g;
                img->data[(i * img->width + j) * 4 + 2] = b;
                img->data[(i * img->width + j) * 4 + 3] = a;
            }
        }
    } else if (strcmp(argv[3], "extract") == 0) {
        for (i = 0; i < img->height; i++) {
            for (j = 0; j < img->width; j++) {
                r = img->data[(i * img->width + j) * 4 + 0];
                g = img->data[(i * img->width + j) * 4 + 1];
                b = img->data[(i * img->width + j) * 4 + 2];

                for (k = 0; k < watermark_len; k++) {
                    if ((i + j) % 2 == 0) {
                        watermark[k] |= ((r - floor(r)) >= 0.005) << (7 - k);
                        watermark[k] |= ((g - floor(g)) >= 0.005) << (6 - k);
                        watermark[k] |= ((b - floor(b)) >= 0.005) << (5 - k);
                    } else {
                        watermark[k] |= ((r - floor(r)) >= 0.005) << (4 - k);
                        watermark[k] |= ((g - floor(g)) >= 0.005) << (3 - k);
                        watermark[k] |= ((b - floor(b)) >= 0.005) << (2 - k);
                    }
                }
            }
        }

        watermark[watermark_len] = '\0';
        printf("%s\n", watermark);
    } else {
        fprintf(stderr, "Invalid operation (embed/extract)\n");
        free_image(img);
        return EXIT_FAILURE;
    }

    free_image(img);

    return EXIT_SUCCESS;
}