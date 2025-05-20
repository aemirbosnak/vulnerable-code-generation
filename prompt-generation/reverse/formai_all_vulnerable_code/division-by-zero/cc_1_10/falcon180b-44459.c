//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

/* Function to generate random integers between min and max */
int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void createArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = randInt(1, 100);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = max / n;
    int *bucket[n];

    for (int i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * (max / bucketSize + 1));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max / bucketSize; j++) {
            bucket[j][i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int index = arr[i] / bucketSize;
        bucket[index][arr[i] % bucketSize]++;
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max / bucketSize; j++) {
            while (bucket[j][i]-- > 0) {
                arr[k++] = j * bucketSize + i;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    createArray(arr, n);
    printf("Before sorting:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("After sorting:\n");
    printArray(arr, n);

    return 0;
}