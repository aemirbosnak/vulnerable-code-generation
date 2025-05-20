//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256
#define PIXEL_BYTES 3
#define MAX_MESSAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT * PIXEL_BYTES - 1)

typedef struct {
    char* filename;
    unsigned char* data;
    int width;
    int height;
} Image;

void read_image(Image* img) {
    FILE* fp = fopen(img->filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", img->filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    if (img->data == NULL) {
        printf("Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(img->data, 1, size, fp);
    fclose(fp);

    img->width = IMAGE_WIDTH;
    img->height = IMAGE_HEIGHT;
}

void write_image(Image* img) {
    FILE* fp = fopen(img->filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s for writing\n", img->filename);
        exit(1);
    }

    fwrite(img->data, 1, strlen(img->data), fp);
    fclose(fp);
}

void hide_message(Image* img, char* message) {
    int message_size = strlen(message);
    if (message_size > MAX_MESSAGE_SIZE) {
        printf("Error: message is too long\n");
        exit(1);
    }

    int index = 0;
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int pixel_index = (y * IMAGE_WIDTH + x) * PIXEL_BYTES;
            for (int c = 0; c < PIXEL_BYTES; c++) {
                img->data[pixel_index + c] += message[index];
                index++;
            }
        }
    }
}

void reveal_message(Image* img, char* message) {
    int message_size = strlen(message);
    if (message_size > MAX_MESSAGE_SIZE) {
        printf("Error: message is too long\n");
        exit(1);
    }

    int index = 0;
    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            int pixel_index = (y * IMAGE_WIDTH + x) * PIXEL_BYTES;
            for (int c = 0; c < PIXEL_BYTES; c++) {
                img->data[pixel_index + c] -= message[index];
                index++;
            }
        }
    }
}

int main() {
    Image image;
    image.filename = "test.bmp";
    read_image(&image);

    char* message = "Hello, world!";
    hide_message(&image, message);
    write_image(&image);

    reveal_message(&image, message);
    write_image(&image);

    return 0;
}