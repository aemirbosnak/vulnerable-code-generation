//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    char flight_number[10];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void insert_passenger(Passenger** head, char* name, char* flight_number, int baggage_weight) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    strcpy(new_passenger->name, name);
    strcpy(new_passenger->flight_number, flight_number);
    new_passenger->baggage_weight = baggage_weight;
    new_passenger->next = NULL;

    if (*head == NULL) {
        *head = new_passenger;
    } else {
        (*head)->next = new_passenger;
    }
}

void print_passengers(Passenger* head) {
    while (head) {
        printf("%s, %s, %d\n", head->name, head->flight_number, head->baggage_weight);
        head = head->next;
    }
}

int calculate_total_baggage_weight(Passenger* head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->baggage_weight;
        head = head->next;
    }
    return total_weight;
}

int main() {
    Passenger* head = NULL;
    insert_passenger(&head, "John Doe", "AA123", 20);
    insert_passenger(&head, "Jane Doe", "BB456", 30);
    insert_passenger(&head, "Peter Pan", "CC789", 40);

    print_passengers(head);

    int total_weight = calculate_total_baggage_weight(head);
    printf("Total baggage weight: %d\n", total_weight);

    return 0;
}