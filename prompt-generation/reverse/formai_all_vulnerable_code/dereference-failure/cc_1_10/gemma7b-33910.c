//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char *s)
{
    int i = 0;
    char num[10];

    if (n < 0)
    {
        s[0] = '-';
        n = -n;
    }

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
    int image_width = 10;
    int image_height = 10;
    int pixel_values[image_width * image_height];

    pixel_values[0] = 255;
    pixel_values[1] = 0;
    pixel_values[2] = 0;
    pixel_values[3] = 255;
    pixel_values[4] = 255;
    pixel_values[5] = 0;
    pixel_values[6] = 0;
    pixel_values[7] = 255;
    pixel_values[8] = 255;
    pixel_values[9] = 0;

    char image_ascii[image_width * image_height];

    for (int y = 0; y < image_height; y++)
    {
        for (int x = 0; x < image_width; x++)
        {
            itoa(pixel_values[x + image_width * y], image_ascii[x + image_width * y]);
        }
    }

    image_ascii[image_width * image_height] = '\0';

    printf("%s", image_ascii);

    return 0;
}