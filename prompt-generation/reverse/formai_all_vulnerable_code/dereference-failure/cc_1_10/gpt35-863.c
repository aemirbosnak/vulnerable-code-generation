//FormAI DATASET v1.0 Category: Sorting ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to print array
void printArray(int *arr, int N){
    for(int i=0; i<N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Function to swap two elements in array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform bubble sort
//In bubble sort, we repeatedly swap the adjacent elements if they are in wrong order
void bubbleSort(int *arr, int N){
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printf("Sorted array: ");
    printArray(arr, N);
}

//Function to perform selection sort
//In selection sort, we repeatedly find the smallest element and swap it with the element in the current position
void selectionSort(int *arr, int N){
    for(int i=0; i<N-1; i++){
        int min = i;
        for(int j=i+1; j<N; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
    printf("Sorted array: ");
    printArray(arr, N);
}

//Function to perform insertion sort
//In insertion sort, we divide the array into two parts - sorted and unsorted. We pick an element from unsorted part and insert it into the correct position in sorted part
void insertionSort(int *arr, int N){
    for(int i=1; i<N; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    printf("Sorted array: ");
    printArray(arr, N);
}

int main(){
    srand(time(0));

    int N = 10; //size of array
    
    //creating array of N random integers
    int *arr = (int*)malloc(N*sizeof(int));
    for(int i=0; i<N; i++){
        arr[i] = rand()%100;
    }

    printf("Original array: ");
    printArray(arr, N);

    int choice;
    printf("Select sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            bubbleSort(arr, N);
            break;
        case 2:
            selectionSort(arr, N);
            break;
        case 3:
            insertionSort(arr, N);
            break;
        default:
            printf("Invalid choice!");
    }

    free(arr); //freeing memory allocated for array

    return 0;
}