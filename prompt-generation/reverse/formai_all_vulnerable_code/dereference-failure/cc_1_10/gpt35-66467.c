//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include<stdio.h>
#define MAX_SIZE 100

// Function to search for an element in an array using Binary Search Algorithm
int binarySearch(int arr[], int left, int right, int x) {
    while(left<=right) {
        int mid = left + (right - left) / 2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid]<x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function to perform interpolation search in an array
int interpolationSearch(int arr[], int n, int x) {
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi-lo) / (arr[hi]-arr[lo]))*(x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

//Function to print the array
void printArray(int arr[], int n) {
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n, x, choice, result;
    printf("Enter number of elements in array: ");
    scanf("%d",&n);
    printf("Enter elements of array in sorted order: ");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    while(1) {
        printf("\nChoose the searching algorithm\n");
        printf("1. Binary Search Algorithm\n");
        printf("2. Interpolation Search Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nEnter the element to search: ");
                scanf("%d",&x);
                result = binarySearch(arr,0,n-1,x);
                printf("\nBinary Search Algorithm\n");
                if(result==-1)
                    printf("Element not found in array!\n");
                else
                    printf("Element found at position %d in array\n",result+1);
                break;
            case 2:
                printf("\nEnter the element to search: ");
                scanf("%d",&x);
                result = interpolationSearch(arr,n,x);
                printf("\nInterpolation Search Algorithm\n");
                if(result==-1)
                    printf("Element not found in array!\n");
                else
                    printf("Element found at position %d in array\n",result+1);
                break;
            case 3:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}