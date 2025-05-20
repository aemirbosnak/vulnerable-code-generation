//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_SIZE 256

int image_width, image_height, image_depth;
unsigned char *image_data = NULL;

int read_file(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    // Read the width, height, and depth of the image
    fread(&image_width, sizeof(int), 1, fp);
    fread(&image_height, sizeof(int), 1, fp);
    fread(&image_depth, sizeof(int), 1, fp);

    // Calculate the total size of the image data
    int data_size = image_width * image_height * image_depth;
    image_data = (unsigned char *) malloc(data_size);

    // Read the image data from the file
    fread(image_data, sizeof(unsigned char), data_size, fp);

    fclose(fp);
    return 0;
}

int write_file(const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Unable to open file %s\n", filename);
        return -1;
    }

    // Write the width, height, and depth of the image
    fwrite(&image_width, sizeof(int), 1, fp);
    fwrite(&image_height, sizeof(int), 1, fp);
    fwrite(&image_depth, sizeof(int), 1, fp);

    // Write the image data to the file
    fwrite(image_data, sizeof(unsigned char), image_width * image_height * image_depth, fp);

    fclose(fp);
    return 0;
}

void invert_image()
{
    int i, j, k;
    for (i = 0; i < image_height; i++)
    {
        for (j = 0; j < image_width; j++)
        {
            for (k = 0; k < image_depth; k++)
            {
                // Invert each color channel
                image_data[(i * image_width + j) * image_depth + k] = 255 - image_data[(i * image_width + j) * image_depth + k];
            }
        }
    }
}

void grayscale_image()
{
    int i, j, k;
    double value;
    for (i = 0; i < image_height; i++)
    {
        for (j = 0; j < image_width; j++)
        {
            // Calculate the grayscale value of each pixel
            value = 0.2126 * image_data[(i * image_width + j) * image_depth + 0] +
                    0.7152 * image_data[(i * image_width + j) * image_depth + 1] +
                    0.0722 * image_data[(i * image_width + j) * image_depth + 2];

            for (k = 0; k < image_depth; k++)
            {
                // Set each color channel to the grayscale value
                image_data[(i * image_width + j) * image_depth + k] = (unsigned char) value;
            }
        }
    }
}

int main(int argc, char **argv)
{
    char input_filename[MAX_FILENAME_SIZE];
    char output_filename[MAX_FILENAME_SIZE];
    int action;

    if (argc < 3)
    {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return -1;
    }

    strncpy(input_filename, argv[1], MAX_FILENAME_SIZE);
    strncpy(output_filename, argv[2], MAX_FILENAME_SIZE);

    if (read_file(input_filename) != 0)
    {
        return -1;
    }

    printf("Select an action:\n");
    printf("1. Invert the image\n");
    printf("2. Convert the image to grayscale\n");
    scanf("%d", &action);

    switch (action)
    {
        case 1:
            invert_image();
            break;

        case 2:
            grayscale_image();
            break;

        default:
            printf("Invalid action selected\n");
            return -1;
    }

    if (write_file(output_filename) != 0)
    {
        return -1;
    }

    printf("Done!\n");

    return 0;
}