//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    int* nums = (int*)malloc(sizeof(int) * n);
    if (nums == NULL) {
        printf("Failed to allocate memory\n");
        return -1;
    }

    // Assign values to the array
    for (int i = 0; i < n; i++) {
        nums[i] = i * 2;
    }

    // Print the array
    printf("Array contents:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Re-allocate memory with a larger size
    int new_size = n * 2;
    int* new_nums = (int*)realloc(nums, sizeof(int) * new_size);
    if (new_nums == NULL) {
        printf("Failed to re-allocate memory\n");
        free(nums);
        return -1;
    }
    nums = new_nums;

    // Assign new values to the array
    for (int i = n; i < new_size; i++) {
        nums[i] = i * 2;
    }

    // Print the new array
    printf("New array contents:\n");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Free allocated memory
    free(nums);

    return 0;
}