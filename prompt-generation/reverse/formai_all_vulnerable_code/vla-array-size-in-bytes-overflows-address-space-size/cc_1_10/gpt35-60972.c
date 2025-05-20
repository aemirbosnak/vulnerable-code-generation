//FormAI DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that swaps two integers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quick sort function
void quicksort(int arr[], int low, int high){
    if (low < high){
        // Choose random pivot
        srand(time(NULL));
        int random = low + rand() % (high - low + 1);
        swap(&arr[random], &arr[high]);

        int pivot = arr[high];
        int i = low - 1;

        for (int j=low; j<high; j++){
            if (arr[j] < pivot){
                i++;
                swap(&arr[i], &arr[j]);
            }
        }

        swap(&arr[i+1], &arr[high]);

        int mid = i+1;
        quicksort(arr, low, mid-1);
        quicksort(arr, mid+1, high);
    }
}

int main(){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Sorting the elements in a post-apocalyptic world...\n");

    quicksort(arr, 0, n-1);

    printf("The sorted elements: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}