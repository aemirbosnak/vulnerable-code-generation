//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: brave
// Ahoy there, matey! Let's embark on a daring digital watermarking escapade!

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Prepare the canvas
typedef struct {
    uint32_t width, height;
    uint8_t *pixels;
} Image;

// Load the canvas from a file
Image *loadImage(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Avast! Couldn't find that treasure map (%s)!\n", filename);
        exit(1);
    }
    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d\n", &image->width, &image->height);
    image->pixels = malloc(image->width * image->height * 3);
    fread(image->pixels, 1, image->width * image->height * 3, file);
    fclose(file);
    return image;
}

// Reveal the hidden message!
void decodeWatermark(Image *image) {
    int bitCount = 0;
    uint8_t byte = 0;
    char message[256] = {0};
    for (int i = 0; i < image->width * image->height * 3; i++) {
        byte <<= 1;
        byte |= (image->pixels[i] & 1);
        bitCount++;
        if (bitCount == 8) {
            message[i / 3] = byte;
            bitCount = 0;
            byte = 0;
            if (byte == '\0') break;
        }
    }
    printf("Shiver me timbers! The hidden message is: %s\n", message);
}

// Yarr, let's hide a message in our image!
void embedWatermark(Image *image, char *message) {
    int bitCount = 0;
    int messageIndex = 0;
    for (int i = 0; i < image->width * image->height * 3; i++) {
        if (bitCount == 0) {
            image->pixels[i] &= 0xFE;
            image->pixels[i] |= message[messageIndex] & 1;
            messageIndex++;
        } else {
            image->pixels[i] &= 0xFE;
            image->pixels[i] |= (message[messageIndex] >> bitCount) & 1;
        }
        bitCount++;
        if (bitCount == 8 || message[messageIndex] == '\0') bitCount = 0;
    }
}

// Save the watery treasure
void saveImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "%d %d\n", image->width, image->height);
    fwrite(image->pixels, 1, image->width * image->height * 3, file);
    fclose(file);
}

// Set sail!
int main() {
    Image *image = loadImage("treasuremap.ppm");
    decodeWatermark(image);
    embedWatermark(image, "X marks the spot!");
    saveImage(image, "treasuremap_watermarked.ppm");
    free(image->pixels);
    free(image);
    return 0;
}