//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int w, h, n, i, j, k;
    char **a;

    printf("Enter the width of the ASCII art: ");
    scanf("%d", &w);

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &h);

    a = (char **)malloc(h * sizeof(char *) + 1);
    for (i = 0; i < h; i++)
    {
        a[i] = (char *)malloc(w * sizeof(char) + 1);
    }

    printf("Enter the number of characters to be used: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the character: ");
        scanf("%c", &a[0][0]);
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            for (k = 0; k < n; k++)
            {
                a[i][j] = a[0][0];
            }
        }
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < h; i++)
    {
        free(a[i]);
    }
    free(a);

    return 0;
}