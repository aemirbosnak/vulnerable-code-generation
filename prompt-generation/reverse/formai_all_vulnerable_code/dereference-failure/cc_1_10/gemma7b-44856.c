//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

int main()
{
    int img_width, img_height;
    int **img_data = NULL;

    // Allocate memory for the image data
    img_data = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        img_data[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    // Get the image dimensions
    printf("Enter the width of the image: ");
    scanf("%d", &img_width);

    printf("Enter the height of the image: ");
    scanf("%d", &img_height);

    // Populate the image data
    printf("Enter the pixel values (separated by commas): ");
    char input[MAX_SIZE];
    scanf("%s", input);

    // Convert the input into integers
    int pixel_values[MAX_SIZE];
    char *p = input;
    int i = 0;
    while (*p)
    {
        pixel_values[i++] = atoi(p);
        p++;
    }

    // Set the pixel values
    for (int r = 0; r < img_height; r++)
    {
        for (int c = 0; c < img_width; c++)
        {
            img_data[r][c] = pixel_values[r * img_width + c];
        }
    }

    // Display the image
    for (int r = 0; r < img_height; r++)
    {
        for (int c = 0; c < img_width; c++)
        {
            printf("%d ", img_data[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < MAX_SIZE; i++)
    {
        free(img_data[i]);
    }
    free(img_data);

    return 0;
}