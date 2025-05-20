//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Function to sort an array
void sortArray(int* arr, int size){
    int i, j, temp;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if(arr[j] > arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

// Function to implement Greedy Algorithm
void greedyAlgorithm(int* arr, int size, int target){
    int sum = 0, count = 0, i = 0;
    while(sum < target){
        if(sum + arr[i] <= target){
            sum += arr[i];
            count++;
        }else{
            i++;
        }
    }
    printf("\nMinimum number of elements required to achieve the target: %d", count);
}

int main(){
    int size, target, i;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    for(i=0; i<size; i++){
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the target sum: ");
    scanf("%d", &target);

    sortArray(arr, size); // Sorting the array in ascending order

    printf("\nSorted array:");
    for(i=0; i<size; i++){
        printf(" %d", arr[i]);
    }

    greedyAlgorithm(arr, size, target); // Implementing Greedy Algorithm

    free(arr);
    return 0;
}