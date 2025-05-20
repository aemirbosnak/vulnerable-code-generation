//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate an array of random integers
int* generateArray(int size){
    int* arr = (int*) malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        arr[i] = rand();
    }
    return arr;
}

//Function to copy contents of one array to another
void copyArray(int* src, int* tgt, int size){
    for(int i=0; i<size; i++){
        tgt[i] = src[i];
    }
}

//Function to perform bubble sort
void bubbleSort(int* arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Function to perform selection sort
void selectionSort(int* arr, int size){
    for(int i=0; i<size-1; i++){
        int minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//Function to perform insertion sort
void insertionSort(int* arr, int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//Function to measure the performance of a sorting algorithm
float measurePerformance(int* arr, int size, void (*sortingFunc)(int*,int)){
    int* arrCopy = (int*) malloc(size*sizeof(int));
    copyArray(arr,arrCopy,size); //copy the original array to a separate array
    clock_t start = clock(); //measure the start time
    sortingFunc(arrCopy,size); //perform sorting
    clock_t end = clock(); //measure the end time
    float timeTaken = ((float) (end-start))/CLOCKS_PER_SEC; //calculate time taken in seconds
    free(arrCopy); //free memory allocated to the separate array
    return timeTaken;
}

int main(){
    int size = 10000;
    int* arr = generateArray(size); //generate an array of random integers
    float timeTaken;

    //measure time taken for bubble sort
    timeTaken = measurePerformance(arr, size, bubbleSort);
    printf("Time taken for bubble sort: %f seconds\n", timeTaken);

    //measure time taken for selection sort
    timeTaken = measurePerformance(arr, size, selectionSort);
    printf("Time taken for selection sort: %f seconds\n", timeTaken);

    //measure time taken for insertion sort
    timeTaken = measurePerformance(arr, size, insertionSort);
    printf("Time taken for insertion sort: %f seconds\n", timeTaken);
    
    free(arr); //free memory allocated to the original array
    return 0;
}