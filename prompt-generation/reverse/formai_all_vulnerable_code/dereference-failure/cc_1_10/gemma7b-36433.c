//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
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

    if (s[0] == '\0')
    {
        s[0] = '0';
    }
}

int main()
{
    int img_width, img_height;
    char **img_data;
    char **ascii_art;

    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    img_data = (char **)malloc(img_height * sizeof(char *));
    ascii_art = (char **)malloc(img_height * sizeof(char *));

    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = (char *)malloc(img_width * sizeof(char));
        ascii_art[h] = (char *)malloc(img_width * sizeof(char));
    }

    printf("Enter image data (each pixel as a number, separated by spaces): ");
    scanf("%[^\n]%*c", img_data);

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            itoa(img_data[h][w], ascii_art[h][w]);
            ascii_art[h][w] = ascii_art[h][w] + 'A' - 1;
        }
    }

    printf("Your ASCII art:\n");

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    return 0;
}