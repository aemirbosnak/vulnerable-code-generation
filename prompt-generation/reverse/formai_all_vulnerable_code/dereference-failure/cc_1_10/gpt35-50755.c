//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to perform digital watermarking
void digitalWatermarking(unsigned char *image, int imageSize, char *watermark) {
    // Convert watermark string to binary
    int watermarkSize = 0;
    while (watermark[watermarkSize] != '\0') {
        watermarkSize++;
    }
    unsigned char watermarkBinary[watermarkSize];
    for (int i = 0; i < watermarkSize; i++) {
        watermarkBinary[i] = (unsigned char) watermark[i];
    }

    // Check if watermark can fit in the image
    int maxWatermarkSize = (imageSize - 4) / 8;
    if (watermarkSize > maxWatermarkSize) {
        printf("Watermark is too large for the image.\n");
        exit(1);
    }

    // Add watermark size to the first 4 bytes of the image
    unsigned char *watermarkSizeBytes = (unsigned char *) &watermarkSize;
    for (int i = 0; i < 4; i++) {
        image[i] = watermarkSizeBytes[i];
    }

    // Embed watermark in the image
    int index = 4;
    for (int i = 0; i < watermarkSize; i++) {
        unsigned char byte = watermarkBinary[i];
        for (int j = 0; j < 8; j++) {
            int bit = (byte >> j) & 1;
            if (bit == 1) {
                image[index] |= 1;
            } else {
                image[index] &= 254;
            }
            index++;
        }
    }
}

int main() {
    // Example usage of digitalWatermarking function
    FILE *imageFile;
    imageFile = fopen("example_image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Unable to open example_image.bmp.\n");
        exit(1);
    }

    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    unsigned char *image = (unsigned char *) malloc(imageSize);
    fread(image, 1, imageSize, imageFile);
    fclose(imageFile);

    char watermark[] = "hello world!";
    digitalWatermarking(image, imageSize, watermark);

    FILE *watermarkedImageFile;
    watermarkedImageFile = fopen("watermarked_image.bmp", "wb");
    fwrite(image, 1, imageSize, watermarkedImageFile);
    fclose(watermarkedImageFile);

    free(image);

    return 0;
}