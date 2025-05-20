//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[11];

    while (n)
    {
        int digit = n % 10;
        num[i++] = digit + '0';
        n /= 10;
    }

    num[i] = '\0';
    strcpy(s, num);
}

int main()
{
    int img_width, img_height;
    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    char **image = (char **)malloc(img_height * sizeof(char *) + 1);
    for (int h = 0; h < img_height; h++)
    {
        image[h] = (char *)malloc(img_width * sizeof(char) + 1);
    }

    printf("Enter image data (separate pixels with spaces): ");
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            scanf("%d ", &image[h][w]);
        }
    }

    char **ascii_image = (char **)malloc(img_height * sizeof(char *) + 1);
    for (int h = 0; h < img_height; h++)
    {
        ascii_image[h] = (char *)malloc(img_width * sizeof(char) + 1);
    }

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            int pixel_value = image[h][w];
            itoa(pixel_value, ascii_image[h][w]);
        }
    }

    printf("ASCII image:\n");
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            printf("%c ", ascii_image[h][w]);
        }
        printf("\n");
    }

    free(image);
    free(ascii_image);

    return 0;
}