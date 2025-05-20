//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random data
void generateRandomData(int *arr, int len){
    srand(time(0)); //Seed the random number generator
    for(int i=0;i<len;i++){
        arr[i] = rand() % 100; //Generating random numbers between 0-99
    }
}

//Function to print an array
void printArray(int *arr, int len){
    for(int i=0;i<len;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

//Sorting Function
void sort(int *arr, int len){
    int i,j,temp;
    for(i=0;i<len-1;i++){
        for(j=i+1;j<len;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arrSize = 10;
    int *arr = (int*)malloc(arrSize*sizeof(int)); //Dynamically allocating memory

    printf("Generating Random Data....\n\n");

    generateRandomData(arr,arrSize);
    printf("Unsorted Data: ");
    printArray(arr,arrSize);

    printf("Sorting Data....\n\n");

    sort(arr,arrSize);

    printf("Sorted Data: ");
    printArray(arr,arrSize);

    printf("Memory Freed....\n");
    free(arr); //Freeing up the dynamically allocated memory.

    return 0;
}