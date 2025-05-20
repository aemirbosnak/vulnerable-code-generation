//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    int arr[MAX_SIZE];
    int size;
} Array;

int pattern_search(int *arr, int size, int *pattern, int pattern_size) {
    int low = 0, high = size - pattern_size;

    while (low <= high) {
        int i;
        for (i = 0; i < pattern_size; i++) {
            if (arr[low + i] != pattern[i]) {
                low++;
                break;
            }
        }

        if (i == pattern_size) {
            return low;
        }
    }

    return -1;
}

void print_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Array arr;
    arr.size = n;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr.arr[i]);
    }

    int pattern[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &pattern[i]);
    }

    int result = pattern_search(arr.arr, arr.size, pattern, m);

    if (result == -1) {
        printf("Pattern not found.\n");
    } else {
        printf("Pattern found at index %d.\n", result);
    }

    print_array(arr.arr, arr.size);

    return 0;
}