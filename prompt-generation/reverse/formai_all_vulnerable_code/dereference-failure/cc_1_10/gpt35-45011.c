//FormAI DATASET v1.0 Category: Benchmarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
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

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;

        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));
    
    printf("Benchmarking...\n\n");
    
    for (int n = 10; n <= 1000000; n *= 10) {
        int* arr1 = malloc(n * sizeof(int));
        int* arr2 = malloc(n * sizeof(int));

        // initialize arrays with random values
        for (int i = 0; i < n; i++) {
            arr1[i] = rand();
            arr2[i] = arr1[i];
        }
        
        // benchmark insertion sort
        clock_t start1 = clock();
        insertion_sort(arr1, n);
        clock_t end1 = clock();
        double time1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
        
        // benchmark merge sort
        clock_t start2 = clock();
        merge_sort(arr2, 0, n-1);
        clock_t end2 = clock();
        double time2 = (double) (end2 - start2) / CLOCKS_PER_SEC;

        printf("Array size: %d\n", n);
        printf("Insertion sort time: %lf seconds\n", time1);
        printf("Merge sort time: %lf seconds\n\n", time2);
        
        free(arr1);
        free(arr2);
    }

    return 0;
}