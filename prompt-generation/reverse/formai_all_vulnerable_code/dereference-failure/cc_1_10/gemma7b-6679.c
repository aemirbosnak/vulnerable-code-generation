//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qr_read(char **data, int x, int y)
{
    int i, j, bit, sum = 0, module = 0;
    char **matrix = (char **)malloc(x * sizeof(char *) + 1);
    for (i = 0; i < x; i++)
    {
        matrix[i] = (char *)malloc(y * sizeof(char) + 1);
        for (j = 0; j < y; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Read data from QR code
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            scanf("%c", &matrix[i][j]);
        }
    }

    // Calculate module and sum
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            module = (matrix[i][j] - 1) / 3;
            sum += module;
        }
    }

    // Check if sum is even
    if (sum % 2 == 0)
    {
        *data = (char *)malloc(x * y * sizeof(char) + 1);
        for (i = 0; i < x; i++)
        {
            for (j = 0; j < y; j++)
            {
                matrix[i][j] = 0;
            }
        }

        // Decode data
        for (i = 0; i < x; i++)
        {
            for (j = 0; j < y; j++)
            {
                bit = matrix[i][j] % 2;
                (*data)[i * y + j] = bit;
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *data = NULL;
    qr_read(&data, 5, 5);

    // Print data
    printf("%s", data);

    return 0;
}