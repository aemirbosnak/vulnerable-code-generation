//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54
#define MAX_IMAGE_SIZE 1048576

typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

Image create_image(int width, int height) {
    Image image = { width, height, (unsigned char*)malloc(width * height * 3) };
    memset(image.pixels, 0, width * height * 3);

    return image;
}

Image read_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    unsigned char header[HEADER_SIZE];
    fread(header, 1, HEADER_SIZE, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int image_size = *(int*)&header[34];

    if (width > 512 || height > 512 || image_size > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Invalid image size\n");
        exit(1);
    }

    unsigned char* pixels = (unsigned char*)malloc(image_size);
    fread(pixels, 1, image_size, file);
    fclose(file);

    Image image = { width, height, pixels };
    return image;
}

void write_image(const char* filename, Image image) {
    unsigned char header[HEADER_SIZE];
    memset(header, 0, HEADER_SIZE);

    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = HEADER_SIZE + image.width * image.height * 3;
    *(int*)&header[10] = HEADER_SIZE;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = image.width;
    *(int*)&header[22] = image.height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    *(int*)&header[34] = image.width * image.height * 3;

    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }
    fwrite(header, 1, HEADER_SIZE, file);
    fwrite(image.pixels, 1, image.width * image.height * 3, file);
    fclose(file);
}

void encode(Image image, const char* message) {
    int message_length = strlen(message);
    if (message_length > (image.width * image.height * 3 / 8)) {
        fprintf(stderr, "Message is too large to encode in image\n");
        exit(1);
    }

    int bit_index = 0;
    int byte_index = 0;
    unsigned char byte = 0;

    for (int i = 0; i <= message_length; i++) {
        char c = message[i];
        for (int j = 0; j < 8; j++) {
            unsigned char bit = (c >> j) & 1;
            byte |= bit << bit_index;
            bit_index++;
            if (bit_index == 8) {
                image.pixels[byte_index] |= byte;
                byte = 0;
                bit_index = 0;
                byte_index++;
            }
        }
    }
}

char* decode(Image image) {
    int bit_index = 0;
    int byte_index = 0;
    unsigned char byte = 0;

    char* result = malloc(MAX_IMAGE_SIZE);
    memset(result, 0, MAX_IMAGE_SIZE);

    for (int i = 0; i < image.width * image.height * 3; i++) {
        unsigned char bit = image.pixels[i] & 1;
        byte |= bit << bit_index;
        bit_index++;
        if (bit_index == 8) {
            if (byte == 0) {
                return result;
            }
            result[byte_index] = byte;
            byte = 0;
            bit_index = 0;
            byte_index++;
        }
    }

    return result;
}

int main() {
    Image image = read_image("image.bmp");
    encode(image, "Hello World");
    write_image("output.bmp", image);

    Image encoded_image = read_image("output.bmp");
    char* message = decode(encoded_image);
    printf("Decoded message: %s\n", message);

    free(encoded_image.pixels);
    free(message);

    return 0;
}