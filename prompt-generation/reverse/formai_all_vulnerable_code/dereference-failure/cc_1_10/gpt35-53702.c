//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert pixel to ascii character
char pixelToChar(unsigned char pixel) {
    const char *asciiChars = " .,-':;{[(|)]}>+*=~$#@";
    // 256 levels of brightness mapped to 19 ascii characters
    int brightnessLevel = (int)(pixel * 19 / 255);
    return asciiChars[brightnessLevel];
}

// function to recursively convert rows of the image to ascii
void imageToAscii(unsigned char *image, int width, int height, char *asciiImage, int rowIndex) {
    if (rowIndex == height) {
        return;
    }
    // convert current row to ascii
    for (int i = 0; i < width; ++i) {
        asciiImage[rowIndex * width + i] = pixelToChar(image[rowIndex * width + i]);
    }
    // move to next row
    imageToAscii(image, width, height, asciiImage, rowIndex + 1);
}

// main function
int main() {
    // read image from file
    FILE *imageFile = fopen("image.bin", "rb");
    if (!imageFile) {
        printf("Error opening image file");
        return 1;
    }
    fseek(imageFile, 0L, SEEK_END);
    int fileSize = ftell(imageFile);
    rewind(imageFile);
    unsigned char *image = (unsigned char*)malloc(fileSize);
    fread(image, 1, fileSize, imageFile);
    fclose(imageFile);
    // generate ascii image recursively
    int width = 64, height = fileSize / width;
    char *asciiImage = (char*)malloc(width * height + 1);
    memset(asciiImage, ' ', width * height + 1);
    imageToAscii(image, width, height, asciiImage, 0);
    asciiImage[width * height] = '\0';
    // print ascii image to console
    printf("%s", asciiImage);
    // free memory
    free(image);
    free(asciiImage);
    return 0;
}