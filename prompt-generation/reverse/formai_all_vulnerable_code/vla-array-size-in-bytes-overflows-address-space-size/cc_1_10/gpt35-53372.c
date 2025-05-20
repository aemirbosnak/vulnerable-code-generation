//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int arr[], int size) {
    int max_val = arr[0];
    int min_val = arr[0];

    for(int i=1; i<size; i++) {
        if(arr[i] > max_val) {
            max_val = arr[i];
        }
        if(arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int bucket_size = max_val/10 - min_val/10 + 1;
    int **buckets = (int **) malloc(bucket_size * sizeof(int *));

    for(int i=0; i<bucket_size; i++) {
        buckets[i] = (int *) malloc(size * sizeof(int));
        for(int j=0; j<size; j++) {
            buckets[i][j] = -1;
        }
    }

    int *bucket_sizes = (int *) malloc(bucket_size * sizeof(int));

    for(int i=0; i<bucket_size; i++) {
        bucket_sizes[i] = 0;
    }

    for(int i=0; i<size; i++) {
        int bucket_index = (arr[i]/10) - (min_val/10);
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }

    for(int i=0; i<bucket_size; i++) {
        printf("Bucket %d: ", i);
        print_array(buckets[i], bucket_sizes[i]);
    }

    int index = 0;
    for(int i=0; i<bucket_size; i++) {
        for(int j=0; j<bucket_sizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    for(int i=0; i<bucket_size; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
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

    printf("Before sorting: ");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("After sorting: ");
    print_array(arr, size);

    return 0;
}