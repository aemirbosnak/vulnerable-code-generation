//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateQR(char *data)
{
    int n = strlen(data) * 2 + 1;
    int **a = malloc(n * n);
    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    int k = 0;
    for (int i = 0; i < strlen(data); i++)
    {
        int d = data[i] - 'a' + 1;
        a[k][k] = d;
        a[k][k + 1] = d;
        a[k + 1][k] = d;
        a[k + 1][k + 1] = d;
        k++;
    }

    char *p = malloc(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i * n + j] = a[i][j] + 'a';
        }
    }

    printf("%s", p);
    free(a);
    free(p);
}

int main()
{
    char data[] = "Donald Knuth";
    generateQR(data);

    return 0;
}