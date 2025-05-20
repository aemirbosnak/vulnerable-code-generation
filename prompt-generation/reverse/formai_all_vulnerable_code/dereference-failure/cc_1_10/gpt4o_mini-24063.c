//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity {
    int start;  // Start time of activity
    int finish; // Finish time of activity
};

// Function to compare two activities based on their finish times
int compareActivities(const void* a, const void* b) {
    struct Activity* activity1 = (struct Activity*)a;
    struct Activity* activity2 = (struct Activity*)b;
    return activity1->finish - activity2->finish; // Sorting in ascending order
}

// Function to implement the activity selection problem
void activitySelection(struct Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(struct Activity), compareActivities);
    
    // The first activity always gets selected
    int lastSelectedIndex = 0;
    printf("Selected Activities: \n");
    printf("Activity %d: Start = %d, Finish = %d\n", lastSelectedIndex + 1, activities[lastSelectedIndex].start, activities[lastSelectedIndex].finish);
    
    // Iterate through the sorted activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected one finishes
        if (activities[i].start >= activities[lastSelectedIndex].finish) {
            // Select this activity
            lastSelectedIndex = i;
            printf("Activity %d: Start = %d, Finish = %d\n", lastSelectedIndex + 1, activities[lastSelectedIndex].start, activities[lastSelectedIndex].finish);
        }
    }
}

int main() {
    // Number of activities
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    // Array to hold activities
    struct Activity* activities = (struct Activity*)malloc(n * sizeof(struct Activity));
    if (activities == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Read the activities from user input
    printf("Enter the start and finish time of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d - Start time: ", i + 1);
        scanf("%d", &(activities[i].start));
        printf("Activity %d - Finish time: ", i + 1);
        scanf("%d", &(activities[i].finish));
    }
    
    // Call the activity selection function
    activitySelection(activities, n);
    
    // Free the allocated memory
    free(activities);
    
    return 0;
}