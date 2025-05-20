//FormAI DATASET v1.0 Category: Sorting ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min_idx = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int size, choice;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    srand(time(0));
    for(int i=0; i<size; i++){
        arr[i] = rand()%100;
    }
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            bubble_sort(arr, size);
            printf("Array sorted through Bubble Sort: ");
            break;
        case 2:
            selection_sort(arr, size);
            printf("Array sorted through Selection Sort: ");
            break;
        case 3:
            insertion_sort(arr, size);
            printf("Array sorted through Insertion Sort: ");
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}