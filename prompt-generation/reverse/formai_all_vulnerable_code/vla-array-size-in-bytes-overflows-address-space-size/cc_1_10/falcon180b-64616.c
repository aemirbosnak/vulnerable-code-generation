//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, k, max, min;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        max = arr[i];
        min = arr[i];
        k = i * MAX_SIZE / n;

        for (j = i + 1; j < n; j++) {
            if (arr[j] > max) {
                max = arr[j];
            }
            if (arr[j] < min) {
                min = arr[j];
            }
        }

        for (j = 0; j < n; j++) {
            if (arr[j] >= min && arr[j] <= max) {
                bucket[k][j] = arr[j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (bucket[j][i]!= 0) {
                arr[i] = bucket[j][i];
                break;
            }
        }
    }
}

void generate_random_array(int arr[], int n) {
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

int main() {
    int n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    generate_random_array(arr, n);

    printf("Before sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}