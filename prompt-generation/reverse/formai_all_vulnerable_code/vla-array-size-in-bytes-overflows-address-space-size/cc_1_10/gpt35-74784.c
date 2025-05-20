//FormAI DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>

// function to search for an element in an unsorted array
int search(int arr[], int n, int elem){
    for(int i=0; i<n; i++){
        if(arr[i] == elem){
            return i;
        }
    }
    return -1;
}

// function to perform binary search on a sorted array
int binarySearch(int arr[], int l, int r, int elem){
    while(l <= r){
        int m = l + (r-l)/2;
        // check if elem is present at mid
        if(arr[m] == elem){
            return m;
        }
        // if elem is greater, ignore left half
        if(arr[m] < elem){
            l = m + 1;
        }
        // if elem is smaller, ignore right half
        else{
            r = m - 1;
        }
    }
    // element not present in array
    return -1;
}

int main(){
    int n, choice, elem, index;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Choose search algorithm:\n1. Linear Search\n2. Binary Search\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            printf("Enter element to search: ");
            scanf("%d", &elem);
            index = search(arr, n, elem);
            if(index == -1){
                printf("Element not found in array\n");
            }
            else{
                printf("Element found at index %d\n", index);
            }
            break;
        case 2:
            // sort array before performing binary search
            for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(arr[i] > arr[j]){
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Enter element to search: ");
            scanf("%d", &elem);
            index = binarySearch(arr, 0, n-1, elem);
            if(index == -1){
                printf("Element not found in array\n");
            }
            else{
                printf("Element found at index %d\n", index);
            }
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}