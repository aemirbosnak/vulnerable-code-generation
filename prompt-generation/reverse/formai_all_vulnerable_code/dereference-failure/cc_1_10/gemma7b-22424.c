//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSENGERS 100
#define MAX_BAGS 20

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Bag {
    char label[20];
    struct Bag* next;
} Bag;

void insertPassenger(Passenger** head, char* name, int numBags) {
    Passenger* newPassenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void insertBag(Bag** head, char* label) {
    Bag* newBag = (Bag*)malloc(sizeof(Bag));
    strcpy(newBag->label, label);
    newBag->next = NULL;

    if (*head == NULL) {
        *head = newBag;
    } else {
        (*head)->next = newBag;
    }
}

void simulateBaggageHandling() {
    Passenger* head = NULL;
    Bag* bagsHead = NULL;

    insertPassenger(&head, "John Doe", 3);
    insertPassenger(&head, "Jane Doe", 2);
    insertPassenger(&head, "Peter Pan", 1);

    insertBag(&bagsHead, "Bag 1");
    insertBag(&bagsHead, "Bag 2");
    insertBag(&bagsHead, "Bag 3");

    // Simulate baggage handling process
    printf("Passenger: %s, number of bags: %d\n", head->name, head->numBags);
    printf("Bags:");
    for (Bag* bag = bagsHead; bag; bag = bag->next) {
        printf(" %s", bag->label);
    }

    printf("\n");
}

int main() {
    simulateBaggageHandling();

    return 0;
}