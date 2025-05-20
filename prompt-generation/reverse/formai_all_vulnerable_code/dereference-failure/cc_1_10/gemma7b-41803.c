//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 100;
    double **arr = (double**)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (double*)malloc(n * sizeof(double));
    }

    // Generate random numbers into the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() / (double)RAND_MAX;
        }
    }

    // Calculate the mean and standard deviation of each row
    for (int i = 0; i < n; i++)
    {
        double mean = 0.0;
        double stddev = 0.0;
        for (int j = 0; j < n; j++)
        {
            mean += arr[i][j];
        }
        mean /= n;

        for (int j = 0; j < n; j++)
        {
            stddev += pow(arr[i][j] - mean, 2.0);
        }
        stddev = sqrt(stddev / n);

        // Print the mean and standard deviation of each row
        printf("Row %d: Mean = %.2f, Standard Deviation = %.2f\n", i + 1, mean, stddev);
    }

    // Free the memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}