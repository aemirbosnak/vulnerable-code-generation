//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Struct to represent an activity
typedef struct Activity {
    int start; // Start time of the activity
    int finish; // Finish time of the activity
} Activity;

// Function to compare two activities based on their finish times
int compare(const void *a, const void *b) {
    Activity *activity1 = (Activity *)a;
    Activity *activity2 = (Activity *)b;
    return activity1->finish - activity2->finish;
}

// Function to find the maximum number of activities that can be performed
void selectActivities(Activity activities[], int n) {
    // Sort the activities based on finish time
    qsort(activities, n, sizeof(Activity), compare);
    
    printf("Selected activities:\n");
    
    // The first activity is always selected
    int lastSelectedIndex = 0;
    printf("Activity%3d: [%2d, %2d]\n", lastSelectedIndex + 1, activities[lastSelectedIndex].start, activities[lastSelectedIndex].finish);
    
    // Iterate through the rest of the activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[i].start >= activities[lastSelectedIndex].finish) {
            printf("Activity%3d: [%2d, %2d]\n", i + 1, activities[i].start, activities[i].finish);
            lastSelectedIndex = i; // Update the last selected activity
        }
    }
}

int main() {
    int n;
    
    // Input the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    // Allocate memory for the activities
    Activity *activities = (Activity *)malloc(n * sizeof(Activity));
    
    // Input the activities
    printf("Enter the start and finish time of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d - Start Time: ", i + 1);
        scanf("%d", &activities[i].start);
        printf("Activity %d - Finish Time: ", i + 1);
        scanf("%d", &activities[i].finish);
    }
    
    // Select the maximum number of activities
    selectActivities(activities, n);
    
    // Free allocated memory
    free(activities);
    
    return 0;
}