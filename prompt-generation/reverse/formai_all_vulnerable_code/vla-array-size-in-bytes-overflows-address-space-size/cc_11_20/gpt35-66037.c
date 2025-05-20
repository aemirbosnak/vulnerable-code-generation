//FormAI DATASET v1.0 Category: Sorting ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){

    printf("Welcome to the Sorting Algorithm example program! Let's get started...\n");

    int size;

    printf("Please enter the size of the array you would like to sort: ");
    scanf("%d", &size);

    int arr[size];

    //Populate array with random integers between 0 and 100
    for(int i=0; i<size; i++){
        arr[i] = rand() % 101;
    }

    printf("Original Array:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    //Bubble Sort Algorithm
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                //swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\n\nSorted Array using Bubble Sort:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    //Selection Sort Algorithm
    int minIndex;
    for(int i=0; i<size-1; i++){
        minIndex = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        //swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    printf("\n\nSorted Array using Selection Sort:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    //Insertion Sort Algorithm
    int key;
    int j;
    for(int i=1; i<size; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("\n\nSorted Array using Insertion Sort:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nThank you for using the Sorting Algorithm example program. Happy Sorting!");

    return 0;

}