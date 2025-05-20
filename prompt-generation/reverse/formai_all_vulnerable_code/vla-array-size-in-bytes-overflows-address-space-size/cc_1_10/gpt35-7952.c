//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>

#define MAX_SIZE 100 // maximum input size of array

// Function for bubble sort
void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function for finding the largest sum of contiguous subarray
int largest_sum(int arr[], int n) {
    int max_so_far = arr[0];
    int max_ending_here = arr[0];
 
    for (int i = 1; i < n; i++) {
        if (arr[i] > (max_ending_here + arr[i])) {
            max_ending_here = arr[i];
        } else {
            max_ending_here = max_ending_here + arr[i];
        }
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }
    }
 
   return max_so_far;
}

int main() {
    printf("Welcome to the Mind-Bending, Greedy Algorithm!\n");
    printf("Please enter your array size (max 100): ");
    
    int size;
    scanf("%d", &size);
    
    if(size > MAX_SIZE) {
        printf("Input size too large. Exiting program...\n");
        return 0;
    }
    
    int input_arr[size];
    
    printf("Please enter your array elements separated by a space: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &input_arr[i]);
    }
    
    printf("You have entered the following array: { ");
    for(int i = 0; i < size; i++) {
        printf("%d ", input_arr[i]);
    }
    printf("}\n");
    
    // Sort the array in non-decreasing order
    bubble_sort(input_arr, size);
    
    printf("The sorted array is: { ");
    for(int i = 0; i < size; i++) {
        printf("%d ", input_arr[i]);
    }
    printf("}\n");
    
    // Find the largest sum of contiguous subarray
    int max_sum = largest_sum(input_arr, size);
    
    printf("The largest sum of contiguous subarray in the input array is: %d\n", max_sum);
    
    return 0;
}