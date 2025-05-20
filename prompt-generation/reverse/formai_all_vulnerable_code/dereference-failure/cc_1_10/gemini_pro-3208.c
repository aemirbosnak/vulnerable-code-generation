//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent an activity
typedef struct Activity {
    int start;  // Start time of the activity
    int finish; // Finish time of the activity
} Activity;

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

// Function to print maximum number of activities that can be done by a single person
void printMaxActivities(Activity *arr, int n) {
    // Sort activities based on their finish times
    qsort(arr, n, sizeof(Activity), compare);

    printf("Following activities can be done by a single person:\n");

    // Initialize the first activity as selected
    int i = 0;
    printf("(%d, %d)\n", arr[i].start, arr[i].finish);

    // Iterate over the remaining activities
    for (int j = 1; j < n; j++) {
        // If the current activity does not conflict with the last selected activity, then select it
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d)\n", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}

// Driver code
int main() {
    // Input data for the activities
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    // Print maximum number of activities that can be done by a single person
    printMaxActivities(arr, n);

    return 0;
}