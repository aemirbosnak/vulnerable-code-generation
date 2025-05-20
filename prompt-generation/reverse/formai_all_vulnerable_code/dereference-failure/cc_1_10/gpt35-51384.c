//FormAI DATASET v1.0 Category: Image Editor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the image file
void readImageFile(char* filename, unsigned char** imageData, int* width, int* height) {
    FILE* imageFile = fopen(filename, "rb");
    if (!imageFile) {
        printf("Unable to open the image file.\n");
        exit(-1);
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);
    
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    int bytesPerPixel = *(int*)&header[28];
    int imageSize = *width * *height * bytesPerPixel;
    *imageData = (unsigned char*) malloc(imageSize);

    // Read the image data
    fread(*imageData, sizeof(unsigned char), imageSize, imageFile);
    fclose(imageFile);
}

// Function to write the image file
void writeImageFile(char* filename, unsigned char* imageData, int width, int height) {
    FILE* imageFile = fopen(filename, "wb");
    if (!imageFile) {
        printf("Unable to create the image file.\n");
        exit(-1);
    }

    // Write the image header
    unsigned char header[54];
    memset(header, 0, 54);

    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + (width * height);
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width; 
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;

    fwrite(header, sizeof(unsigned char), 54, imageFile);

    // Write the image data
    fwrite(imageData, sizeof(unsigned char), width * height * 3, imageFile);
    fclose(imageFile);
}

// Function to invert the colors of the image
void invertColors(unsigned char* imageData, int width, int height) {
    for (int i = 0; i < (width * height * 3); i++) {
        imageData[i] = 255 - imageData[i];
    }
}

// Function to apply sepia filter to the image
void applySepiaFilter(unsigned char* imageData, int width, int height) {
    unsigned char* r = imageData;
    unsigned char* g = imageData + 1;
    unsigned char* b = imageData + 2;

    for (int i = 0; i < (width * height); i++) {
        unsigned char originalR = *r, originalG = *g, originalB = *b;
        *r = (unsigned char) ((originalR * 0.393) + (originalG * 0.769) + (originalB * 0.189));
        *g = (unsigned char) ((originalR * 0.349) + (originalG * 0.686) + (originalB * 0.168));
        *b = (unsigned char) ((originalR * 0.272) + (originalG * 0.534) + (originalB * 0.131));

        r += 3; g += 3; b += 3;
    }
}

// Main function
int main(int argc, char* argv[]) {
    // Read the input image file
    int width, height;
    unsigned char* imageData;
    readImageFile("input.bmp", &imageData, &width, &height);

    // Apply image filters
    invertColors(imageData, width, height);
    applySepiaFilter(imageData, width, height);

    // Write the output image file
    writeImageFile("output.bmp", imageData, width, height);

    // Free the allocated memory
    free(imageData);

    return 0;
}