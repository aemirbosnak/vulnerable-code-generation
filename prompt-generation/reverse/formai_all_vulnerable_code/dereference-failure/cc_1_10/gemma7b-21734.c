//Gemma-7B DATASET v1.0 Category: QR code generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define QR_SIZE 25
#define BORDER 2

int main()
{
    char **qr_code = NULL;
    int i, j, k, l, size, data_len;
    char data[] = "This is a QR code!";

    size = QR_SIZE + 2 * BORDER;
    qr_code = (char**)malloc(size * size * sizeof(char));

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            qr_code[i][j] = 0;
        }
    }

    data_len = strlen(data);
    l = 0;

    for (i = BORDER; i < size - BORDER; i++)
    {
        for (j = BORDER; j < size - BORDER; j++)
        {
            for (k = 0; k < data_len && l < data_len; k++)
            {
                if (data[k] == qr_code[i][j])
                {
                    qr_code[i][j] = 1;
                    l++;
                }
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", qr_code[i][j]);
        }
        printf("\n");
    }

    free(qr_code);

    return 0;
}