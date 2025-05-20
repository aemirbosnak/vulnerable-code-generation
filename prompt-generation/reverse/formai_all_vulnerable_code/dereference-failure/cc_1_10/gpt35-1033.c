//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUCKET_SIZE 10  

void bucket_sort(int *, const int);

int main() {
    int i, array_size;
    int *array;
    printf("Enter the size of the array: ");
    scanf("%d",&array_size);
    array = (int*)malloc(array_size * sizeof(int));
    srand(time(NULL));
    printf("Original Array: \n[ ");
    for(i = 0; i < array_size; i++) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    printf("]\n");
    bucket_sort(array, array_size);
    printf("Sorted Array: \n[ ");
    for(i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n");
    return 0;
}

void bucket_sort(int *array, const int array_size) {
    int i, j, k;
    int maxValue = array[0];
    int minValue = array[0];
    for(i = 1; i < array_size; i++) {
        if(array[i] > maxValue) maxValue = array[i];
        if(array[i] < minValue) minValue = array[i];
    }
    
    const int bucket_count = (maxValue - minValue) / BUCKET_SIZE + 1;
    int **buckets = (int **)malloc(sizeof(int*) * bucket_count);
    for(i = 0; i < bucket_count; i++) {
        buckets[i] = (int*)malloc(sizeof(int) * array_size);
    }

    int *bucket_sizes = (int*)malloc(sizeof(int) * bucket_count);
    for(i = 0; i < bucket_count; i++) {
        bucket_sizes[i] = 0;
    }
    for(i = 0; i < array_size; i++) {
        const int bucket_index = (array[i] - minValue) / BUCKET_SIZE;
        buckets[bucket_index][bucket_sizes[bucket_index]++] = array[i];
    }
    for(i = 0; i < bucket_count; i++) {
        for(j = 0; j < bucket_sizes[i]; j++) {
            for(k = j + 1; k < bucket_sizes[i]; k++) {
                if(buckets[i][j] > buckets[i][k]) {
                    const int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }
    int index = 0;
    for(i = 0; i < bucket_count; i++) {
        for(j = 0; j < bucket_sizes[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    for(i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}