//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_RANGE 100
#define BUCKET_SIZE 10

void insertionSort(int arr[], int n){
    int i, key, j;  
    for (i = 1; i < n; i++){  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key){  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

void bucketSort(int arr[], int n){
    int i, j, k;           
    int minVal = arr[0], maxVal = arr[0];       
    for (i = 1; i < n; i++){
        if (arr[i] < minVal)
            minVal = arr[i];
        else if (arr[i] > maxVal)
            maxVal = arr[i];
    }      
    int bucketCount = (maxVal - minVal) / BUCKET_SIZE + 1;    
    int** buckets = (int**) malloc(sizeof(int*) * bucketCount);
    for (i = 0; i < bucketCount; i++) {
        buckets[i] = (int*) malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) {
            buckets[i][j] = -1;
        }
    }    
    int* bucketSizes = (int*) calloc(bucketCount, sizeof(int)); 
    for (i = 0; i < n; i++) { 
        int bucketIndex = (arr[i] - minVal) / BUCKET_SIZE; 
        if (bucketSizes[bucketIndex] == n) {
            printf("Bucket overflow!\n"); 
            exit(1);
        }
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }    
    k = 0;      
    for (i = 0; i < bucketCount; i++) {  
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]); 
            for (j = 0; j < bucketSizes[i]; j++) {
                arr[k + j] = buckets[i][j];
            }
            k += bucketSizes[i]; 
        }
        free(buckets[i]);
    } 
    free(bucketSizes);
    free(buckets); 
}

void printArray(int arr[], int n) { 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main(){
    int arr[MAX_RANGE], i, n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    srand(time(NULL)); 
    for(i=0; i<n; i++){
        arr[i] = rand() % MAX_RANGE;
    }

    printf("Unsorted array is: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array is: ");
    printArray(arr, n);

    return 0;
}