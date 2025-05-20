//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void compress(char **a, int n)
{
    int i, j, count = 0, flag = 0;
    char **b = (char**)malloc(n * MAX);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (a[i][j] != '\0')
            {
                b[count++] = a[i][j];
                flag = 1;
            }
        }
    }
    if (flag)
    {
        printf("Compressed data:\n");
        for (i = 0; i < count; i++)
        {
            printf("%c ", b[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No data to compress.\n");
    }
    free(b);
}

int main()
{
    char **a = (char**)malloc(MAX * MAX);
    a[0][0] = 'R';
    a[0][1] = 'O';
    a[0][2] = 'M';
    a[1][0] = 'E';
    a[1][1] = 'Y';
    a[1][2] = 'L';
    a[2][0] = 'U';
    a[2][1] = 'T';
    a[2][2] = 'A';

    compress(a, 3);

    free(a);

    return 0;
}