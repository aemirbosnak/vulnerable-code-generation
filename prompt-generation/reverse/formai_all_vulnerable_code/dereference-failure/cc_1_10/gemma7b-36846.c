//Gemma-7B DATASET v1.0 Category: Data mining ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    float a, b, c, d, e, f, g, h, i_1, i_2, i_3, j_1, j_2, j_3;
    char ch, e_1, e_2, f_1, f_2, g_1, h_1, h_2, h_3;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the number of data points: ");
    scanf("%d", &m);

    // Allocate memory for the data matrix
    float **data = (float**)malloc(m * sizeof(float *));
    for (i = 0; i < m; i++)
    {
        data[i] = (float*)malloc(n * sizeof(float));
    }

    // Get the data
    printf("Enter the data: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &data[i][j]);
        }
    }

    // Calculate the mean of each variable
    for (i = 0; i < n; i++)
    {
        i_1 = 0.0f;
        for (j = 0; j < m; j++)
        {
            i_1 += data[j][i];
        }
        i_2 = i_1 / m;
        printf("The mean of variable %d is: %.2f\n", i, i_2);
    }

    // Calculate the standard deviation of each variable
    for (i = 0; i < n; i++)
    {
        i_1 = 0.0f;
        for (j = 0; j < m; j++)
        {
            i_1 += (data[j][i] - i_2) * (data[j][i] - i_2);
        }
        i_3 = sqrtf(i_1 / m);
        printf("The standard deviation of variable %d is: %.2f\n", i, i_3);
    }

    // Free the memory
    for (i = 0; i < m; i++)
    {
        free(data[i]);
    }
    free(data);

    return 0;
}