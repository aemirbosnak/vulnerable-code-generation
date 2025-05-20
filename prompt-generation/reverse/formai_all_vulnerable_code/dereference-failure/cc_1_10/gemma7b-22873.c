//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void watermark(char **image, int w, int h, int n, char *key)
{
    if (n == 0)
    {
        return;
    }

    int x = rand() % w;
    int y = rand() % h;

    image[x][y] = key[n - 1];

    watermark(image, w, h, n - 1, key);
}

int main()
{
    char **image = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    image = (char **)malloc(h * w * sizeof(char));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            image[i][j] = 0;
        }
    }

    char key[] = "SECRET KEY";

    int n = strlen(key);

    watermark(image, w, h, n, key);

    printf("Watermarked image:\n");

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c ", image[i][j]);
        }

        printf("\n");
    }

    free(image);

    return 0;
}