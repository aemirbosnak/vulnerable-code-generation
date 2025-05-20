//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Comparison function to sort activities based on their finishing time
int cmp(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

// Function to perform the activity selection
void activitySelection(Activity activities[], int n) {
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(Activity), cmp);
    
    // The first activity always gets selected
    printf("Selected activities:\n");
    printf("Activity %d: Start = %d, Finish = %d\n", 0, activities[0].start, activities[0].finish);

    int lastFinishTime = activities[0].finish;

    // Iterate through the remaining activities
    for (int i = 1; i < n; i++) {
        // If the start time of this activity is greater than or equal to the finish time of the last selected
        if (activities[i].start >= lastFinishTime) {
            printf("Activity %d: Start = %d, Finish = %d\n", i, activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish;
        }
    }
}

int main() {
    int n;
    
    // Input the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    Activity *activities = malloc(n * sizeof(Activity));
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Input the start and finish times of activities
    printf("Enter the start and finish times of the activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d Start Finish: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    // Perform activity selection
    activitySelection(activities, n);

    // Free allocated memory
    free(activities);
    
    return 0;
}