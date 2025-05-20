//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS_PER_FLIGHT 1000
#define MAX_FLIGHTS_PER_DAY 50
#define MAX_TERMINALS 5
#define MAX_WEIGHT_PER_BAG 70

typedef struct {
    int flight_num; // Flight number
    int num_bags; // Number of bags for the flight
    int terminal_num; // Terminal number for the flight
    int* bag_weights; // Array of weights for each bag
} Flight;

typedef struct {
    int terminal_num; // Terminal number
    int* bag_counts; // Array of bag counts for each flight
} Terminal;

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize flights
    Flight flights[MAX_FLIGHTS_PER_DAY];
    for(int i = 0; i < MAX_FLIGHTS_PER_DAY; i++) {
        flights[i].flight_num = i + 1;
        flights[i].num_bags = rand() % MAX_BAGS_PER_FLIGHT + 1;
        flights[i].terminal_num = rand() % MAX_TERMINALS + 1;
        flights[i].bag_weights = malloc(flights[i].num_bags * sizeof(int));
        for(int j = 0; j < flights[i].num_bags; j++) {
            flights[i].bag_weights[j] = rand() % MAX_WEIGHT_PER_BAG + 1;
        }
    }
    
    // Initialize terminals
    Terminal terminals[MAX_TERMINALS];
    for(int i = 0; i < MAX_TERMINALS; i++) {
        terminals[i].terminal_num = i + 1;
        terminals[i].bag_counts = calloc(MAX_FLIGHTS_PER_DAY, sizeof(int));
    }
    
    // Assign bags to terminals
    for(int i = 0; i < MAX_FLIGHTS_PER_DAY; i++) {
        int terminal_num = flights[i].terminal_num - 1;
        terminals[terminal_num].bag_counts[i] = flights[i].num_bags;
    }
    
    // Print out results
    for(int i = 0; i < MAX_TERMINALS; i++) {
        printf("Terminal %d:\n", terminals[i].terminal_num);
        for(int j = 0; j < MAX_FLIGHTS_PER_DAY; j++) {
            printf("Flight %2d: %3d bags | ", flights[j].flight_num, terminals[i].bag_counts[j]);
            for(int k = 0; k < terminals[i].bag_counts[j]; k++) {
                printf("%2d ", flights[j].bag_weights[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Free dynamic memory
    for(int i = 0; i < MAX_FLIGHTS_PER_DAY; i++) {
        free(flights[i].bag_weights);
    }
    for(int i = 0; i < MAX_TERMINALS; i++) {
        free(terminals[i].bag_counts);
    }
    
    return 0;
}