//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);
void swap(int* a, int* b);
void userInput(int arr[], int size);
int* generateRandomArray(int size);
void sortAndPrint(int arr[], int size);

int main() {
    // Size of the array
    int n, choice;
    
    printf("Welcome to the C Sorting Program!\n");
    printf("Please enter the number of elements you want to sort: ");
    scanf("%d", &n);
    
    if(n <= 0) {
        printf("Please enter a valid size greater than zero.\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nMenu:\n");
    printf("1. Input numbers manually\n");
    printf("2. Generate random numbers\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        userInput(arr, n);
    } else if(choice == 2) {
        arr = generateRandomArray(n);
        printf("Generated random array: ");
        printArray(arr, n);
    } else {
        printf("Invalid choice! Exiting...\n");
        free(arr);
        return 1;
    }

    printf("\nArray before sorting: ");
    printArray(arr, n);
    
    // Perform merge sort
    mergeSort(arr, 0, n - 1);
    
    printf("\nArray after sorting: ");
    printArray(arr, n);

    // Free the allocated memory
    free(arr);
    return 0;
}

// Function to merge two halves
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = l; // Initial index of merged sub-array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);
}

// Sorts arr[l..r] using merge()
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to swap two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to take user input
void userInput(int arr[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to generate an array of random integers
int* generateRandomArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Random number between 0 and 99
    }
    return arr;
}

// Function to sort and print the array - unused
void sortAndPrint(int arr[], int size) {
    mergeSort(arr, 0, size - 1);
    printArray(arr, size);
}