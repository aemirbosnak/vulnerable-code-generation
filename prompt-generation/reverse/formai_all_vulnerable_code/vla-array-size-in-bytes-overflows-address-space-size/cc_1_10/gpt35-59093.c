//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to sort array in ascending order
void sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)     
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

// Function to find maximum product of k elements 
int maxProduct(int arr[], int n, int k)
{
    sort(arr, n); // Sort the array in ascending order
 
    int product = 1;
 
    // If k is odd, include the middle element
    if (k%2 != 0)
    {
        product *= arr[n/2];
        k--;
    }
 
    // Initialize left and right pointers 
    int left = 0, right = n-1;
 
    // Multiply k largest numbers from both ends
    for (int i = 0; i < k/2; i++) {
        int leftProduct = arr[left] * arr[left+1];
        int rightProduct = arr[right] * arr[right-1];

        if (leftProduct > rightProduct) {
            product *= leftProduct;
            left += 2;
        } else {
            product *= rightProduct;
            right -= 2;
        }
    }
 
    return product;
}

// Main function
int main()
{
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if(k > n)
    {
        printf("Invalid Input.");
        return 0;
    }
    int max_product = maxProduct(arr, n, k);
    printf("The maximum product of %d elements of the array is %d", k, max_product);
    return 0;
}