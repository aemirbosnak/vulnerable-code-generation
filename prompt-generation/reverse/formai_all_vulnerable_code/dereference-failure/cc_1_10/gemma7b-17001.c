//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void itoa(int n, char *s)
{
    int i = 0;
    while (n)
    {
        int digit = n % 10;
        n /= 10;
        s[i++] = digit + '0';
    }
    s[i] = '\0';
}

int main()
{
    int image_width, image_height;
    printf("Enter image width: ");
    scanf("%d", &image_width);
    printf("Enter image height: ");
    scanf("%d", &image_height);

    int **pixel_array = malloc(image_height * sizeof(int *));
    pixel_array[0] = malloc(image_width * sizeof(int));

    printf("Enter pixel values (separated by commas): ");
    char *pixel_values = malloc(image_width * image_height * sizeof(char));
    scanf("%s", pixel_values);

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            pixel_array[h][w] = atoi(pixel_values[h * image_width + w]) & 0xFF;
        }
    }

    int max_pixel_value = pixel_array[0][0];
    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            if (pixel_array[h][w] > max_pixel_value)
            {
                max_pixel_value = pixel_array[h][w];
            }
        }
    }

    int ascii_width = (int)ceil(max_pixel_value / 8) + 1;
    int **ascii_array = malloc(ascii_width * sizeof(int *));
    ascii_array[0] = malloc(image_width * sizeof(int));

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            int pixel_value = pixel_array[h][w];
            int ascii_value = (pixel_value * 8) / max_pixel_value * ascii_width;
            ascii_array[h][w] = ascii_value;
        }
    }

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            printf("%c ", ascii_array[h][w] + 32);
        }
        printf("\n");
    }

    free(pixel_array);
    free(pixel_values);
    free(ascii_array);

    return 0;
}