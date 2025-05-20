//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: retro
#include <stdlib.h>
#include <time.h>

#define MAX_Passengers 10

typedef struct Passenger {
    char name[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

Passenger* head = NULL;

void addPassenger(char* name, int baggage_weight) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(new_passenger->name, name);
    new_passenger->baggage_weight = baggage_weight;
    new_passenger->next = NULL;

    if (head == NULL) {
        head = new_passenger;
    } else {
        head->next = new_passenger;
        head = new_passenger;
    }
}

void simulateBaggageHandling() {
    time_t start_time = time(NULL);
    int num_passengers = rand() % MAX_Passengers;

    for (int i = 0; i < num_passengers; i++) {
        addPassenger("Passenger " + i, rand() % 20);
    }

    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        printf("Processing passenger: %s, baggage weight: %d\n", passenger->name, passenger->baggage_weight);
    }

    time_t end_time = time(NULL);
    int total_time = end_time - start_time;

    printf("Total time: %d seconds\n", total_time);
}

int main() {
    simulateBaggageHandling();

    return 0;
}