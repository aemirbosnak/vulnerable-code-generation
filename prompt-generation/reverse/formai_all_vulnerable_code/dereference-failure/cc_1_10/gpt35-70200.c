//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    // Open the input and output files
    FILE *input_file = fopen("input.bmp", "rb");
    FILE *output_file = fopen("output.bmp", "wb");

    // Read the header data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);

    // Get the image size
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));

    // Read the image data
    fread(image_data, sizeof(unsigned char), width * height * 3, input_file);

    // Flip the image horizontally
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            int index1 = (y * width + x) * 3;
            int index2 = (y * width + (width - x - 1)) * 3;
            for (int i = 0; i < 3; i++)
            {
                unsigned char tmp = image_data[index1 + i];
                image_data[index1 + i] = image_data[index2 + i];
                image_data[index2 + i] = tmp;
            }
        }
    }

    // Adjust the brightness and contrast
    float brightness = 50.0;
    float contrast = 1.5;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (y * width + x) * 3;
            for (int i = 0; i < 3; i++)
            {
                int value = image_data[index + i];
                value = (int)(value * contrast + brightness);
                if (value > 255) value = 255;
                if (value < 0) value = 0;
                image_data[index + i] = (unsigned char)value;
            }
        }
    }

    // Write the header and image data to the output file
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image_data, sizeof(unsigned char), width * height * 3, output_file);

    // Close the input and output files, and free the memory
    fclose(input_file);
    fclose(output_file);
    free(image_data);

    return 0;
}