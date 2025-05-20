//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to create buckets
void bucketSort(float arr[], int n) {
    // Number of buckets
    int bucketCount = 10;
    
    // Create an array of buckets
    float **buckets = malloc(bucketCount * sizeof(float *));
    int *bucketSizes = malloc(bucketCount * sizeof(int));
    
    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = malloc(n * sizeof(float)); // Maximum size of bucket
        bucketSizes[i] = 0;
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * bucketCount);
        if (bucketIndex >= bucketCount) {
            bucketIndex = bucketCount - 1; // Handle case where arr[i] is 1
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and gather results
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        // Sort each individual bucket using a simple insertion sort
        for (int j = 1; j < bucketSizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;

            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }

        // Collect sorted bucket elements into original array
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free bucket arrays
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Function to display array elements
void displayArray(float arr[], int n) {
    printf("Sorted Array: [ ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("]\n");
}

// Main function
int main() {
    int n;
    printf("Welcome to the Bucket Sort Program!\n");
    
    // Let's show gratitude for the numbers we're about to sort
    printf("How many floating-point numbers do you want to sort? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Please enter a valid positive integer.\n");
        return 1;
    }

    float *arr = malloc(n * sizeof(float));

    // Populate the array with gratitude for the random numbers
    printf("Please enter %d floating-point numbers (0.0 to 1.0):\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%f", &arr[i]) != 1 || arr[i] < 0.0 || arr[i] > 1.0) {
            fprintf(stderr, "Please enter valid floating-point numbers between 0.0 and 1.0.\n");
            free(arr);
            return 1;
        }
    }

    // Thank the user for their kind input
    printf("Thank you for providing the numbers!\n");

    // Sorting the array
    bucketSort(arr, n);

    // Display the sorted results
    displayArray(arr, n);

    // Free the allocated memory for the array
    free(arr);

    // A final note of gratitude for running this program
    printf("Thank you for using the Bucket Sort Program! Have a great day!\n");
    return 0;
}