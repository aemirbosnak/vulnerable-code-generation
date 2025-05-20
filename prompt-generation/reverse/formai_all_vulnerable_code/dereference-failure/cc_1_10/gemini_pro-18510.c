//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of time jumps
#define MAX_JUMPS 10

// Define the possible time periods
enum TimePeriod {
    PREHISTORIC,
    ANCIENT,
    MEDIEVAL,
    RENAISSANCE,
    MODERN,
    FUTURE
};

// Define the time jump struct
struct TimeJump {
    int year;
    enum TimePeriod period;
};

// Create a new time jump
struct TimeJump* create_time_jump(int year, enum TimePeriod period) {
    struct TimeJump* time_jump = malloc(sizeof(struct TimeJump));
    time_jump->year = year;
    time_jump->period = period;
    return time_jump;
}

// Free a time jump
void free_time_jump(struct TimeJump* time_jump) {
    free(time_jump);
}

// Print a time jump
void print_time_jump(struct TimeJump* time_jump) {
    printf("Year: %d, Period: %s\n", time_jump->year, time_jump->period);
}

// Generate a random time jump
struct TimeJump* generate_random_time_jump() {
    // Get a random year
    int year = rand() % 100000;

    // Get a random time period
    enum TimePeriod period = rand() % 6;

    // Create a new time jump
    return create_time_jump(year, period);
}

// Simulate a time travel journey
void simulate_time_travel_journey() {
    // Create an array of time jumps
    struct TimeJump* time_jumps[MAX_JUMPS];

    // Generate a random time jump for each jump
    for (int i = 0; i < MAX_JUMPS; i++) {
        time_jumps[i] = generate_random_time_jump();
    }

    // Print the time jumps
    for (int i = 0; i < MAX_JUMPS; i++) {
        print_time_jump(time_jumps[i]);
    }

    // Free the time jumps
    for (int i = 0; i < MAX_JUMPS; i++) {
        free_time_jump(time_jumps[i]);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Simulate a time travel journey
    simulate_time_travel_journey();

    return 0;
}