//FormAI DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500

// Function to read a PPM image file and return its pixel data as a dynamically allocated array
unsigned char* readPPM(const char* filename, int *width, int *height, int *maxval) {

    // open the file for reading in binary mode
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Unable to open input file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // check if the file has the correct magic number
    char magic[3];
    fgets(magic, sizeof magic, file);
    if (magic[0] != 'P' || magic[1] != '6') {
        fprintf(stderr, "Invalid PPM image format: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // skip over any comments in the file header
    int c;
    while ((c = getc(file)) == '#') {
        while (getc(file) != '\n');
    }
    ungetc(c, file);

    // read the image width, height, and maximum pixel value
    if (fscanf(file, "%d %d %d", width, height, maxval) != 3) {
        fprintf(stderr, "Invalid PPM image format: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // allocate memory for the pixel data
    unsigned char *data = (unsigned char*) malloc((*width) * (*height) * 3);
    if (data == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    // read the pixel data from the file and close it
    fread(data, sizeof(unsigned char), (*width) * (*height) * 3, file);
    fclose(file);

    // return the pixel data
    return data;
}

// Function to write a PPM image file with the given pixel data
void writePPM(const char* filename, const unsigned char* data, const int width, const int height, const int maxval) {
    
    // open the file for writing in binary mode
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Unable to open output file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // write the PPM file header
    fprintf(file, "P6\n%d %d\n%d\n", width, height, maxval);

    // write the pixel data to the file and close it
    fwrite(data, sizeof(unsigned char), width * height * 3, file);
    fclose(file);
}

// Function to convert a grayscale image to a binary image using a specified threshold
void threshold(const unsigned char* in, unsigned char* out, const int width, const int height, const int threshold) {

    // iterate over the pixels in the image
    for (int i = 0; i < width * height * 3; i += 3) {

        // compute the average of the three color channels
        int average = (in[i] + in[i+1] + in[i+2]) / 3;

        // set the output pixel to white if the average is above the threshold, black otherwise
        if (average >= threshold) {
            out[i] = out[i+1] = out[i+2] = 255;  // white
        } else {
            out[i] = out[i+1] = out[i+2] = 0;    // black
        }
    }
}

int main(int argc, char **argv) {
    
    // check command-line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.ppm output.ppm threshold\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // read the input image file
    int width, height, maxval;
    unsigned char *in = readPPM(argv[1], &width, &height, &maxval);

    // allocate memory for the output image
    unsigned char *out = (unsigned char*) malloc(width * height * 3);
    if (out == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }

    // convert the input image to a binary image using the specified threshold
    threshold(in, out, width, height, atoi(argv[3]));

    // write the output image file
    writePPM(argv[2], out, width, height, maxval);

    // free the memory allocated for the input and output images
    free(in);
    free(out);

    return EXIT_SUCCESS;
}