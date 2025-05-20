//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// You won't believe how bucket sort works!
// Each element is put into its respective bucket based on its value. Then, we merge the buckets together to get the sorted array!
// It's like magic! Abracadabra! ✨

// Forward declaration of the bucket sort function
void bucketSort(int*, int, int);

// Main function where the magic begins!
int main() {
    int n, max;
    printf("Hey there! Let's play bucket sort! How many numbers do you want to sort? ");
    scanf("%d", &n);
    printf("What's the biggest number you'll throw at me? ");
    scanf("%d", &max);

    // Declare an array to hold our numbers
    int arr[n];
    printf("Now, show me your numbers! ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Abracadabra! Let's sort these numbers!
    bucketSort(arr, n, max);

    // Tada! Here are your sorted numbers:
    printf("Behold, the magic of bucket sort! Your sorted numbers are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// The bucket sort function - the heart of the magic!
void bucketSort(int *arr, int n, int max) {
    int i, j, k;
    int *buckets[max + 1]; // An array of pointers to buckets

    // Create buckets
    for (i = 0; i <= max; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * n); // Allocate memory for each bucket
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        buckets[arr[i]]++; // Increment the count of the corresponding bucket
    }

    // Sort elements in each bucket
    for (i = 0; i <= max; i++) {
        for (j = 0; j < buckets[i]; j++) {
            *arr++ = i; // Put elements back into the array in sorted order
        }
    }

    // Free the buckets
    for (i = 0; i <= max; i++) {
        free(buckets[i]);
    }
}