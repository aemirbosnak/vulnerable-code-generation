//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort on an array
void bucket_sort(int arr[], int n) {
    int i, j, count[10] = {0};

    // Initialize the count array
    for (i = 0; i < n; i++) {
        count[arr[i] / 10]++;
    }

    // Modify the count array to store the actual positions of elements in the sorted array
    for (i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }

    // Place the elements in their correct buckets
    for (i = n - 1; i >= 0; i--) {
        j = arr[i] / 10;
        swap(&arr[i], &arr[count[j] - 1]);
        count[j]--;
    }
}

// Function to generate a random array of integers
void generate_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand_int(1, 100);
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Generate a random array of integers
    int arr[n];
    generate_array(arr, n);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, n);

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}