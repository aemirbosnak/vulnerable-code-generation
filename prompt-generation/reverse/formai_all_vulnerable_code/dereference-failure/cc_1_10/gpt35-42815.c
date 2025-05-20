//FormAI DATASET v1.0 Category: Searching algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x) {
	
	while (l <= r) {
		int mid = l + (r - l) / 2;
		
		if (arr[mid] == x) {
			return mid;
		}
		
		if (arr[mid] < x) {
			l = mid + 1;
		} 
		
		else {
			r = mid - 1;
		}
	}
	
	// If the element is not present in the array
	return -1;
}

int main() {
	
	// Prompt User to Input Array Size
	printf("Enter size of array : ");
	int size;
	scanf("%d", &size);
	
	// Allocate Memory for Array
	int *arr = malloc(size * sizeof(int));
	
	// Prompt User to Input Array Elements
	printf("Enter array elements : \n");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	
	// Sort the Array
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	// Prompt User to Input Target Value
	printf("Enter the target value : ");
	int target;
	scanf("%d", &target);
	
	// Perform Binary Search
	int index = binarySearch(arr, 0, size-1, target);
	
	// Print Result to Console
	if (index == -1) {
		printf("Element not found in array!\n");
	} else {
		printf("Element found at index %d\n", index);
	}
	
	// Free Allocated Memory
	free(arr);
	
	return 0;
}