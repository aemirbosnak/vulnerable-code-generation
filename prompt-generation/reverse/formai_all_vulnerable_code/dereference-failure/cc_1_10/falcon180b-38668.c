//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 100000
#define RANGE 100

int *create_array(int n) {
    int *arr = (int*) malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        arr[i] = rand()%RANGE;
    }
    return arr;
}

void print_array(int *arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void bucket_sort(int *arr, int n) {
    int *bucket = (int*) malloc(MAX_SIZE*sizeof(int));
    int bucket_size = 0;
    int *sorted_arr = (int*) malloc(n*sizeof(int));
    for(int i=0; i<n; i++) {
        int index = arr[i]/RANGE;
        if(index >= MAX_SIZE) {
            printf("Error: Bucket overflow\n");
            exit(1);
        }
        bucket[index] = arr[i];
        bucket_size++;
    }
    for(int i=0; i<MAX_SIZE; i++) {
        if(bucket[i]!= 0) {
            int *temp = (int*) malloc(bucket_size*sizeof(int));
            int temp_size = 0;
            for(int j=0; j<n; j++) {
                if(arr[j]/RANGE == i) {
                    temp[temp_size++] = arr[j];
                }
            }
            sorted_arr[i] = partition(temp, 0, temp_size-1);
            free(temp);
        }
    }
    for(int i=0; i<n; i++) {
        arr[i] = sorted_arr[arr[i]/RANGE];
    }
    free(sorted_arr);
    free(bucket);
}

int main() {
    srand(time(NULL));
    int n = 10000;
    int *arr = create_array(n);
    print_array(arr, n);
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}