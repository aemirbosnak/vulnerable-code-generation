//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_BAGS 20

typedef struct Passenger {
    char name[20];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char label[20];
    struct Bag* next;
} Bag;

void simulate_airport() {
    Passenger* head = NULL;
    Bag* headBags = NULL;

    // Simulate passenger check-in
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
        strcpy(newPassenger->name, "Passenger " + i);
        newPassenger->numBags = rand() % MAX_BAGS;

        if (head == NULL) {
            head = newPassenger;
        } else {
            head->next = newPassenger;
            head = newPassenger;
        }
    }

    // Simulate baggage handling
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        for (int i = 0; i < passenger->numBags; i++) {
            Bag* newBag = (Bag*)malloc(sizeof(Bag));
            strcpy(newBag->label, "Bag " + i);

            if (headBags == NULL) {
                headBags = newBag;
            } else {
                headBags->next = newBag;
                headBags = newBag;
            }
        }
    }

    // Print passenger and baggage information
    printf("Passengers:\n");
    for (Passenger* passenger = head; passenger; passenger = passenger->next) {
        printf("%s has %d bags.\n", passenger->name, passenger->numBags);
    }

    printf("Bags:\n");
    for (Bag* bag = headBags; bag; bag = bag->next) {
        printf("%s\n", bag->label);
    }
}

int main() {
    simulate_airport();

    return 0;
}