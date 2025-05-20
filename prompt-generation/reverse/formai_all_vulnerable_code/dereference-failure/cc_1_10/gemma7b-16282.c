//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define NUM_TESTS 1000

int main()
{
    int i, j, k, test_cases = NUM_TESTS;

    // Allocate memory for test cases
    double **test_data = (double**)malloc(test_cases * sizeof(double*));
    for (i = 0; i < test_cases; i++)
    {
        test_data[i] = (double*)malloc(10 * sizeof(double));
    }

    // Generate random numbers for each test case
    for (i = 0; i < test_cases; i++)
    {
        for (j = 0; j < 10; j++)
        {
            test_data[i][j] = rand() % 1000;
        }
    }

    // Calculate the mean and standard deviation for each test case
    for (i = 0; i < test_cases; i++)
    {
        double mean = 0.0, std_dev = 0.0;
        for (j = 0; j < 10; j++)
        {
            mean += test_data[i][j];
        }
        mean /= 10;
        for (j = 0; j < 10; j++)
        {
            std_dev += (test_data[i][j] - mean) * (test_data[i][j] - mean);
        }
        std_dev /= 10;
        printf("Test Case %d: Mean = %.2lf, Standard Deviation = %.2lf\n", i + 1, mean, std_dev);
    }

    // Free memory
    for (i = 0; i < test_cases; i++)
    {
        free(test_data[i]);
    }
    free(test_data);

    return 0;
}