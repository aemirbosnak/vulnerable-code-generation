//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

// Function for swapping two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function for sorting an array using bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// Function for finding the median of an array
double findMedian(int arr[], int n) {
    bubbleSort(arr, n);
    int middleIndex = n/2;
    if (n % 2 == 0) {
        return (arr[middleIndex-1] + arr[middleIndex]) / 2.0;
    } else {
        return arr[middleIndex];
    }
}

// Function for finding the mode of an array
int findMode(int arr[], int n) {
    int maxCount = 0, mode = arr[0];
    int count[256] = {0};
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
            mode = arr[i];
        }
    }
    return mode;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int mode = findMode(arr, n);
    double median = findMedian(arr, n);

    printf("Mode: %d\n", mode);
    printf("Median: %.2lf\n", median);

    return 0;
}