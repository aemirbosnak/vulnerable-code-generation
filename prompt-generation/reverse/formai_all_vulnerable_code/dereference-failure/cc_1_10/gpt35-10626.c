//FormAI DATASET v1.0 Category: Searching algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int dynamic_search(int arr[], int n, int key) {
    int i, j, min;
    int* table = (int*)malloc((n+1)*sizeof(int));

    table[0] = -1;

    for(i = 1; i <= n; i++) {
        min = i-1;

        for(j = i-1; j >= 0; j--) {
            if(arr[j] < arr[i-1] && table[j] > table[min]) {
                min = j;
            }
        }

        table[i] = table[min] + 1;
    }

    min = n;
    for(i = n-1; i >= 0; i--) {
        if(arr[i] < key && table[i+1] < table[min]) {
            min = i+1;
        }
    }

    free(table);

    if(min == n) {
        return -1;
    }

    return arr[min];
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int result = dynamic_search(arr, n, key);

    if(result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found: %d\n", result);
    }

    return 0;
}