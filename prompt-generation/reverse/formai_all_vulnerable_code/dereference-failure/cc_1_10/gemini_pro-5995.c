//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_TIME_TRAVELERS 10
#define MAX_TIME_TRIPS 100

// Data structures
typedef struct {
    int id;
    int departure_time;
    int arrival_time;
    int destination_time;
} TimeTraveler;

typedef struct {
    int id;
    int start_time;
    int end_time;
    TimeTraveler* time_travelers;
} TimeTrip;

// Global variables
TimeTraveler time_travelers[MAX_TIME_TRAVELERS];
TimeTrip time_trips[MAX_TIME_TRIPS];

// Function prototypes
void generate_time_travelers();
void generate_time_trips();
void simulate_time_travel();
void print_time_travelers();
void print_time_trips();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate time travelers
    generate_time_travelers();

    // Generate time trips
    generate_time_trips();

    // Simulate time travel
    simulate_time_travel();

    // Print time travelers
    print_time_travelers();

    // Print time trips
    print_time_trips();

    return 0;
}

void generate_time_travelers() {
    for (int i = 0; i < MAX_TIME_TRAVELERS; i++) {
        time_travelers[i].id = i;
        time_travelers[i].departure_time = rand() % 2000;
        time_travelers[i].arrival_time = rand() % 2000;
        time_travelers[i].destination_time = rand() % 2000;
    }
}

void generate_time_trips() {
    for (int i = 0; i < MAX_TIME_TRIPS; i++) {
        time_trips[i].id = i;
        time_trips[i].start_time = rand() % 2000;
        time_trips[i].end_time = rand() % 2000;
        time_trips[i].time_travelers = malloc(sizeof(TimeTraveler) * MAX_TIME_TRAVELERS);
        for (int j = 0; j < MAX_TIME_TRAVELERS; j++) {
            time_trips[i].time_travelers[j] = time_travelers[j];
        }
    }
}

void simulate_time_travel() {
    for (int i = 0; i < MAX_TIME_TRIPS; i++) {
        for (int j = 0; j < MAX_TIME_TRAVELERS; j++) {
            if (time_trips[i].start_time <= time_travelers[j].departure_time && time_trips[i].end_time >= time_travelers[j].arrival_time) {
                time_travelers[j].destination_time = time_trips[i].start_time;
            }
        }
    }
}

void print_time_travelers() {
    printf("Time travelers:\n");
    for (int i = 0; i < MAX_TIME_TRAVELERS; i++) {
        printf("ID: %d, Departure time: %d, Arrival time: %d, Destination time: %d\n", time_travelers[i].id, time_travelers[i].departure_time, time_travelers[i].arrival_time, time_travelers[i].destination_time);
    }
}

void print_time_trips() {
    printf("Time trips:\n");
    for (int i = 0; i < MAX_TIME_TRIPS; i++) {
        printf("ID: %d, Start time: %d, End time: %d\n", time_trips[i].id, time_trips[i].start_time, time_trips[i].end_time);
        for (int j = 0; j < MAX_TIME_TRAVELERS; j++) {
            printf("Time traveler ID: %d\n", time_trips[i].time_travelers[j].id);
        }
    }
}