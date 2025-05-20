//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold activity details
struct Activity {
    int start;
    int end;
    int index; // To store the original position of the activity
};

// Function to compare two activities based on their finish time
int compare(const void *a, const void *b) {
    struct Activity *activity1 = (struct Activity *)a;
    struct Activity *activity2 = (struct Activity *)b;
    return activity1->end - activity2->end;
}

// Function that implements the Activity Selection greedy algorithm
void selectActivities(struct Activity activities[], int n) {
    // An array to store the selected activities
    int *selected = (int *)malloc(n * sizeof(int));

    // First, sort activities based on their finish times
    qsort(activities, n, sizeof(activities[0]), compare);

    // The first activity always gets selected
    selected[0] = 0;

    // To keep track of the last selected activity's end time
    int last_selected = 0;
    int j = 1; // j to track selection index

    // Iterate through the remaining activities
    for (int i = 1; i < n; i++) {
        // If this activity starts after or when the last one ends
        if (activities[i].start >= activities[last_selected].end) {
            selected[j] = i; // select this activity
            j++; // Increment selection index
            last_selected = i; // Update last selected activity
        }
    }

    // Print selected activities
    printf("Selected Activities:\n");
    for (int i = 0; i < j; i++) {
        printf("Activity %d: Start = %d, End = %d\n", activities[selected[i]].index+1, activities[selected[i]].start, activities[selected[i]].end);
    }

    // Free allocated memory
    free(selected);
}

// Main function to drive the program
int main() {
    // Create an array of activities (custom art piece)
    struct Activity activities[] = {
        {0, 6, 0}, {5, 7, 1}, {1, 3, 2}, {8, 9, 3}, 
        {5, 9, 4}, {3, 4, 5}, {2, 3, 6}, {9, 10, 7}
    };

    // Calculate the number of activities
    int n = sizeof(activities) / sizeof(activities[0]);

    // Showcase the incoming artwork (activities)
    printf("🎨 Incoming Activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: Start = %d, End = %d\n", activities[i].index + 1, activities[i].start, activities[i].end);
    }
    printf("\n");

    // Call the function to select the maximum number of activities
    selectActivities(activities, n);

    return 0;
}