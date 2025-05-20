//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)
#define MAX_BYTES (MAX_PIXELS * 3)

typedef struct {
    int width, height;
    unsigned char *data;
} image_t;

void read_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (filesize!= MAX_BYTES) {
        printf("Error: invalid image size\n");
        exit(1);
    }

    image->data = (unsigned char *) malloc(MAX_BYTES);
    fread(image->data, 1, MAX_BYTES, fp);

    fclose(fp);

    image->width = MAX_WIDTH;
    image->height = MAX_HEIGHT;
}

void write_image(const char *filename, const image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    fwrite(image->data, 1, MAX_BYTES, fp);

    fclose(fp);
}

void add_message(image_t *image, const char *message) {
    int message_size = strlen(message);
    int pixel_index = 0;

    for (int i = 0; i < message_size; i++) {
        int bit = message[i] - 'a';
        for (int j = 0; j < 8; j++) {
            int byte_index = pixel_index / 3;
            int bit_index = pixel_index % 3;

            int mask = 1 << (7 - j);
            if (bit & mask) {
                image->data[byte_index] |= (1 << (7 - bit_index));
            } else {
                image->data[byte_index] &= ~(1 << (7 - bit_index));
            }

            pixel_index++;
        }
    }
}

void extract_message(const image_t *image, char *message) {
    int message_size = strlen(message);
    int pixel_index = 0;

    for (int i = 0; i < message_size; i++) {
        int bit = 0;
        for (int j = 0; j < 8; j++) {
            int byte_index = pixel_index / 3;
            int bit_index = pixel_index % 3;

            int mask = 1 << (7 - j);
            if (image->data[byte_index] & mask) {
                bit |= mask;
            }

            pixel_index++;
        }

        message[i] = 'a' + bit;
    }

    message[message_size] = 0;
}

int main() {
    image_t image;

    read_image("input.bmp", &image);

    char *message = "Hello, world!";
    add_message(&image, message);

    write_image("output.bmp", &image);

    char extracted_message[100];
    extract_message(&image, extracted_message);

    printf("Extracted message: %s\n", extracted_message);

    return 0;
}