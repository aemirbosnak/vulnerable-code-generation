//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 10000000

void sort(int *arr, int size) {
    int temp;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(*(arr+j) < *(arr+i)) {
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }   
}

int binary_search(int *arr, int left, int right, int target) {
    int mid;

    while(left <= right) {
        mid = (left+right)/2;

        if(*(arr+mid) == target) {
            return mid;
        }
        else if(*(arr+mid) < target) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }

    return -1;
}

int main() {
    srand(time(NULL));
    int *arr = malloc(ARRAY_SIZE*sizeof(int));
    clock_t start, end;
    double duration;

    // Fill array with random values
    for(int i=0; i<ARRAY_SIZE; i++) {
        *(arr+i) = rand()%100 + 1;
    }

    // Sort array for binary search
    sort(arr, ARRAY_SIZE);

    // Perform binary search on random target
    int target = rand()%100 + 1;
    start = clock();
    int index = binary_search(arr, 0, ARRAY_SIZE-1, target);
    end = clock();
    duration = (double)(end - start)/CLOCKS_PER_SEC;

    // Output results
    if(index >= 0) {
        printf("Target value %d found at index %d\n", target, index);
    }
    else {
        printf("Target value %d not found\n", target);
    }
    printf("Binary search took %lf seconds\n", duration);

    free(arr);
    return 0;
}