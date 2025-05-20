//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function prototypes
void generateRandomArray(int arr[], int size);
void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

int main() {
    int arr[MAX_SIZE];
    int size, choice;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Innovative Sorting Program!\n");
    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    // Generate a random array
    generateRandomArray(arr, size);
    printf("Generated random array:\n");
    printArray(arr, size);

    printf("\nSelect Sorting Method:\n");
    printf("1. Bubble Sort\n2. Quick Sort\n3. Merge Sort\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    // Sort based on user choice
    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            printf("\nArray sorted using Bubble Sort:\n");
            printArray(arr, size);
            break;
        case 2:
            quickSort(arr, 0, size - 1);
            printf("\nArray sorted using Quick Sort:\n");
            printArray(arr, size);
            break;
        case 3:
            mergeSort(arr, 0, size - 1);
            printf("\nArray sorted using Merge Sort:\n");
            printArray(arr, size);
            break;
        default:
            printf("Invalid choice!\n");
            return -1;
    }
    
    return 0;
}

// Function to generate an array with random numbers
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0 and 999
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort implementation
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick Sort implementation
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);  
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;  
            // Swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivot
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Merge Sort implementation
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Merge function for Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays
    i = 0; 
    j = 0; 
    k = left; 
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

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}