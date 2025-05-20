//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_PASSENGERS 50

typedef struct {
    int id;
    int weight;
} Baggage;

typedef struct {
    int id;
    Baggage* baggage[MAX_BAGGAGE];
    int num_bags;
} Passenger;

typedef struct {
    int id;
    int capacity;
    int num_bags;
    Baggage* baggage[MAX_BAGGAGE];
} ConveyorBelt;

typedef struct {
    int id;
    int capacity;
    int num_bags;
    Baggage* baggage[MAX_BAGGAGE];
} BaggageCart;

typedef struct {
    int id;
    Passenger* passenger[MAX_PASSENGERS];
    int num_passengers;
} BoardingGate;

void generate_baggage(Baggage* baggage) {
    baggage->id = rand() % 1000;
    baggage->weight = rand() % 30 + 1;
}

void generate_baggage_for_passenger(Passenger* passenger) {
    for(int i=0; i<passenger->num_bags; i++) {
        Baggage* baggage = (Baggage*) malloc(sizeof(Baggage));
        generate_baggage(baggage);
        passenger->baggage[i] = baggage;
    }
}

void add_baggage_to_conveyor_belt(ConveyorBelt* cb, Baggage* baggage) {
    if(cb->num_bags == cb->capacity) {
        printf("Conveyor Belt full! Cannot add more baggage.\n");
    } else {
        cb->baggage[cb->num_bags] = baggage;
        cb->num_bags++;
        printf("Baggage with id %d added to Conveyor Belt\n", baggage->id);
    }
}

Baggage* remove_baggage_from_conveyor_belt(ConveyorBelt* cb) {
    if(cb->num_bags == 0) {
        printf("Conveyor Belt empty! Cannot remove baggage.\n");
        return NULL;
    } else {
        Baggage* baggage = cb->baggage[cb->num_bags-1];
        cb->num_bags--;
        printf("Baggage with id %d removed from Conveyor Belt\n", baggage->id);
        return baggage;
    }
}

void add_baggage_to_cart(BaggageCart* cart, Baggage* baggage) {
    if(cart->num_bags == cart->capacity) {
        printf("Baggage Cart full! Cannot add more baggage.\n");
    } else {
        cart->baggage[cart->num_bags] = baggage;
        cart->num_bags++;
        printf("Baggage with id %d added to Baggage Cart\n", baggage->id);
    }
}

void add_passenger_to_boarding_gate(BoardingGate* bg, Passenger* passenger) {
    if(bg->num_passengers == MAX_PASSENGERS) {
        printf("Boarding Gate full! Cannot add more passengers.\n");
    } else {
        bg->passenger[bg->num_passengers] = passenger;
        bg->num_passengers++;
        printf("Passenger with id %d added to Boarding Gate\n", passenger->id);
    }
}

int main() {
    srand(time(NULL));

    ConveyorBelt cb = { 1, 20, 0 };
    BaggageCart cart = { 1, 5, 0 };
    BoardingGate bg = { 1, {} };

    // Generate passengers and baggage
    for(int i=0; i<MAX_PASSENGERS; i++) {
        Passenger* passenger = (Passenger*) malloc(sizeof(Passenger));
        passenger->id = rand() % 1000;
        passenger->num_bags = rand() % 3 + 1;
        generate_baggage_for_passenger(passenger);

        // Add baggage to conveyor belt
        for(int j=0; j<passenger->num_bags; j++) {
            add_baggage_to_conveyor_belt(&cb, passenger->baggage[j]);
        }

        // Add passenger to boarding gate
        add_passenger_to_boarding_gate(&bg, passenger);
    }

    // Load baggage onto cart from conveyor belt
    while(cb.num_bags > 0) {
        Baggage* baggage = remove_baggage_from_conveyor_belt(&cb);
        add_baggage_to_cart(&cart, baggage);
    }

    // Unload baggage from cart and print details
    printf("Baggage details:\n");
    int total_weight = 0;
    for(int i=0; i<cart.num_bags; i++) {
        Baggage* baggage = cart.baggage[i];
        printf("Baggage id: %d, Weight: %d kgs\n", baggage->id, baggage->weight);
        total_weight += baggage->weight;
    }
    printf("Total weight of baggage: %d kgs\n", total_weight);

    return 0;
}