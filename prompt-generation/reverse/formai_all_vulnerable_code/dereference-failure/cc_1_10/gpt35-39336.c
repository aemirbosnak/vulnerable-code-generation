//FormAI DATASET v1.0 Category: Sorting ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Let's start by greeting the user
    printf("Welcome to the Happy Sorting Program!\n");

    // Let's get some input from the user to determine the size of the array
    int n;
    printf("Please enter the size of the array you want to sort: ");
    scanf("%d", &n);

    // We'll create an array and fill it with random numbers
    int *arr = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    // Let's print the unsorted array so the user can appreciate how happy it looks
    printf("\nHere is your unsorted array: [");
    for (int i = 0; i < n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);

    // Now, we'll use the bubble sort algorithm to sort the array in ascending order
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Let's print the sorted array so the user can see how happy it looks now
    printf("\nTa-da! Your array is now sorted in ascending order: [");
    for (int i = 0; i < n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n\n", arr[n-1]);

    // We're done! Let's bid the user farewell and clean up after ourselves
    printf("Thank you for using the Happy Sorting Program. We hope your day is as happy as your sorted array!\n");
    free(arr);
    return 0;
}