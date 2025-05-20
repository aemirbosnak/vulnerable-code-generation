//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Global Variables
int num_activities; 
int *start_time, *finish_time; 
int *selected_activities;

// Compare function for qsort
int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

// Function to determine maximum number of activities that can be selected
int max_activities() {
    int selected_index = 0;
    int count = 1;
    int i;
    for (i = 1; i < num_activities; i++) {
        if (start_time[i] >= finish_time[selected_index]) {
            count++;
            selected_activities[selected_index] = 1;
            selected_index = i;
        }
    }
    selected_activities[selected_index] = 1;
    return count;
}

int main() {
    int i;
    
    printf("Welcome to the Activity Selection Program!\n\n");

    // Prompt user to input number of activities
    printf("Please enter the number of activities: ");
    scanf("%d", &num_activities);

    // Dynamically allocate memory for start_time, finish_time, and selected_activities arrays
    start_time = (int *)malloc(sizeof(int) * num_activities);
    finish_time = (int *)malloc(sizeof(int) * num_activities);
    selected_activities = (int *)calloc(num_activities, sizeof(int));

    // Prompt user to input start and finish times for each activity
    for (i = 0; i < num_activities; i++) {
        printf("\nActivity %d Details:\n", i+1);
        printf("Start Time: ");
        scanf("%d", &start_time[i]);
        printf("Finish Time: ");
        scanf("%d", &finish_time[i]);
    }

    // Sort activities based on finish time
    qsort(finish_time, num_activities, sizeof(int), cmpfunc);

    // Determine maximum number of activities that can be selected
    int max = max_activities();

    // Print results
    printf("\n\nSelected Activities: ");
    for (i = 0; i < num_activities; i++) {
        if (selected_activities[i] == 1) {
            printf("Activity %d ", i+1);
        }
    }
    printf("\n\nMaximum Number of Activities Selected: %d\n\n", max);

    // Free dynamically allocated memory
    free(start_time);
    free(finish_time);
    free(selected_activities);

    return 0;
}