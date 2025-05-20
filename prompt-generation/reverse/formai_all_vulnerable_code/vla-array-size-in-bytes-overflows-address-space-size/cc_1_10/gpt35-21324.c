//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

/* This function sorts the input array using bucket sort algorithm */
void bucketSort(int arr[], int n)
{
    // Create n empty buckets
    int* bucket = (int*)calloc(n, sizeof(int));

    // Increase the value of bucket[i] by 1 for each occurrence of arr[i] in the input array
    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // Traverse through all buckets and sort the elements
    for (int i = 0, j = 0; i < n; i++) {
        while (bucket[i]--) {
            arr[j++] = i;
        }
    }
}

int main()
{
    printf("Welcome to the Bucket Sort Program!\n");
    printf("We will sort an array of integers using the Bucket Sort algorithm.\n\n");

    // Input the size of the array
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Input the elements of the array
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort algorithm
    bucketSort(arr, n);

    // Output the sorted array
    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nThank you for using the Bucket Sort Program. Have a nice day!\n");

    return 0;
}