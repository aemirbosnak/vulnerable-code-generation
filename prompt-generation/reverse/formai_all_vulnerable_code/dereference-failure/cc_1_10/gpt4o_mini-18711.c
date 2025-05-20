//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("\n--- Welcome to the Array Searching Program ---\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("3. Exit\n");
    printf("Select an option (1-3): ");
}

void linearSearch(int arr[], int size, int target) {
    printf("Performing Linear Search for %d...\n", target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element %d found at index %d\n", target, i);
            return;
        }
    }
    printf("Element %d not found in the array.\n", target);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void binarySearch(int arr[], int size, int target) {
    printf("Performing Binary Search for %d...\n", target);
    
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            printf("Element %d found at index %d\n", target, mid);
            return;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element %d not found in the array.\n", target);
}

void takeUserInput(int arr[], int *size) {
    printf("Enter the number of elements in the array: ");
    scanf("%d", size);
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }
}

void clearInputBuffer() {
    while(getchar() != '\n'); // Clear input buffer
}

int main() {
    int arr[100], size = 0, target = 0, choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        clearInputBuffer(); // Clear the buffer for the next input
        
        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 2) {
            printf("Invalid option, please select again.\n");
            continue;
        }
        
        takeUserInput(arr, &size);
        
        if (choice == 2) {
            // Sort the array first for binary search
            qsort(arr, size, sizeof(int), compare);
            printf("Sorted Array: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        printf("Enter the element to search: ");
        scanf("%d", &target);
        
        if (choice == 1) {
            linearSearch(arr, size, target);
        } else if (choice == 2) {
            binarySearch(arr, size, target);
        }
    }

    return 0;
}