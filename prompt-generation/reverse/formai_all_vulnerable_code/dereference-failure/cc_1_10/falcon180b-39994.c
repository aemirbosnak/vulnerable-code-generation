//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the number of terms to generate
#define NUM_TERMS 5000

// Define the maximum value for the terms
#define MAX_VALUE 1000000

// Define the minimum value for the terms
#define MIN_VALUE 1

// Define the function to generate a random value
double generateRandomValue(void) {
    return (rand() % MAX_VALUE) + MIN_VALUE;
}

// Define the function to calculate the sum of the terms
double calculateSum(double *terms, int numTerms) {
    double sum = 0;
    for (int i = 0; i < numTerms; i++) {
        sum += terms[i];
    }
    return sum;
}

// Define the function to calculate the average of the terms
double calculateAverage(double *terms, int numTerms) {
    return calculateSum(terms, numTerms) / numTerms;
}

// Define the function to calculate the standard deviation of the terms
double calculateStandardDeviation(double *terms, int numTerms) {
    double sum = 0;
    double average = calculateAverage(terms, numTerms);
    for (int i = 0; i < numTerms; i++) {
        sum += pow((terms[i] - average), 2);
    }
    return sqrt(sum / numTerms);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Allocate memory for the terms
    double *terms = malloc(NUM_TERMS * sizeof(double));

    // Generate the terms
    for (int i = 0; i < NUM_TERMS; i++) {
        terms[i] = generateRandomValue();
    }

    // Calculate the sum, average, and standard deviation of the terms
    double sum = calculateSum(terms, NUM_TERMS);
    double average = calculateAverage(terms, NUM_TERMS);
    double standardDeviation = calculateStandardDeviation(terms, NUM_TERMS);

    // Print the results
    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", average);
    printf("Standard Deviation: %.2f\n", standardDeviation);

    // Free the memory allocated for the terms
    free(terms);

    return 0;
}