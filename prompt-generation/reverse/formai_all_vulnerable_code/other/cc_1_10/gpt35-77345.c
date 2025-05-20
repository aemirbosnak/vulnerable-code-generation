//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to store the digital watermarked image
typedef struct {
    char header[54];
    int width;
    int height;
    unsigned char* pixels;
} Image;

// Function to read the BMP image
Image readImage(char* filename) {
    Image img;

    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Read BMP header
    fread(img.header, 1, 54, file);
    img.width = *(int*)&img.header[18];
    img.height = *(int*)&img.header[22];

    // Allocate memory for pixels
    int size = img.width * img.height * 3;
    img.pixels = (unsigned char*)malloc(size);

    // Read pixels
    fread(img.pixels, 1, size, file);
    fclose(file);

    return img;
}

// Function to write the BMP image
void writeImage(char* filename, Image img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Write BMP header
    fwrite(img.header, 1, 54, file);

    // Write pixels
    fwrite(img.pixels, 1, img.width * img.height * 3, file);
    fclose(file);
}

// Function to generate a random binary watermark
char* generateWatermark(int length) {
    char* watermark = (char*)malloc(length+1);

    // Generate a random seed
    srand(time(0));

    for (int i = 0; i < length; i++) {
        watermark[i] = rand() % 2 + '0';
    }
    watermark[length] = '\0';

    return watermark;
}

// Function to embed binary watermark in LSB of image pixels
void embedWatermark(Image* img, char* watermark) {
    int len = strlen(watermark);

    for (int i = 0; i < len; i++) {
        char b = watermark[i];

        // Embed the bit b in the LSB of the pixel (R,G,B)
        for (int j = i*8; j < (i+1)*8; j++) {
            int idx = j*3;

            if (b & (1 << (7 - j%8))) {
                img->pixels[idx+2] |= 1;
            } else {
                img->pixels[idx+2] &= ~1;
            }
        }
    }
}

// Function to extract binary watermark from LSB of image pixels
char* extractWatermark(Image img, int length) {
    char* watermark = (char*)malloc(length+1);

    for (int i = 0; i < length; i++) {
        char b = 0;

        // Extract the bit b from the LSB of the pixel (R,G,B)
        for (int j = i*8; j < (i+1)*8; j++) {
            int idx = j*3;
            b |= ((img.pixels[idx+2] & 1) << (7 - j%8));
        }

        watermark[i] = b;
    }
    watermark[length] = '\0';

    return watermark;
}

int main() {
    // Read the input image
    Image img = readImage("input.bmp");

    // Create a binary watermark of length 32 bits
    char* watermark = generateWatermark(32);

    // Embed the watermark in the image pixels
    embedWatermark(&img, watermark);

    // Write the watermarked image to file
    writeImage("watermarked.bmp", img);

    // Read the watermarked image
    Image watermarkedImg = readImage("watermarked.bmp");

    // Extract the watermark from the watermarked image pixels
    char* extractedWatermark = extractWatermark(watermarkedImg, 32);

    // Check if the extracted watermark matches the original watermark
    if (strcmp(watermark, extractedWatermark) == 0) {
        printf("Watermarking successful!\n");
    } else {
        printf("Error: Watermarking failed!\n");
    }

    // Free memory
    free(watermark);
    free(extractedWatermark);
    free(img.pixels);
    free(watermarkedImg.pixels);

    return 0;
}