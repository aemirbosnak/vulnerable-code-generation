//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} pixel;

void rle_encode(unsigned char *data, size_t size, unsigned char *output) {
    size_t i = 0, j = 0;
    unsigned char prev = data[0];
    unsigned char count = 1;

    while (i < size) {
        if (data[i] == prev) {
            count++;
        } else {
            output[j++] = prev;
            if (count > 1) {
                output[j++] = count;
                count = 1;
            }
            prev = data[i++];
        }
    }

    if (count > 1) {
        output[j++] = prev;
        output[j++] = count;
    }

    *((size_t *)output) = j;
}

void load_image(const char *filename, pixel *image) {
    FILE *file = fopen(filename, "rb");
    size_t size = 0;
    unsigned char header[2] = {0};

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fread(header, sizeof(header), 1, file);

    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Invalid file format\n");
        exit(EXIT_FAILURE);
    }

    fseek(file, 10, SEEK_SET); // Skip over file size and offset fields

    size = (WIDTH * HEIGHT) * 3;
    image = malloc(size);

    fread(image, 1, size, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pixel image[WIDTH * HEIGHT];
    unsigned char *encoded_data = NULL;
    size_t encoded_size = 0;

    load_image(argv[1], (pixel *)image);

    rle_encode((unsigned char *)image, sizeof(image), encoded_data);

    printf("Encoded data size: %zu bytes\n", encoded_size);

    free(image);

    return EXIT_SUCCESS;
}