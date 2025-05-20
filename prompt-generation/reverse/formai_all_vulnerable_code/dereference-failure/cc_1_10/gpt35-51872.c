//FormAI DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int leftLen, int right[], int rightLen) {
    int i = 0, j = 0, k = 0;

    while (i < leftLen && j < rightLen) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftLen) {
        arr[k++] = left[i++];
    }

    while (j < rightLen) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int len) {
    if (len <= 1) {
        return;
    }

    int mid = len / 2;
    int *left = (int *) malloc(mid * sizeof(int));
    int *right = (int *) malloc((len - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < len; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, len - mid);
    merge(arr, left, mid, right, len - mid);

    free(left);
    free(right);
}

int main() {
    int arr[] = {5, 8, 3, 6, 9, 2, 1, 7, 4};
    int len = sizeof(arr) / sizeof(int);

    mergeSort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}