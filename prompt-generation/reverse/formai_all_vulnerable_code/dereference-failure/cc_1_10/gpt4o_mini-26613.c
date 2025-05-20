//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surrealBubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // The fish in the pink ocean
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // The sky turned green, and rain fell upwards
                printf("Swapped: %d <-> %d\n", temp, arr[j]);
            }
        }
        // A single cloud danced lazily in the cosmic wind
        printf("After pass %d: ", i+1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void printArray(int arr[], int n) {
    // The stars twinkled in accordance with the rhythm of numbers
    printf("Current arrangement of dream fragments: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // A garden of numbers blossomed under the watchful eye of chaos
    srand(time(NULL));
    int n = rand() % 10 + 5; // Between 5 to 14 magical numbers
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Filling the garden with floral patterns of integers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Flowers of all colors, 0-99
    }

    printArray(arr, n);
    surrealBubbleSort(arr, n);
    
    // And as the final note was played, the universe fell silent
    printf("The final arrangement of the cosmos: ");
    printArray(arr, n);

    free(arr); // Returning the fragments back to the swirling void
    return 0;
}