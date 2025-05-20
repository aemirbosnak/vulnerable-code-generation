//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

/* Elementary, my dear Watson! */
int main(void) {
    int width, height;
    unsigned char *image;

    /* Load the image */
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open image file\n");
        return EXIT_FAILURE;
    }
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&image, width * height * sizeof(Pixel), 1, fp);
    fclose(fp);

    /* Watson, enhance the image */
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            Pixel *pixel = &image[i * width + j];
            int gray = (pixel->red + pixel->green + pixel->blue) / 3;
            pixel->red = gray;
            pixel->green = gray;
            pixel->blue = gray;
        }
    }

    /* Save the image */
    fp = fopen("enhanced.bmp", "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open output file\n");
        return EXIT_FAILURE;
    }
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(&image, width * height * sizeof(Pixel), 1, fp);
    fclose(fp);

    /* The game is afoot! */
    return EXIT_SUCCESS;
}