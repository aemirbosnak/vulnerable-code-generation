//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

typedef struct {
    int id;
    char destination[20];
} Flight;

typedef struct {
    int id;
    int weight;
    Flight* flight;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];
int num_bags = 0, num_flights = 0;

void generate_flights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].id = i + 1;
        strcpy(flights[i].destination, ("Destination " + (char)(i % 3 + 'A')));
    }
}

void check_in_bags() {
    srand(time(NULL));
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % 50 + 5;
        int flight_index = rand() % MAX_FLIGHTS;
        bags[i].flight = &flights[flight_index];
        printf("Passenger %d checked in bag %d with weight %d going to %s\n", i/10 + 1, i+1, bags[i].weight, bags[i].flight->destination);
        num_bags++;
    }
}

void load_bags_onto_plane(int flight_id) {
    for (int i = 0; i < num_bags; i++) {
        if (bags[i].flight->id == flight_id) {
            printf("Bag %d with weight %d loaded onto plane %d\n", bags[i].id, bags[i].weight, flight_id);
        }
    }
}

int main() {
    generate_flights();
    check_in_bags();

    printf("\nBegin boarding...\n");

    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("\nBoarding plane %d going to %s...\n", flights[i].id, flights[i].destination);
        load_bags_onto_plane(flights[i].id);
    }

    printf("\nAll planes have departed.\n");

    return 0;
}