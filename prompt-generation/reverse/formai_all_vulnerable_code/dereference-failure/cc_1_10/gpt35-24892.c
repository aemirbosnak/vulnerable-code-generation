//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>

int main()
{
    printf("Wooohoo! Let's do some image processing!\n");
    printf("We will start by flipping an image.\n");

    //Allocate memory for an image
    int height = 300;
    int width = 400;
    int* image = (int*)malloc(height*width*sizeof(int));

    //Fill the image with some data
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            image[i*width + j] = i*j;
        }
    }

    //Print the original image
    printf("\nOriginal Image:\n");
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            printf("%d ", image[i*width + j]);
        }
        printf("\n");
    }

    //Flip the image
    printf("\nFlipped Image:\n");
    for(int i=height-1; i>=0; i--)
    {
        for(int j=0; j<width; j++)
        {
            printf("%d ", image[i*width + j]);
        }
        printf("\n");
    }

    //Change the brightness and contrast of the image
    float brightness = 1.5;
    float contrast = 0.75;
    printf("\nModified Image:\n");
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            int pixel = image[i*width + j];
            //Change the brightness
            pixel = (int)(pixel*brightness);
            //Change the contrast
            pixel = (int)((pixel-128)*contrast + 128);
            printf("%d ", pixel);
        }
        printf("\n");
    }

    printf("\nWow, that was amazing! Let's do some more image processing next time.");

    //Free the memory allocated for the image
    free(image);

    return 0;
}