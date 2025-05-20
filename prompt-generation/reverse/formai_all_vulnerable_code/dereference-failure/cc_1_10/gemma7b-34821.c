//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_PASSENGERS 10

typedef struct Passenger {
    char name[50];
    int baggage_count;
    struct Passenger* next;
} Passenger;

Passenger* head = NULL;

void add_passenger(char* name, int baggage_count) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(new_passenger->name, name);
    new_passenger->baggage_count = baggage_count;
    new_passenger->next = NULL;

    if (head == NULL) {
        head = new_passenger;
    } else {
        head->next = new_passenger;
        head = new_passenger;
    }
}

void handle_baggage(int baggage_count) {
    printf("Handling baggage for %s with %d bags...\n", head->name, baggage_count);

    switch (baggage_count) {
        case 1:
            printf("Loading one bag...\n");
            break;
        case 2:
            printf("Loading two bags...\n");
            break;
        case 3:
            printf("Loading three bags...\n");
            break;
        default:
            printf("Error loading baggage.\n");
            break;
    }

    printf("Baggage handling complete.\n");
}

int main() {
    add_passenger("John Doe", 2);
    add_passenger("Jane Doe", 3);
    add_passenger("Peter Pan", 1);

    handle_baggage(head->baggage_count);
    handle_baggage(head->next->baggage_count);
    handle_baggage(head->next->next->baggage_count);

    return 0;
}