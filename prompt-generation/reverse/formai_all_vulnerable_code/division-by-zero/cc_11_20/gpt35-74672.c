//FormAI DATASET v1.0 Category: Image compression ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000
#define MAX_COMPRESSION_RATIO 10

int main()
{
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int compressed_image[MAX_IMAGE_SIZE / MAX_COMPRESSION_RATIO][MAX_IMAGE_SIZE / MAX_COMPRESSION_RATIO];      
    int image_size = 0, compression_ratio = 0;
    
    printf("Enter the size of the square image (less than or equal to %d): ", MAX_IMAGE_SIZE);
    scanf("%d", &image_size);
    if (image_size > MAX_IMAGE_SIZE)
    {
        printf("Error: Image size too large!\n");
        exit(1);
    }
    
    printf("Enter the compression ratio (less than or equal to %d): ", MAX_COMPRESSION_RATIO);
    scanf("%d", &compression_ratio);
    if (compression_ratio > MAX_COMPRESSION_RATIO)
    {
        printf("Error: Compression ratio too large!\n");
        exit(1);
    }
    
    printf("Enter the image values (0 to 255) separated by space or newline:\n");
    for (int i = 0; i < image_size; i++)
    {
        for (int j = 0; j < image_size; j++)
        {
            scanf("%d", &image[i][j]);     
            if (image[i][j] > 255)
            {
                printf("Error: Invalid pixel value %d at (%d, %d)!\n", image[i][j], i, j);
                exit(1);
            }       
        }
    }
    
    // compression algorithm
    int compressed_size = image_size / compression_ratio;
    for (int i = 0; i < compressed_size; i++)
    {
        for (int j = 0; j < compressed_size; j++)
        {
            int sum = 0;
            for (int k = 0; k < compression_ratio; k++)
            {
                for (int l = 0; l < compression_ratio; l++)
                {
                    sum += image[i * compression_ratio + k][j * compression_ratio + l];
                }
            }
            compressed_image[i][j] = round((double)sum / (compression_ratio * compression_ratio));
        }
    }
    
    // print compressed image
    printf("\nCompressed image:\n");
    for (int i = 0; i < compressed_size; i++)
    {
        for (int j = 0; j < compressed_size; j++)
        {
            printf("%d ", compressed_image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}