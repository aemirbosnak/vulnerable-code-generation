//FormAI DATASET v1.0 Category: Image Editor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54

void grayscale(unsigned char *input, unsigned char *output, int width, int height)
{
    int row, col, offset, gray;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            offset = (row * width + col) * 3;
            gray = (int)(0.2989 * input[offset] + 0.5870 * input[offset + 1] + 0.1140 * input[offset + 2]);
            output[offset] = (unsigned char)gray;
            output[offset + 1] = (unsigned char)gray;
            output[offset + 2] = (unsigned char)gray;
        }
    }
}

void invert(unsigned char *input, unsigned char *output, int width, int height)
{
    int row, col, offset;
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            offset = (row * width + col) * 3;
            output[offset] = 255 - input[offset];
            output[offset + 1] = 255 - input[offset + 1];
            output[offset + 2] = 255 - input[offset + 2];
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *fin = fopen(input_file, "rb");
    if (!fin)
    {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *fout = fopen(output_file, "wb");
    if (!fout)
    {
        printf("Error opening output file.\n");
        return 1;
    }

    // read BMP header
    unsigned char header[BMP_HEADER_SIZE];
    if (fread(header, sizeof(unsigned char), BMP_HEADER_SIZE, fin) != BMP_HEADER_SIZE)
    {
        printf("Error reading BMP header.\n");
        return 1;
    }

    // check BMP format
    if (header[0] != 'B' || header[1] != 'M')
    {
        printf("Error: unsupported BMP format.\n");
        return 1;
    }

    // read image size
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // allocate memory for input and output images
    int input_size = width * height * 3;
    int output_size = input_size;
    unsigned char *input = (unsigned char *)malloc(input_size);
    unsigned char *output = (unsigned char *)malloc(output_size);

    if (!input || !output)
    {
        printf("Error: memory allocation failed.\n");
        return 1;
    }

    // read input image
    if (fread(input, sizeof(unsigned char), input_size, fin) != input_size)
    {
        printf("Error reading input image.\n");
        return 1;
    }

    // close input file
    fclose(fin);

    // apply grayscale filter
    grayscale(input, output, width, height);

    // apply invert filter
    invert(output, output, width, height);

    // write output image
    if (fwrite(header, sizeof(unsigned char), BMP_HEADER_SIZE, fout) != BMP_HEADER_SIZE || fwrite(output, sizeof(unsigned char), output_size, fout) != output_size)
    {
        printf("Error writing output image.\n");
        return 1;
    }

    // close output file
    fclose(fout);

    // free memory
    free(input);
    free(output);

    printf("Image filter applied successfully!\n");

    return 0;
}