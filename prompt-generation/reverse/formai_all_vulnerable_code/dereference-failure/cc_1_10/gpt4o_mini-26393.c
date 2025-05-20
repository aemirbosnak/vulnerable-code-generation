//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

// Comparator function to sort activities by their finish time
int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Function to select the maximum number of activities
void selectActivities(struct Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected activities are:\n");

    // Always select the first activity
    int lastActivity = 0;
    printf("Activity %d: Start = %d, Finish = %d\n", lastActivity + 1, activities[lastActivity].start, activities[lastActivity].finish);

    // Check the next activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last selected activity finishes
        if (activities[i].start >= activities[lastActivity].finish) {
            printf("Activity %d: Start = %d, Finish = %d\n", i + 1, activities[i].start, activities[i].finish);
            lastActivity = i; // Update the index of last selected activity
        }
    }
}

// Function to read activities from the user
void readActivities(struct Activity activities[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter start and finish time for activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }
}

int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    // Allocate memory for activities
    struct Activity *activities = malloc(n * sizeof(struct Activity));
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read activities from the user
    readActivities(activities, n);

    // Select and print the maximum number of non-conflicting activities
    selectActivities(activities, n);

    // Free the allocated memory
    free(activities);
    return 0;
}