//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to compare two intervals by their finish time
int compareIntervals(const void *a, const void *b) {
    int *interval1 = *(int **)a;
    int *interval2 = *(int **)b;
    return interval1[1] - interval2[1];
}

// Function to find the maximum number of non-overlapping intervals
int maxNonOverlappingIntervals(int **intervals, int n) {
    // Sort the intervals by their finish time
    qsort(intervals, n, sizeof(int *), compareIntervals);

    // Initialize the count of non-overlapping intervals
    int count = 1;

    // Initialize the end time of the last non-overlapping interval
    int lastEndTime = intervals[0][1];

    // Iterate over the remaining intervals
    for (int i = 1; i < n; i++) {
        // If the start time of the current interval is greater than the end time of the last non-overlapping interval, then the current interval is non-overlapping
        if (intervals[i][0] > lastEndTime) {
            count++;
            lastEndTime = intervals[i][1];
        }
    }

    // Return the count of non-overlapping intervals
    return count;
}

// Driver code to test the above function
int main() {
    // Create an array of intervals
    int intervals[][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Get the number of intervals
    int n = sizeof(intervals) / sizeof(intervals[0]);

    // Convert the array of intervals to an array of pointers to intervals
    int **intervals_ptr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        intervals_ptr[i] = intervals[i];
    }

    // Find the maximum number of non-overlapping intervals
    int max_non_overlapping_intervals = maxNonOverlappingIntervals(intervals_ptr, n);

    // Print the maximum number of non-overlapping intervals
    printf("The maximum number of non-overlapping intervals is: %d\n", max_non_overlapping_intervals);

    // Free the allocated memory
    free(intervals_ptr);

    return 0;
}