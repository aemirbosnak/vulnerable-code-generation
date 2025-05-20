//FormAI DATASET v1.0 Category: Data mining ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void read_data(int n, int m, float data[][m])
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        printf("Enter data for record %d: ", i+1);
        for(j = 0; j < m; j++)
        {
            scanf("%f", &data[i][j]);
        }
    }
}

void normalize_data(int n, int m, float data[][m])
{
    int i, j;
    float sum, mean, std_dev;
    for(j = 0; j < m; j++)
    {
        sum = 0.0;
        for(i = 0; i < n; i++)
        {
            sum += data[i][j];
        }
        mean = sum / n;
        sum = 0.0;
        for(i = 0; i < n; i++)
        {
            sum += pow(data[i][j] - mean, 2);
        }
        std_dev = sqrt(sum / n);
        for(i = 0; i < n; i++)
        {
            data[i][j] = (data[i][j] - mean) / std_dev;
        }
    }
}

int main()
{
    int n, m;
    printf("Enter number of records: ");
    scanf("%d", &n);
    printf("Enter number of attributes: ");
    scanf("%d", &m);
    float data[n][m];
    read_data(n, m, data);
    normalize_data(n, m, data);
    int i, j;
    for(i = 0; i < n; i++)
    {
        printf("Normalized values for record %d: ", i+1);
        for(j = 0; j < m; j++)
        {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}