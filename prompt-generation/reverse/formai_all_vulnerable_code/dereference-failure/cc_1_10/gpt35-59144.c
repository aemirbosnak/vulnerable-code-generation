//FormAI DATASET v1.0 Category: Compression algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to compress an array using dynamic compression
int dynamic_compression(int arr[], int n)
{
    // Array to store the compressed sequence
    int *compressed = (int*)malloc(n * sizeof(int));
    int count = 1;
    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == arr[i-1])
        {
            count++;
        }
        else
        {
            compressed[j++] = count;
            compressed[j++] = arr[i-1];
            count = 1;
        }
    }

    // Print the compressed sequence
    printf("Compressed sequence: ");
    
    for (int i = 0; i < j; i++)
    {
        printf("%d ", compressed[i]);
    }
    
    printf("\n");

    // Free the allocated memory
    free(compressed);
}

// Function to decompress an array using dynamic compression
int dynamic_decompression(int arr[], int n)
{
    // Array to store the decompressed sequence
    int *decompressed = (int*)malloc(n * sizeof(int));
    int j = 0;

    for (int i = 0; i < n; i += 2)
    {
        for (int k = 0; k < arr[i]; k++)
        {
            decompressed[j++] = arr[i+1];
        }
    }

    // Print the decompressed sequence
    printf("Decompressed sequence: ");

    for (int i = 0; i < j; i++)
    {
        printf("%d ", decompressed[i]);
    }

    printf("\n");

    // Free the allocated memory
    free(decompressed);
}

int main()
{
    int arr[20] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 7, 7, 7, 8, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    dynamic_compression(arr, n);
    dynamic_decompression(dynamic_compression(arr, n), n);

    return 0;
}