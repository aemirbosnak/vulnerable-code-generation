//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void flipImage(int *arr, int width, int height);
void changeBrightness(int *arr, int width, int height, int brightness);
void changeContrast(int *arr, int width, int height, float contrast);

int main()
{
    int *image;
    int width = 640;
    int height = 480;
    int brightness = 50;
    float contrast = 1.5;

    image = (int *)malloc(width * height * sizeof(int));

    // Code to read image file into image array

    flipImage(image, width, height);
    changeBrightness(image, width, height, brightness);
    changeContrast(image, width, height, contrast);

    // Code to write image array to file

    free(image);
    return 0;
}

void flipImage(int *arr, int width, int height)
{
    int *temp;
    int i, j;

    temp = (int *)malloc(width * sizeof(int));

    for (i = 0; i < height/2; i++)
    {
        for (j = 0; j < width; j++)
        {
            temp[j] = arr[i*width+j];
            arr[i*width+j] = arr[(height-i-1)*width+j];
            arr[(height-i-1)*width+j] = temp[j];
        }
    }

    free(temp);
}

void changeBrightness(int *arr, int width, int height, int brightness)
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            arr[i*width+j] += brightness;
            if (arr[i*width+j] > 255) arr[i*width+j] = 255;
            if (arr[i*width+j] < 0) arr[i*width+j] = 0;
        }
    }
}

void changeContrast(int *arr, int width, int height, float contrast)
{
    int i, j;
    int val;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            val = (int)((arr[i*width+j]-128)*contrast+128);
            if (val > 255) val = 255;
            if (val < 0) val = 0;
            arr[i*width+j] = val;
        }
    }
}