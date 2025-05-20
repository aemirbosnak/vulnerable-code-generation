//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to watermark an image with a given string
void watermark(char* image, char* watermark) {
    // Open the image file
    FILE* img = fopen(image, "r");
    if (!img) {
        printf("Error: Unable to open file '%s'\n", image);
        return;
    }

    // Open the watermark file
    FILE* wmk = fopen(watermark, "r");
    if (!wmk) {
        printf("Error: Unable to open file '%s'\n", watermark);
        fclose(img);
        return;
    }

    // Read the image data
    fseek(img, 0, SEEK_END);
    long imgSize = ftell(img);
    fseek(img, 0, SEEK_SET);
    char* imgData = (char*)malloc(imgSize);
    fread(imgData, 1, imgSize, img);
    fclose(img);

    // Read the watermark data
    fseek(wmk, 0, SEEK_END);
    long wmkSize = ftell(wmk);
    fseek(wmk, 0, SEEK_SET);
    char* wmkData = (char*)malloc(wmkSize);
    fread(wmkData, 1, wmkSize, wmk);
    fclose(wmk);

    // Apply the watermark
    int i;
    for (i = 0; i < imgSize; i++) {
        if (imgData[i] == wmkData[i]) {
            imgData[i] = '#';
        }
    }

    // Write the watermarked image
    FILE* out = fopen(image, "w");
    if (!out) {
        printf("Error: Unable to open file '%s'\n", image);
        free(imgData);
        free(wmkData);
        return;
    }
    fwrite(imgData, 1, imgSize, out);
    fclose(out);

    // Free memory
    free(imgData);
    free(wmkData);
}

int main() {
    char* img = "image.png";
    char* wmk = "watermark.txt";
    watermark(img, wmk);
    return 0;
}