//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <string.h>

#define WATERMARK_SIZE 16

int main(int argc, char *argv[]) {
    char *watermark = "SECRET_WATERMARK";
    char *image = "input.jpg";

    int watermarkSize = strlen(watermark);

    FILE *imageFile = fopen(image, "rb");
    if (imageFile == NULL) {
        fprintf(stderr, "Error opening image file\n");
        return 1;
    }

    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    char *imageData = (char *)malloc(imageSize);
    if (imageData == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }

    fread(imageData, 1, imageSize, imageFile);
    fclose(imageFile);

    char *watermarkData = (char *)malloc(watermarkSize);
    if (watermarkData == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        free(imageData);
        return 1;
    }

    memcpy(watermarkData, watermark, watermarkSize);

    int watermarkPos = 0;
    for (int i = 0; i < imageSize; i += WATERMARK_SIZE) {
        memcpy(&imageData[i], watermarkData, WATERMARK_SIZE);
        watermarkPos += WATERMARK_SIZE;
    }

    FILE *outputFile = fopen("output.jpg", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file\n");
        free(imageData);
        free(watermarkData);
        return 1;
    }

    fwrite(imageData, 1, imageSize, outputFile);
    fclose(outputFile);

    free(imageData);
    free(watermarkData);

    return 0;
}