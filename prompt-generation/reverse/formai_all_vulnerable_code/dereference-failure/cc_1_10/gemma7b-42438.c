//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void compress(char **a, int *n)
{
    int i = 0, j = 0, count = 1, repeat = 0, size = 0;
    char **b = NULL;

    *n = 0;

    for (i = 0; a[i] && i < MAX; i++)
    {
        if (a[i] == a[i - 1])
        {
            repeat++;
        }
        else
        {
            if (repeat)
            {
                b[size++] = repeat;
                b[size++] = a[i];
            }
            else
            {
                b[size++] = a[i];
            }

            repeat = 1;
        }
    }

    *n = size;
    return;
}

int main()
{
    char **a = NULL;
    int n = 0, i = 0, size = 0;

    a = malloc(MAX * sizeof(char *));

    for (i = 0; i < MAX; i++)
    {
        a[i] = malloc(MAX * sizeof(char));
    }

    a[0] = "abccaaabbbb";

    compress(a, &n);

    printf("Original size: %d\n", size);
    printf("Compressed size: %d\n", n);

    return 0;
}