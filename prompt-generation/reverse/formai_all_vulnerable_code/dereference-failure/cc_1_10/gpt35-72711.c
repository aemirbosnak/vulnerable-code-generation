//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *fp1;
    int x, y, range, i, j, val;
    unsigned char *img, *new_img;

    // Open input file
    fp = fopen("input.pgm", "rb");
    if (!fp) {
        printf("Unable to open file!\n");
        return 1;
    }

    // Read magic number
    char magic[3];
    fscanf(fp, "%s", magic);

    // Read image dimensions
    fscanf(fp, "%d %d", &x, &y);

    // Read range (max value)
    fscanf(fp, "%d", &range);

    // Allocate memory for image and new image
    img = (unsigned char*)malloc(x * y * sizeof(unsigned char));
    new_img = (unsigned char*)malloc(x * y * sizeof(unsigned char));

    // Read image data into array
    for (i = 0; i < x * y; i++) {
        val = fgetc(fp);
        img[i] = (unsigned char)val;
    }

    // Close input file
    fclose(fp);

    // Flipping the image horizontally
    for (i = 0; i < y; i++) {
        for (j = 0; j < x; j++) {
            new_img[i*x + x - j - 1] = img[i*x + j];
        }
    }

    // Changing brightness and contrast of the image
    for (i = 0; i < x * y; i++) {
        if (new_img[i] < 128) {
            new_img[i] += 50;
        }
        else {
            new_img[i] -= 50;
        }
    }

    // Open output file
    fp1 = fopen("output.pgm", "wb");
    if (!fp1) {
        printf("Unable to open file!\n");
        return 1;
    }

    // Write magic number, image dimensions, and range to output file
    fprintf(fp1, "%s\n", magic);
    fprintf(fp1, "%d %d\n", x, y);
    fprintf(fp1, "%d\n", range);

    // Write new image data to output file
    for (i = 0; i < x*y; i++) {
        fputc(new_img[i], fp1);
    }

    // Close output file
    fclose(fp1);

    // Free memory
    free(img);
    free(new_img);

    return 0;
}