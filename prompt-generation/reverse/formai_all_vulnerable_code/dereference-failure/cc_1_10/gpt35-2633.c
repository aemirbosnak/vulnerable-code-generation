//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

//Function to perform bucket sort
void bucketSort(float arr[], int n) {
    // Create n buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    // Traverse through input array and fill buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        count[bucketIndex]++;
    }
 
    // Sort individual buckets and combine all to get sorted array
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        float temp[count[bucketIndex]];
        for(j=0; j<count[bucketIndex]; j++)
            temp[j] = arr[j];
        int k, index = 0;
        for(k=0; k<i; k++)
            index += count[k];
        for (j = 0; j < count[bucketIndex]; j++)
            arr[index + j] = temp[j];
    }
}

//Function to print the array
void printArray(float arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
}

//Driver program
int main() {
    float arr[] = {0.56, 0.34, 0.12, 0.89, 0.44, 0.50, 0.10, 0.77, 0.98, 0.55};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original Array:\n");
    printArray(arr, n);
    
    printf("\nSorted Array:\n");
    bucketSort(arr, n);
    printArray(arr, n);
    return 0;
}