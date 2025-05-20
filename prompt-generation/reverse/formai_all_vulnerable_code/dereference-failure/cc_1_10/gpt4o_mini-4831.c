//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int start;
    int finish;
} Activity;

// Comparator function to sort activities by their finish times
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select the maximum number of activities that don't overlap
void selectActivities(Activity activities[], int n) {
    // Sort activities by finish times
    qsort(activities, n, sizeof(Activity), compare);

    // The first activity always gets selected
    printf("Selected activities: ");
    int lastFinishTime = activities[0].finish;
    printf("Activity %d (Start: %d, Finish: %d)\n", activities[0].id, activities[0].start, activities[0].finish);

    // For the rest of the activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[i].start >= lastFinishTime) {
            printf("Activity %d (Start: %d, Finish: %d)\n", activities[i].id, activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish; // Update last finish time
        }
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    // Input activities
    for (int i = 0; i < n; i++) {
        activities[i].id = i + 1;
        printf("Enter start and finish time for activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
        // Ensure valid input
        if (activities[i].start < 0 || activities[i].finish < 0 || activities[i].finish < activities[i].start) {
            printf("Invalid input, please ensure that start and finish are non-negative and finish is greater than start.\n");
            free(activities);
            return 1;
        }
    }

    // Select and print the maximum number of non-overlapping activities
    selectActivities(activities, n);

    // Free allocated memory
    free(activities);
    return 0;
}