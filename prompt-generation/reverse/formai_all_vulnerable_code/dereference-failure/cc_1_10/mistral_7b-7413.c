//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_BAGS 100
#define MAX_FLIGHTS 20

typedef struct {
    int id;
    char* origin;
    char* destination;
    int num_bags;
    int* bags;
} Flight;

typedef struct {
    int id;
    int weight;
    char status;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];
int num_flights = 0, num_bags = 0;

void generate_flights() {
    srand(time(NULL));
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].id = i + 1;
        flights[i].num_bags = rand() % 10 + 1;
        for (int j = 0; j < flights[i].num_bags; j++) {
            bags[num_bags].id = num_bags + 1;
            bags[num_bags].weight = rand() % 51 + 5;
            bags[num_bags].status = 'A';
            strcpy(flights[i].origin, "CityA");
            strcpy(flights[i].destination, "CityB");
            num_bags++;
        }
        strcpy(flights[i].origin, "CityRandom");
        strcpy(flights[i].destination, "CityRandom");
        num_flights++;
    }
}

void handle_bags(Flight* flight) {
    printf("\nHandling bags for Flight %d (%s -> %s)\n", flight->id, flight->origin, flight->destination);
    for (int i = 0; i < flight->num_bags; i++) {
        Bag* bag = &bags[flight->bags[i]];
        printf("\nBag %d (%d kg) from Flight %d\n", bag->id, bag->weight, flight->id);
        if (bag->weight > 32) {
            printf("Oops! Heavy bag detected! Let's check it out.\n");
            // Surprise event: open bag and check for explosives or other threats
            int threat_detected = rand() % 2;
            if (threat_detected) {
                printf("Threat detected! Evacuate the area immediately!\n");
                // Evacuate the area, notify authorities, etc.
            } else {
                printf("Bag checked and cleared. Continuing baggage handling.\n");
            }
        }
        bag->status = 'B'; // Bag is being handled
    }
    printf("All bags for Flight %d have been handled.\n\n", flight->id);
}

void main() {
    generate_flights();
    for (int i = 0; i < num_flights; i++) {
        handle_bags(&flights[i]);
    }
    printf("All flights have been handled.\n");
}