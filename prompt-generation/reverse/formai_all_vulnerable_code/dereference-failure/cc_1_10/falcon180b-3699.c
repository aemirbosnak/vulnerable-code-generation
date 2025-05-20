//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_FLIGHTS 100

typedef struct {
    int flight_number;
    int destination;
    int num_bags;
    int *bag_ids;
} Flight;

typedef struct {
    int id;
    int flight_number;
    int destination;
    int status;
} Bag;

int main() {
    srand(time(NULL));

    Flight flights[MAX_FLIGHTS];
    Bag bags[MAX_BAGS];

    int num_flights = rand() % 10 + 1; // Generate random number of flights between 1 and 10
    for (int i = 0; i < num_flights; i++) {
        flights[i].flight_number = i + 1;
        flights[i].destination = rand() % 10 + 1;
        flights[i].num_bags = rand() % 10 + 1;
        flights[i].bag_ids = malloc(flights[i].num_bags * sizeof(int));
        for (int j = 0; j < flights[i].num_bags; j++) {
            Bag bag;
            bag.id = rand() % MAX_BAGS + 1;
            bag.flight_number = flights[i].flight_number;
            bag.destination = flights[i].destination;
            bag.status = 0; // Not loaded yet
            flights[i].bag_ids[j] = bag.id;
            bags[bag.id] = bag;
        }
    }

    int num_loaded_bags = 0;
    while (num_loaded_bags < MAX_BAGS) {
        int bag_id = rand() % MAX_BAGS + 1;
        Bag bag = bags[bag_id];
        if (bag.status == 0) {
            int flight_number = bag.flight_number;
            int destination = bag.destination;
            Flight flight = flights[flight_number - 1];
            int bag_index = -1;
            for (int i = 0; i < flight.num_bags; i++) {
                if (flight.bag_ids[i] == bag_id) {
                    bag_index = i;
                    break;
                }
            }
            if (bag_index == -1) {
                printf("Bag %d loaded onto flight %d going to %d\n", bag_id, flight_number, destination);
                flight.bag_ids[flight.num_bags - 1] = bag_id;
                flight.num_bags++;
                bag.status = 1;
                num_loaded_bags++;
            } else {
                printf("Bag %d already loaded onto flight %d\n", bag_id, flight_number);
            }
        }
    }

    return 0;
}