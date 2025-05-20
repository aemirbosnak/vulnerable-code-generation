//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

void img_to_ascii(unsigned char **img, int w, int h)
{
    int i, j, k;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            k = img[i][j];
            switch (k)
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
                    printf("$");
                    break;
                case 4:
                    printf("%");
                    break;
                case 5:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }
}

int main()
{
    unsigned char **img = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    img = (unsigned char **)malloc(h * sizeof(unsigned char *) + h);
    for (int i = 0; i < h; i++)
    {
        img[i] = (unsigned char *)malloc(w * sizeof(unsigned char) + w);
    }

    printf("Enter the pixels of the image (separated by commas): ");
    char pixel[1000];
    scanf("%s", pixel);

    int p = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            img[i][j] = pixel[p] - '0';
            p++;
        }
    }

    img_to_ascii(img, w, h);

    free(img);
    return 0;
}