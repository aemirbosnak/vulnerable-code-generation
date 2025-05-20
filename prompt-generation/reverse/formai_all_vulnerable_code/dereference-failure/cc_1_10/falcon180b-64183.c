//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to initialize the image
void initImage(int **image, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            image[i][j] = randInt(0, 255);
        }
    }
}

// Function to display the image
void displayImage(int **image, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to classify the image
void classifyImage(int **image, int rows, int cols)
{
    int total = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            total += image[i][j];
        }
    }

    if (total < 1000)
    {
        printf("The image is black and white.\n");
    }
    else if (total < 2000)
    {
        printf("The image is grayscale.\n");
    }
    else
    {
        printf("The image is colored.\n");
    }
}

int main()
{
    int rows, cols;

    // Get the dimensions of the image from the user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize the image with random values
    int **image = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        image[i] = (int *)malloc(cols * sizeof(int));
    }

    initImage(image, rows, cols);

    // Display the image
    printf("The original image:\n");
    displayImage(image, rows, cols);

    // Classify the image
    classifyImage(image, rows, cols);

    // Free the memory
    for (int i = 0; i < rows; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}