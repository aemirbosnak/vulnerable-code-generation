//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRIVAL 1
#define DEPARTURE 2
#define MAX_BAGS 1000
#define MAX_CHECKINS 100
#define MAX_ARRIVALS 100

typedef struct {
    int id;
    int weight;
    int destination;
    int status; // ARRIVAL or DEPARTURE
} Baggage;

typedef struct {
    int id;
    int num_bags;
    Baggage bags[MAX_BAGS];
} Checkin;

typedef struct {
    int id;
    int num_bags;
    Baggage bags[MAX_ARRIVALS];
} Arrival;

typedef struct {
    int num_checkins;
    Checkin checkins[MAX_CHECKINS];
    int num_arrivals;
    Arrival arrivals[MAX_ARRIVALS];
} Airport;

// Create a new airport
Airport *create_airport() {
    Airport *airport = malloc(sizeof(Airport));
    airport->num_checkins = 0;
    airport->num_arrivals = 0;

    for (int i = 0; i < MAX_CHECKINS; i++) {
        airport->checkins[i].id = i;
        airport->checkins[i].num_bags = 0;
    }

    for (int i = 0; i < MAX_ARRIVALS; i++) {
        airport->arrivals[i].id = i;
        airport->arrivals[i].num_bags = 0;
    }

    return airport;
}

// Create a new checkin
Checkin *create_checkin(Airport *airport) {
    Checkin *checkin = malloc(sizeof(Checkin));
    checkin->id = airport->num_checkins++;
    checkin->num_bags = 0;

    return checkin;
}

// Create a new arrival
Arrival *create_arrival(Airport *airport) {
    Arrival *arrival = malloc(sizeof(Arrival));
    arrival->id = airport->num_arrivals++;
    arrival->num_bags = 0;

    return arrival;
}

// Add a new baggage to a checkin
void add_baggage_to_checkin(Checkin *checkin, Baggage *baggage) {
    checkin->bags[checkin->num_bags++] = *baggage;
}

// Add a new baggage to an arrival
void add_baggage_to_arrival(Arrival *arrival, Baggage *baggage) {
    arrival->bags[arrival->num_bags++] = *baggage;
}

// Print the airport status
void print_airport(Airport *airport) {
    printf("Airport status:\n");

    for (int i = 0; i < airport->num_checkins; i++) {
        Checkin *checkin = &airport->checkins[i];
        printf("Checkin %d:\n", checkin->id);
        for (int j = 0; j < checkin->num_bags; j++) {
            Baggage *baggage = &checkin->bags[j];
            printf(" - Baggage %d: %d kg, destination %d\n", baggage->id, baggage->weight, baggage->destination);
        }
    }

    for (int i = 0; i < airport->num_arrivals; i++) {
        Arrival *arrival = &airport->arrivals[i];
        printf("Arrival %d:\n", arrival->id);
        for (int j = 0; j < arrival->num_bags; j++) {
            Baggage *baggage = &arrival->bags[j];
            printf(" - Baggage %d: %d kg, arrived from %d\n", baggage->id, baggage->weight, baggage->destination);
        }
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Create a new airport
    Airport *airport = create_airport();

    // Create some checkins
    for (int i = 0; i < 10; i++) {
        Checkin *checkin = create_checkin(airport);

        // Add some baggage to each checkin
        for (int j = 0; j < rand() % MAX_BAGS; j++) {
            Baggage baggage;
            baggage.id = j;
            baggage.weight = rand() % 50 + 1;
            baggage.destination = rand() % 10 + 1;
            baggage.status = DEPARTURE;

            add_baggage_to_checkin(checkin, &baggage);
        }
    }

    // Create some arrivals
    for (int i = 0; i < 10; i++) {
        Arrival *arrival = create_arrival(airport);

        // Add some baggage to each arrival
        for (int j = 0; j < rand() % MAX_ARRIVALS; j++) {
            Baggage baggage;
            baggage.id = j;
            baggage.weight = rand() % 50 + 1;
            baggage.destination = rand() % 10 + 1;
            baggage.status = ARRIVAL;

            add_baggage_to_arrival(arrival, &baggage);
        }
    }

    // Print the airport status
    print_airport(airport);

    return 0;
}