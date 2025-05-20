//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, max_val = 0;
    int *arr;
    int *bucket[MAX_SIZE];

    //Input array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    //Bucket initialization
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(n * sizeof(int));
    }

    //Bucket Sort
    for (i = 0; i < n; i++) {
        int index = arr[i] * MAX_SIZE / max_val;
        bucket[index] = (int *)realloc(bucket[index], (index + 1) * sizeof(int));
        bucket[index][index] = arr[i];
    }

    //Rearranging the array
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < bucket[i][0]; j++) {
            arr[j] = bucket[i][j + 1];
        }
    }

    //Printing the sorted array
    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}