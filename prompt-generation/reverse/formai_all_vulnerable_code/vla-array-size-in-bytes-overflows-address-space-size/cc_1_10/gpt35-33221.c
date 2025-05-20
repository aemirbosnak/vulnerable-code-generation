//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(int arr[], int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int n){
    int i, j, min_index;
    for(i=0; i<n-1; i++){
        min_index=i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        if(min_index!=i){
            swap(&arr[i], &arr[min_index]);
        }
    }
}

void insertion_sort(int arr[], int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int n, choice, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in the array\n", n);
    for (i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }

    printf("Which sorting method do you want to use:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");

    scanf("%d", &choice);

    switch(choice){
        case 1:
            bubble_sort(arr, n);
            printf("The array sorted using Bubble Sort is:\n");
            break;
        case 2:
            selection_sort(arr, n);
            printf("The array sorted using Selection Sort is:\n");
            break;
        case 3:
            insertion_sort(arr, n);
            printf("The array sorted using Insertion Sort is:\n");
            break;
        default:
            printf("Invalid Input\n");
            exit(0);
    }

    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}