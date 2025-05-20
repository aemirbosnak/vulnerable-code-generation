//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 100

int main(int argc, char **argv) {
    FILE *infile, *outfile;
    unsigned char *image;
    int i, j;
    double alpha, beta;
    char watermark[10] = "example";

    //read input image from file
    infile = fopen("input.bmp", "rb");
    if (infile == NULL) {
        printf("Error: cannot open input file.\n");
        exit(1);
    }

    //allocate memory for image
    image = (unsigned char *) malloc(WIDTH * HEIGHT * 3);
    if (image == NULL) {
        printf("Error: cannot allocate memory for image.\n");
        exit(1);
    }

    //read input image into memory
    fread(image, 1, WIDTH * HEIGHT * 3, infile);
    fclose(infile);

    //embed watermark into image
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            alpha = (double) rand() / RAND_MAX;
            beta = (double) rand() / RAND_MAX;
            image[3 * (i + j * WIDTH)] += alpha * beta * MAX_VALUE;
        }
    }

    //write watermarked image to output file
    outfile = fopen("output.bmp", "wb");
    if (outfile == NULL) {
        printf("Error: cannot open output file.\n");
        exit(1);
    }

    fwrite(image, 1, WIDTH * HEIGHT * 3, outfile);
    fclose(outfile);

    free(image);
    return 0;
}