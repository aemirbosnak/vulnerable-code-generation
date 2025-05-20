//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// function to convert RGB values to grayscale
int grayscale(int r, int g, int b) {
    return (int)(r * 0.2989 + g * 0.5870 + b * 0.1140);
}

// function to set the ASCII character based on the grayscale value
char setChar(int val) {
    const char *chars = " .:-=+*#%@";
    int numChars = 10; // number of characters in the chars variable
    int interval = 255 / numChars; // divide the grayscale range into intervals
    
    // loop through each interval and return the corresponding character
    for (int i = 0; i < numChars; i++) {
        if (val <= interval * (i + 1)) {
            return chars[i];
        }
    }
    return ' '; // if the value is outside the grayscale range, return a space character
}

// main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please enter the filename of the image\n");
        return 1;
    }
    
    FILE *file;
    if ((file = fopen(argv[1], "rb")) == NULL) {
        printf("File not found\n");
        return 1;
    }
    
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file); // read the 54-byte header of the BMP file
    
    int width = *(int*)&header[18]; // extract image width
    int height = *(int*)&header[22]; // extract image height
    
    int padding = (4 - (width * sizeof(int)) % 4) % 4; // calculate padding needed for each row
    
    unsigned char pixel[3];
    char ascii[height][width];
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(pixel, sizeof(unsigned char), 3, file);
            int gray = grayscale(pixel[2], pixel[1], pixel[0]);
            ascii[i][j] = setChar(gray); // set the character based on grayscale value
        }
        fseek(file, padding, SEEK_CUR); // skip the padding bytes
    }
    
    fclose(file);
    
    // print the ASCII art
    
    printf("ASCII art output:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}