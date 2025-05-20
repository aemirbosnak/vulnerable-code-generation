//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

int compare(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if(x > y)
        return 1;
    else if(x < y)
        return -1;
    else
        return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucket_sort(int arr[], int size) {
    int range = MAX_RANGE / size;
    int *buckets[MAX_SIZE];
    for(int i=0; i<MAX_SIZE; i++) {
        buckets[i] = (int*)malloc(size * sizeof(int));
    }
    for(int i=0; i<size; i++) {
        buckets[arr[i] / range][i % size] = arr[i];
    }
    for(int i=0; i<size; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            if(buckets[j][i]!= 0) {
                arr[i] = buckets[j][i];
                break;
            }
        }
    }
    for(int i=0; i<MAX_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    clock_t start_time = clock();
    bucket_sort(arr, size);
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorted array:\n");
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %.6f seconds\n", time_taken);
    return 0;
}