//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 5000000;
    int *arr = malloc(size * sizeof(int));  // allocating memory dynamically for array
    clock_t start, end;
    double cpu_time_used;

    // assigning random values to array elements
    for(int i=0; i<size; i++) {
        arr[i] = rand()%size;
    }

    // bubble sort algorithm
    start = clock();
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; i++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Bubble Sort: %lf\n",cpu_time_used);

    // selection sort algorithm
    start = clock();
    for(int i=0; i<size-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j]<arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Selection Sort: %lf\n",cpu_time_used);

    // merge sort algorithm
    void merge(int *arr, int left, int mid, int right);
    void mergeSort(int *arr, int left, int right);
    start = clock();
    mergeSort(arr, 0, size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Merge Sort: %lf\n",cpu_time_used);

    // freeing allocated memory
    free(arr);

    return 0;
}

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right) {
    if(left<right){
        int mid = left+(right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}