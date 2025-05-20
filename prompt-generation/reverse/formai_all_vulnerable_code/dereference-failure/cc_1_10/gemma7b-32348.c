//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 100

typedef struct Passenger
{
    char name[50];
    char destination[50];
    int baggage_weight;
    struct Passenger* next;
} Passenger;

void handle_baggage(Passenger* passenger)
{
    int baggage_fee = 0;
    if (passenger->baggage_weight <= 20)
    {
        baggage_fee = 10;
    }
    else if (passenger->baggage_weight <= 30)
    {
        baggage_fee = 15;
    }
    else
    {
        baggage_fee = 20;
    }

    printf("Passenger: %s, Destination: %s, Baggage Weight: %d, Baggage Fee: %d\n", passenger->name, passenger->destination, passenger->baggage_weight, baggage_fee);
}

int main()
{
    Passenger* head = NULL;
    Passenger* tail = NULL;

    // Create a few passengers
    Passenger* passenger1 = (Passenger*)malloc(sizeof(Passenger));
    strcpy(passenger1->name, "John Doe");
    strcpy(passenger1->destination, "New York");
    passenger1->baggage_weight = 25;

    Passenger* passenger2 = (Passenger*)malloc(sizeof(Passenger));
    strcpy(passenger2->name, "Jane Doe");
    strcpy(passenger2->destination, "Los Angeles");
    passenger2->baggage_weight = 35;

    Passenger* passenger3 = (Passenger*)malloc(sizeof(Passenger));
    strcpy(passenger3->name, "Peter Pan");
    strcpy(passenger3->destination, "Neverland");
    passenger3->baggage_weight = 40;

    // Add passengers to the list
    if (head == NULL)
    {
        head = passenger1;
        tail = passenger1;
    }
    else
    {
        tail->next = passenger1;
        tail = passenger1;
    }

    if (head->next)
    {
        tail->next = passenger2;
        tail = passenger2;
    }

    if (head->next->next)
    {
        tail->next = passenger3;
        tail = passenger3;
    }

    // Handle baggage for each passenger
    handle_baggage(passenger1);
    handle_baggage(passenger2);
    handle_baggage(passenger3);

    return 0;
}