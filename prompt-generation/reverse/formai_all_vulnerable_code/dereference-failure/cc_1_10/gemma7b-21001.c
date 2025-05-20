//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char temp;

    while (num)
    {
        temp = num % 10;
        str[i++] = temp + '0';
        num /= 10;
    }

    str[i] = '\0';
}

int main()
{
    int img_width, img_height;
    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    int **img_data = (int **)malloc(img_height * sizeof(int *));
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = (int *)malloc(img_width * sizeof(int));
    }

    printf("Enter image data (separated by commas): ");
    char img_data_str[1024];
    scanf("%s", img_data_str);

    char *p = img_data_str;
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            img_data[h][w] = atoi(p);
            p++;
        }
    }

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            switch (img_data[h][w])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("/");
                    break;
                case 3:
                    printf("@");
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