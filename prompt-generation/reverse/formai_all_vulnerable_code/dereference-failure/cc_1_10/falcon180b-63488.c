//Falcon-180B DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    double x[100], y[100], t[100];
    int n, m;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the time values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &t[i]);
    }

    printf("Enter the data values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    printf("Enter the desired sampling rate:\n");
    scanf("%d", &m);

    int k = n / m;

    double* xp = (double*)malloc(sizeof(double) * m);
    double* yp = (double*)malloc(sizeof(double) * m);

    for (int i = 0; i < m; i++)
    {
        double tp = i * (t[k] - t[0]) / (k - 1) + t[0];
        double xp_val = 0;
        double yp_val = 0;

        for (int j = 0; j < n; j++)
        {
            if (t[j] <= tp && t[j+1] > tp)
            {
                double alpha = (t[j+1] - tp) / (t[j+1] - t[j]);
                xp_val += alpha * x[j] + (1 - alpha) * x[j+1];
                yp_val += alpha * y[j] + (1 - alpha) * y[j+1];
            }
        }

        xp[i] = xp_val;
        yp[i] = yp_val;
    }

    printf("The resampled data points are:\n");
    for (int i = 0; i < m; i++)
    {
        printf("%lf ", xp[i]);
    }

    return 0;
}