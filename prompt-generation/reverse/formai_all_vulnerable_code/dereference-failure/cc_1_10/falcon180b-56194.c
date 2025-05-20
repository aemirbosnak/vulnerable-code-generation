//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_FLIGHTS 100
#define MAX_BAG_TYPES 10
#define MAX_FLIGHT_TYPES 10

typedef struct {
    int flight_number;
    int num_bags;
    int *bag_types;
} Flight;

typedef struct {
    int type;
    int size;
    int weight;
} Bag;

int main() {
    srand(time(0));

    // Initialize flights
    Flight flights[MAX_FLIGHTS];
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flight_number = i + 1;
        flights[i].num_bags = rand() % 50 + 1;
        flights[i].bag_types = malloc(flights[i].num_bags * sizeof(int));
        for (int j = 0; j < flights[i].num_bags; j++) {
            flights[i].bag_types[j] = rand() % MAX_BAG_TYPES + 1;
        }
    }

    // Initialize bag types
    Bag bag_types[MAX_BAG_TYPES];
    for (int i = 0; i < MAX_BAG_TYPES; i++) {
        bag_types[i].type = i + 1;
        bag_types[i].size = rand() % 100 + 1;
        bag_types[i].weight = rand() % 50 + 1;
    }

    // Simulate baggage handling
    int num_lost_bags = 0;
    int num_delayed_bags = 0;
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d has %d bags:\n", flights[i].flight_number, flights[i].num_bags);
        for (int j = 0; j < flights[i].num_bags; j++) {
            int bag_type = flights[i].bag_types[j];
            Bag *bag = &bag_types[bag_type - 1];
            printf("\tBag %d: Type %d, Size %d, Weight %d\n", j + 1, bag->type, bag->size, bag->weight);

            if (bag->size > 50 || bag->weight > 50) {
                printf("\t\tThis bag is oversized/overweight and will be delayed.\n");
                num_delayed_bags++;
            } else if (rand() % 10 == 0) {
                printf("\t\tThis bag has been lost in transit.\n");
                num_lost_bags++;
            }
        }
    }

    printf("\nTotal number of lost bags: %d\n", num_lost_bags);
    printf("Total number of delayed bags: %d\n", num_delayed_bags);

    return 0;
}