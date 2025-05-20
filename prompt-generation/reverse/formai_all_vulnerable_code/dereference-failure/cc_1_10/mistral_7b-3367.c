//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void print_arr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int c_searching(int *arr, int target, int left, int right) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return c_searching(arr, target, left, mid - 1);
        }

        return c_searching(arr, target, mid + 1, right);
    }

    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);

    int result = c_searching(arr, target, 0, size - 1);

    if (result == -1) {
        printf("Target value not found in the array.\n");
    } else {
        printf("Target value found at index %d.\n", result);
    }

    print_arr(arr, size);

    return 0;
}