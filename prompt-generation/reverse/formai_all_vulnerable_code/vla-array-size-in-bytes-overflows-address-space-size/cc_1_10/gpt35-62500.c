//FormAI DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>

//Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//My sorting function in ascending order
void mySort(int arr[], int n) {
    int i, j, min_index;
    
    for(i = 0; i < n-1; i++) {
        min_index = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

int main() {
    int i, n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    mySort(arr, n);

    printf("\nArray after sorting: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}