//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 100

typedef struct Passenger {
    char name[50];
    int flight_number;
    struct Passenger* next;
} Passenger;

void simulate_baggage_handling(Passenger* head) {
    time_t start_time = time(NULL);

    // Randomly select passengers and their baggage
    for (int i = 0; i < 10; i++) {
        Passenger* passenger = head;
        while (passenger) {
            if (rand() % MAX_PASSENGERS == i) {
                printf("%s is checking in for flight %d\n", passenger->name, passenger->flight_number);
                break;
            }
            passenger = passenger->next;
        }
    }

    // Simulate baggage weighing and sorting
    for (int i = 0; i < 5; i++) {
        printf("Baggage item %d is being weighed\n", i);
        sleep(rand() % 3);
    }

    // Sort baggage by weight
    printf("Bags are being sorted...\n");
    sleep(rand() % 5);

    // Load baggage onto the plane
    printf("Bags are being loaded onto the plane\n");
    sleep(rand() % 2);

    time_t end_time = time(NULL);
    printf("Total time spent on baggage handling: %d seconds\n", end_time - start_time);
}

int main() {
    // Create a linked list of passengers
    Passenger* head = NULL;
    for (int i = 0; i < MAX_PASSENGERS; i++) {
        Passenger* passenger = (Passenger*)malloc(sizeof(Passenger));
        passenger->name[0] = 'A' + i;
        passenger->flight_number = rand() % 1000;
        passenger->next = head;
        head = passenger;
    }

    // Simulate baggage handling
    simulate_baggage_handling(head);

    return 0;
}