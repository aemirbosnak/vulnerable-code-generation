//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char img[100] = "I am a cat";
    int i = 0;
    int w = 0;

    for (i = 0; img[i] != '\0'; i++)
    {
        if (img[i] == ' ')
        {
            w++;
        }
    }

    int h = w + 1;
    char **ascii = (char **)malloc(h * sizeof(char *) + 1);

    for (i = 0; i < h; i++)
    {
        ascii[i] = (char *)malloc((w + 1) * sizeof(char) + 1);
    }

    for (i = 0; img[i] != '\0'; i++)
    {
        if (img[i] == ' ')
        {
            ascii[w][0] = '\0';
            w++;
        }
        else
        {
            ascii[w][img[i] - 97] = '*';
        }
    }

    ascii[h - 1][0] = '\0';

    for (i = 0; ascii[i] != NULL; i++)
    {
        for (w = 0; ascii[i][w] != '\0'; w++)
        {
            printf("%c ", ascii[i][w]);
        }
        printf("\n");
    }

    free(ascii);

    return 0;
}