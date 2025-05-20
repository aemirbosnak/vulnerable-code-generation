//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* Generate random numbers */
void generateData(double* inputData, int numPoints) {

    int i;
    for (i = 0; i < numPoints; i++) {
        inputData[i] = ((double) rand() / (RAND_MAX)) * 10;
    }
}

/* Calculate the mean of a set of data */
double calculateMean(double* inputData, int numPoints) {

    int i;
    double sum = 0.0;

    for (i = 0; i < numPoints; i++) {
        sum += inputData[i];
    }

    return sum / numPoints;
}

/* Calculate the variance of a set of data */
double calculateVariance(double* inputData, int numPoints) {

    int i;
    double mean = calculateMean(inputData, numPoints);
    double variance = 0.0;

    for (i = 0; i < numPoints; i++) {
        variance += (inputData[i] - mean) * (inputData[i] - mean);
    }

    return variance / numPoints;
}

/* Find the maximum value in a set of data */
double findMax(double* inputData, int numPoints) {

    int i;
    double maxVal = inputData[0];

    for (i = 1; i < numPoints; i++) {
        if (inputData[i] > maxVal) {
            maxVal = inputData[i];
        }
    }

    return maxVal;
}

/* Find the minimum value in a set of data */
double findMin(double* inputData, int numPoints) {

    int i;
    double minVal = inputData[0];

    for (i = 1; i < numPoints; i++) {
        if (inputData[i] < minVal) {
            minVal = inputData[i];
        }
    }

    return minVal;
}

int main() {

    /* Generate some sample data */
    int numPoints = 1000;
    double* inputData = (double*) malloc(numPoints * sizeof(double));
    generateData(inputData, numPoints);

    /* Calculate the mean, variance, maximum, and minimum of the data */
    double mean = calculateMean(inputData, numPoints);
    double variance = calculateVariance(inputData, numPoints);
    double maxVal = findMax(inputData, numPoints);
    double minVal = findMin(inputData, numPoints);

    /* Print the results */
    printf("Sample data:\n");
    int i;
    for (i = 0; i < numPoints; i++) {
        printf("%f ", inputData[i]);
    }

    printf("\n\n");
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    printf("Maximum value: %f\n", maxVal);
    printf("Minimum value: %f\n", minVal);

    /* Clean up memory */
    free(inputData);

    return 0;
}