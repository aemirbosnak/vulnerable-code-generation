//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an image to ASCII art
char *image_to_ascii(const char *filename)
{
    // Open the image file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned char header[14];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M')
    {
        fprintf(stderr, "Error: File is not a valid BMP file\n");
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Read the image data
    unsigned char *data = (unsigned char *)malloc(width * height * 3);
    fread(data, width * height * 3, 1, fp);

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    char *ascii = (char *)malloc((width + 1) * height + 1);
    int index = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get the average of the RGB values
            unsigned char avg = (data[index] + data[index + 1] + data[index + 2]) / 3;

            // Convert the average to an ASCII character
            char c;
            if (avg < 32)
            {
                c = '#';
            }
            else if (avg < 64)
            {
                c = '&';
            }
            else if (avg < 96)
            {
                c = 'o';
            }
            else if (avg < 128)
            {
                c = ':';
            }
            else if (avg < 160)
            {
                c = '*';
            }
            else if (avg < 192)
            {
                c = '.';
            }
            else if (avg < 224)
            {
                c = ' ';
            }
            else
            {
                c = ' ';
            }

            // Add the character to the ASCII art string
            ascii[index++] = c;
        }

        // Add a newline character to the ASCII art string
        ascii[index++] = '\n';
    }

    // Add a null terminator to the ASCII art string
    ascii[index] = '\0';

    // Return the ASCII art string
    return ascii;
}

// Function to print the ASCII art to the console
void print_ascii(const char *ascii)
{
    // Print the ASCII art to the console
    printf("%s", ascii);
}

// Function to free the memory allocated for the ASCII art string
void free_ascii(char *ascii)
{
    // Free the memory allocated for the ASCII art string
    free(ascii);
}

// Main function
int main(int argc, char **argv)
{
    // Check if the user has provided an image file name
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Convert the image file to ASCII art
    char *ascii = image_to_ascii(argv[1]);
    if (ascii == NULL)
    {
        fprintf(stderr, "Error converting image to ASCII art\n");
        return EXIT_FAILURE;
    }

    // Print the ASCII art to the console
    print_ascii(ascii);

    // Free the memory allocated for the ASCII art string
    free_ascii(ascii);

    return EXIT_SUCCESS;
}