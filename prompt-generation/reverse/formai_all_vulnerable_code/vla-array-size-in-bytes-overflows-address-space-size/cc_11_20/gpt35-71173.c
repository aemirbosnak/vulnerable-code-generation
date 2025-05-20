//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Reading the input image
    FILE *imageFile;
    imageFile = fopen("input_image.ppm", "rb");
    if (imageFile == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }

    char header[500];
    fgets(header, 500, imageFile);
    fgets(header, 500, imageFile);

    int num_columns = 0;
    int num_rows = 0;
    int max_color = 0;

    fscanf(imageFile, "%d %d %d", &num_columns, &num_rows, &max_color);

    unsigned char image[num_rows][num_columns][3];

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            fread(image[i][j], 1, 3, imageFile);
        }
    }

    fclose(imageFile);

    // Flipping the input image horizontally
    unsigned char flipped_image[num_rows][num_columns][3];

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            flipped_image[i][num_columns - j - 1][0] = image[i][j][0];
            flipped_image[i][num_columns - j - 1][1] = image[i][j][1];
            flipped_image[i][num_columns - j - 1][2] = image[i][j][2];
        }
    }

    // Changing the brightness and contrast of the flipped image
    float brightness = 50.0; // Increase or decrease the brightness here
    float contrast = 1.5; // Increase or decrease the contrast here

    unsigned char brightened_image[num_rows][num_columns][3];

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            float r = (flipped_image[i][j][0] - 127.5) * contrast + 127.5 + brightness;
            float g = (flipped_image[i][j][1] - 127.5) * contrast + 127.5 + brightness;
            float b = (flipped_image[i][j][2] - 127.5) * contrast + 127.5 + brightness;

            brightened_image[i][j][0] = (unsigned char)fmin(fmax(r, 0), 255);
            brightened_image[i][j][1] = (unsigned char)fmin(fmax(g, 0), 255);
            brightened_image[i][j][2] = (unsigned char)fmin(fmax(b, 0), 255);
        }
    }

    // Writing the output image
    FILE *outputFile;
    outputFile = fopen("output_image.ppm", "wb");
    if (outputFile == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }

    fprintf(outputFile, "%s", header);
    fprintf(outputFile, "%d %d\n", num_columns, num_rows);
    fprintf(outputFile, "%d\n", max_color);

    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_columns; j++)
        {
            fwrite(brightened_image[i][j], 1, 3, outputFile);
        }
    }

    fclose(outputFile);

    printf("Image processing complete!\n");

    return 0;
}