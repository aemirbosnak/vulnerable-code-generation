//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
// C Image Editor Example Program
// Author: John Doe
// Date: January 1, 2022

#include <stdio.h>
#include <stdlib.h>

// Function to load an image file
void load_image(const char* file_name, unsigned char* image_data, int width, int height)
{
    FILE* file = fopen(file_name, "rb");
    if (!file)
    {
        printf("Error: could not load image file %s\n", file_name);
        exit(1);
    }
    fread(image_data, sizeof(unsigned char), width * height, file);
    fclose(file);
}

// Function to save an image file
void save_image(const char* file_name, unsigned char* image_data, int width, int height)
{
    FILE* file = fopen(file_name, "wb");
    if (!file)
    {
        printf("Error: could not save image file %s\n", file_name);
        exit(1);
    }
    fwrite(image_data, sizeof(unsigned char), width * height, file);
    fclose(file);
}

// Function to invert colors
void invert_colors(unsigned char* image_data, int width, int height)
{
    for (int i = 0; i < width * height; i++)
    {
        image_data[i] = 255 - image_data[i];
    }
}

// Function to blur image
void blur_image(unsigned char* image_data, int width, int height)
{
    unsigned char* image_copy = malloc(width * height * sizeof(unsigned char));
    for (int i = 0; i < width * height; i++)
    {
        image_copy[i] = image_data[i];
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int sum = 0;
            int count = 0;

            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height)
                    {
                        sum += image_copy[ny * width + nx];
                        count++;
                    }
                }
            }

            image_data[y * width + x] = sum / count;
        }
    }

    free(image_copy);
}

int main()
{
    const char* file_name = "image.dat";
    const int width = 256;
    const int height = 256;

    unsigned char* image_data = malloc(width * height * sizeof(unsigned char));
    load_image(file_name, image_data, width, height);

    invert_colors(image_data, width, height);

    blur_image(image_data, width, height);

    save_image("output.dat", image_data, width, height);

    free(image_data);

    printf("Image processing complete.\n");

    return 0;
}