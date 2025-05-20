//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void reshape(int **arr, int n, int m)
{
    int i, j, k = 0;
    int **new_arr = (int **)malloc(n * m * sizeof(int));
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            new_arr[i][j] = arr[k];
            k++;
        }
    }
    free(arr);
    arr = new_arr;
}

int main()
{
    int **qr_code = (int **)malloc(MAX * MAX * sizeof(int));
    qr_code[0][0] = 1;
    qr_code[1][0] = 1;
    qr_code[1][1] = 1;
    qr_code[2][1] = 1;
    qr_code[2][2] = 1;

    reshape(qr_code, MAX, MAX);

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(qr_code[i][j] == 1)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    free(qr_code);

    return 0;
}