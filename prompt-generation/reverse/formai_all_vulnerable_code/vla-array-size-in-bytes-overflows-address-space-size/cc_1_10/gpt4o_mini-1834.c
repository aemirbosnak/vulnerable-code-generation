//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include <stdio.h>

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size, target;
    char choice;

    printf("Welcome to the Linear Search Program!\n");

    do {
        printf("Enter the size of the array: ");
        scanf("%d", &size);

        int arr[size]; // Create an array of given size
        
        printf("Enter %d integer elements:\n", size);
        for (int i = 0; i < size; i++) {
            printf("Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        displayArray(arr, size);

        printf("Enter the integer to search: ");
        scanf("%d", &target);

        int result = linearSearch(arr, size, target);

        if (result != -1) {
            printf("Element %d found at index %d.\n", target, result);
        } else {
            printf("Element %d not found in the array.\n", target);
        }

        printf("Do you want to search again? (y/n): ");
        scanf(" %c", &choice); // The space before %c ignores any leftover newline characters

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Linear Search Program!\n");
    return 0;
}