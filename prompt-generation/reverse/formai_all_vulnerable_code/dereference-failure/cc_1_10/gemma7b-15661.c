//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WEIGHT 50
#define MAX_TICKETS 10

typedef struct baggage {
    char name[20];
    int weight;
    int ticket;
} baggage;

void weigh_baggage(baggage *b) {
    printf("Please enter the weight of your baggage (in kg): ");
    scanf("%d", &b->weight);

    if (b->weight > MAX_WEIGHT) {
        printf("Error: baggage weight exceeds limit of %d kg.\n", MAX_WEIGHT);
    } else {
        printf("Baggage weight: %d kg.\n", b->weight);
    }
}

void ticket_baggage(baggage *b) {
    printf("Enter your ticket number: ");
    scanf("%d", &b->ticket);

    if (b->ticket > MAX_TICKETS) {
        printf("Error: invalid ticket number.\n");
    } else {
        printf("Ticket number: %d.\n", b->ticket);
    }
}

void simulate_conveyor_belt(baggage *b) {
    printf("Baggage is being loaded onto the conveyor belt...\n");
    sleep(2);
    printf("Baggage is moving on the conveyor belt...\n");
    sleep(2);
    printf("Baggage has reached its destination.\n");
}

void simulate_baggage_claim(baggage *b) {
    printf("Please claim your baggage at the baggage claim booth.\n");
    sleep(2);
    printf("Your baggage has been retrieved.\n");
}

int main() {
    baggage *b = malloc(sizeof(baggage));

    weigh_baggage(b);
    ticket_baggage(b);
    simulate_conveyor_belt(b);
    simulate_baggage_claim(b);

    free(b);

    return 0;
}