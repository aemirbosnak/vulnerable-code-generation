//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_VALUE 1000000

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int n) {
    int i, j, count[MAX_VALUE] = {0};
    int* buckets[MAX_VALUE];
    for (i = 0; i < MAX_VALUE; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        count[(arr[i] - 1) / 10000]++;
    }
    for (i = 0; i < MAX_VALUE; i++) {
        for (j = 0; j < count[i]; j++) {
            buckets[i][j] = rand_int(i * 10000, (i + 1) * 10000 - 1);
        }
    }
    for (i = 0; i < n; i++) {
        int index = (arr[i] - 1) / 10000;
        int j;
        for (j = 0; j < count[index]; j++) {
            if (arr[i] == buckets[index][j]) {
                break;
            }
        }
        if (j == count[index]) {
            printf("Error: Element not found in bucket!\n");
            exit(0);
        }
        swap(&arr[i], &buckets[index][j]);
    }
    for (i = 0; i < MAX_VALUE; i++) {
        free(buckets[i]);
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
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}