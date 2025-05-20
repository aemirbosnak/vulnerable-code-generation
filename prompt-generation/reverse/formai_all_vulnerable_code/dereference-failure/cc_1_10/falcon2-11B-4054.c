//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int size;
    int max_value;
} Bucket;

void init_bucket(Bucket* bucket, int* arr, int size) {
    bucket->arr = malloc(size * sizeof(int));
    bucket->size = size;
    bucket->max_value = arr[size-1];
    
    for (int i = 0; i < size; i++) {
        bucket->arr[i] = arr[i];
    }
}

void free_bucket(Bucket* bucket) {
    free(bucket->arr);
}

void bucket_sort(Bucket* bucket, int* arr) {
    for (int i = 0; i < bucket->size; i++) {
        int* sorted_arr = malloc(bucket->size * sizeof(int));
        int* current_arr = bucket->arr;
        int* end_arr = bucket->arr + bucket->size;
        
        while (current_arr < end_arr) {
            int* next_bucket = current_arr + bucket->max_value;
            
            for (int j = 0; j < bucket->size; j++) {
                if (*current_arr < *next_bucket) {
                    int temp = *current_arr;
                    *current_arr = *next_bucket;
                    *next_bucket = temp;
                    
                    current_arr++;
                } else {
                    current_arr++;
                    next_bucket++;
                }
            }
            
            if (current_arr >= end_arr) {
                break;
            }
        }
        
        for (int j = 0; j < bucket->size; j++) {
            arr[i+j] = sorted_arr[j];
        }
        
        free(sorted_arr);
    }
}

int main() {
    int arr[] = {5, 2, 7, 1, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    Bucket bucket;
    
    init_bucket(&bucket, arr, size);
    bucket_sort(&bucket, arr);
    
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    free_bucket(&bucket);
    
    return 0;
}