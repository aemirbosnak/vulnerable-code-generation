//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Baggage types
#define SMALL 1
#define MEDIUM 2
#define LARGE 3

// Baggage conveyor belt
struct belt {
    int* baggage;
    int size;
    int head;
    int tail;
};

// Airport baggage system
struct airport {
    struct belt belts[3];  // Small, medium, large baggage belts
    int num_belts;
    int num_arrivals;
    int num_departures;
};

// Initialize baggage conveyor belt
struct belt* create_belt(int size) {
    struct belt* belt = malloc(sizeof(struct belt));
    belt->size = size;
    belt->baggage = malloc(sizeof(int) * size);
    belt->head = 0;
    belt->tail = 0;
    return belt;
}

// Destroy baggage conveyor belt
void destroy_belt(struct belt* belt) {
    free(belt->baggage);
    free(belt);
}

// Initialize airport baggage system
struct airport* create_airport(int num_belts, int num_arrivals, int num_departures) {
    struct airport* airport = malloc(sizeof(struct airport));
    airport->num_belts = num_belts;
    for (int i = 0; i < num_belts; i++) {
        airport->belts[i] = *create_belt(100);
    }
    airport->num_arrivals = num_arrivals;
    airport->num_departures = num_departures;
    return airport;
}

// Destroy airport baggage system
void destroy_airport(struct airport* airport) {
    for (int i = 0; i < airport->num_belts; i++) {
        destroy_belt(&airport->belts[i]);
    }
    free(airport);
}

// Add baggage to conveyor belt
void add_baggage(struct belt* belt, int type) {
    belt->baggage[belt->tail++] = type;
    belt->tail %= belt->size;
}

// Remove baggage from conveyor belt
int remove_baggage(struct belt* belt) {
    int type = belt->baggage[belt->head++];
    belt->head %= belt->size;
    return type;
}

// Simulate airport baggage handling
void simulate_airport(struct airport* airport) {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random baggage arrivals and departures
    for (int i = 0; i < airport->num_arrivals; i++) {
        int type = rand() % 3 + 1;
        add_baggage(&airport->belts[type - 1], type);
    }

    // Process baggage departures
    for (int i = 0; i < airport->num_departures; i++) {
        for (int j = 0; j < airport->num_belts; j++) {
            // Process next baggage item
            int type = remove_baggage(&airport->belts[j]);

            // Send baggage to departure gate
            printf("Baggage %d: Sent to departure gate %d\n", type, j + 1);
        }
    }
}

// Main function
int main() {
    // Create airport baggage system
    struct airport* airport = create_airport(3, 100, 50);

    // Simulate airport baggage handling
    simulate_airport(airport);

    // Destroy airport baggage system
    destroy_airport(airport);

    return 0;
}