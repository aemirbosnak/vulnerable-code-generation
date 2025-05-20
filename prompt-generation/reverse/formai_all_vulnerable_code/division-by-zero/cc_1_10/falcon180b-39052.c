//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, index, max_val = arr[0];
    int bucket[MAX_SIZE];
    for (i = 0; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    for (i = 0; i < n; i++) {
        index = arr[i] * MAX_SIZE / max_val;
        if (!bucket[index]) {
            bucket[index] = 1;
        }
        bucket[index]++;
    }
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]) {
            for (j = 0; j < bucket[i]; j++) {
                arr[j * MAX_SIZE / n + i * MAX_SIZE / n] = i * MAX_SIZE / n + 1;
            }
        }
    }
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bucket_sort(arr, n);
    printf("Sorted array: ");
    print_array(arr, n);
    return 0;
}