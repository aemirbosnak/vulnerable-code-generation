//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_OF_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    char flight_number[10];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

Passenger* insert_passenger(Passenger* head) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    printf("Enter passenger name: ");
    scanf("%s", new_passenger->name);
    printf("Enter flight number: ");
    scanf("%s", new_passenger->flight_number);
    printf("Enter baggage weight: ");
    scanf("%d", &new_passenger->baggage_weight);
    new_passenger->next = head;
    head = new_passenger;
    return head;
}

void print_passengers(Passenger* head) {
    Passenger* current_passenger = head;
    while (current_passenger) {
        printf("Name: %s\n", current_passenger->name);
        printf("Flight number: %s\n", current_passenger->flight_number);
        printf("Baggage weight: %d\n", current_passenger->baggage_weight);
        printf("\n");
        current_passenger = current_passenger->next;
    }
}

int main() {
    Passenger* head = NULL;
    int num_passengers = 0;

    while (num_passengers < MAX_NUMBER_OF_PASSENGERS) {
        head = insert_passenger(head);
        num_passengers++;
    }

    print_passengers(head);

    return 0;
}