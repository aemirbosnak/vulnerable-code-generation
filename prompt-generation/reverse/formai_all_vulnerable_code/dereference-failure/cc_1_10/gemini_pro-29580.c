//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_CHECKIN_COUNTERS 5
#define MAX_BAGGAGE_CLAIM_AREAS 5

typedef struct {
    int id;
    char *flight_number;
    time_t departure_time;
    time_t arrival_time;
    int num_bags;
} flight_t;

typedef struct {
    int id;
    char *name;
    int num_bags;
} passenger_t;

typedef struct {
    int id;
    char *name;
    int num_bags;
} baggage_t;

// Create a new flight
flight_t *create_flight(int id, char *flight_number, time_t departure_time, time_t arrival_time, int num_bags) {
    flight_t *flight = malloc(sizeof(flight_t));
    flight->id = id;
    flight->flight_number = strdup(flight_number);
    flight->departure_time = departure_time;
    flight->arrival_time = arrival_time;
    flight->num_bags = num_bags;
    return flight;
}

// Create a new passenger
passenger_t *create_passenger(int id, char *name, int num_bags) {
    passenger_t *passenger = malloc(sizeof(passenger_t));
    passenger->id = id;
    passenger->name = strdup(name);
    passenger->num_bags = num_bags;
    return passenger;
}

// Create a new baggage
baggage_t *create_baggage(int id, char *name, int num_bags) {
    baggage_t *baggage = malloc(sizeof(baggage_t));
    baggage->id = id;
    baggage->name = strdup(name);
    baggage->num_bags = num_bags;
    return baggage;
}

// Print a flight
void print_flight(flight_t *flight) {
    printf("Flight %s, departing at %s, arriving at %s, with %d bags\n",
        flight->flight_number, ctime(&flight->departure_time), ctime(&flight->arrival_time), flight->num_bags);
}

// Print a passenger
void print_passenger(passenger_t *passenger) {
    printf("Passenger %s, with %d bags\n", passenger->name, passenger->num_bags);
}

// Print a baggage
void print_baggage(baggage_t *baggage) {
    printf("Baggage %s, with %d bags\n", baggage->name, baggage->num_bags);
}

// Main function
int main() {
    // Create a list of flights
    flight_t *flights[MAX_FLIGHTS];
    flights[0] = create_flight(1, "AA123", time(NULL), time(NULL) + 3600, 10);
    flights[1] = create_flight(2, "UA456", time(NULL) + 3600, time(NULL) + 7200, 15);
    flights[2] = create_flight(3, "DL789", time(NULL) + 7200, time(NULL) + 10800, 20);

    // Create a list of passengers
    passenger_t *passengers[MAX_CHECKIN_COUNTERS];
    passengers[0] = create_passenger(1, "John Smith", 1);
    passengers[1] = create_passenger(2, "Jane Doe", 2);
    passengers[2] = create_passenger(3, "Bill Jones", 3);
    passengers[3] = create_passenger(4, "Mary Johnson", 4);
    passengers[4] = create_passenger(5, "Bob Brown", 5);

    // Create a list of baggage
    baggage_t *baggage[MAX_BAGGAGE_CLAIM_AREAS];
    baggage[0] = create_baggage(1, "John Smith's baggage", 1);
    baggage[1] = create_baggage(2, "Jane Doe's baggage", 2);
    baggage[2] = create_baggage(3, "Bill Jones' baggage", 3);
    baggage[3] = create_baggage(4, "Mary Johnson's baggage", 4);
    baggage[4] = create_baggage(5, "Bob Brown's baggage", 5);

    // Print the list of flights
    printf("Flights:\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        print_flight(flights[i]);
    }

    // Print the list of passengers
    printf("Passengers:\n");
    for (int i = 0; i < MAX_CHECKIN_COUNTERS; i++) {
        print_passenger(passengers[i]);
    }

    // Print the list of baggage
    printf("Baggage:\n");
    for (int i = 0; i < MAX_BAGGAGE_CLAIM_AREAS; i++) {
        print_baggage(baggage[i]);
    }

    return 0;
}