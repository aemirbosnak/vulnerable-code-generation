//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ACTIVITIES 100
#define MAX_ACTIVITY_NAME_LEN 50

// Struct to store activity information
typedef struct {
    char name[MAX_ACTIVITY_NAME_LEN];
    int duration;
    time_t start_time;
} Activity;

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize activity tracker
    Activity activities[MAX_ACTIVITIES];
    int num_activities = 0;

    // Main loop
    while (1) {
        printf("Enter an activity (or 'q' to quit):\n");
        char input[100];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "q") == 0) {
            break;
        }

        // Parse input and add new activity
        char *name = strtok(input, " ");
        int duration = atoi(strtok(NULL, " "));
        time_t start_time = time(NULL);

        if (num_activities >= MAX_ACTIVITIES) {
            printf("Too many activities. Please remove an existing activity before adding a new one.\n");
            continue;
        }

        strncpy(activities[num_activities].name, name, MAX_ACTIVITY_NAME_LEN - 1);
        activities[num_activities].name[MAX_ACTIVITY_NAME_LEN - 1] = '\0';
        activities[num_activities].duration = duration;
        activities[num_activities].start_time = start_time;

        num_activities++;
    }

    // Print summary of activities
    printf("\nSummary:\n");
    printf("Total activities: %d\n", num_activities);
    for (int i = 0; i < num_activities; i++) {
        printf("Activity %d: %s (%d minutes)\n", i+1, activities[i].name, activities[i].duration/60);
    }

    return 0;
}