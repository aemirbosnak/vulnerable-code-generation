//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max, min, range, count[MAX_SIZE] = {0};
    int bucket[MAX_SIZE] = {0};
    int sorted_arr[n];

    max = arr[0];
    min = arr[0];

    for (i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;

    for (i = 0; i < n; i++) {
        count[(arr[i] - min) / range]++;
    }

    for (i = 1; i < MAX_SIZE; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        sorted_arr[count[(arr[i] - min) / range] - 1] = arr[i];
        count[(arr[i] - min) / range]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }
}

int main() {
    int i, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}