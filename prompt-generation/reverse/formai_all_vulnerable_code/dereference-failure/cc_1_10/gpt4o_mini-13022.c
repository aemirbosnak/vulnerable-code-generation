//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int index;
} Activity;

// Function to compare two activities based on their end time
int compare(const void *a, const void *b) {
    Activity *activity1 = (Activity *)a;
    Activity *activity2 = (Activity *)b;

    return activity1->end - activity2->end;
}

// Function to select the maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Sort activities based on their end time
    qsort(activities, n, sizeof(Activity), compare);

    // List to keep track of selected activity indexes
    int selected[n];
    int count = 0;

    // Assume the first activity is always selected
    selected[count] = activities[0].index;
    count++;

    // The end time of the last selected activity
    int last_end_time = activities[0].end;

    // Iterate over the sorted activities
    for (int i = 1; i < n; i++) {
        // If the start time of the current activity is greater than or equal to
        // the end time of the last selected activity
        if (activities[i].start >= last_end_time) {
            selected[count] = activities[i].index;
            count++;
            last_end_time = activities[i].end; // update the last end time
        }
    }

    // Print the selected activities
    printf("The maximum number of activities that can be selected is: %d\n", count);
    printf("Selected activities: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // User input for the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity activities[n];

    // User input for the start and end times of activities
    for (int i = 0; i < n; i++) {
        printf("Enter start and end time for activity %d: ", i + 1);
        activities[i].index = i + 1; // Store index (1-indexed)
        scanf("%d %d", &activities[i].start, &activities[i].end);
    }

    // Select and display activities
    selectActivities(activities, n);

    return 0;
}