//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANES 4
#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 15
#define INTERSECTION_WAIT_TIME 2

int main() {
    int i, j;
    time_t start_time, end_time;
    struct tm *current_time;

    // Initialize the intersection
    for (i = 0; i < NUM_LANES; i++) {
        printf("Lane %d: Red light\n", i + 1);
    }

    // Main loop
    for (i = 0; i < 10; i++) {
        // Update the time
        time(&start_time);
        current_time = localtime(&start_time);

        // Check if it's time to change the lights
        if (current_time->tm_sec % GREEN_LIGHT_DURATION == 0 &&
            current_time->tm_sec % (GREEN_LIGHT_DURATION + YELLOW_LIGHT_DURATION)!= 0) {
            // Change to yellow light
            for (j = 0; j < NUM_LANES; j++) {
                printf("Lane %d: Yellow light\n", j + 1);
            }
        } else if (current_time->tm_sec % (GREEN_LIGHT_DURATION + YELLOW_LIGHT_DURATION) == 0) {
            // Change to red light
            for (j = 0; j < NUM_LANES; j++) {
                printf("Lane %d: Red light\n", j + 1);
            }
        }

        // Wait for the specified duration
        time(&end_time);
        current_time = localtime(&end_time);
        while (difftime(end_time, start_time) < INTERSECTION_WAIT_TIME) {
            time(&end_time);
            current_time = localtime(&end_time);
        }
    }

    return 0;
}