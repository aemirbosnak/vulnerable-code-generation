//FormAI DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void log_analysis(int n, double arr[])
{
    double sum = 0, variance = 0;

    // Finding the mean of the logarithmic values
    for (int i = 0; i < n; i++) {
        arr[i] = log(arr[i]);
        sum += arr[i];
    }
    double mean = sum / n;

    // Finding the variance of the logarithmic values
    for (int i = 0; i < n; i++) {
        double diff = arr[i] - mean;
        variance += diff * diff;
    }
    variance /= n;

    // Finding the standard deviation of the logarithmic values
    double std_deviation = sqrt(variance);

    // Finding the skewness of the logarithmic values
    double skewness = 0;
    for (int i = 0; i < n; i++) {
        skewness += pow((arr[i] - mean) / std_deviation, 3);
    }
    skewness /= n;

    // Outputting the statistical analysis of the logarithmic values
    printf("Statistical Analysis of Logarithmic Values:\n");
    printf("Mean: %lf\n", mean);
    printf("Variance: %lf\n", variance);
    printf("Standard Deviation: %lf\n", std_deviation);
    printf("Skewness: %lf\n", skewness);
}

int main()
{
    int n;
    printf("Enter the number of values: ");
    scanf("%d", &n);

    double arr[n];
    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    log_analysis(n, arr);

    return 0;
}