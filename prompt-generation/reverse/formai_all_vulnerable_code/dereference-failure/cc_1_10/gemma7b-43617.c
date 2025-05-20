//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int num, char *str)
{
    int i = 0;
    char buf[11];

    sprintf(buf, "%d", num);
    while (buf[i] != '\0')
    {
        str[i] = buf[i];
        i++;
    }

    str[i] = '\0';
}

int main()
{
    char image[] = "C Image to ASCII Art Converter";
    int w = 50;
    int h = 10;
    char **arr = NULL;
    int i, j;

    arr = (char **)malloc(h * w * sizeof(char *));
    for (i = 0; i < h; i++)
    {
        arr[i] = (char *)malloc(w * sizeof(char));
    }

    for (i = 0; image[i] != '\0'; i++)
    {
        arr[0][i] = image[i];
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            itoa(arr[i][j], arr[i][j] + 32);
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}