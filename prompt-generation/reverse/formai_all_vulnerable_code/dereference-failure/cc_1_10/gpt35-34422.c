//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/* Function to convert integer to binary */
void decToBinary(int n, int binaryArray[]) {

    int i = 0;
    while (n > 0) {
        binaryArray[i] = n % 2;
        n = n / 2;
        i++;
    }
}

/* Function to convert binary to decimal */
int binaryToDecimal(int binaryArray[]) {

    int decimal = 0;

    for (int i = 0; i < 8; i++) {
        decimal += binaryArray[i] * pow(2, i);
    }

    return decimal;
}

/* Function to embed the watermark */
void embedWatermark(char *imageData, int watermark) {

    int binaryArray[8];
    decToBinary(watermark, binaryArray);

    /* Embed the watermark in the 4th byte of the image data */
    for (int i = 0; i < 8; i++) {
        imageData[i + 3] = (char)binaryArray[i];
    }
}

/* Function to extract the watermark */
int extractWatermark(char *imageData) {

    int binaryArray[8];

    /* Extract the watermark from the 4th byte of the image data */
    for (int i = 0; i < 8; i++) {
        binaryArray[i] = (int)imageData[i + 3];
    }

    int watermark = binaryToDecimal(binaryArray);

    return watermark;
}

int main() {

    FILE *imageFile, *watermarkedImageFile;
    char *imageData;
    int imageDataSize;
    int watermark = 123;

    /* Open the image file */
    imageFile = fopen("image.bmp", "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    /* Get the size of the image data */
    fseek(imageFile, 0, SEEK_END);
    imageDataSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    /* Allocate memory for the image data */
    imageData = malloc(imageDataSize);
    if (imageData == NULL) {
        printf("Error allocating memory for image data.\n");
        return 2;
    }

    /* Read the image data into memory */
    fread(imageData, 1, imageDataSize, imageFile);

    /* Embed the watermark in the image data */
    embedWatermark(imageData, watermark);

    /* Write the watermarked image data to a new file */
    watermarkedImageFile = fopen("watermarked_image.bmp", "wb");
    if (watermarkedImageFile == NULL) {
        printf("Error creating watermarked image file.\n");
        return 3;
    }

    fwrite(imageData, 1, imageDataSize, watermarkedImageFile);

    fclose(imageFile);
    fclose(watermarkedImageFile);

    /* Open the watermarked image file */
    watermarkedImageFile = fopen("watermarked_image.bmp", "rb");
    if (watermarkedImageFile == NULL) {
        printf("Error opening watermarked image file.\n");
        return 4;
    }

    /* Get the size of the watermarked image data */
    fseek(watermarkedImageFile, 0, SEEK_END);
    imageDataSize = ftell(watermarkedImageFile);
    fseek(watermarkedImageFile, 0, SEEK_SET);

    /* Allocate memory for the watermarked image data */
    imageData = malloc(imageDataSize);
    if (imageData == NULL) {
        printf("Error allocating memory for watermarked image data.\n");
        return 5;
    }

    /* Read the watermarked image data into memory */
    fread(imageData, 1, imageDataSize, watermarkedImageFile);

    /* Extract the watermark from the image data */
    int extractedWatermark = extractWatermark(imageData);
    printf("Extracted watermark: %d\n", extractedWatermark);

    fclose(watermarkedImageFile);
    free(imageData);

    return 0;
}