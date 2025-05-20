//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

Passenger* insert_passenger(Passenger* head) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    new_passenger->next = NULL;

    if (head == NULL) {
        head = new_passenger;
    } else {
        head->next = new_passenger;
    }

    return head;
}

void calculate_baggage_fees(Passenger* head) {
    while (head) {
        int fee = 0;
        if (head->baggage_weight <= 20) {
            fee = 50;
        } else if (head->baggage_weight <= 30) {
            fee = 75;
        } else if (head->baggage_weight <= 40) {
            fee = 100;
        } else {
            fee = 125;
        }

        printf("%s's baggage fee is %d.\n", head->name, fee);
        head = head->next;
    }
}

int main() {
    Passenger* head = NULL;

    // Insert passengers
    insert_passenger(head);
    insert_passenger(head);
    insert_passenger(head);

    // Calculate baggage fees
    calculate_baggage_fees(head);

    return 0;
}