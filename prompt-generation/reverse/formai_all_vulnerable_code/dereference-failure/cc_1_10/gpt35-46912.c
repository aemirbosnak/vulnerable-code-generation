//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

void convertToAsciiArt(char* imageFile, char* outputAsciiFile) {
    FILE *image, *outputAscii;

    // Open the image file for reading
    image = fopen(imageFile, "rb");

    if (!image) {
        printf("Cannot open image file %s\n", imageFile);
        exit(EXIT_FAILURE);
    }

    // Open the output ASCII art file for writing
    outputAscii = fopen(outputAsciiFile, "w");

    if (!outputAscii) {
        printf("Cannot create output ASCII art file %s\n", outputAsciiFile);
        exit(EXIT_FAILURE);
    }

    // Get the height and width of the image
    fseek(image, 18, SEEK_SET);
    int width = fgetc(image);
    int height = fgetc(image);

    // Print the dimensions of the image to the ASCII art file
    fprintf(outputAscii, "Image dimensions: %dx%d\n", width, height);

    // Convert each pixel in the image to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = fgetc(image);

            // Map the pixel value to an ASCII character
            char asciiChar;

            if (pixel > 240)
                asciiChar = ' ';
            else if (pixel > 210)
                asciiChar = '.';
            else if (pixel > 180)
                asciiChar = ':';
            else if (pixel > 150)
                asciiChar = 'o';
            else if (pixel > 120)
                asciiChar = '&';
            else if (pixel > 90)
                asciiChar = '8';
            else if (pixel > 60)
                asciiChar = '#';
            else if (pixel > 30)
                asciiChar = '%';
            else
                asciiChar = '@';

            // Write the ASCII character to the output ASCII art file
            fputc(asciiChar, outputAscii);
        }

        // Write a newline to the output ASCII art file
        fputc('\n', outputAscii);
    }

    // Close the image and output ASCII art files
    fclose(image);
    fclose(outputAscii);
}

int main() {
    convertToAsciiArt("image.bmp", "outputAscii.txt");
    return 0;
}