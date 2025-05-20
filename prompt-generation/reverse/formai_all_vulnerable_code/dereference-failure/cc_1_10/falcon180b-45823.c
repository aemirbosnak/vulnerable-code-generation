//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int arr_size, search_num, rand_num, i;
    int *arr;
    clock_t start_time, end_time;
    double cpu_time_used;

    // User input for array size and number to search for
    printf("Enter array size: ");
    scanf("%d", &arr_size);
    printf("Enter number to search for: ");
    scanf("%d", &search_num);

    // Dynamically allocate memory for array
    arr = (int *)malloc(arr_size * sizeof(int));

    // Initialize array with random numbers
    srand(time(NULL));
    for (i = 0; i < arr_size; i++) {
        rand_num = rand() % 100;
        arr[i] = rand_num;
    }

    // Display original array
    printf("\nOriginal array:\n");
    for (i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Start timer
    start_time = clock();

    // Perform linear search
    int found = 0;
    for (i = 0; i < arr_size; i++) {
        if (arr[i] == search_num) {
            found = 1;
            break;
        }
    }

    // Display result
    if (found) {
        printf("\nNumber found at index %d.\n", i);
    } else {
        printf("\nNumber not found in array.\n");
    }

    // Stop timer
    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    // Display time taken for search
    printf("\nTime taken for search: %lf seconds.\n", cpu_time_used);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}