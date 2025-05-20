//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FILE_NAME 100
#define MAX_PIXELS 100000

// Function to read the image file
char *read_image(char *file_name)
{
    FILE *file = fopen(file_name, "rb");
    if (!file)
    {
        printf("Error: Unable to open file!\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = (char *) malloc(sizeof(char) * file_size);
    if (!buffer)
    {
        printf("Error: Unable to allocate memory for buffer!\n");
        fclose(file);
        return NULL;
    }

    size_t result = fread(buffer, 1, file_size, file);
    if (result != file_size)
    {
        printf("Error: Unable to read file!\n");
        fclose(file);
        free(buffer);
        return NULL;
    }

    fclose(file);
    return buffer;
}

// Function to convert pixel to ASCII character
char *get_ascii_char(int gray_value)
{
    static char ascii_chars[11] = " .,:;ox%#@";
    int num_chars = sizeof(ascii_chars) - 1;
    int char_index = (gray_value * num_chars) / 255;
    return &ascii_chars[char_index];
}

// Function to convert image to ASCII art
void convert_to_ascii(char *pixels, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_index = (y * width + x) * 3;
            int gray_value = (pixels[pixel_index] + pixels[pixel_index + 1] + pixels[pixel_index + 2]) / 3;
            printf("%s", get_ascii_char(gray_value));
        }
        printf("\n");
    }
}

int main()
{
    char file_name[MAX_FILE_NAME];
    printf("Enter the name of the image file: ");
    scanf("%s", file_name);

    char *image_data = read_image(file_name);
    if (!image_data)
    {
        printf("Error: Unable to read image file!\n");
        return -1;
    }

    int width = *(int *) &image_data[18];
    int height = *(int *) &image_data[22];
    int num_pixels = width * height;

    if (num_pixels > MAX_PIXELS)
    {
        printf("Error: Image size exceeds maximum allowed size!\n");
        free(image_data);
        return -1;
    }

    convert_to_ascii(&image_data[54], width, height);
    free(image_data);
    return 0;
}