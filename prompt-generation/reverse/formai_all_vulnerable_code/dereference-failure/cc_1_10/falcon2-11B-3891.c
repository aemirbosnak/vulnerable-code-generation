//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>

// Bucket sort implementation

void bucketSort(int arr[], int n)
{
    // Sorting array
    int *buckets = (int *)malloc(n * sizeof(int));
    int *temp = (int *)malloc(n * sizeof(int));

    // Dividing the array into buckets
    for (int i = 0; i < n; i++)
        buckets[arr[i] % n] = arr[i];

    // Sorting each bucket
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            for (int k = j + 1; k < buckets[i] + buckets[i]; k++) {
                if (temp[k] < temp[j]) {
                    int t = temp[j];
                    temp[j] = temp[k];
                    temp[k] = t;
                }
            }
        }
    }

    // Reassigning the sorted array
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

// Function to print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);
    printf("Sorted array is:\n");
    printArray(arr, n);

    return 0;
}