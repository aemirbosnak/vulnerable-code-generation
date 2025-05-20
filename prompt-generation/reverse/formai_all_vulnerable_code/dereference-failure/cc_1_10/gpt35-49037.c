//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Reading image file
    FILE *file;
    file = fopen("image.bmp", "rb");

    if (file == NULL)
    {
        printf("Error: File not found.");
        exit(1);
    }

    // Reading and parsing the file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Reading image information
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int imageSize = width * height * 3;
    unsigned char *imageData = (unsigned char*)malloc(imageSize);

    fread(imageData, sizeof(unsigned char), imageSize, file);
    fclose(file);

    // Flipping the image horizontally
    unsigned char *flippedData = (unsigned char*)malloc(imageSize);
    int rowSize = width * 3;

    for (int i = 0; i < height; i++)
    {
        memcpy(flippedData + (i * rowSize), imageData + ((height - i - 1) * rowSize), rowSize);
    }

    // Saving the flipped image
    file = fopen("flipped.bmp", "wb");

    if (file == NULL)
    {
        printf("Error: Unable to create file.");
        exit(1);
    }

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(flippedData, sizeof(unsigned char), imageSize, file);
    fclose(file);

    // Freeing memory
    free(imageData);
    free(flippedData);

    return 0;
}