//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **a = NULL;
    int **b = NULL;
    int i, j, k, l;
    char msg[1024];

    a = (char **)malloc(10 * sizeof(char *));
    b = (int **)malloc(10 * sizeof(int *));

    for (i = 0; i < 10; i++)
    {
        a[i] = (char *)malloc(10 * sizeof(char));
        b[i] = (int *)malloc(10 * sizeof(int));
    }

    printf("Enter your secret message: ");
    scanf("%s", msg);

    k = 0;
    l = 0;

    for (i = 0; msg[i] != '\0'; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (int z = 0; z < 10; z++)
            {
                a[j][z] = msg[k] & 0x3F;
                b[j][z] = (msg[k] & 0x3F) << 2;
                k++;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            free(a[i]);
            free(b[i]);
        }
        free(a[i]);
        free(b[i]);
    }

    free(a);
    free(b);

    return 0;
}