//FormAI DATASET v1.0 Category: Searching algorithm ; Style: protected
#include<stdio.h>
#include<stdlib.h>

/* Define a struct for the array */
struct array {
    int* arr;
    int size;
};

/* Helper function to print the array */
void printArray(struct array a) {
    int i;
    printf("[");
    for(i=0;i<a.size-1;i++) {
        printf("%d, ", a.arr[i]);
    }
    printf("%d]\n", a.arr[i]);
}

/* Helper function to compare two integers */
int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* The searching algorithm */
int search(struct array a, int key) {
    int lo = 0, hi = a.size-1, mid;

    while(lo <= hi) {
        mid = lo + (hi-lo)/2;
        if(a.arr[mid] == key)
            return mid;
        else if(a.arr[mid] < key)
            lo = mid+1;
        else
            hi = mid-1;
    }

    return -1; // key not found
}

/* Driver program */
int main() {
    struct array a;
    int key, idx;

    // Initialize the array
    a.size = 10;
    a.arr = (int*) malloc(a.size * sizeof(int));
    // Fill the array
    a.arr[0] = 5;
    a.arr[1] = 3;
    a.arr[2] = 2;
    a.arr[3] = 10;
    a.arr[4] = 1;
    a.arr[5] = 4;
    a.arr[6] = 9;
    a.arr[7] = 8;
    a.arr[8] = 7;
    a.arr[9] = 6;
    // Print the array
    printArray(a);

    // Sort the array
    qsort(a.arr, a.size, sizeof(int), cmpfunc);
    // Print the sorted array
    printf("Sorted array: ");
    printArray(a);

    // Get the item to search
    printf("Enter the item to search for: ");
    scanf("%d", &key);
    // Search for the item and get the index
    idx = search(a, key);
    // Print the result
    if(idx != -1)
        printf("Found item at index %d\n", idx);
    else
        printf("Item not found\n");

    // Free the array memory
    free(a.arr);

    return 0;
}