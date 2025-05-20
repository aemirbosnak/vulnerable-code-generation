//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

//function prototype
void flip_image(int rows, int cols, int original_image[rows][cols]);

int main()
{
   int rows = 5; //number of rows in image
   int cols = 5; //number of columns in image
   int original_image[rows][cols];//original image

   //filling image with sample pixels
   for(int i=0; i<rows; i++)
    {
      for(int j=0; j<cols; j++)
        {
          original_image[i][j] = rand()%255;
        }
    }

    //printing original image
    printf("Original Image: \n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", original_image[i][j]);
        }
        printf("\n");
    }

    //flipping image
    flip_image(rows, cols, original_image);

    //printing flipped image
    printf("Flipped Image: \n");
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%d ", original_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//function to flip the image
void flip_image(int rows, int cols, int original_image[rows][cols])
{
    int temp; //variable to store temporary pixel value during swap

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols/2; j++) //loop through half the columns
        {
            temp = original_image[i][j]; //store value of current pixel
            original_image[i][j] = original_image[i][cols-j-1]; //swap pixel with opposite pixel in row
            original_image[i][cols-j-1] = temp; //store opposite pixel value in current pixel space
        }
    }
}