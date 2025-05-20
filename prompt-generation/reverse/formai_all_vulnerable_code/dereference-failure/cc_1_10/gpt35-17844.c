//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void flipImage(unsigned char *imageData, int width, int height);
void adjustBrightness(unsigned char *imageData, int width, int height, int brightness);
void adjustContrast(unsigned char *imageData, int width, int height, float contrast);

int main()
{
    // read image file
    FILE *file;
    unsigned char *imageData;
    int imageWidth, imageHeight;
    file = fopen("image.raw", "rb");
    if(file == NULL)
    {
        printf("Error: Failed to read image file.\n");
        return 1;
    }
    fseek(file, 0, SEEK_END);
    int imageSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    imageData = (unsigned char*) malloc(imageSize);
    if(imageData == NULL)
    {
        printf("Error: Unable to allocate memory for image data.\n");
        fclose(file);
        return 1;
    }
    fread(imageData, imageSize, 1, file);
    fclose(file);

    // flip image horizontally
    flipImage(imageData, imageWidth, imageHeight);

    // adjust brightness of image
    int brightness = 50;
    adjustBrightness(imageData, imageWidth, imageHeight, brightness);

    // adjust contrast of image
    float contrast = 1.5;
    adjustContrast(imageData, imageWidth, imageHeight, contrast);

    // write modified image to file
    file = fopen("modified_image.raw", "wb");
    if(file == NULL)
    {
        printf("Error: Failed to write modified image file.\n");
        free(imageData);
        return 1;
    }
    fwrite(imageData, imageSize, 1, file);
    fclose(file);
    free(imageData);

    return 0;
}

void flipImage(unsigned char *imageData, int width, int height)
{
    // loop through image row by row, flipping each pixel horizontally
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width/2; x++)
        {
            int index1 = (y * width + x) * 3;
            int index2 = (y * width + (width - x - 1)) * 3;
            unsigned char temp1 = imageData[index1];
            unsigned char temp2 = imageData[index1+1];
            unsigned char temp3 = imageData[index1+2];
            imageData[index1] = imageData[index2];
            imageData[index1+1] = imageData[index2+1];
            imageData[index1+2] = imageData[index2+2];
            imageData[index2] = temp1;
            imageData[index2+1] = temp2;
            imageData[index2+2] = temp3;
        }
    }
}

void adjustBrightness(unsigned char *imageData, int width, int height, int brightness)
{
    // loop through image pixel by pixel, adjusting brightness of each pixel
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int index = (y * width + x) * 3;
            imageData[index] += brightness;
            imageData[index+1] += brightness;
            imageData[index+2] += brightness;
        }
    }
}

void adjustContrast(unsigned char *imageData, int width, int height, float contrast)
{
    // calculate contrast adjustment factor based on input contrast value
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    // loop through image pixel by pixel, adjusting contrast of each pixel
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            int index = (y * width + x) * 3;
            imageData[index] = (unsigned char) (factor * (imageData[index] - 128) + 128);
            imageData[index+1] = (unsigned char) (factor * (imageData[index+1] - 128) + 128);
            imageData[index+2] = (unsigned char) (factor * (imageData[index+2] - 128) + 128);
        }
    }
}