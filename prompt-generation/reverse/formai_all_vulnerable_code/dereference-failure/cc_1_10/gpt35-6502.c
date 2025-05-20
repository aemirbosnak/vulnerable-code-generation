//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define ASCII_SIZE 128

char* ascii_art[ASCII_SIZE] = { NULL }; // This array will store the ASCII art characters corresponding to their ASCII values.


// This function will load the ASCII art character set from a file.
void load_ascii_art_characters(char* filename)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Failed to open file '%s' for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    char c;
    char* buffer = (char*)malloc((MAX_WIDTH + 1) * sizeof(char));
    size_t buffer_size = MAX_WIDTH + 1;

    for (int i = 0; i < ASCII_SIZE; i++)
    {
        if (getline(&buffer, &buffer_size, fp) == -1)
        {
            fprintf(stderr, "Error: Missing ASCII art for character '%c'.\n", (char)i);
            exit(EXIT_FAILURE);
        }

        ascii_art[i] = strdup(buffer);
    }

    free(buffer);
    fclose(fp);
}

// This function will convert the given image to ASCII art and print the result to the console.
void convert_image_to_ascii_art(unsigned char image[MAX_HEIGHT][MAX_WIDTH], int width, int height)
{
    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        fprintf(stderr, "Error: Image size exceeds the maximum dimensions.\n");
        return;
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int index = (int)((double)image[y][x] / 255.0 * (double)(ASCII_SIZE - 1));
            printf("%s", ascii_art[index]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <image_file> <ascii_art_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* image_filename = argv[1];
    char* ascii_art_filename = argv[2];

    // Load the ASCII art character set from file.
    load_ascii_art_characters(ascii_art_filename);

    // Load the image file.
    FILE* fp = fopen(image_filename, "rb");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Failed to open file '%s' for reading.\n", image_filename);
        exit(EXIT_FAILURE);
    }

    int width, height;
    unsigned char image[MAX_HEIGHT][MAX_WIDTH];

    if (fscanf(fp, "P5 %d %d 255 ", &width, &height) != 2)
    {
        fprintf(stderr, "Error: Invalid PGM file format.\n");
        exit(EXIT_FAILURE);
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        fprintf(stderr, "Error: Image size exceeds the maximum dimensions.\n");
        exit(EXIT_FAILURE);
    }

    if (fread(image, sizeof(unsigned char), width * height, fp) != width * height)
    {
        fprintf(stderr, "Error: Failed to read image data.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    // Convert the image to ASCII art and print the result to the console.
    convert_image_to_ascii_art(image, width, height);

    return EXIT_SUCCESS;
}