//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to implement bucket sort
void bucket_sort(double arr[], int n)
{
    // Create buckets based on integer division
    int num_buckets = 10;
    double max_val = arr[0];
    double min_val = arr[0];
    int i, j, k;
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    double bucket_range = (max_val - min_val) / num_buckets;
    double* buckets[num_buckets];
    for (i = 0; i < num_buckets; i++) {
        buckets[i] = malloc(n * sizeof(double));
    }

    // Distribute array values to buckets
    for (i = 0; i < n; i++) {
        int bucket_index = floor((arr[i] - min_val) / bucket_range);
        int bucket_size = 0;
        for (j = 0; j < n; j++) {
            if (buckets[bucket_index][j] == 0) {
                bucket_size = j;
                break;
            }
        }
        buckets[bucket_index][bucket_size] = arr[i];
    }

    // Sort buckets using insertion sort
    for (i = 0; i < num_buckets; i++) {
        for (j = 1; j < n; j++) {
            double temp = buckets[i][j];
            for (k = j - 1; k >= 0 && temp < buckets[i][k]; k--) {
                buckets[i][k + 1] = buckets[i][k];
                buckets[i][k] = temp;
            }
        }
    }

    // Merge buckets back into original array
    int index = 0;
    for (i = 0; i < num_buckets; i++) {
        for (j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[index] = buckets[i][j];
                index++;
            }
        }
        free(buckets[i]);
    }
}

// Driver code
int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    double arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%lf ", arr[i]);
    }

    return 0;
}