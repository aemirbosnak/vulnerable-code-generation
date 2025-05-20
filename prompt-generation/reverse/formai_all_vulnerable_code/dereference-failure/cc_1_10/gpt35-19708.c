//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_PIXEL 255

char shades[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

void convert_to_ascii(char *image_path)
{
    char *output_path = malloc(strlen(image_path) + 5);
    strcpy(output_path, image_path);
    strcat(output_path, ".txt");

    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL)
    {
        printf("Error opening image file.\n");
        exit(1);
    }

    FILE *output_file = fopen(output_path, "w");
    if (output_file == NULL)
    {
        printf("Error creating output file.\n");
        exit(1);
    }

    unsigned char image[HEIGHT][WIDTH];

    fread(image, sizeof(char), HEIGHT * WIDTH, image_file);
    fclose(image_file);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            int pixel_value = image[y][x];
            int shade_index = (int)(((float)pixel_value / MAX_PIXEL) * 10);
            fprintf(output_file, "%c", shades[shade_index]);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    printf("Conversion successful. ASCII art saved to %s\n", output_path);
    free(output_path);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s <image_path>\n", argv[0]);
        exit(1);
    }

    convert_to_ascii(argv[1]);

    return 0;
}