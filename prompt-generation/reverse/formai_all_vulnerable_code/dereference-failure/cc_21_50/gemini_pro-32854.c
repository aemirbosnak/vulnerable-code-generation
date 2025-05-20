//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr, "Usage: %s <input file> <output file> <operation>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *operation = argv[3];

    FILE *input = fopen(input_file, "rb");
    if (input == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return 1;
    }

    int width, height;
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);

    pixel **image = malloc(height * sizeof(pixel *));
    for (int i = 0; i < height; i++)
    {
        image[i] = malloc(width * sizeof(pixel));
        fread(image[i], sizeof(pixel), width, input);
    }

    if (strcmp(operation, "grayscale") == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                unsigned char gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
                image[i][j].r = gray;
                image[i][j].g = gray;
                image[i][j].b = gray;
            }
        }
    }
    else if (strcmp(operation, "invert") == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j].r = 255 - image[i][j].r;
                image[i][j].g = 255 - image[i][j].g;
                image[i][j].b = 255 - image[i][j].b;
            }
        }
    }
    else if (strcmp(operation, "blur") == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int r = 0, g = 0, b = 0;
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        int x = j + k, y = i + l;
                        if (x >= 0 && x < width && y >= 0 && y < height)
                        {
                            r += image[y][x].r;
                            g += image[y][x].g;
                            b += image[y][x].b;
                        }
                    }
                }
                image[i][j].r = r / 9;
                image[i][j].g = g / 9;
                image[i][j].b = b / 9;
            }
        }
    }
    else if (strcmp(operation, "sharpen") == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                int r = 0, g = 0, b = 0;
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        int x = j + k, y = i + l;
                        if (x >= 0 && x < width && y >= 0 && y < height)
                        {
                            r += image[y][x].r * ((k == 0 && l == 0) ? 2 : -1);
                            g += image[y][x].g * ((k == 0 && l == 0) ? 2 : -1);
                            b += image[y][x].b * ((k == 0 && l == 0) ? 2 : -1);
                        }
                    }
                }
                image[i][j].r = r;
                image[i][j].g = g;
                image[i][j].b = b;
            }
        }
    }

    fwrite(&width, sizeof(int), 1, output);
    fwrite(&height, sizeof(int), 1, output);
    for (int i = 0; i < height; i++)
    {
        fwrite(image[i], sizeof(pixel), width, output);
    }

    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    fclose(input);
    fclose(output);

    return 0;
}