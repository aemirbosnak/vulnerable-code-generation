//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

int compareActivities(const void* a, const void* b) {
    Activity* activityA = (Activity*)a;
    Activity* activityB = (Activity*)b;
    return activityA->finish - activityB->finish;
}

void selectActivities(Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(Activity), compareActivities);

    int i = 0; // The first activity always gets selected
    printf("Selected activities: \n");
    printf("Activity %d (%d, %d)\n", i, activities[i].start, activities[i].finish);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d (%d, %d)\n", j, activities[j].start, activities[j].finish);
            i = j; // Update last selected activity
        }
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity* activities = (Activity*)malloc(n * sizeof(Activity));
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d: ", i);
        scanf("%d %d", &(activities[i].start), &(activities[i].finish));
    }

    selectActivities(activities, n);

    free(activities);
    return 0;
}