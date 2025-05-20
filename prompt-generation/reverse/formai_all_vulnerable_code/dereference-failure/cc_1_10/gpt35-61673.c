//FormAI DATASET v1.0 Category: Sorting ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function that prints an array
void printArray(int* arr, int n){
    printf("[");
    for(int i=0; i<n; i++){
        if(i==n-1){
            printf("%d]",arr[i]);
        }
        else{
            printf("%d, ",arr[i]);
        }
    }
    printf("\n");
}

//Function that performs Bubble Sort on an array
void bubbleSort(int* arr, int n){
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Function that performs Insertion Sort on an array
void insertionSort(int* arr, int n){
    int temp, j;
    for(int i=1; i<n; i++){
        temp = arr[i];
        j = i-1;
        while(temp<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

//Function that performs Selection Sort on an array
void selectionSort(int* arr, int n){
    int temp, minIndex;
    for(int i=0; i<n-1; i++){
        minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//Main function that generates an array, sorts it using 3 sorting algorithms and prints the time taken by each algorithm
int main(){
    int n=10;
    int* arr = (int*)malloc(n*sizeof(int));
    srand(time(0));
    for(int i=0; i<n; i++){
        arr[i] = rand() % 100;
    }
    printf("\nUnsorted array: ");
    printArray(arr, n);
    
    int* arrCopy = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        arrCopy[i] = arr[i];
    }

    clock_t start, end;
    double cpu_time_used;
    
    //Bubble Sort
    start = clock();
    bubbleSort(arr, n);
    end = clock();
    
    printf("\nBubble Sort: ");
    printArray(arr, n);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds", cpu_time_used);
    
    for(int i=0; i<n; i++){
        arr[i] = arrCopy[i];
    }
    
    //Insertion Sort
    start = clock();
    insertionSort(arr, n);
    end = clock();
    
    printf("\nInsertion Sort: ");
    printArray(arr, n);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds", cpu_time_used);
    
    for(int i=0; i<n; i++){
        arr[i] = arrCopy[i];
    }
    
    //Selection Sort
    start = clock();
    selectionSort(arr, n);
    end = clock();
    
    printf("\nSelection Sort: ");
    printArray(arr, n);
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    free(arr);
    free(arrCopy);
    return 0;
}