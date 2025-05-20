//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to load image data from file
unsigned char *loadImageData(char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // check magic number
    char magic[3];
    fread(magic, sizeof(char), 2, file);
    if (strcmp(magic, "P6") != 0) {
        printf("Error: Invalid PPM file format\n");
        fclose(file);
        return NULL;
    }

    // read width and height
    fscanf(file, "%d %d\n", width, height);

    // read max value
    int maxVal;
    fscanf(file, "%d\n", &maxVal);
    if (maxVal != 255) {
        printf("Error: Unsupported PPM max value\n");
        fclose(file);
        return NULL;
    }

    // allocate memory for image data
    unsigned char *data = (unsigned char *) malloc((*width) * (*height) * 3);
    if (!data) {
        printf("Error: Could not allocate memory for image data\n");
        fclose(file);
        return NULL;
    }

    // read image data
    fread(data, sizeof(unsigned char), (*width) * (*height) * 3, file);

    // close file and return data
    fclose(file);
    return data;
}

// function to convert image data to ASCII art
void convertToAsciiArt(unsigned char *data, int width, int height, char *art, int artWidth, int artHeight) {
    // calculate pixel aspect ratio
    float pixelAspectRatio = (float) width / height;

    // calculate box aspect ratio
    float boxAspectRatio = (float) artWidth / artHeight;

    // calculate scale factors for width and height
    float widthScale = (float) artWidth / width;
    float heightScale = (float) artHeight / height;

    // loop through each box in the ASCII art
    for (int i = 0; i < artHeight; i++) {
        for (int j = 0; j < artWidth; j++) {
            // calculate corresponding pixel coordinates in original image
            int x = (int) (j / widthScale);
            int y = (int) (i / heightScale);

            // ensure x and y are within image bounds
            if (x >= width) x = width - 1;
            if (y >= height) y = height - 1;

            // calculate pixel index in image data
            int pixel_index = (y * width + x) * 3;

            // calculate average pixel intensity
            // using luminance formula: (0.2126 * R + 0.7152 * G + 0.0722 * B)
            unsigned char intensity = (unsigned char) (
                    0.2126 * data[pixel_index] +
                    0.7152 * data[pixel_index + 1] +
                    0.0722 * data[pixel_index + 2]);

            // choose ASCII character based on intensity
            char character;
            if (intensity < 50) {
                character = '#';
            } else if (intensity < 100) {
                character = '&';
            } else if (intensity < 150) {
                character = '$';
            } else if (intensity < 200) {
                character = '*';
            } else if (intensity < 225) {
                character = '~';
            } else {
                character = '.';
            }

            // set ASCII character in art array
            art[i * artWidth + j] = character;
        }
    }
}

int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc < 4) {
        printf("Error: Expected usage: [input_file] [output_file] [art_width] [art_height]\n");
        return 1;
    }

    // read command line arguments
    char *inputFile = argv[1];
    char *outputFile = argv[2];
    int artWidth = atoi(argv[3]);
    int artHeight = atoi(argv[4]);

    // load image data
    int width, height;
    unsigned char *data = loadImageData(inputFile, &width, &height);
    if (!data) return 1;

    // allocate memory for ASCII art
    char *asciiArt = (char *) malloc(artWidth * artHeight);
    if (!asciiArt) {
        printf("Error: Could not allocate memory for ASCII art\n");
        free(data);
        return 1;
    }

    // convert image data to ASCII art
    convertToAsciiArt(data, width, height, asciiArt, artWidth, artHeight);

    // write ASCII art to output file
    FILE *file = fopen(outputFile, "w");
    if (!file) {
        printf("Error: Could not open file %s for writing\n", outputFile);
        free(data);
        free(asciiArt);
        return 1;
    }
    fprintf(file, "%s", asciiArt);
    fclose(file);

    // free memory allocated for image data and ASCII art
    free(data);
    free(asciiArt);

    return 0;
}