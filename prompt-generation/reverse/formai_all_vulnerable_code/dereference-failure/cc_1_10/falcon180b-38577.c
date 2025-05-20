//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_FLIGHTS 10
#define BAG_SIZE 4

struct baggage {
    int flight_num;
    int dest_city;
    int status;
    struct baggage *next;
};

struct baggage *baggage_list[NUM_BAGS] = {NULL};
int num_bags = 0;

struct baggage *create_baggage(int flight_num, int dest_city) {
    struct baggage *bag = (struct baggage*)malloc(sizeof(struct baggage));
    bag->flight_num = flight_num;
    bag->dest_city = dest_city;
    bag->status = 0;
    bag->next = NULL;
    return bag;
}

void add_baggage(struct baggage *bag) {
    baggage_list[num_bags++] = bag;
}

void display_baggage() {
    int i;
    printf("Baggage List:\n");
    for(i=0; i<num_bags; i++) {
        struct baggage *bag = baggage_list[i];
        while(bag!= NULL) {
            printf("Flight %d, Dest %d, Status %d\n", bag->flight_num, bag->dest_city, bag->status);
            bag = bag->next;
        }
    }
}

int main() {
    int i, j;
    srand(time(NULL));

    // Create baggage for each flight
    for(i=0; i<NUM_FLIGHTS; i++) {
        int num_bags_flight = rand() % (BAG_SIZE*2) + 1;
        printf("Flight %d has %d bags\n", i+1, num_bags_flight);
        for(j=0; j<num_bags_flight; j++) {
            int dest_city = rand() % 10 + 1;
            struct baggage *bag = create_baggage(i+1, dest_city);
            add_baggage(bag);
        }
    }

    // Display initial baggage list
    display_baggage();

    // Simulate baggage handling
    for(i=0; i<NUM_BAGS; i++) {
        int flight_num = baggage_list[i]->flight_num;
        int dest_city = baggage_list[i]->dest_city;
        printf("Handling baggage for flight %d, dest %d\n", flight_num, dest_city);
        if(dest_city % 2 == 0) {
            baggage_list[i]->status = 1;
        } else {
            baggage_list[i]->status = 2;
        }
    }

    // Display final baggage list
    display_baggage();

    return 0;
}