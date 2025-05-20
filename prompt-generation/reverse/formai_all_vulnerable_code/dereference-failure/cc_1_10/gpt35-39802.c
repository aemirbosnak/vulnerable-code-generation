//FormAI DATASET v1.0 Category: Data mining ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random float values
float randomFloat() {
    float randNum = (float)rand() / (float)RAND_MAX;
    return randNum;
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Declare variables
    int numInstances, numAttributes, i, j;
    float **data;
    float *minVals;
    float *maxVals;
    
    // Prompt the user for the number of instances and attributes
    printf("Enter the number of instances: ");
    scanf("%d", &numInstances);
    printf("Enter the number of attributes: ");
    scanf("%d", &numAttributes);
    
    // Allocate memory for the data array
    data = (float**)malloc(numInstances * sizeof(float*));
    for (i = 0; i < numInstances; i++) {
        data[i] = (float*)malloc(numAttributes * sizeof(float));
    }
    
    // Generate random data values and store them in the data array
    for (i = 0; i < numInstances; i++) {
        for (j = 0; j < numAttributes; j++) {
            data[i][j] = randomFloat();
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }
    
    // Allocate memory for the minVals and maxVals arrays
    minVals = (float*)malloc(numAttributes * sizeof(float));
    maxVals = (float*)malloc(numAttributes * sizeof(float));
    
    // Initialize the minVals and maxVals arrays with the first instance of data
    for (i = 0; i < numAttributes; i++) {
        minVals[i] = data[0][i];
        maxVals[i] = data[0][i];
    }
    
    // Iterate through the data, finding the minimum and maximum value for each attribute
    for (i = 0; i < numInstances; i++) {
        for (j = 0; j < numAttributes; j++) {
            if (data[i][j] < minVals[j]) {
                minVals[j] = data[i][j];
            }
            if (data[i][j] > maxVals[j]) {
                maxVals[j] = data[i][j];
            }
        }
    }
    
    // Print the minimum and maximum values for each attribute
    printf("\nMinimum and maximum values for each attribute:\n");
    for (i = 0; i < numAttributes; i++) {
        printf("Attribute %d: min=%.2f max=%.2f\n", i+1, minVals[i], maxVals[i]);
    }
    
    // Free the memory allocated for the data, minVals, and maxVals arrays
    for (i = 0; i < numInstances; i++) {
        free(data[i]);
    }
    free(data);
    free(minVals);
    free(maxVals);
    
    return 0;
}