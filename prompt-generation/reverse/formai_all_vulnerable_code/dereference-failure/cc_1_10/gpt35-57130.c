//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUTS 1000
#define MAX_ATTRIBUTES 100

int main() {
    int numInputs, numAttributes;
    printf("How many inputs? ");
    scanf("%d", &numInputs);
    printf("How many attributes per input? ");
    scanf("%d", &numAttributes);

    // Allocate memory for the inputs
    float **inputs = (float **) malloc(numInputs * sizeof(float *));
    for (int i = 0; i < numInputs; i++) {
        inputs[i] = (float *) malloc(numAttributes * sizeof(float));
    }

    // Get the inputs from the user
    printf("Enter the inputs:\n");
    for (int i = 0; i < numInputs; i++) {
        printf("Input %d: ", i+1);
        for (int j = 0; j < numAttributes; j++) {
            scanf("%f", &inputs[i][j]);
        }
    }

    // Perform data mining
    float means[MAX_ATTRIBUTES];
    float variances[MAX_ATTRIBUTES];
    for (int i = 0; i < numAttributes; i++) {
        float sum = 0;
        for (int j = 0; j < numInputs; j++) {
            sum += inputs[j][i];
        }
        means[i] = sum / numInputs;

        float variance = 0;
        for (int j = 0; j < numInputs; j++) {
            variance += (inputs[j][i] - means[i]) * (inputs[j][i] - means[i]);
        }
        variances[i] = variance / numInputs;
    }

    // Print the results
    printf("Results:\n");
    for (int i = 0; i < numAttributes; i++) {
        printf("Attribute %d mean: %f\n", i+1, means[i]);
        printf("Attribute %d variance: %f\n", i+1, variances[i]);
    }

    // Free allocated memory
    for (int i = 0; i < numInputs; i++) {
        free(inputs[i]);
    }
    free(inputs);

    return 0;
}