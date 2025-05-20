//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 256

void read_image(char *filename, int image[][MAX], int *rows, int *cols) 
{
    FILE *fp;
    char filetype[3];
    int maxval, i, j;

    // Open the image file
    fp = fopen(filename, "rb");
    if(fp == NULL) 
    {
        printf("***Error: Unable to open file %s.\n", filename);
        exit(1);
    }

    // Check the image filetype
    fscanf(fp, "%s\n", filetype);
    if(strcmp(filetype, "P5")) 
    {
        printf("***Error: Invalid filetype.\n");
        exit(1);
    }

    // Read the image dimensions
    fscanf(fp, "%d %d\n", cols, rows);

    // Read the maximum pixel value
    fscanf(fp, "%d\n", &maxval);

    // Read the image data
    for(i = 0; i < *rows; i++) 
    {
        for(j = 0; j < *cols; j++) 
        {
            image[i][j] = getc(fp);
        }
    }

    // Close the image file
    fclose(fp);
}

void write_image(char *filename, int image[][MAX], int rows, int cols) 
{
    FILE *fp;
    int i, j;

    // Open the output file
    fp = fopen(filename, "wb");
    if(fp == NULL) 
    {
        printf("***Error: Unable to create file %s.\n", filename);
        exit(1);
    }

    // Write the image header
    fprintf(fp, "P5\n%d %d\n%d\n", cols, rows, 255);

    // Write the image data
    for(i = 0; i < rows; i++) 
    {
        for(j = 0; j < cols; j++) 
        {
            putc(image[i][j], fp);
        }
    }

    // Close the output file
    fclose(fp);
}

void flip_horizontally(int image[][MAX], int rows, int cols) 
{
    int i, j, temp;

    for(i = 0; i < rows; i++) 
    {
        for(j = 0; j < cols / 2; j++) 
        {
            temp = image[i][j];
            image[i][j] = image[i][cols - j - 1];
            image[i][cols - j - 1] = temp;
        }
    }
}

void flip_vertically(int image[][MAX], int rows, int cols) 
{
    int i, j, temp;

    for(i = 0; i < rows / 2; i++) 
    {
        for(j = 0; j < cols; j++) 
        {
            temp = image[i][j];
            image[i][j] = image[rows - i - 1][j];
            image[rows - i - 1][j] = temp;
        }
    }
}

void adjust_brightness(int image[][MAX], int rows, int cols, int value) 
{
    int i, j;

    for(i = 0; i < rows; i++) 
    {
        for(j = 0; j < cols; j++) 
        {
            if(image[i][j] + value < 0) 
            {
                image[i][j] = 0;
            } 
            else if(image[i][j] + value > 255) 
            {
                image[i][j] = 255;
            } 
            else 
            {
                image[i][j] += value;
            }
        }
    }
}

void adjust_contrast(int image[][MAX], int rows, int cols, int value) 
{
    int i, j;
    float factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));

    for(i = 0; i < rows; i++) 
    {
        for(j = 0; j < cols; j++) 
        {
            image[i][j] = factor * (image[i][j] - 128) + 128;
        }
    }
}

int main(int argc, char *argv[]) 
{
    int image[MAX][MAX], rows, cols;

    if(argc != 3) 
    {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        exit(1);
    }

    // Read the input image
    read_image(argv[1], image, &rows, &cols);

    // Flip the image horizontally
    flip_horizontally(image, rows, cols);

    // Flip the image vertically
    flip_vertically(image, rows, cols);

    // Adjust the brightness
    adjust_brightness(image, rows, cols, 50);

    // Adjust the contrast
    adjust_contrast(image, rows, cols, 50);

    // Write the output image
    write_image(argv[2], image, rows, cols);

    return 0;
}