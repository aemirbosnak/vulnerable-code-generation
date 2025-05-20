//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max = 0;
    int bucket[MAX_SIZE] = {0};

    // Find the maximum element in the array
    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the range of the array
    int range = max / n;

    // Place the elements in the appropriate bucket
    for (i = 0; i < n; i++) {
        j = arr[i] / range;
        bucket[j]++;
    }

    // Place the elements in the final sorted array
    int index = 0;
    for (i = 0; i < n; i++) {
        j = arr[i] / range;
        for (int k = 0; k < bucket[j]; k++) {
            arr[index++] = i;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}