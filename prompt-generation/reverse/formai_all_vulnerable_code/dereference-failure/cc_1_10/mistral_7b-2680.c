//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 5
#define MAX_SIZE 1000

void print_array(int arr[], int size) {
    int i;
    printf("Array: ");
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int GreedyBob(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if(arr[mid] == target)
            return mid;

        if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    printf("Target not found in the array.\n");
    return -1;
}

int main() {
    int arr[MAX_SIZE], size, target, index;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    print_array(arr, size);
    printf("Enter the target value: ");
    scanf("%d", &target);

    index = GreedyBob(arr, size, target);

    if(index != -1)
        printf("Index of %d: %d\n", target, index);

    return 0;
}