//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

// Comparator function for sorting activities by finish time
int compare(const void *a, const void *b) {
    return ((Activity *)a)->finish - ((Activity *)b)->finish;
}

// Function to select maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(Activity), compare);
    
    // Always select the first activity
    int lastSelectedIndex = 0;
    printf("Selected activities:\n");
    printf("Activity %d: (%d, %d)\n", 1, activities[0].start, activities[0].finish);
    
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when last selected finishes
        if (activities[i].start >= activities[lastSelectedIndex].finish) {
            printf("Activity %d: (%d, %d)\n", i + 1, activities[i].start, activities[i].finish);
            lastSelectedIndex = i; // Update the last selected activity index
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    
    Activity *activities = malloc(n * sizeof(Activity));
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    // Read the activities' start and finish times
    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d (start finish): ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
        if (activities[i].start > activities[i].finish) {
            fprintf(stderr, "Invalid input: start time must be less than or equal to finish time.\n");
            free(activities);
            return EXIT_FAILURE;
        }
    }
    
    // Select and print the maximum number of activities
    selectActivities(activities, n);

    // Free allocated memory
    free(activities);
    
    return EXIT_SUCCESS;
}