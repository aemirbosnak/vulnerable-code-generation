//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Function to find the maximum sum of a subarray with given constraints
int max_sum_subarray(int arr[], int n, int k)
{
    int max_sum = INT_MIN;
    int curr_sum = 0;
    int start = 0;
    int end = 0;

    // Initialize the first window with the first k elements
    for(int i=0; i<k; i++)
    {
        curr_sum += arr[i];
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
            start = 0;
            end = i;
        }
    }

    // Slide the window to the right and update the maximum sum
    for(int i=k; i<n; i++)
    {
        curr_sum += arr[i] - arr[i-k];
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
            start = i-k+1;
            end = i;
        }
    }

    // Return the maximum sum and the corresponding subarray
    printf("Maximum sum subarray: %d\n", max_sum);
    printf("Subarray: ");
    for(int i=start; i<=end; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return max_sum;
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
        scanf("%d", &arr[i]);

    printf("Enter the size of the window: ");
    scanf("%d", &k);

    max_sum_subarray(arr, n, k);

    return 0;
}