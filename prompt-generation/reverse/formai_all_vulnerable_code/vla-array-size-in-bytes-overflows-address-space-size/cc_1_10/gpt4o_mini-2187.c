//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>

// Structure to represent an activity
struct Activity {
    int start;
    int finish;
};

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    struct Activity *activityA = (struct Activity *)a;
    struct Activity *activityB = (struct Activity *)b;
    return activityA->finish - activityB->finish;
}

// Function to select maximum number of activities
void selectActivities(struct Activity activities[], int n) {
    // Sort the activities based on finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities:\n");
    
    // The first activity always gets selected
    int lastFinishTime = activities[0].finish;
    printf("Activity 1: Start Time = %d, Finish Time = %d\n", activities[0].start, activities[0].finish);
    
    // Iterate through the rest of the activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after the last selected activity finishes
        if (activities[i].start >= lastFinishTime) {
            printf("Activity %d: Start Time = %d, Finish Time = %d\n", i + 1, activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish; // Update the last finish time
        }
    }
}

int main() {
    int n;

    // Prompt the user to enter the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    // Get the start and finish times for each activity
    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Run the selection function
    selectActivities(activities, n);

    return 0;
}