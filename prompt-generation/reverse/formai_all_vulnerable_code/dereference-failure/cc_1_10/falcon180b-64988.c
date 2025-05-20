//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 200
#define HEIGHT 200

int main(int argc, char **argv) {
    int i, j, k;
    double alpha, beta;
    unsigned char *image, *row, *pixel;
    FILE *infile, *outfile;

    // Open input file
    infile = fopen("input.bmp", "rb");
    if (infile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read image data
    image = (unsigned char *) malloc(WIDTH * HEIGHT * 3);
    if (image == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    fread(image, WIDTH * HEIGHT * 3, 1, infile);

    // Flip image vertically
    for (i = 0; i < HEIGHT / 2; i++) {
        row = image + i * WIDTH * 3;
        row += WIDTH * 3;
        for (j = 0; j < WIDTH * 3; j++) {
            pixel = row + j;
            row[j] = pixel[2];
            pixel[2] = 255 - pixel[2];
        }
    }

    // Change brightness and contrast
    alpha = 1.5;
    beta = 50;
    for (i = 0; i < HEIGHT; i++) {
        row = image + i * WIDTH * 3;
        for (j = 0; j < WIDTH; j++) {
            pixel = row + j * 3;
            pixel[0] = (unsigned char) (alpha * pixel[0] + beta);
            pixel[1] = (unsigned char) (alpha * pixel[1] + beta);
            pixel[2] = (unsigned char) (alpha * pixel[2] + beta);
        }
    }

    // Open output file
    outfile = fopen("output.bmp", "wb");
    if (outfile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write image data
    fwrite(image, WIDTH * HEIGHT * 3, 1, outfile);

    // Close files
    fclose(infile);
    fclose(outfile);

    return 0;
}