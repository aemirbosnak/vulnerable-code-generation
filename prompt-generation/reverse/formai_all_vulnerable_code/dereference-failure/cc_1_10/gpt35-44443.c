//FormAI DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_WIDTH 640
#define IMG_HEIGHT 480
#define MAX_COLOR 255


// Function to read a PPM image file and extract the image data
void read_ppm(char* filename, unsigned char** image_data, int* width, int* height)
{
    FILE* fp;
    char magic[3];
    int maxval;
    
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error: could not open file: %s\n", filename);
        exit(1);
    }
    
    fscanf(fp, "%s\n", magic);
    if (strcmp(magic, "P6") != 0)
    {
        printf("Error: not a P6 PPM file\n");
        exit(1);
    }
    
    fscanf(fp, "%d %d\n", width, height);
    fscanf(fp, "%d\n", &maxval);
    
    *image_data = (unsigned char*)malloc((*width) * (*height) * 3);
    fread(*image_data, 1, (*width) * (*height) * 3, fp);
    
    fclose(fp);
}


// Function to write image data to a PPM file
void write_ppm(char* filename, unsigned char** image_data, int width, int height)
{
    FILE* fp;
    
    fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error: could not open file: %s\n", filename);
        exit(1);
    }
    
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "%d\n", MAX_COLOR);
    
    fwrite(*image_data, 1, width * height * 3, fp);
    
    fclose(fp);
}


// Function to apply grayscale filter to an image
void grayscale_filter(unsigned char* image_data, int width, int height)
{
    int i, j, r, g, b, gray;
    
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            r = image_data[(i * width + j) * 3];
            g = image_data[(i * width + j) * 3 + 1];
            b = image_data[(i * width + j) * 3 + 2];
            
            gray = 0.299 * r + 0.587 * g + 0.114 * b;
            
            image_data[(i * width + j) * 3] = gray;
            image_data[(i * width + j) * 3 + 1] = gray;
            image_data[(i * width + j) * 3 + 2] = gray;
        }
    }
}


int main()
{
    unsigned char* image_data;
    int width, height;
    
    // Read input image
    read_ppm("input.ppm", &image_data, &width, &height);
    
    // Apply grayscale filter
    grayscale_filter(image_data, width, height);
    
    // Write output image
    write_ppm("output.ppm", &image_data, width, height);
    
    return 0;
}