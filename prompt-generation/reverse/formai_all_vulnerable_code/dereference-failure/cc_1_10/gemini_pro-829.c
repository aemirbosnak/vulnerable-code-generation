//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the airport structure
typedef struct airport {
    int num_gates;
    int num_belts;
    int *gates;
    int *belts;
} airport;

// Define the baggage structure
typedef struct baggage {
    int weight;
    int destination;
} baggage;

// Define the event structure
typedef struct event {
    int type;
    int time;
    int gate;
    int belt;
    baggage *baggage;
} event;

// Create a new airport
airport *create_airport(int num_gates, int num_belts) {
    airport *a = malloc(sizeof(airport));
    a->num_gates = num_gates;
    a->num_belts = num_belts;
    a->gates = malloc(sizeof(int) * num_gates);
    a->belts = malloc(sizeof(int) * num_belts);
    for (int i = 0; i < num_gates; i++) {
        a->gates[i] = 0;
    }
    for (int i = 0; i < num_belts; i++) {
        a->belts[i] = 0;
    }
    return a;
}

// Destroy an airport
void destroy_airport(airport *a) {
    free(a->gates);
    free(a->belts);
    free(a);
}

// Create a new baggage
baggage *create_baggage(int weight, int destination) {
    baggage *b = malloc(sizeof(baggage));
    b->weight = weight;
    b->destination = destination;
    return b;
}

// Destroy a baggage
void destroy_baggage(baggage *b) {
    free(b);
}

// Create a new event
event *create_event(int type, int time, int gate, int belt, baggage *baggage) {
    event *e = malloc(sizeof(event));
    e->type = type;
    e->time = time;
    e->gate = gate;
    e->belt = belt;
    e->baggage = baggage;
    return e;
}

// Destroy an event
void destroy_event(event *e) {
    free(e);
}

// Compare two events
int compare_events(event *a, event *b) {
    return a->time - b->time;
}

// Simulate an airport
void simulate_airport(airport *a, int num_events) {
    // Create a priority queue of events
    event **events = malloc(sizeof(event *) * num_events);
    int num_events_processed = 0;

    // Generate random events
    for (int i = 0; i < num_events; i++) {
        // Generate a random event type
        int type = rand() % 3;

        // Generate a random time
        int time = rand() % 100;

        // Generate a random gate
        int gate = rand() % a->num_gates;

        // Generate a random belt
        int belt = rand() % a->num_belts;

        // Generate a random baggage
        baggage *baggage = create_baggage(rand() % 100, rand() % a->num_belts);

        // Create an event
        event *e = create_event(type, time, gate, belt, baggage);

        // Insert the event into the priority queue
        events[num_events_processed] = e;
        num_events_processed++;
    }

    // Sort the events by time
    qsort(events, num_events_processed, sizeof(event *), compare_events);

    // Process the events
    for (int i = 0; i < num_events_processed; i++) {
        event *e = events[i];

        // Process the event
        if (e->type == 0) {
            // Arrive at gate
            a->gates[e->gate]++;
        } else if (e->type == 1) {
            // Depart from gate
            a->gates[e->gate]--;
        } else if (e->type == 2) {
            // Load baggage onto belt
            a->belts[e->belt] += e->baggage->weight;
        } else if (e->type == 3) {
            // Unload baggage from belt
            a->belts[e->belt] -= e->baggage->weight;
        }

        // Destroy the event
        destroy_event(e);
    }

    // Print the results
    printf("Gates:\n");
    for (int i = 0; i < a->num_gates; i++) {
        printf("%d: %d\n", i, a->gates[i]);
    }
    printf("Belts:\n");
    for (int i = 0; i < a->num_belts; i++) {
        printf("%d: %d\n", i, a->belts[i]);
    }

    // Free the events
    free(events);
}

// Main function
int main() {
    // Create an airport
    airport *a = create_airport(10, 10);

    // Simulate the airport
    simulate_airport(a, 1000);

    // Destroy the airport
    destroy_airport(a);

    return 0;
}