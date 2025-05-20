//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int x)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] == x)
			return i;
	}
	return -1;
}

// Function to perform binary search
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
			return mid;

		if (arr[mid] < x)
			l = mid + 1;

		else
			r = mid - 1;
	}
	return -1;
}

int main()
{
	srand(time(0)); // seed for random number generation

	int n, x, choice;

	printf("Enter the size of the array: ");
	scanf("%d", &n);

	// Dynamically allocate memory for the array
	int *arr = (int*)malloc(n * sizeof(int));

	// Generate random numbers and fill the array
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	// Display the array
	printf("\nGenerated array: \n");

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n\nEnter the element to search: ");
	scanf("%d", &x);

	printf("\nChoose the search algorithm: \n");
	printf("1. Linear search\n");
	printf("2. Binary search\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch (choice) {
		case 1: { // call linear search function
			int index = linearSearch(arr, n, x);
			if (index != -1)
				printf("\nElement found at index %d\n", index);
			else
				printf("\nElement not found\n");
			break;
		}
		case 2: { // call binary search function
			int index = binarySearch(arr, 0, n - 1, x);
			if (index != -1)
				printf("\nElement found at index %d\n", index);
			else
				printf("\nElement not found\n");
			break;
		}
		default: {
			printf("\nInvalid choice!\n");
		}
	}

	free(arr);

	return 0;
}