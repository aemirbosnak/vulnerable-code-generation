//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint64_t value;
    uint64_t index;
} Rank;

void insertionSort(Rank *arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        Rank current = arr[i];
        size_t j = i - 1;
        while ((j >= 0) && (current.value < arr[j].value)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void merge(Rank *arr, size_t start, size_t mid, size_t end) {
    size_t size1 = mid - start + 1;
    size_t size2 = end - mid;
    
    Rank *left = (Rank *)malloc(sizeof(Rank) * size1);
    Rank *right = (Rank *)malloc(sizeof(Rank) * size2);
    
    for (size_t i = 0; i < size1; i++) {
        left[i].value = arr[start + i].value;
        left[i].index = arr[start + i].index;
    }
    for (size_t i = 0; i < size2; i++) {
        right[i].value = arr[mid + 1 + i].value;
        right[i].index = arr[mid + 1 + i].index;
    }
    
    size_t i = 0;
    size_t j = 0;
    size_t k = start;
    
    while (i < size1 && j < size2) {
        if (left[i].value <= right[j].value) {
            arr[k].value = left[i].value;
            arr[k].index = left[i].index;
            i++;
        } else {
            arr[k].value = right[j].value;
            arr[k].index = right[j].index;
            j++;
        }
        k++;
    }
    
    while (i < size1) {
        arr[k].value = left[i].value;
        arr[k].index = left[i].index;
        i++;
        k++;
    }
    
    while (j < size2) {
        arr[k].value = right[j].value;
        arr[k].index = right[j].index;
        j++;
        k++;
    }
    
    free(left);
    free(right);
}

void mergeSort(Rank *arr, size_t start, size_t end) {
    if (start == end) {
        return;
    }
    size_t mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main() {
    size_t n;
    scanf("%lu", &n);
    Rank *arr = (Rank *)malloc(sizeof(Rank) * n);
    for (size_t i = 0; i < n; i++) {
        arr[i].index = i + 1;
        scanf("%lu", &arr[i].value);
    }
    
    insertionSort(arr, n);
    
    size_t m;
    scanf("%lu", &m);
    size_t *queries = (size_t *)malloc(sizeof(size_t) * m);
    for (size_t i = 0; i < m; i++) {
        scanf("%lu", &queries[i]);
    }
    
    for (size_t i = 0; i < m; i++) {
        size_t query = queries[i];
        if (query == n) {
            Rank min_arr = arr[0];
            for (size_t j = 1; j < n; j++) {
                if (arr[j].value < min_arr.value) {
                    min_arr = arr[j];
                }
            }
            printf("%lu\n", min_arr.index);
        } else {
            mergeSort(arr, 0, query - 1);
            Rank max_arr = arr[query - 1];
            printf("%lu\n", max_arr.index);
        }
    }
    
    return 0;
}