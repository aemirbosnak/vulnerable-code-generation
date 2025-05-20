//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10

typedef struct Passenger {
    char name[20];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void add_passenger(Passenger** head) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    printf("Enter passenger name: ");
    scanf("%s", new_passenger->name);
    printf("Enter baggage weight: ");
    scanf("%d", &new_passenger->baggage_weight);
    new_passenger->next = NULL;

    if (*head == NULL) {
        *head = new_passenger;
    } else {
        (*head)->next = new_passenger;
    }
}

void calculate_total_baggage_weight(Passenger* head) {
    int total_weight = 0;
    while (head) {
        total_weight += head->baggage_weight;
        head = head->next;
    }
    printf("Total baggage weight: %d", total_weight);
}

int main() {
    Passenger* head = NULL;
    int num_passengers = 0;

    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);

    for (int i = 0; i < num_passengers; i++) {
        add_passenger(&head);
    }

    calculate_total_baggage_weight(head);

    return 0;
}