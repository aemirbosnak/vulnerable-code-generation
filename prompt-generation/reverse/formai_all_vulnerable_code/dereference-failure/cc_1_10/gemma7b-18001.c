//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int w, h;
    scanf("Enter image dimensions (w,h): ", &w, &h);

    char **img = (char **)malloc(h * sizeof(char *) + 1);
    for (int i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    printf("Enter image data: ");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            scanf("%c ", &img[i][j]);
        }
    }

    int **ascii = (int **)malloc(h * sizeof(int *) + 1);
    for (int i = 0; i < h; i++)
    {
        ascii[i] = (int *)malloc(w * sizeof(int) + 1);
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ascii[i][j] = img[i][j] * 2 + 32;
        }
    }

    printf("ASCII Art:\n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c ", ascii[i][j]);
        }
        printf("\n");
    }

    free(img);
    free(ascii);

    return 0;
}