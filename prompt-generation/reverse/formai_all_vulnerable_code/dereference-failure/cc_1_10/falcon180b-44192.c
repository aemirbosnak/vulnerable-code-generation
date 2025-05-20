//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 100

void bucket_sort(int arr[], int n) {
    int i, j, k, max, min, range;
    int *bucket[MAX_SIZE];

    for (i = 0; i < n; i++) {
        bucket[arr[i] / 10] = (int *)malloc(sizeof(int) * (++bucket[arr[i] / 10][0]));
        bucket[arr[i] / 10][0] = 1;
        bucket[arr[i] / 10][bucket[arr[i] / 10][0] - 1] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = bucket[arr[i] / 10][0] - 1;
    }

    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]) {
            free(bucket[i]);
        }
    }
}

int main() {
    int i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        int rand_index = rand() % n;
        int temp = arr[i];
        arr[i] = arr[rand_index];
        arr[rand_index] = temp;
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}