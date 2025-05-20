//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enum for activity types
enum activity_type {
    WALKING,
    RUNNING,
    CYCLING,
    SWIMMING,
    OTHER
};

// Struct for activity data
struct activity_data {
    enum activity_type type;
    time_t start_time;
    time_t end_time;
    double distance;
    double duration;
};

// Function to create a new activity
struct activity_data *create_activity(enum activity_type type, time_t start_time, time_t end_time, double distance) {
    struct activity_data *activity = malloc(sizeof(struct activity_data));
    activity->type = type;
    activity->start_time = start_time;
    activity->end_time = end_time;
    activity->distance = distance;
    activity->duration = difftime(end_time, start_time);
    return activity;
}

// Function to print activity data
void print_activity(struct activity_data *activity) {
    char *activity_type_str;
    switch (activity->type) {
        case WALKING:
            activity_type_str = "Walking";
            break;
        case RUNNING:
            activity_type_str = "Running";
            break;
        case CYCLING:
            activity_type_str = "Cycling";
            break;
        case SWIMMING:
            activity_type_str = "Swimming";
            break;
        case OTHER:
            activity_type_str = "Other";
            break;
    }
    printf("Activity: %s\n", activity_type_str);
    printf("Start time: %s", ctime(&activity->start_time));
    printf("End time: %s", ctime(&activity->end_time));
    printf("Distance: %.2f km\n", activity->distance);
    printf("Duration: %.2f hours\n", activity->duration / 3600);
}

// Main function
int main() {
    // Create some sample activities
    struct activity_data *activities[] = {
        create_activity(WALKING, time(NULL) - 3600, time(NULL), 5.0),
        create_activity(RUNNING, time(NULL) - 7200, time(NULL) - 3600, 10.0),
        create_activity(CYCLING, time(NULL) - 10800, time(NULL) - 7200, 20.0),
        create_activity(SWIMMING, time(NULL) - 14400, time(NULL) - 10800, 1.5),
        create_activity(OTHER, time(NULL) - 18000, time(NULL) - 14400, 3.0)
    };

    // Print the activities
    for (int i = 0; i < 5; i++) {
        print_activity(activities[i]);
        printf("\n");
    }

    // Free the memory allocated for the activities
    for (int i = 0; i < 5; i++) {
        free(activities[i]);
    }

    return 0;
}