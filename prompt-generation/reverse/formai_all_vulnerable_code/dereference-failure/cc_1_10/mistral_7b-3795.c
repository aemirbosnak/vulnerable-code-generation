//MISTRAL-7B DATASET v1.0 Category: Image Steganography ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Struct to store image details
typedef struct {
    int width, height;
    unsigned char *data;
} Image;

// Function to read image from file
Image readImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 2, SEEK_SET);
    int size = 0;
    fread(&size, sizeof(int), 1, file);
    size += 2;
    Image img = {.width = size / 3, .height = size / 2, .data = malloc(size)};
    fread(img.data, sizeof(unsigned char), size, file);
    fclose(file);
    return img;
}

// Function to write image to file
void writeImage(const char *filename, const Image img) {
    FILE *file = fopen(filename, "wb");
    fwrite(&img.width, sizeof(int), 1, file);
    fwrite(&img.height, sizeof(int), 1, file);
    fwrite(img.data, sizeof(unsigned char), img.width * img.height, file);
    fclose(file);
}

// Function to hide message in image
void hideMessage(Image *img, const char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        int x = (img->width * (img->height * i) / (256 * 256));
        int b = img->data[x] + message[i];
        if (b > 255) b -= 255;
        img->data[x] = b;
    }
}

// Function to extract message from image
char *extractMessage(const Image img) {
    int len = img.width * img.height;
    char *message = malloc(len);
    for (int i = 0; i < len; i++) {
        message[i] = img.data[i] - (img.data[i] % 1);
    }
    return message;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <image> <message>\n", argv[0]);
        return 1;
    }

    Image img = readImage(argv[1]);
    char *message = argv[2];

    hideMessage(&img, message);
    writeImage("steganized.bmp", img);

    free(img.data);

    char *extracted = extractMessage(img);
    printf("Extracted message: %s\n", extracted);
    free(extracted);

    return 0;
}