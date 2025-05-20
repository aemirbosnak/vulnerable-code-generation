//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB values to grayscale
int getGrayScale(unsigned char *rgb, int stride) {
    return (int) (0.2126 * rgb[0] + 0.7152 * rgb[1] + 0.0722 * rgb[2]);
}

/* This function converts the image to ASCII. 
   The input arguments are:
   - image: The pixel values of the image
   - width: The width of the image
   - height: The height of the image
   - output: The output buffer that will contain the ASCII art
*/
void convertImageToASCII(unsigned char *image, int width, int height, char *output) {
    int numChars = strlen(" .,:;i1tfLCG08@");
    int charStep = 255 / (numChars - 1);
    int outputIndex = 0;

    // Loop through all the pixels in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Convert RGB to grayscale
            unsigned char *pixel = image + i * width * 3 + j * 3;
            int gray = getGrayScale(pixel, width * 3);

            // Map the pixel value to a character
            int charIndex = gray / charStep;
            if (charIndex >= numChars) {
                charIndex = numChars - 1;
            }
            char asciiChar = " .,:;i1tfLCG08@"[charIndex];

            // Write the character to the output buffer
            output[outputIndex] = asciiChar;
            outputIndex++;
        }
        output[outputIndex] = '\n';
        outputIndex++;
    }
    output[outputIndex] = '\0';
}

int main(int argc, char *argv[]) {
    // Read in the image file
    FILE *fp = fopen("image.rgb", "rb");
    if (fp == NULL) {
        printf("Error opening image file!\n");
        return 1;
    }

    // Determine image dimensions
    fseek(fp, 0, SEEK_END);
    int imageSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    int width = imageSize / 3;
    int height = 1;
    while (imageSize > width * height * 3) {
        height++;
    }

    // Allocate memory for the image and output buffer
    unsigned char *image = (unsigned char *) malloc(imageSize * sizeof(unsigned char));
    char *output = (char *) malloc((width * height + height) * sizeof(char));

    // Read in the image data
    int bytesRead = 0;
    while (bytesRead < imageSize) {
        bytesRead += fread(image + bytesRead, 1, imageSize - bytesRead, fp);
    }
    fclose(fp);

    // Convert the image to ASCII art
    convertImageToASCII(image, width, height, output);

    // Write the output to a file
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error writing output file!\n");
        return 1;
    }
    fprintf(fp, "%s", output);
    fclose(fp);

    // Free memory
    free(image);
    free(output);

    return 0;
}