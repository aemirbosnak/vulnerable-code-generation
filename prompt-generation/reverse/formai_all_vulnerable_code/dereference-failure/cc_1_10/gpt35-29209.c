//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//Function to flip the given image
void flipImage(int width, int height, unsigned char* image)
{
    unsigned char temp;
    int row = 0, col = 0;

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width / 2; col++)
        {
            temp = image[row * width + col];
            image[row * width + col] = image[row * width + (width - col - 1)];
            image[row * width + (width - col - 1)] = temp;
        }
    }
}

//Function to adjust the brightness and contrast of the given image
void adjustImage(int width, int height, unsigned char* image, float brightness, float contrast)
{
    int i = 0, j = 0;
    float pixelValue = 0.0, pixel = 0.0;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            pixelValue = (float)image[i * width + j];
            pixel = pixelValue * contrast + brightness;
            if (pixel < 0)
            {
                pixel = 0;
            }
            if (pixel > 255)
            {
                pixel = 255;
            }
            image[i * width + j] = (unsigned char)pixel;
        }
    }
}

int main()
{
    //Read the input image
    FILE* file = fopen("inputImage.raw", "rb");
    if (file == NULL) 
    {
        printf("Error: Unable to open the input image file!");
        return 0;
    }

    int width = 512, height = 512;
    unsigned char* image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), width * height, file);
    fclose(file);

    //Flip the image
    flipImage(width, height, image);

    //Adjust the brightness and contrast of the image
    float brightness = 50.0, contrast = 1.5;
    adjustImage(width, height, image, brightness, contrast);

    //Write the output image
    FILE* output = fopen("outputImage.raw", "wb");
    if (output == NULL)
    {
        printf("Error: Unable to open the output image file!");
        return 0;
    }
    fwrite(image, sizeof(unsigned char), width * height, output);
    fclose(output);

    free(image);
    printf("Image processing completed successfully! Check the output file.\n");

    return 0;
}