//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by their start times
int compInt(const void *a, const void *b) {
  int x = *(int *)a;
  int y = *(int *)b;
  return x - y;
}

// Function to perform the greedy algorithm
int greedy(int arr[], int n) {
  // Sort the intervals by their start times
  qsort(arr, n, sizeof(int), compInt);

  // Initialize the result
  int count = 1;
  int end = arr[0];

  // Iterate over the remaining intervals
  for (int i = 1; i < n; i++) {
    // If the current interval overlaps with the previous one, ignore it
    if (arr[i] <= end) {
      continue;
    }

    // Otherwise, increment the count and update the end time
    count++;
    end = arr[i];
  }

  // Return the result
  return count;
}

int main() {
  // Get the number of intervals
  int n;
  scanf("%d", &n);

  // Get the start and end times of the intervals
  int arr[n * 2];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[2 * i], &arr[2 * i + 1]);
  }

  // Perform the greedy algorithm
  int count = greedy(arr, n * 2);

  // Print the result
  printf("%d\n", count);

  return 0;
}