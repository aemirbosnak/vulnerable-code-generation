//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

#define MAX_VALUE 255
#define MIN_VALUE 0

int main(int argc, char *argv[]) {

    // Load image
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    // Read header
    char header[54];
    fread(header, 1, 54, fp);

    // Check if BMP file
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: Invalid image file format.\n");
        fclose(fp);
        return 1;
    }

    // Read image data
    unsigned char *data = (unsigned char *) malloc(WIDTH * HEIGHT * 3);
    fread(data, 1, WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    // Embed watermark
    int watermark_width = 100;
    int watermark_height = 50;
    int watermark_x = WIDTH / 2 - watermark_width / 2;
    int watermark_y = HEIGHT / 2 - watermark_height / 2;

    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            int index = (watermark_y + j) * WIDTH + (watermark_x + i);
            data[index * 3] = 0;
            data[index * 3 + 1] = 0;
            data[index * 3 + 2] = 0;
        }
    }

    // Save watermarked image
    FILE *out_fp = fopen("watermarked_image.bmp", "wb");
    if (out_fp == NULL) {
        printf("Error: Could not open output file.\n");
        free(data);
        return 1;
    }

    // Write header
    fwrite(header, 1, 54, out_fp);

    // Write image data
    fwrite(data, 1, WIDTH * HEIGHT * 3, out_fp);

    fclose(out_fp);
    free(data);

    printf("Watermark embedded successfully.\n");

    return 0;
}