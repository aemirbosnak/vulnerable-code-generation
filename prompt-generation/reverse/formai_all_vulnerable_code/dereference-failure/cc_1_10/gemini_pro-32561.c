//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Structure to hold the time travel data
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

// Function to simulate time travel
void *time_travel(void *arg) {
    // Get the current time
    Time *current_time = (Time *)arg;

    // Sleep for the specified amount of time
    sleep(current_time->year * 31557600 + current_time->month * 2629800 + current_time->day * 86400 + current_time->hour * 3600 + current_time->minute * 60 + current_time->second);

    // Print the new time
    printf("New time: %d-%d-%d %d:%d:%d\n", current_time->year, current_time->month, current_time->day, current_time->hour, current_time->minute, current_time->second);

    // Return NULL to indicate success
    return NULL;
}

int main() {
    // Create a thread for each time travel simulation
    int num_simulations = 3;
    pthread_t threads[num_simulations];
    for (int i = 0; i < num_simulations; i++) {
        Time *time_to_travel = malloc(sizeof(Time));
        time_to_travel->year = 2023 + i;
        time_to_travel->month = 1 + i;
        time_to_travel->day = 1 + i;
        time_to_travel->hour = 0;
        time_to_travel->minute = 0;
        time_to_travel->second = 0;
        pthread_create(&threads[i], NULL, time_travel, (void *)time_to_travel);
    }

    // Wait for all the threads to finish
    for (int i = 0; i < num_simulations; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}