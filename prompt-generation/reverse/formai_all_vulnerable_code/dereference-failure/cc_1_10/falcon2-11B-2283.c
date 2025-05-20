//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    // Check for proper usage
    if (argc!= 3)
    {
        fprintf(stderr, "Usage: %s input_image output_image\n", argv[0]);
        return 1;
    }

    // Open input and output files
    FILE *infile = fopen(argv[1], "rb");
    FILE *outfile = fopen(argv[2], "wb");
    if (!infile ||!outfile)
    {
        fprintf(stderr, "Failed to open file %s or %s\n", argv[1], argv[2]);
        return 2;
    }

    // Read image header
    unsigned int width, height, channels;
    unsigned char magic[4];
    fread(&magic, sizeof(magic), 1, infile);
    if (memcmp(magic, "BM", 2))
    {
        fprintf(stderr, "Invalid image file format\n");
        fclose(infile);
        fclose(outfile);
        return 3;
    }
    fread(&width, sizeof(width), 1, infile);
    fread(&height, sizeof(height), 1, infile);
    fread(&channels, sizeof(channels), 1, infile);
    if (channels!= 3)
    {
        fprintf(stderr, "Image must be RGB\n");
        fclose(infile);
        fclose(outfile);
        return 4;
    }

    // Read image data
    unsigned char *data = (unsigned char *)malloc(width * height * channels);
    if (!data)
    {
        fprintf(stderr, "Failed to allocate memory\n");
        fclose(infile);
        fclose(outfile);
        return 5;
    }
    fread(data, width * height * channels, 1, infile);
    fclose(infile);

    // Flip image horizontally
    unsigned char *flipped = (unsigned char *)malloc(width * height * channels);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            unsigned char *src = &data[(y * width + x) * channels];
            unsigned char *dest = &flipped[(height - y - 1) * width + x * channels];
            memcpy(dest, src, channels);
        }
    }

    // Write flipped image to output file
    fwrite(flipped, width * height * channels, 1, outfile);
    fclose(outfile);
    free(data);
    free(flipped);

    return 0;
}