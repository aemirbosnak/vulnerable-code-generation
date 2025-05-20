//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void text_to_ascii(char text[], int text_len, int height)
{
    int i, j, k, l;
    char **ascii_art = (char**)malloc(height * sizeof(char*));
    for (i = 0; i < height; i++)
    {
        ascii_art[i] = (char*)malloc(text_len * sizeof(char));
    }

    for (i = 0; i < text_len; i++)
    {
        ascii_art[0][i] = text[i];
    }

    for (k = 1; k < height; k++)
    {
        for (l = 0; l < text_len; l++)
        {
            ascii_art[k][l] = '*';
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < text_len; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < height; i++)
    {
        free(ascii_art[i]);
    }
    free(ascii_art);
}

int main()
{
    char text[] = "HELLO WORLD!";
    int text_len = strlen(text);
    int height = 5;

    text_to_ascii(text, text_len, height);

    return 0;
}