//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to perform Bubble Sort
void bubbleSort(int arr[], int n){
    int i, j,temp;
    for (i = 0; i < n-1; i++){  
        for (j = 0; j < n-i-1; j++){  
            if (arr[j] > arr[j+1]){  
                temp = arr[j];  
                arr[j] = arr[j+1];  
                arr[j+1] = temp;  
            }  
        }  
    }  
}

// Function to perform Quick Sort
void quicksort(int arr[], int low, int high){
    int i,j,pivot,temp;
    if (low < high){
        pivot = low;
        i = low;
        j = high;
        while (i < j){
            while (arr[i] <= arr[pivot] && i<high){
                i++;
            }
            while (arr[j] > arr[pivot]){
                j--;
            }
            if (i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, low, j-1);
        quicksort(arr, j+1, high);
    }
}

int main(){
    // Initial array size
    int n = 10;
    // Used to keep track of the time taken for each test
    double bubbleTime, quickTime;
    // Used to hold the start and end times for each test
    clock_t start, end;

    //Perform tests on increasing sizes of arrays
    for(int i=1; i<=5; i++){
        // Dynamically allocate memory for array of size n
        int* arr = (int*)malloc(n * sizeof(int));

        // Populate array with random numbers
        for(int j=0; j<n; j++){
            arr[j] = rand() % 100;
        }

        //Bubble Sort Test
        start = clock();    //Start the clock
        bubbleSort(arr, n); //Perform Bubble Sort
        end = clock();      //Stop the clock
        
        //Calculate the time taken for Bubble Sort
        bubbleTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        //Reset the array to unsorted state
        for(int j=0; j<n; j++){
            arr[j] = rand() % 100;
        }

        // Quick Sort Test
        start = clock();     //Start the clock
        quicksort(arr, 0, n-1);  //Perform Quick Sort
        end = clock();        //Stop the clock
        
        //Calculate the time taken for Quick Sort
        quickTime = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Print the results of the test
        printf("For array size %d:\n", n);
        printf("Time taken for Bubble Sort: %lf seconds\n", bubbleTime);
        printf("Time taken for Quick Sort: %lf seconds\n\n", quickTime);
        
        //Free the memory allocated for the array
        free(arr);
        
        // Double the size of the array for the next test
        n *= 2;
    }

    return 0;
}