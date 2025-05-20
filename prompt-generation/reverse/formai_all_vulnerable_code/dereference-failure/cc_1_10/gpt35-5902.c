//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <time.h>

int main() {
    // Get the current timestamp
    time_t current_time = time(NULL);
    // Print the current time
    printf("Current time: %s", ctime(&current_time));
    
    // Set the travel date and time by modifying the timestamp
    struct tm *travel_time = localtime(&current_time);
    travel_time->tm_year = 98;   // Set year
    travel_time->tm_mon = 9;     // Set month
    travel_time->tm_mday = 21;   // Set day
    travel_time->tm_hour = 13;   // Set hour
    travel_time->tm_min = 20;    // Set minute
    travel_time->tm_sec = 0;     // Set second
    time_t travel_timestamp = mktime(travel_time);
    
    // Print the travel date and time
    printf("Travel time: %s", ctime(&travel_timestamp));
    
    // Calculate the time difference between current time and travel time
    double time_diff = difftime(travel_timestamp, current_time);
    
    // Check if we are travelling to the past or future
    if(time_diff > 0) {
        // Travel to the future
        printf("\nTravelling to the future...\n");
        while(difftime(time(NULL), travel_timestamp) < 0) {
            // Wait and print the remaining time
            printf("Remaining time: %.0fs\n", difftime(travel_timestamp, time(NULL)));
            sleep(1);
        }
        printf("Arrived in the future!\n");
    } else {
        // Travel to the past
        printf("\nTravelling to the past...\n");
        while(difftime(time(NULL), travel_timestamp) > 0) {
            // Wait and print the remaining time
            printf("Remaining time: %.0fs\n", -difftime(travel_timestamp, time(NULL)));
            sleep(1);
        }
        printf("Arrived in the past!\n");
    }
    
    // Print the current time after time travel
    printf("Current time after time travel: %s", ctime(&current_time));
    
    return 0;
}