//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//Function to read image data from file
void read_image(char *filename, uint8_t **image_ptr, uint32_t *width_ptr, uint32_t *height_ptr)
{
    FILE *fPtr;
    uint32_t width, height;

    fPtr = fopen(filename, "rb");
    fread(&width, sizeof(uint32_t), 1, fPtr);
    fread(&height, sizeof(uint32_t), 1, fPtr);

    uint8_t *image = (uint8_t *) malloc(width * height * sizeof(uint8_t));
    fread(image, sizeof(uint8_t), width * height, fPtr);

    fclose(fPtr);

    *image_ptr = image;
    *width_ptr = width;
    *height_ptr = height;
}

//Function to write image data to file
void write_image(char *filename, uint8_t *image, uint32_t width, uint32_t height)
{
    FILE *fPtr = fopen(filename, "wb");
    fwrite(&width, sizeof(uint32_t), 1, fPtr);
    fwrite(&height, sizeof(uint32_t), 1, fPtr);
    fwrite(image, sizeof(uint8_t), width * height, fPtr);
    fclose(fPtr);
}

//Function to flip image horizontally
void flip_horizontally(uint8_t *image, uint32_t width, uint32_t height)
{
    uint32_t i, j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width / 2; j++)
        {
            uint8_t temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - 1 - j)];
            image[i * width + (width - 1 - j)] = temp;
        }
    }
}

//Function to change image brightness and contrast
void change_brightness_contrast(uint8_t *image, uint32_t width, uint32_t height, int brightness, float contrast)
{
    uint32_t i, j;

    //Adjust brightness
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            int pixel = (int) image[i * width + j] + brightness;
            if(pixel > 255) pixel = 255;
            if(pixel < 0) pixel = 0;
            image[i * width + j] = (uint8_t) pixel;
        }
    }

    //Adjust contrast
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            int pixel = (int) image[i * width + j];
            pixel = (int) (factor * (pixel - 128) + 128);
            if(pixel > 255) pixel = 255;
            if(pixel < 0) pixel = 0;
            image[i * width + j] = (uint8_t) pixel;
        }
    }
}

int main()
{
    uint8_t *image, *flipped_image;
    uint32_t width, height;

    //Read image data from file
    read_image("input.bmp", &image, &width, &height);

    //Flip image horizontally
    flipped_image = (uint8_t *) malloc(width * height * sizeof(uint8_t));
    memcpy(flipped_image, image, width * height * sizeof(uint8_t));
    flip_horizontally(flipped_image, width, height);

    //Change brightness and contrast of original image
    change_brightness_contrast(image, width, height, 50, 1.5);

    //Write processed images to file
    write_image("output_flip.bmp", flipped_image, width, height);
    write_image("output_bright_contrast.bmp", image, width, height);

    //Free memory
    free(image);
    free(flipped_image);

    return 0;
}