//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Function to implement Bucket Sort
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    int i;
    int m = n;
    float max_val = arr[0];
    for (i = 1; i < n; i++){
        if (arr[i] > max_val){
            max_val = arr[i];
        }
    }
    int bucket_count = (max_val-m+1);
    float* buckets[bucket_count];
    for(i = 0; i < bucket_count; i++){
        buckets[i] = (float*) malloc(sizeof(float) * n);
    }
 
    // Put the elements in the buckets
    for (i = 0; i < n; i++) {
        int bucket_index =(int) ((arr[i]-m) * bucket_count / (max_val-m+1));
        buckets[bucket_index][(int)(i)] = arr[i];
    }
 
    // Sort the elements of each individual bucket
    for (i = 0; i < bucket_count; i++) {
        int arr_size = 0;
        while (arr_size < n && buckets[i][arr_size] != 0) {
            arr_size++;
        }
        float* sorted_arr = (float*) malloc(sizeof(float) * arr_size);
        int j;
        for (j = 0; j < arr_size; j++) {
            sorted_arr[j] = buckets[i][j];
        }
        int k;
        for (j = 0; j < arr_size-1; j++) {
            for (k = 0; k < arr_size-j-1; k++) {
                if (sorted_arr[k] > sorted_arr[k+1]) {
                    float temp = sorted_arr[k+1];
                    sorted_arr[k+1] = sorted_arr[k];
                    sorted_arr[k] = temp;
                }
            }
        }
        
        // Print the sorted elements of the bucket
        for (j = 0; j < arr_size; j++) {
            printf("%.2f ", sorted_arr[j]);
        }
        printf("\n");
    }
}
 
// Driver code
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float arr[n];
    int i;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    printf("\nSorted Array:\n");
    bucketSort(arr, n);
    return 0;
}