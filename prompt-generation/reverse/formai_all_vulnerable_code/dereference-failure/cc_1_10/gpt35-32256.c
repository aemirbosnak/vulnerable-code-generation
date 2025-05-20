//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define ASCII_CHARACTERS " .:-=+*#%@"

char *convert_to_ascii(unsigned char *pixels, int width, int height, int char_width, int char_height);
unsigned char *load_image(char *filename, int *width, int *height);

int main(int argc, char **argv)
{
    int width, height;

    if (argc < 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    unsigned char *pixels = load_image(argv[1], &width, &height);

    // Define the size of the ASCII image
    int char_width = 5;
    int char_height = 10;

    char *ascii_image = convert_to_ascii(pixels, width, height, char_width, char_height);
    printf("%s", ascii_image);

    // Cleanup
    free(ascii_image);
    free(pixels);

    return 0;
}

char *convert_to_ascii(unsigned char *pixels, int width, int height, int char_width, int char_height)
{
    int scaled_width = width / char_width;
    int scaled_height = height / char_height;

    char *ascii_image = (char *)malloc((scaled_width * scaled_height) + scaled_height + 1);
    char *ptr = ascii_image;

    for (int y = 0; y < height; y += char_height)
    {
        for (int x = 0; x < width; x += char_width)
        {
            unsigned int grayscale_value = 0;

            // Calculate the average grayscale value for the current character block
            for (int cy = y; cy < y + char_height && cy < height; cy++)
            {
                for (int cx = x; cx < x + char_width && cx < width; cx++)
                {
                    grayscale_value += pixels[(cy * width) + cx];
                }
            }

            grayscale_value = grayscale_value / (char_width * char_height);
            int index = ((grayscale_value * 10) / MAX_PIXEL_VALUE) * strlen(ASCII_CHARACTERS);
            *ptr++ = ASCII_CHARACTERS[index];
        }

        *ptr++ = '\n';
    }

    // Terminate the ASCII image string with null character
    *ptr = '\0';

    return ascii_image;
}

unsigned char *load_image(char *filename, int *width, int *height)
{
    FILE *f = fopen(filename, "rb");

    if (!f)
    {
        printf("Unable to open file %s\n", filename);
        exit(1);
    }

    char magic[3];
    fread(magic, 1, 2, f);

    if (strncmp(magic, "P5", 2))
    {
        printf("Invalid image format.\n");
        exit(1);
    }

    // Skip over comments in the image header
    while (fgetc(f) == '#')
    {
        while (fgetc(f) != '\n')
        {
        }
    }

    fseek(f, -1, SEEK_CUR);

    // Read image dimensions
    fscanf(f, "%d %d", width, height);

    // Read the maximum pixel value (Ignore this value since we only need grayscale values)
    int max_value;
    fscanf(f, "%d\n", &max_value);

    // Allocate memory for the pixel data
    unsigned char *pixels = (unsigned char *)malloc(*width * *height * sizeof(unsigned char));

    // Read the pixel data
    fread(pixels, *width, *height, f);

    fclose(f);

    return pixels;
}