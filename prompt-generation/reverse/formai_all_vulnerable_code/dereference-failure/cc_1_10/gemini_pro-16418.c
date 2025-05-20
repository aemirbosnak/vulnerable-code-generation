//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGS 100
#define MAX_CONVEYORS 10
#define MAX_CHECK_IN_COUNTERS 5

// Baggage system components
typedef struct Bag {
    int id;
    int weight;
    int destination;
} Bag;

typedef struct Conveyor {
    int id;
    int length;
    int speed;
    struct Bag *bags[MAX_BAGS];
    int num_bags;
} Conveyor;

typedef struct CheckInCounter {
    int id;
    int num_bags_processed;
} CheckInCounter;

// Simulation parameters
int num_bags = 50;
int num_conveyors = 5;
int num_check_in_counters = 3;
int simulation_time = 100;

// Initialize baggage system components
Bag *bags[MAX_BAGS];
Conveyor *conveyors[MAX_CONVEYORS];
CheckInCounter *check_in_counters[MAX_CHECK_IN_COUNTERS];

void initialize_bags() {
    for (int i = 0; i < num_bags; i++) {
        bags[i] = malloc(sizeof(Bag));
        bags[i]->id = i;
        bags[i]->weight = rand() % 50 + 1; // Random weight between 1 and 50 kg
        bags[i]->destination = rand() % 10; // Random destination between 0 and 9
    }
}

void initialize_conveyors() {
    for (int i = 0; i < num_conveyors; i++) {
        conveyors[i] = malloc(sizeof(Conveyor));
        conveyors[i]->id = i;
        conveyors[i]->length = rand() % 100 + 1; // Random length between 1 and 100 meters
        conveyors[i]->speed = rand() % 10 + 1; // Random speed between 1 and 10 m/s
        conveyors[i]->num_bags = 0;
    }
}

void initialize_check_in_counters() {
    for (int i = 0; i < num_check_in_counters; i++) {
        check_in_counters[i] = malloc(sizeof(CheckInCounter));
        check_in_counters[i]->id = i;
        check_in_counters[i]->num_bags_processed = 0;
    }
}

// Simulation loop
void simulate() {
    for (int time = 0; time < simulation_time; time++) {
        // Check in bags
        for (int i = 0; i < num_bags; i++) {
            int check_in_counter_id = rand() % num_check_in_counters;
            CheckInCounter *check_in_counter = check_in_counters[check_in_counter_id];
            check_in_counter->num_bags_processed++;
        }

        // Move bags on conveyors
        for (int i = 0; i < num_conveyors; i++) {
            Conveyor *conveyor = conveyors[i];
            for (int j = 0; j < conveyor->num_bags; j++) {
                Bag *bag = conveyor->bags[j];
                bag->destination--;
                if (bag->destination == 0) {
                    // Remove bag from conveyor
                    for (int k = j; k < conveyor->num_bags - 1; k++) {
                        conveyor->bags[k] = conveyor->bags[k + 1];
                    }
                    conveyor->num_bags--;
                }
            }
        }
    }
}

// Print simulation results
void print_results() {
    printf("Number of bags: %d\n", num_bags);
    printf("Number of conveyors: %d\n", num_conveyors);
    printf("Number of check-in counters: %d\n", num_check_in_counters);
    printf("Simulation time: %d\n", simulation_time);
    printf("\n");

    // Print conveyor statistics
    printf("Conveyor statistics:\n");
    for (int i = 0; i < num_conveyors; i++) {
        Conveyor *conveyor = conveyors[i];
        printf("Conveyor %d: length = %d m, speed = %d m/s, num_bags = %d\n",
                conveyor->id, conveyor->length, conveyor->speed, conveyor->num_bags);
    }
    printf("\n");

    // Print check-in counter statistics
    printf("Check-in counter statistics:\n");
    for (int i = 0; i < num_check_in_counters; i++) {
        CheckInCounter *check_in_counter = check_in_counters[i];
        printf("Check-in counter %d: num_bags_processed = %d\n",
                check_in_counter->id, check_in_counter->num_bags_processed);
    }
}

// Free memory
void free_memory() {
    for (int i = 0; i < num_bags; i++) {
        free(bags[i]);
    }
    for (int i = 0; i < num_conveyors; i++) {
        free(conveyors[i]);
    }
    for (int i = 0; i < num_check_in_counters; i++) {
        free(check_in_counters[i]);
    }
}

int main() {
    initialize_bags();
    initialize_conveyors();
    initialize_check_in_counters();
    simulate();
    print_results();
    free_memory();
    return 0;
}