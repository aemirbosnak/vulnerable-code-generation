//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

int main()
{
    int n, i, j, k;
    char **qr_code = NULL;
    char data[] = "Hello, world!";

    n = strlen(data) + 1;
    qr_code = (char**)malloc(n * MAX_SIZE);

    for (i = 0; i < n; i++)
    {
        qr_code[i] = (char*)malloc(MAX_SIZE);
        for (j = 0; j < MAX_SIZE; j++)
        {
            qr_code[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < strlen(data); j++)
        {
            if (data[j] == qr_code[i][j])
            {
                qr_code[i][j] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (qr_code[i][j] == 1)
            {
                printf("%c ", 248);
            }
            else
            {
                printf("%c ", 255);
            }
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(qr_code[i]);
    }

    free(qr_code);

    return 0;
}