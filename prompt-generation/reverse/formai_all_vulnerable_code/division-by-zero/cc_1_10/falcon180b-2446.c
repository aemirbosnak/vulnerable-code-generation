//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
} Bucket;

void createBucket(Bucket *b, int size) {
    b->arr = (int *) malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = -1;
    }
}

void insert(Bucket *b, int x) {
    int index = x / b->size;
    if (b->arr[index] == -1) {
        b->arr[index] = x;
    } else {
        printf("Bucket is full\n");
    }
}

void sort(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max / n;
    Bucket *b = (Bucket *) malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        createBucket(&b[i], range);
    }

    for (int i = 0; i < n; i++) {
        insert(&b[arr[i] / range], arr[i]);
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (b[i].arr[0]!= -1) {
            arr[j++] = b[i].arr[0];
            while (b[i].arr[0]!= -1) {
                b[i].arr[0] = -1;
                insert(&b[arr[j - 1] / range], arr[j - 1]);
                j++;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}