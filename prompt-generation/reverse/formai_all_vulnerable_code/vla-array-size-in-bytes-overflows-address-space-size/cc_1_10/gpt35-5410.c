//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define structure for activity with start and finish times
struct Activity {
    int startTime;
    int endTime;
};

// Function to compare activities by finish time (used in qsort)
int compare(const void *a, const void *b) {
    return (((struct Activity*)a)->endTime - ((struct Activity*)b)->endTime);
}

// Function to find maximum number of activities that can be performed
int findMaxActivities(struct Activity activities[], int n) {
    int i, j, maxActivities = 1;
    i = 0;

    // Sort activities by finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    // Pick the first activity
    printf("Selected activity: (%d, %d)\n", activities[0].startTime, activities[0].endTime);

    // Check for all remaining activities whether they overlap with the selected activity
    for (j = 1; j < n; j++) {
        if (activities[j].startTime >= activities[i].endTime) {
            printf("Selected activity: (%d, %d)\n", activities[j].startTime, activities[j].endTime);
            maxActivities++;
            i = j;
        }
    }

    return maxActivities;
}

int main() {
    int n, i;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    // Enter start and finish times for each activity
    for (i = 0; i < n; i++) {
        printf("Enter start and finish times for activity %d: ", i+1);
        scanf("%d %d", &activities[i].startTime, &activities[i].endTime);
    }

    int maxActivities = findMaxActivities(activities, n);
    printf("\nMaximum number of activities that can be performed: %d", maxActivities);

    return 0;
}