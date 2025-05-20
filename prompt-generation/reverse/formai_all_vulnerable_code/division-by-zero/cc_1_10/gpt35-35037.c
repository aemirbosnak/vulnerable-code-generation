//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The dimensions of the final ASCII art image
#define WIDTH 80
#define HEIGHT 40

// The grayscale ASCII characters to use for the conversion
const char *ASCII_CHARS = " .:-=+*#%@";

// Function to load an image from file and convert it to grayscale
void load_image_gray(char *file_name, int **image_data, int *width, int *height)
{
    // Open the image file
    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        printf("Error: could not open file: %s\n", file_name);
        exit(EXIT_FAILURE);
    }
    
    // Read in the header data
    char header[54];
    fread(header, sizeof(char), 54, fp);
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];
    
    // Allocate memory for the image data
    int *image = (int *)malloc((*width) * (*height) * sizeof(int));
    
    // Read in the pixel data and convert to grayscale
    unsigned char pixel[3];
    for (int i = 0; i < (*height); i++)
    {
        for (int j = 0; j < (*width); j++)
        {
            fread(pixel, sizeof(unsigned char), 3, fp);
            image[i * (*width) + j] = (int)(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);
        }
    }
    
    // Close the file and return the image data
    fclose(fp);
    *image_data = image;
}

// Function to convert grayscale image to ASCII art
void convert_to_ascii(int *image_data, int width, int height, char *ascii_data)
{
    // Calculate the aspect ratio of the original image
    float aspect_ratio = (float)width / (float)height;
    
    // Calculate the aspect ratio of the final ASCII art image
    float ascii_aspect_ratio = (float)WIDTH / (float)HEIGHT;
    
    // Determine the scaling factor for the ASCII art image
    float scale_factor = aspect_ratio / ascii_aspect_ratio;
    
    // Determine the dimensions of the scaled image
    int scaled_width = (int)((float)WIDTH * scale_factor);
    int scaled_height = (int)((float)HEIGHT / scale_factor);
    
    // Determine the size of each block of pixels in the scaled image
    int block_width = width / scaled_width;
    int block_height = height / scaled_height;
    
    // Loop through each block of pixels in the scaled image
    for (int i = 0; i < scaled_height; i++)
    {
        for (int j = 0; j < scaled_width; j++)
        {
            // Calculate the average grayscale value of the block
            int sum = 0;
            for (int k = 0; k < block_height; k++)
            {
                for (int l = 0; l < block_width; l++)
                {
                    sum += image_data[(i * block_height + k) * width + (j * block_width + l)];
                }
            }
            int avg = sum / (block_width * block_height);
            
            // Determine the ASCII character to use based on the grayscale value
            int index = (int)((float)avg / 255.0 * (strlen(ASCII_CHARS) - 1));
            ascii_data[i * WIDTH + j] = ASCII_CHARS[index];
        }
    }
}

int main(int argc, char **argv)
{
    // Check that the correct number of command line arguments were provided
    if (argc != 3)
    {
        printf("Usage: %s [input image filename] [output text filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Load the image and convert it to grayscale
    int *image_data;
    int width, height;
    load_image_gray(argv[1], &image_data, &width, &height);
    
    // Convert the grayscale image to ASCII art
    char ascii_data[WIDTH * HEIGHT];
    convert_to_ascii(image_data, width, height, ascii_data);
    
    // Open the output file
    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL)
    {
        printf("Error: could not open file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    // Write the ASCII art to the output file
    for (int i = 0; i < HEIGHT; i++)
    {
        fwrite(&ascii_data[i * WIDTH], sizeof(char), WIDTH, fp);
        fwrite("\n", sizeof(char), 1, fp);
    }
    
    // Close the output file and free the image data
    fclose(fp);
    free(image_data);
    
    return 0;
}