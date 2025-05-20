//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_RANGE 100000

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int *bucket[MAX_SIZE];
    int range = MAX_RANGE / n;

    for (i = 0; i < n; i++) {
        bucket[arr[i] / range] = &arr[i];
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (bucket[j]!= NULL) {
                if (arr[i] == *bucket[j]) {
                    k = *bucket[j];
                    *bucket[j] = arr[i];
                    arr[i] = k;
                    break;
                }
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
    int i, n;
    int arr[MAX_SIZE];

    srand(time(NULL));

    printf("Enter size of array (<= %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}