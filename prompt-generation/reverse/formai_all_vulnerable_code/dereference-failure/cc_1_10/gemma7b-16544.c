//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void draw_ascii_art(int x, int y, char **arr)
{
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char **arr;
    int x, y;
    time_t t;

    x = rand() % MAX;
    y = rand() % MAX;

    arr = (char **)malloc(x * sizeof(char *) + 1);
    for (int i = 0; i < x; i++)
    {
        arr[i] = (char *)malloc(y * sizeof(char) + 1);
    }

    t = time(NULL);

    srand(t);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = (rand() % 2) ? 'X' : 'O';
        }
    }

    draw_ascii_art(x, y, arr);

    free(arr);

    return 0;
}