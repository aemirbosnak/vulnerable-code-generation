//FormAI DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    // variables for file i/o
    FILE *infile, *outfile;

    // variables for image dimensions and pixel values
    int width, height, depth;
    unsigned char *pixels;

    // open input file for reading
    infile = fopen("input_image.ppm", "rb");
    if (infile == NULL) {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }

    // read in header values
    char header[3];
    fscanf(infile, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Input file must be P6 ppm format\n");
        exit(EXIT_FAILURE);
    }
    fscanf(infile, "%d %d", &width, &height);
    fscanf(infile, "%d", &depth);
    fgetc(infile);

    // allocate memory for pixel values
    pixels = (unsigned char*)malloc(3 * width * height * sizeof(unsigned char));
    if (pixels == NULL) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }

    // read in pixel values
    fread(pixels, sizeof(unsigned char), 3 * width * height, infile);
    fclose(infile);

    // apply image filter here
    // for example, invert colors
    for (int i = 0; i < 3 * width * height; i++) {
        pixels[i] = depth - pixels[i];
    }

    // open output file for writing
    outfile = fopen("output_image.ppm", "wb");
    if (outfile == NULL) {
        perror("Unable to open output file");
        exit(EXIT_FAILURE);
    }

    // write header and pixel values
    fprintf(outfile, "P6\n%d %d\n%d\n", width, height, depth);
    fwrite(pixels, sizeof(unsigned char), 3 * width * height, outfile);
    fclose(outfile);

    // free allocated memory
    free(pixels);

    return 0;
}