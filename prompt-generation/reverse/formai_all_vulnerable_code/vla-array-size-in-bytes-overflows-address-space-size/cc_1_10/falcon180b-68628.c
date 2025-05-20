//Falcon-180B DATASET v1.0 Category: Sorting ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void countingSort(int arr[], int size) {
    int i, j, n, max;
    int count[10] = {0};
    int output[size];

    max = arr[0];
    for (i=0; i<size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (i=0; i<=max; i++)
        count[i] = 0;

    for (i=0; i<size; i++)
        count[(arr[i]/10)%10]++;

    for (i=1; i<10; i++)
        count[i] += count[i-1];

    for (i=size-1; i>=0; i--) {
        output[count[(arr[i]/10)%10]-1] = arr[i];
        count[(arr[i]/10)%10]--;
    }

    for (i=0; i<size; i++)
        arr[i] = output[i];
}

int main() {
    int i, n;
    int arr[100];

    srand(time(NULL));

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}