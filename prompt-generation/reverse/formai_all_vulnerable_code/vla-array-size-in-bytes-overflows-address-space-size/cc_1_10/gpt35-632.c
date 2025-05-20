//FormAI DATASET v1.0 Category: Searching algorithm ; Style: decentralized
// Decentralized Binary Search Algorithm

#include<stdio.h>

int d_binarySearch(int *arr, int n, int key, int id) {
    int start=0, end=n-1, mid, result;

    while(start <= end) {
        mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            result = mid;
            break;
        }
        
        if (arr[mid] < key)
            start = mid + 1;
        
        else
            end = mid - 1;
    }

    // Check if the search was successful
    if (start > end) {
        printf("Node %d: Search Unsuccessful!\n", id);
        return -1;
    }

    printf("Node %d: The element is found at index %d.\n", id, result);

    return result;
}

int main() {
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in sorted order: \n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
 
    printf("Enter the element to be found: ");
    scanf("%d", &key);

    int result = d_binarySearch(arr, n, key, 1);

    if (result == -1) 
        printf("Element not found in the array.\n");
  
    return 0;
}