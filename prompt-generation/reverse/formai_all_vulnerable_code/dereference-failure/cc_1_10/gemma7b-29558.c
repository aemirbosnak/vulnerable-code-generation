//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

Passenger* insert_passenger(Passenger* head, char* name, int baggage_weight) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(new_passenger->name, name);
    new_passenger->baggage_weight = baggage_weight;
    new_passenger->next = NULL;

    if (head == NULL) {
        head = new_passenger;
    } else {
        head->next = new_passenger;
    }

    return head;
}

void print_passengers(Passenger* head) {
    Passenger* current = head;
    while (current) {
        printf("%s has a baggage weight of %d\n", current->name, current->baggage_weight);
        current = current->next;
    }
}

void calculate_total_baggage_weight(Passenger* head) {
    int total_weight = 0;
    Passenger* current = head;
    while (current) {
        total_weight += current->baggage_weight;
        current = current->next;
    }
    printf("Total baggage weight: %d\n", total_weight);
}

int main() {
    Passenger* head = NULL;

    insert_passenger(head, "John Doe", 20);
    insert_passenger(head, "Jane Doe", 30);
    insert_passenger(head, "Peter Pan", 10);

    print_passengers(head);
    calculate_total_baggage_weight(head);

    return 0;
}