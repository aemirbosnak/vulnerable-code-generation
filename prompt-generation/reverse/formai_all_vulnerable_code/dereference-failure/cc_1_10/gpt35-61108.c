//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>

#define MAX_N 100 // Maximum number of input elements
#define MAX_K 10  // Maximum number of output elements

void selectionSort(int arr[], int n);
int findMaximumSum(int arr[], int n, int k);

int main()
{
    int n, k;
    int arr[MAX_N];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of elements to include in the sum: ");
    scanf("%d", &k);
    if(n < k){
        printf("Error: The array cannot be split into %d elements\n", k);
        return 0;
    }
    selectionSort(arr, n);
    printf("The maximum sum of %d elements is: %d\n", k, findMaximumSum(arr, n, k));
    return 0;
}

// Sort the array in ascending order using selection sort
void selectionSort(int arr[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

// Find the maximum possible sum of k elements in the array
int findMaximumSum(int arr[], int n, int k)
{
    int sum = 0;
    for(int i = n-1; i >= n-k; i--){
        sum += arr[i];
    }
    return sum;
}