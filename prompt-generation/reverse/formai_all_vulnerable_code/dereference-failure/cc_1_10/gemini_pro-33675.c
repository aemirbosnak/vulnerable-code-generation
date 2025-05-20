//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct Interval {
    int start;
    int end;
} Interval;

// Function to compare two intervals by their starting times
int compareIntervals(const void *a, const void *b) {
    Interval *ia = (Interval *)a;
    Interval *ib = (Interval *)b;
    return ia->start - ib->start;
}

// Function to merge overlapping intervals
int mergeIntervals(Interval *intervals, int n) {
    // Sort the intervals by their starting times
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // Create a stack to store the merged intervals
    Interval *stack = malloc(sizeof(Interval) * n);
    int top = 0;

    // Push the first interval onto the stack
    stack[top++] = intervals[0];

    // Iterate over the remaining intervals
    for (int i = 1; i < n; i++) {
        // If the current interval overlaps with the top of the stack
        if (intervals[i].start <= stack[top - 1].end) {
            // Merge the current interval with the top of the stack
            stack[top - 1].end = fmax(stack[top - 1].end, intervals[i].end);
        } else {
            // Push the current interval onto the stack
            stack[top++] = intervals[i];
        }
    }

    // Copy the merged intervals back into the original array
    for (int i = 0; i < top; i++) {
        intervals[i] = stack[i];
    }

    // Free the stack
    free(stack);

    // Return the number of merged intervals
    return top;
}

// Driver code to test the mergeIntervals function
int main() {
    // Create an array of intervals
    Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    // Merge the intervals
    int merged = mergeIntervals(intervals, n);

    // Print the merged intervals
    for (int i = 0; i < merged; i++) {
        printf("{%d, %d}\n", intervals[i].start, intervals[i].end);
    }

    return 0;
}