//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

void compress(char **a, int **b, int n)
{
    int i, j, k, l, count = 0, flag = 0;
    for (i = 0; i < n; i++)
    {
        l = 1;
        for (j = i + 1; j < n && a[i] == a[j]; j++)
            l++;
        if (l > 1)
        {
            b[count++] = a[i];
            b[count++] = l - 1;
            flag = 1;
        }
        else
            b[count++] = a[i];
    }
    if (flag)
        return;
    else
        *b = NULL;
}

int main()
{
    char **a = NULL;
    int **b = NULL, n = 0;
    a = (char **)malloc(MAX * sizeof(char *));
    for (n = 0; n < MAX; n++)
        a[n] = (char *)malloc(MAX * sizeof(char));

    // Sample data
    a[0] = "abc";
    a[1] = "aab";
    a[2] = "abb";

    compress(a, &b, 3);

    if (b)
    {
        for (n = 0; b[n] != NULL; n++)
            printf("%c ", b[n]);
        printf("\n");
    }

    return 0;
}