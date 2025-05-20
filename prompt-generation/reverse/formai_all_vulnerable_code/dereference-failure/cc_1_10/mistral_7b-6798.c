//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int binary_search(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);

        return binary_search(arr, mid + 1, right, x);
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int arr[MAX_SIZE];
    int size, search_num, index;

    if (argc < 2) {
        printf("Usage: %s <size of array>\n", argv[0]);
        return 1;
    }

    size = atoi(argv[1]);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Error: Invalid array size.\n");
        return 1;
    }

    printf("Enter %d integers: ", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search_num);

    if (binary_search(arr, 0, size - 1, search_num) != -1) {
        printf("Element found at index: ");
        index = binary_search(arr, 0, size - 1, search_num);
        printf("%d", index);
    } else {
        printf("Element not found.\n");
    }

    free(arr);
    return 0;
}