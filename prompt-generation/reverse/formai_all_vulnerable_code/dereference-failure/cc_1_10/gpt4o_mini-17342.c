//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char header[54];
    unsigned int width;
    unsigned int height;
    unsigned int size;
} BMPImage;

void print_error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

BMPImage* load_bmp(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file)
        print_error("Could not open the BMP file.");

    BMPImage *image = malloc(sizeof(BMPImage));
    fread(image->header, sizeof(unsigned char), 54, file);
    image->width = *(int*)&image->header[18];
    image->height = *(int*)&image->header[22];
    image->size = 3 * image->width * image->height;

    return image;
}

void save_bmp(const char *filename, BMPImage *image, unsigned char *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file)
        print_error("Could not save the BMP file.");

    fwrite(image->header, sizeof(unsigned char), 54, file);
    fwrite(pixels, sizeof(unsigned char), image->size, file);
    fclose(file);
}

void embed_message(unsigned char *pixels, const char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 8; j++) {
            pixels[i * 8 + j * 3] &= 0xFE; // Clear the LSB
            pixels[i * 8 + j * 3] |= (message[i] >> (7 - j)) & 1; // Embed the LSB
        }
    }
}

void extract_message(unsigned char *pixels, char *message, int length) {
    for (int i = 0; i < length; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] <<= 1; // Shift left
            message[i] |= (pixels[i * 8 + j * 3] & 1); // Extract LSB
        }
    }
    message[length] = '\0'; // Null terminate the message
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input.bmp> <output.bmp> <message> <extract: 1/0>\n", argv[0]);
        return 1;
    }

    BMPImage *image = load_bmp(argv[1]);
    unsigned char *pixels = malloc(image->size);
    memcpy(pixels, image->header + 54, image->size);

    if (atoi(argv[4]) == 0) {
        embed_message(pixels, argv[3]);
        save_bmp(argv[2], image, pixels);
        printf("A message of love has been embedded within the image.\n");
    } else {
        char extracted[256];
        extract_message(pixels, extracted, strlen(argv[3]) / 8);
        printf("The message extracted is: %s\n", extracted);
    }

    free(pixels);
    free(image);
    return 0;
}