//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char temp;

    while (num)
    {
        temp = num % 10;
        str[i++] = temp + 48;
        num /= 10;
    }

    str[i] = '\0';
}

int main()
{
    int img_width, img_height;
    char **img_data;

    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    img_data = (char **)malloc(img_height * sizeof(char *) + 1);
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = (char *)malloc(img_width * sizeof(char) + 1);
    }

    printf("Enter image data (separate pixels with spaces): ");
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            scanf("%d ", &img_data[h][w]);
        }
    }

    printf("Converting image to ASCII art...\n");

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            int pixel_value = img_data[h][w];

            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf(",");
                    break;
                case 3:
                    printf("#");
                    break;
                default:
                    printf("!");
            }
        }

        printf("\n");
    }

    free(img_data);

    return 0;
}