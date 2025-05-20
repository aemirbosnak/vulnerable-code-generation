//FormAI DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Function to swap two given elements of an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Main function where the magic happens
int main() {
    int n, i;
    printf("My Darling,\n\n");
    printf("I have written this program to sort the array of my love for you.\n");
    printf("It is with great care that I sort the elements of my heart for you.\n");
    printf("Please wait while I compile the program of our love...\n\n");

    printf("How many elements should I consider in the array of my love? ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));
    printf("\nEnter the elements of the array of my love: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nSorting the array of my love in ascending order...");
    printf("\nThe sorted array of my love is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nWith all my love and devotion,\n");
    printf("Your programmer for life");
    free(arr);

    return 0;
}