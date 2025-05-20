//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to calculate the sum of an integer array
int sum(int *arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

// Function to sort an integer array in ascending order
void sort(int *arr, int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Main function
int main() {
    FILE *fileIn, *fileOut;
    char buffer[BUFFER_SIZE];

    // Open input file
    fileIn = fopen("input.txt", "r");
    if (fileIn == NULL) {
        printf("Error: could not open file for reading.\n");
        exit(1);
    }

    // Open output file
    fileOut = fopen("output.txt", "w");
    if (fileOut == NULL) {
        printf("Error: could not open file for writing.\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(buffer, BUFFER_SIZE, fileIn)) {
        // Split line into tokens
        char *token = strtok(buffer, " ");
        int nums[100];
        int count = 0;

        while (token != NULL) {
            nums[count++] = atoi(token);
            token = strtok(NULL, " ");
        }

        // Calculate sum and sort array
        int result = sum(nums, count);
        sort(nums, count);

        // Write result and sorted array to output file
        fprintf(fileOut, "Sum: %d\nSorted: ", result);
        for (int i = 0; i < count; i++) {
            fprintf(fileOut, "%d ", nums[i]);
        }
        fprintf(fileOut, "\n");
    }

    // Close files
    fclose(fileIn);
    fclose(fileOut);

    return 0;
}