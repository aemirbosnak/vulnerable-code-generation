//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Comparator function to sort activities based on finish time
int compare(const void *a, const void *b) {
    Activity *activityA = (Activity *)a;
    Activity *activityB = (Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Sort activities based on finish time
    qsort(activities, n, sizeof(Activity), compare);

    printf("Selected activities:\n");

    // The first activity always gets selected
    int lastFinishTime = activities[0].finish;
    printf("Activity %d (Start: %d, Finish: %d)\n", 0, activities[0].start, activities[0].finish);

    // Iterate through the rest of the activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[i].start >= lastFinishTime) {
            printf("Activity %d (Start: %d, Finish: %d)\n", i, activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish; // Update the finish time
        }
    }
}

int main() {
    int n;
    
    // Input number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity *activities = (Activity *)malloc(n * sizeof(Activity));

    // Input start and finish time for each activity
    printf("Enter the start and finish times (start finish):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Select and print the maximum activities
    selectActivities(activities, n);

    // Free dynamically allocated memory
    free(activities);

    return 0;
}