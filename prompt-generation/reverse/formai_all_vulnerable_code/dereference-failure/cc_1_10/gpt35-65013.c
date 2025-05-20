//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>

/**
 * This function converts a given pixel value to its corresponding ASCII character.
 * Depending on the range of the pixel value, an appropriate ASCII character is chosen from
 * the grayscale characters set.
 *
 * @param pixelValue The pixel value to be converted to an ASCII character.
 * @return The ASCII character corresponding to the pixel value.
 */
char getAsciiChar(int pixelValue) {
    const char *asciiSet = " .:-=+*#%@";
    int asciiSetLength = strlen(asciiSet);
    int grayscaleRange = 255 / asciiSetLength;
    int charIndex = pixelValue / grayscaleRange;
    charIndex = (charIndex >= asciiSetLength) ? (asciiSetLength - 1) : charIndex;
    return asciiSet[charIndex];
}

/**
 * This function reads an input image file and converts it into ASCII art.
 * The ASCII art is displayed on console and also saved in an output file.
 *
 * @param inputFile The input image file containing the image to be converted to ASCII art.
 * @param outputFile The output file to which the ASCII art is saved.
 */
void convertImageToAsciiArt(char *inputFile, char *outputFile) {
    FILE *fp = fopen(inputFile, "rb");
    if (!fp) {
        printf("Unable to read input file %s", inputFile);
        exit(1);
    }

    // Read BMP image header
    unsigned char bmpHeader[54];
    fread(bmpHeader, sizeof(unsigned char), 54, fp);
    int width = *(int *)&bmpHeader[18];
    int height = *(int *)&bmpHeader[22];
    int bytesPerPixel = *(int *)&bmpHeader[28];

    // Validate image format
    if (bmpHeader[0] != 'B' || bmpHeader[1] != 'M' || bytesPerPixel != 3) {
        printf("Unsupported image format. Only 24-bit BMP images are supported.");
        exit(1);
    }

    // Create output file
    FILE *fpOut = fopen(outputFile, "w");
    if (!fpOut) {
        printf("Unable to create output file %s", outputFile);
        exit(1);
    }

    // Read image data
    int rowSize = width * bytesPerPixel;
    unsigned char *imageData = (unsigned char *) malloc(rowSize * height * sizeof(unsigned char));
    fread(imageData, sizeof(unsigned char), rowSize * height, fp);

    // Process image data
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixelIndex = (i * rowSize) + (j * bytesPerPixel);
            int pixelValue = (0.3 * imageData[pixelIndex + 2]) +
                             (0.59 * imageData[pixelIndex + 1]) +
                             (0.11 * imageData[pixelIndex]);
            char asciiChar = getAsciiChar(pixelValue);
            printf("%c", asciiChar);
            fprintf(fpOut, "%c", asciiChar);
        }
        printf("\n");
        fprintf(fpOut, "\n");
    }

    // Cleanup
    free(imageData);
    fclose(fp);
    fclose(fpOut);
}

int main() {
    convertImageToAsciiArt("input.bmp", "output.txt");
    return 0;
}