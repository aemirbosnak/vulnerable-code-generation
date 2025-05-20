//MISTRAL-7B DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define SEED 7213
#define PIXELS_PER_BYTE 8
#define BMP_HEADER_SIZE 64
#define MAX_IMAGE_SIZE (1024 * 1024 * 3)
#define HIDDEN_DATA_SIZE 32

typedef struct {
    unsigned short type;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_data;
} bitmap_file_header;

typedef struct {
    unsigned short size;
    unsigned short width;
    unsigned short height;
    unsigned short planes;
    unsigned short bit_count;
    unsigned short compression;
    unsigned short size_image;
    unsigned int x_pixels_per_meter;
    unsigned int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int colors_important;
} bitmap_info_header;

typedef unsigned char byte;
typedef unsigned short word;

void randomize(unsigned int *buffer, int size) {
    unsigned int temp;
    for (int i = 0; i < size; i++) {
        srand(SEED + i);
        temp = rand();
        buffer[i] = (byte) (temp & 0xFF);
    }
}

void generate_noise(byte *image_data, int width, int height) {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            image_data[3 * (y * width + x)] += rand() % 256;
        }
    }
}

void hide_data(byte *image_data, int width, int height, byte *data) {
    int pixel_index = 0;
    for (int i = 0; i < HIDDEN_DATA_SIZE; i++) {
        int r = image_data[3 * (rand() % height * width + rand() % width)];
        int g = image_data[3 * (rand() % height * width + rand() % width) + 1];
        int b = image_data[3 * (rand() % height * width + rand() % width) + 2];

        image_data[3 * (pixel_index)] = r;
        image_data[3 * (pixel_index) + 1] = g;
        image_data[3 * (pixel_index) + 2] = b;

        image_data[3 * (pixel_index) + (PIXELS_PER_BYTE * 2)] = data[i];

        pixel_index++;
    }
}

void save_image(byte *image_data, int width, int height, char *filename) {
    bitmap_file_header file_header;
    bitmap_info_header info_header;

    file_header.type = 0x4D42;
    file_header.filesize = BMP_HEADER_SIZE + width * height * 3;
    info_header.size = sizeof(bitmap_info_header);
    info_header.width = width;
    info_header.height = height;
    info_header.planes = 1;
    info_header.bit_count = 24;
    info_header.compression = 0;
    info_header.size_image = width * height * 3;

    byte bmp_header[BMP_HEADER_SIZE];

    memcpy(bmp_header, &file_header, sizeof(bitmap_file_header));
    memcpy(bmp_header + sizeof(bitmap_file_header), &info_header, sizeof(bitmap_info_header));

    FILE *file = fopen(filename, "wb");
    fwrite(bmp_header, BMP_HEADER_SIZE, 1, file);
    fwrite(image_data, width * height * 3, 1, file);
    fclose(file);
}

int main() {
    int width = 512;
    int height = 512;
    byte *image_data = (byte *) malloc(width * height * 3);
    byte hidden_data[HIDDEN_DATA_SIZE];

    randomize(image_data, width * height * 3);
    generate_noise(image_data, width, height);

    printf("Enter hidden data: ");
    fread(hidden_data, HIDDEN_DATA_SIZE, 1, stdin);

    hide_data(image_data, width, height, hidden_data);

    save_image(image_data, width, height, "output.bmp");

    free(image_data);
    return 0;
}