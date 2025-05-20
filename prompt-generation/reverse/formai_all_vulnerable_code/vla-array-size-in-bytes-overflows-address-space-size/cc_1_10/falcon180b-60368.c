//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bucket_sort(int arr[], int n) {
    int i, j, k;
    int *bucket[100];
    for (i = 0; i < 100; i++) {
        bucket[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        k = arr[i] / 10;
        if (bucket[k] == NULL) {
            bucket[k] = (int *) malloc(10 * sizeof(int));
        }
        for (j = 0; j < 10; j++) {
            if (bucket[k][j] == 0) {
                bucket[k][j] = arr[i];
                break;
            }
        }
    }
    for (i = 0; i < 100; i++) {
        if (bucket[i]!= NULL) {
            for (j = 0; j < 10; j++) {
                arr[j * 100 + i] = bucket[i][j];
            }
        }
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}