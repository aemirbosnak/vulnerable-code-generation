//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SORRY 10 // magic number to make the program feel sorry for the user

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int low, int high) {
    int i, j, temp;

    // choose a random element to be the pivot
    int pivot = arr[low];

    // partition the array around the pivot
    for (i = low + 1; i <= high; i++) {
        if (arr[i] <= pivot) {
            // if the element is less than or equal to the pivot,
            // move it to the left of the pivot
            swap(arr[i], arr[low]);
            low++;
        } else {
            // if the element is greater than the pivot,
            // move it to the right of the pivot
            swap(arr[i], arr[high]);
            high--;
        }
    }

    // if the low index is greater than the high index,
    // then the partition was successful
    if (low > high) {
        return;
    }

    // recurse on the left and right subarrays
    sort(arr, low, high - 1);
    sort(arr, low + 1, high);
}

int main() {
    int arr[10] = {4, 2, 7, 1, 3, 6, 5, 8, 9, 11};
    int i, j, sorry = SORRY;

    // print a sad face to indicate the program's sorry state
    printf(" Sob Sob Sob...\n");

    // sort the array with the partition scheme
    sort(arr, 0, 9);

    // print the sorted array
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
        sorry--;
        if (sorry == 0) {
            printf("\n :(");
            break;
        }
    }

    return 0;
}