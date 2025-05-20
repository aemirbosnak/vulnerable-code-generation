//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char *s)
{
    int i = 0;
    char tmp;

    s[0] = '\0';

    while (n)
    {
        tmp = n % 10;
        n /= 10;

        s[i++] = tmp + '0';
    }

    if (i == 0)
    {
        s[0] = '0';
    }

    s[i] = '\0';
}

int main()
{
    int image_width, image_height, pixel_size;
    char **image_data;
    char **ascii_data;

    printf("Enter image width: ");
    scanf("%d", &image_width);

    printf("Enter image height: ");
    scanf("%d", &image_height);

    printf("Enter pixel size: ");
    scanf("%d", &pixel_size);

    image_data = (char **)malloc(image_height * sizeof(char *));
    ascii_data = (char **)malloc(image_height * sizeof(char *));

    for (int h = 0; h < image_height; h++)
    {
        image_data[h] = (char *)malloc(image_width * sizeof(char));
        ascii_data[h] = (char *)malloc(image_width * sizeof(char));
    }

    printf("Enter pixel values (separated by commas): ");
    scanf("%s", image_data[0]);

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            itoa(image_data[h][w], ascii_data[h][w]);
        }
    }

    printf("ASCII image:\n");

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            printf("%c ", ascii_data[h][w]);
        }

        printf("\n");
    }

    free(image_data);
    free(ascii_data);

    return 0;
}