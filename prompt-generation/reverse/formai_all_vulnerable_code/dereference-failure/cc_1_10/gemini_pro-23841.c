//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the search space
#define MIN_VALUE 0
#define MAX_VALUE 100

// Define the number of elements in the search space
#define NUM_ELEMENTS 10

// Generate a random search space
int *generate_search_space() {
  int *search_space = (int *)malloc(NUM_ELEMENTS * sizeof(int));

  for (int i = 0; i < NUM_ELEMENTS; i++) {
    search_space[i] = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
  }

  return search_space;
}

// Print the search space
void print_search_space(int *search_space) {
  printf("Search space: ");
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    printf("%d ", search_space[i]);
  }
  printf("\n");
}

// Search for a target value in the search space using linear search
int linear_search(int *search_space, int target) {
  for (int i = 0; i < NUM_ELEMENTS; i++) {
    if (search_space[i] == target) {
      return i;
    }
  }

  return -1;
}

// Search for a target value in the search space using binary search
int binary_search(int *search_space, int target) {
  int left = 0;
  int right = NUM_ELEMENTS - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (search_space[mid] == target) {
      return mid;
    } else if (search_space[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the search space
  int *search_space = generate_search_space();

  // Print the search space
  print_search_space(search_space);

  // Get the target value from the user
  int target;
  printf("Enter the target value: ");
  scanf("%d", &target);

  // Search for the target value using linear search
  int linear_search_result = linear_search(search_space, target);
  if (linear_search_result == -1) {
    printf("Target value not found using linear search.\n");
  } else {
    printf("Target value found at index %d using linear search.\n", linear_search_result);
  }

  // Search for the target value using binary search
  int binary_search_result = binary_search(search_space, target);
  if (binary_search_result == -1) {
    printf("Target value not found using binary search.\n");
  } else {
    printf("Target value found at index %d using binary search.\n", binary_search_result);
  }

  // Free the search space
  free(search_space);

  return 0;
}