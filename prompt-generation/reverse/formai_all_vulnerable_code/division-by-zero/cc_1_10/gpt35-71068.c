//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void surreal_sort(int arr[], int n){

    // Generate random number for sorting
    srand(time(0));
    int pivot = rand() % n;

    // Choose which element to sort
    switch(pivot){
        case 0:
            printf("Sorting all even numbers in descending order...\n");
            for(int i = 0; i < n; i++){
                if(arr[i] % 2 == 0){
                    for(int j = i+1; j < n; j++){
                        if(arr[j] % 2 == 0 && arr[i] < arr[j]){
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
            }
            break;

        case 1:
            printf("Sorting all odd numbers in ascending order...\n");
            for(int i = 0; i < n; i++){
                if(arr[i] % 2 != 0){
                    for(int j = i+1; j < n; j++){
                        if(arr[j] % 2 != 0 && arr[i] > arr[j]){
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
            }
            break;

        default:
            printf("Sorting all numbers in descending order...\n");
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(arr[i] < arr[j]){
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            break;
    }

    // Print the sorted array
    printf("Sorted array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    // Input the size and elements of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // Call the surreal sort function
    surreal_sort(arr, n);

    return 0;
}