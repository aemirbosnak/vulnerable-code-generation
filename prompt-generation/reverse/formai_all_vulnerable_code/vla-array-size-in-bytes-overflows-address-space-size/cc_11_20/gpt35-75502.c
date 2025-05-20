//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include<stdio.h>                                    // Required input/output header file
#include<stdlib.h>                                   // Required library header file

int main()
{
    printf("\nWelcome to the cheerful world of C Bucket Sort Implementation!\n\n");   // Cheerful welcome message
    
    int i, j, n, m = 0, exp = 1, big = 0;            // Required variables for program execution
    
    // Take user input for the size of the array
    printf("\nEnter the size of the array you want to sort: ");
    scanf("%d", &n);
    
    // Declare the array with user-input size
    int arr[n];
    
    // Loop for taking user inputs for array elements
    printf("\nEnter the elements you want to sort:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i] > big)
        {
            big = arr[i];
        }
    }
    
    // Loop to check digits for max element
    while(big > 0)
    {
        m++;
        big = big/10;
    }
    
    // Start bucket sort
    int bucket[10][10], bucket_count[10];
    for(i = 0; i < 10; i++)
    {
        bucket_count[i] = 0;
        
        // Initialize bucket elements to -1
        for(j = 0; j<n; j++)
        {
            bucket[i][j] = -1;
        }
    }
    
    // Loop to sort digits of each element of the array
    for(i = 0; i < m; i++)
    {
        // Obtaining actual digit for position
        for(j = 0; j < n; j++)
        {
            int a = arr[j]/exp;
            int b = a%10;
            bucket[b][bucket_count[b]] = arr[j];
            bucket_count[b]++;
        }
        
        // Re-arrange array elements after checking the buckets
        int k = 0;
        for(j = 0; j < 10; j++)
        {
            for(int l = 0; l < bucket_count[j]; l++)
            {
                arr[k] = bucket[j][l];
                k++;
            }
            
            // Re-initialize bucket elements
            bucket[j][bucket_count[j]] = -1;
            bucket_count[j] = 0;
        }
        
        // Move on to next position
        exp *= 10;
    }
    
    // Display the sorted array
    printf("\n\nSorted array after C Bucket Sort Implementation:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    // Cheerful exit message
    printf("\n\nYay! Task completed successfully. Happy Programming! :)\n");
    
    return 0;
}