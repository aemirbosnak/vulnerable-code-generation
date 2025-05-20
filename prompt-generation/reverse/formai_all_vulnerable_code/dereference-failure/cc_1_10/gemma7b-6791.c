//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100
#define MAX_LUGGAGE 50

typedef struct Passenger {
    char name[50];
    int numBags;
    struct Passenger* next;
} Passenger;

typedef struct Luggage {
    char description[200];
    int weight;
    struct Luggage* next;
} Luggage;

void addPassenger(Passenger** head, char* name, int numBags) {
    Passenger* newPassenger = malloc(sizeof(Passenger));
    strcpy(newPassenger->name, name);
    newPassenger->numBags = numBags;
    newPassenger->next = NULL;

    if (*head == NULL) {
        *head = newPassenger;
    } else {
        (*head)->next = newPassenger;
    }
}

void addLuggage(Luggage** head, char* description, int weight) {
    Luggage* newLuggage = malloc(sizeof(Luggage));
    strcpy(newLuggage->description, description);
    newLuggage->weight = weight;
    newLuggage->next = NULL;

    if (*head == NULL) {
        *head = newLuggage;
    } else {
        (*head)->next = newLuggage;
    }
}

void printPassengers(Passenger* head) {
    Passenger* currentPassenger = head;
    while (currentPassenger) {
        printf("Name: %s, Number of Bags: %d\n", currentPassenger->name, currentPassenger->numBags);
        currentPassenger = currentPassenger->next;
    }
}

void printLuggage(Luggage* head) {
    Luggage* currentLuggage = head;
    while (currentLuggage) {
        printf("Description: %s, Weight: %d\n", currentLuggage->description, currentLuggage->weight);
        currentLuggage = currentLuggage->next;
    }
}

int main() {
    Passenger* passengers = NULL;
    Luggage* luggage = NULL;

    addPassenger(&passengers, "John Doe", 3);
    addPassenger(&passengers, "Jane Doe", 2);
    addPassenger(&passengers, "Bob Smith", 4);

    addLuggage(&luggage, "Suitcase", 20);
    addLuggage(&luggage, "Handbag", 10);
    addLuggage(&luggage, "Backpack", 15);

    printPassengers(passengers);
    printLuggage(luggage);

    return 0;
}