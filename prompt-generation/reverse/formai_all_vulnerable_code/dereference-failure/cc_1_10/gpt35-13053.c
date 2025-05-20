//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipHorizontal(unsigned char *image, int width, int height, int bytesPerPixel)
{
    int row, col, offset;
    unsigned char *temp;
    temp = (unsigned char *)malloc(sizeof(unsigned char) * bytesPerPixel);

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width / 2; col++)
        {
            // Swap the left and right pixels
            offset = row * width * bytesPerPixel + col * bytesPerPixel;
            memcpy(temp, &image[offset], sizeof(unsigned char) * bytesPerPixel);
            memcpy(&image[offset], &image[(row * width + width - col - 1) * bytesPerPixel], sizeof(unsigned char) * bytesPerPixel);
            memcpy(&image[(row * width + width - col - 1) * bytesPerPixel], temp, sizeof(unsigned char) * bytesPerPixel);
        }
    }

    free(temp);
}

// Function to change the brightness of an image
void changeBrightness(unsigned char *image, int width, int height, int bytesPerPixel, int brightness)
{
    int row, col, offset;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            offset = row * width * bytesPerPixel + col * bytesPerPixel;
            int red = image[offset];
            int green = image[offset + 1];
            int blue = image[offset + 2];

            // Increase or decrease the brightness of each pixel
            red += brightness;
            green += brightness;
            blue += brightness;

            // Ensure that the pixel values are within the 0-255 range
            red = red < 0 ? 0 : red > 255 ? 255 : red;
            green = green < 0 ? 0 : green > 255 ? 255 : green;
            blue = blue < 0 ? 0 : blue > 255 ? 255 : blue;

            image[offset] = red;
            image[offset + 1] = green;
            image[offset + 2] = blue;
        }
    }
}

// Function to change the contrast of an image
void changeContrast(unsigned char *image, int width, int height, int bytesPerPixel, float contrast)
{
    int row, col, offset;
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            offset = row * width * bytesPerPixel + col * bytesPerPixel;
            int red = image[offset];
            int green = image[offset + 1];
            int blue = image[offset + 2];

            // Apply the contrast formula to each pixel
            red = (int)(factor * (red - 128) + 128);
            green = (int)(factor * (green - 128) + 128);
            blue = (int)(factor * (blue - 128) + 128);

            // Ensure that the pixel values are within the 0-255 range
            red = red < 0 ? 0 : red > 255 ? 255 : red;
            green = green < 0 ? 0 : green > 255 ? 255 : green;
            blue = blue < 0 ? 0 : blue > 255 ? 255 : blue;

            image[offset] = red;
            image[offset + 1] = green;
            image[offset + 2] = blue;
        }
    }
}

int main()
{
    // Load the input image
    unsigned char *inputImage;
    char inputFilename[] = "input.bmp";
    FILE *fp = fopen(inputFilename, "rb");
    if (fp == NULL)
    {
        printf("Unable to open file %s\n", inputFilename);
        return -1;
    }
    fseek(fp, 54, SEEK_SET); // Move past header data
    int width = 512;         // Width of image
    int height = 512;        // Height of image
    int bytesPerPixel = 3;   // Number of bytes per pixel (RGB)

    inputImage = (unsigned char *)malloc(sizeof(unsigned char) * width * height * bytesPerPixel);
    fread(inputImage, sizeof(unsigned char), width * height * bytesPerPixel, fp);
    fclose(fp);

    // Perform image processing tasks
    flipHorizontal(inputImage, width, height, bytesPerPixel);
    changeBrightness(inputImage, width, height, bytesPerPixel, 50);
    changeContrast(inputImage, width, height, bytesPerPixel, 50.0);

    // Save the output image
    char outputFilename[] = "output.bmp";
    fp = fopen(outputFilename, "wb");
    if (fp == NULL)
    {
        printf("Unable to create file %s\n", outputFilename);
        return -1;
    }
    unsigned char header[54] = {0};
    header[0] = 'B';
    header[1] = 'M';
    int fileSize = 54 + bytesPerPixel * width * height;
    header[2] = (unsigned char)(fileSize);
    header[3] = (unsigned char)(fileSize >> 8);
    header[4] = (unsigned char)(fileSize >> 16);
    header[5] = (unsigned char)(fileSize >> 24);
    header[10] = 54;
    header[14] = 40;
    header[18] = (unsigned char)(width);
    header[19] = (unsigned char)(width >> 8);
    header[20] = (unsigned char)(width >> 16);
    header[21] = (unsigned char)(width >> 24);
    header[22] = (unsigned char)(height);
    header[23] = (unsigned char)(height >> 8);
    header[24] = (unsigned char)(height >> 16);
    header[25] = (unsigned char)(height >> 24);
    header[26] = 1;
    header[28] = 24;

    fwrite(header, sizeof(unsigned char), 54, fp);
    fwrite(inputImage, sizeof(unsigned char), width * height * bytesPerPixel, fp);
    fclose(fp);

    // Free memory
    free(inputImage);

    return 0;
}