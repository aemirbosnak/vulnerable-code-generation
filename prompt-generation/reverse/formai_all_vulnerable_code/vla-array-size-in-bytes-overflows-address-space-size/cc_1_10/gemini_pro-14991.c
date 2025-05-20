//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Elementary, my dear Watson!
void bucketSort(int *nums, int n) {
    // Initialize buckets
    int buckets[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        buckets[i] = 0;
    }

    // Watson, count the occurrences
    for (int i = 0; i < n; ++i) {
        ++buckets[nums[i]];
    }

    // Holmes, put the suspects in their rightful place
    int idx = 0;
    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < buckets[i]; ++j) {
            nums[idx++] = i;
        }
    }

    // Watson, the case is closed
    printf("The suspects, sorted:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    // Set the stage
    int n;
    printf("Watson, tell me the count of suspects:\n");
    scanf("%d", &n);

    // Gather evidence
    int nums[n];
    printf("Holmes, enter the list of suspects:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &nums[i]);
    }

    // Time to solve the puzzle
    bucketSort(nums, n);

    // Bask in the glory of our deductions
    printf("Elementary, my dear Watson!\n");
    return 0;
}