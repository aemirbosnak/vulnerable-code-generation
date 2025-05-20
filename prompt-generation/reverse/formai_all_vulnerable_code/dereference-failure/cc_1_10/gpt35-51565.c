//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int size) {
    // find the max value in the array
    int max_val = array[0];
    for(int i = 0; i < size; i++) {
        if(array[i] > max_val)
            max_val = array[i];
    }
    
    // allocate memory for the buckets
    int *buckets = calloc(max_val + 1, sizeof(int));
    
    // count the number of occurrences of each value in the array
    for(int i = 0; i < size; i++) {
        buckets[array[i]]++;
    }
    
    // sort the array by placing values from the buckets back into the array
    int index = 0;
    for(int i = 0; i <= max_val; i++) {
        for(int j = 0; j < buckets[i]; j++) {
            array[index++] = i;
        }
    }
    
    // free up the memory from the buckets
    free(buckets);
}

// print the contents of an array
void print_array(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int test_array[] = {9, 5, 8, 2, 1, 4, 7, 3, 6, 0};
    int size = sizeof(test_array)/sizeof(test_array[0]);
    
    printf("Before sorting:\n");
    print_array(test_array, size);
    
    bucket_sort(test_array, size);
    
    printf("After sorting:\n");
    print_array(test_array, size);
    
    return 0;
}