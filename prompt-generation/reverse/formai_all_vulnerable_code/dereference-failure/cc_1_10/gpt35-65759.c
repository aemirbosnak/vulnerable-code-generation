//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// define maximum image size
#define MAX_SIZE 1024

// function to convert pixel to ASCII character
char pixelToChar(int pixel) {
    // define character set (replace as desired)
    const char *charSet = "$#@&%*+=-:. ";

    // calculate index in character set
    int index = (int)(pixel / 255.0 * (strlen(charSet) - 1));

    // return character at the calculated index
    return charSet[index];
}

int main(int argc, char *argv[]) {
    // check if input file provided
    if (argc < 2) {
        printf("Usage: img2ascii file\n");
        return 1;
    }

    // open input file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // read image dimensions
    char magicNumber[3];
    int width, height, maxPixelValue;
    fscanf(fp, "%s\n%d %d\n%d\n", magicNumber, &width, &height, &maxPixelValue);

    // check that file format is correct
    if (strcmp(magicNumber, "P5") != 0) {
        printf("Invalid file format: %s\n", magicNumber);
        return 1;
    }
    if (maxPixelValue > 255) {
        printf("Unsupported maximum pixel value: %d\n", maxPixelValue);
        return 1;
    }
    if (width > MAX_SIZE || height > MAX_SIZE) {
        printf("Image is too large: %d x %d\n", width, height);
        return 1;
    }

    // allocate memory for image data
    unsigned char *imageData = malloc(width * height);
    if (!imageData) {
        printf("Unable to allocate memory for image data\n");
        return 1;
    }

    // read image data
    fread(imageData, sizeof(unsigned char), width * height, fp);

    // close input file
    fclose(fp);

    // create output string
    char output[MAX_SIZE * (MAX_SIZE + 2)];
    int nextIndex = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // get pixel from image data
            int pixel = imageData[y * width + x];

            // convert pixel to ASCII character
            char outputChar = pixelToChar(pixel);

            // add character to output string
            output[nextIndex++] = outputChar;
        }

        // add newline character
        output[nextIndex++] = '\n';
    }

    // print output string
    printf("%s", output);

    // free memory
    free(imageData);

    return 0;
}