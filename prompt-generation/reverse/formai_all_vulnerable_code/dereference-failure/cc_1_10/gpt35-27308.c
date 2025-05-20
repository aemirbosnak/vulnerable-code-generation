//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Flips an image
void flip_image(unsigned char* img_data, int img_width, int img_height)
{
    unsigned char* tmp_row = malloc(img_width * sizeof(unsigned char));
    int row_top = 0;
    int row_bot = img_height - 1;

    while (row_top < row_bot)
    {
        // Swap rows
        memcpy(tmp_row, img_data + row_top * img_width, img_width * sizeof(unsigned char));
        memcpy(img_data + row_top * img_width, img_data + row_bot * img_width,
               img_width * sizeof(unsigned char));
        memcpy(img_data + row_bot * img_width, tmp_row, img_width * sizeof(unsigned char));

        row_top++;
        row_bot--;
    }

    free(tmp_row);
}

// Changes brightness of an image
void adjust_brightness(unsigned char* img_data, int img_width, int img_height, int brightness)
{
    for (int r = 0; r < img_height; r++)
    {
        for (int c = 0; c < img_width; c++)
        {
            int pixel_loc = r * img_width + c;
            int new_val = (int)img_data[pixel_loc] + brightness;
            if (new_val < 0)
                new_val = 0;
            else if (new_val > 255)
                new_val = 255;
            img_data[pixel_loc] = (unsigned char)new_val;
        }
    }
}

// Changes contrast of an image
void adjust_contrast(unsigned char* img_data, int img_width, int img_height, int contrast)
{
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (int r = 0; r < img_height; r++)
    {
        for (int c = 0; c < img_width; c++)
        {
            int pixel_loc = r * img_width + c;
            int new_val = (int)(factor * ((int)img_data[pixel_loc] - 128) + 128);
            if (new_val < 0)
                new_val = 0;
            else if (new_val > 255)
                new_val = 255;
            img_data[pixel_loc] = (unsigned char)new_val;
        }
    }
}

int main()
{
    // Load image data
    const char* filename = "image.raw";
    FILE* img_file = fopen(filename, "rb");
    if (img_file == NULL)
    {
        printf("Error: Cannot open file \"%s\"\n", filename);
        return 1;
    }

    int img_width = 512;
    int img_height = 512;
    unsigned char* img_data = malloc(img_width * img_height * sizeof(unsigned char));

    fread(img_data, sizeof(unsigned char), img_width * img_height, img_file);
    fclose(img_file);

    // Flip image
    flip_image(img_data, img_width, img_height);

    // Adjust brightness
    int brightness = 50;
    adjust_brightness(img_data, img_width, img_height, brightness);

    // Adjust contrast
    int contrast = 50;
    adjust_contrast(img_data, img_width, img_height, contrast);

    // Save processed image
    const char* output_filename = "output.raw";
    FILE* output_file = fopen(output_filename, "wb");
    fwrite(img_data, sizeof(unsigned char), img_width * img_height, output_file);
    fclose(output_file);

    free(img_data);

    return 0;
}