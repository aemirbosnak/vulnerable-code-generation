//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 50

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char tag[20];
    int weight;
    struct Bag* next;
} Bag;

void simulate_airport() {
    // Create a list of passengers
    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
        strcpy(new_passenger->name, "Passenger " + i);
        new_passenger->numBags = rand() % MAX_BAGS;
        new_passenger->next = head;
        head = new_passenger;
    }

    // Create a list of bags
    Bag* tail = NULL;
    for (int i = 0; i < MAX_BAGS; i++) {
        Bag* new_bag = (Bag*)malloc(sizeof(Bag));
        strcpy(new_bag->tag, "Bag " + i);
        new_bag->weight = rand() % 20;
        new_bag->next = tail;
        tail = new_bag;
    }

    // Simulate passenger baggage handling
    time_t start_time = time(NULL);
    for (Passenger* passenger = head; passenger; passenger++) {
        int num_bags = passenger->numBags;
        for (int i = 0; i < num_bags; i++) {
            for (Bag* bag = tail; bag; bag--) {
                if (strcmp(bag->tag, passenger->name) == 0) {
                    printf("%s is retrieving Bag %s\n", passenger->name, bag->tag);
                    tail = bag->next;
                    break;
                }
            }
        }
    }

    time_t end_time = time(NULL);
    printf("Total time spent handling baggage: %ld seconds\n", end_time - start_time);
}

int main() {
    simulate_airport();
    return 0;
}