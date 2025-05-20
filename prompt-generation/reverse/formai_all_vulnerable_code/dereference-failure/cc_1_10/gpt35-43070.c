//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binarySearch(int arr[], int l, int r, int x){
    while(l <= r){
        int mid = l + (r-l)/2;
 
        if(arr[mid] == x)
            return mid;
 
        if(arr[mid] < x)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

int* generateRandomNumbers(int n){
    int *arr = malloc(n * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
    return arr;
}

int main(){
    int n, *arr, x;
    printf("Enter length of array: ");
    scanf("%d", &n);

    arr = generateRandomNumbers(n);
    printf("Generated Random Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input value to search
    printf("Enter a value to search: ");
    scanf("%d", &x);

    int index = binarySearch(arr, 0, n-1, x);

    if(index == -1)
        printf("%d not found in the array\n", x);
    else
        printf("%d found at index %d\n", x, index);

    free(arr);
    return 0;
}