//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int n) {
    int max_val = array[0];
    int min_val = array[0];
    int range;
    int *buckets = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
        if (array[i] < min_val) {
            min_val = array[i];
        }
    }
    range = max_val - min_val + 1;
    int bucket_size = range / n;
    for (int i = 0; i < n; i++) {
        buckets[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int bucket_index = (array[i] - min_val) / bucket_size;
        buckets[bucket_index]++;
    }
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < buckets[i]) {
            array[i * n + j] = i * n + j;
            j++;
        }
    }
    free(buckets);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    bucket_sort(array, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}