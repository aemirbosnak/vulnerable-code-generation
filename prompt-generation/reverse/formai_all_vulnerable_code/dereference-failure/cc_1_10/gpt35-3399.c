//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontally(unsigned char* image_data, int width, int height, int bytes_per_pixel)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            for (int k = 0; k < bytes_per_pixel; k++)
            {
                int idx1 = i * width * bytes_per_pixel + j * bytes_per_pixel + k;
                int idx2 = i * width * bytes_per_pixel + (width - 1 - j) * bytes_per_pixel + k;

                unsigned char temp = image_data[idx1];
                image_data[idx1] = image_data[idx2];
                image_data[idx2] = temp;
            }
        }
    }
}

// Function to adjust brightness
void adjustBrightness(unsigned char* image_data, int width, int height, int bytes_per_pixel, int brightness)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < bytes_per_pixel; k++)
            {
                int idx = i * width * bytes_per_pixel + j * bytes_per_pixel + k;
                int pixel_val = image_data[idx] + brightness;
                image_data[idx] = pixel_val > 255 ? 255 : (pixel_val < 0 ? 0 : pixel_val);
            }
        }
    }
}

// Function to adjust contrast
void adjustContrast(unsigned char* image_data, int width, int height, int bytes_per_pixel, float contrast)
{
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < bytes_per_pixel; k++)
            {
                int idx = i * width * bytes_per_pixel + j * bytes_per_pixel + k;
                int pixel_val = (int)(factor * (image_data[idx] - 128) + 128);
                image_data[idx] = pixel_val > 255 ? 255 : (pixel_val < 0 ? 0 : pixel_val);
            }
        }
    }
}

int main()
{
    FILE* f = fopen("input_image.raw", "rb"); // Replace input_image with your own input file
    if (!f)
    {
        printf("Error opening file!");
        return -1;
    }

    int width = 640;    // Replace with your own image width
    int height = 480;   // Replace with your own image height
    int bytes_per_pixel = 3;    // 3 bytes per pixel for a rgb image

    unsigned char* image_data = (unsigned char*)malloc(width * height * bytes_per_pixel);
    fread(image_data, sizeof(unsigned char), width * height * bytes_per_pixel, f);
    fclose(f);

    // Do some image processing
    flipHorizontally(image_data, width, height, bytes_per_pixel);
    adjustBrightness(image_data, width, height, bytes_per_pixel, 50);
    adjustContrast(image_data, width, height, bytes_per_pixel, 50.0);

    // Write output file
    FILE* out_f = fopen("output_image.raw", "wb"); // Replace output_image with your own output file
    fwrite(image_data, sizeof(unsigned char), width * height * bytes_per_pixel, out_f);
    fclose(out_f);

    free(image_data);
    return 0;
}