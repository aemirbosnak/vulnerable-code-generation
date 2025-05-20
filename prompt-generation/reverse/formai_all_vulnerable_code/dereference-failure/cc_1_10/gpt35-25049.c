//FormAI DATASET v1.0 Category: Image compression ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 8
#define IMAGE_SIZE 64

void compress_image(uint8_t* image_data)
{
    // Calculate the size of the image in blocks
    int num_blocks = IMAGE_SIZE / BLOCK_SIZE;
    
    // Allocate memory for the compressed image
    uint8_t* compressed_image = (uint8_t*)malloc(num_blocks * sizeof(uint8_t));
    
    for(int i = 0; i < num_blocks; i++)
    {
        int block_sum = 0;
        for(int j = 0; j < BLOCK_SIZE; j++)
        {
            for(int k = 0; k < BLOCK_SIZE; k++)
            {
                int index = ((i * BLOCK_SIZE) + j) * IMAGE_SIZE + k;
                block_sum += image_data[index];
            }
        }
        compressed_image[i] = block_sum / (BLOCK_SIZE * BLOCK_SIZE);
    }
    
    // Print the compressed image
    printf("Compressed image:\n");
    for(int i = 0; i < num_blocks; i++)
    {
        printf("%d ", compressed_image[i]);
    }
    printf("\n");
    
    free(compressed_image);
}

int main()
{
    // Allocate memory for the image data
    uint8_t* image_data = (uint8_t*)malloc(IMAGE_SIZE * IMAGE_SIZE * sizeof(uint8_t));
    
    // Initialize the image with random pixel values
    for(int i = 0; i < IMAGE_SIZE; i++)
    {
        for(int j = 0; j < IMAGE_SIZE; j++)
        {
            int index = i * IMAGE_SIZE + j;
            image_data[index] = rand() % 256;
        }
    }
    
    // Print the original image
    printf("Original image:\n");
    for(int i = 0; i < IMAGE_SIZE; i++)
    {
        for(int j = 0; j < IMAGE_SIZE; j++)
        {
            int index = i * IMAGE_SIZE + j;
            printf("%d ", image_data[index]);
        }
        printf("\n");
    }
    
    compress_image(image_data);
    
    free(image_data);
    
    return 0;
}