//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char tmp;

    while (num)
    {
        tmp = num % 10;
        str[i++] = tmp + '0';
        num /= 10;
    }

    str[i] = '\0';
}

int main()
{
    int image_width, image_height;
    char **image_data;
    char **ascii_art;

    printf("Enter image width: ");
    scanf("%d", &image_width);

    printf("Enter image height: ");
    scanf("%d", &image_height);

    image_data = (char **)malloc(image_height * sizeof(char *));
    ascii_art = (char **)malloc(image_height * sizeof(char *));

    for (int h = 0; h < image_height; h++)
    {
        image_data[h] = (char *)malloc(image_width * sizeof(char));
        ascii_art[h] = (char *)malloc(image_width * sizeof(char));
    }

    printf("Enter image data (separated by spaces): ");
    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            scanf("%c", &image_data[h][w]);
        }
    }

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            itoa(image_data[h][w], ascii_art[h][w]);
            ascii_art[h][w] = ascii_art[h][w] + 32;
        }
    }

    printf("Here is your ASCII art: \n");
    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    return 0;
}