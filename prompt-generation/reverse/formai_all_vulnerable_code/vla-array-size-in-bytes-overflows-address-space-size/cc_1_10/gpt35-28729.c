//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printSortedArray(int arr[], int size) {
    printf("Sorted Array: ");
    for(int i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[], int size) {
    srand(time(0)); // seeding the random function with current time
    printf("Sorting the array. Please wait...\n");
    for(int i=0;i<size;i++) {
        for(int j=0;j<size-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("%d%% done...\r", (i*100)/size); // printing percentage completion
        fflush(stdout);
        sleep(1); // simulating the sort progress
    }
    printf("100%% done...\n");
}

void fillRandomArray(int arr[], int size) {
    printf("Creating a random Array...\n\n");
    for(int i=0;i<size;i++) {
        arr[i] = rand()%100;
        printf("%d ", arr[i]); // printing each element of the array
        sleep(1); // simulating the random generation
    }
    printf("\n\n");
}

int main() {
    int size;
    printf("Welcome to the funny sorting program!\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    fillRandomArray(arr, size);
    sort(arr, size);
    printSortedArray(arr, size);
    return 0;
}