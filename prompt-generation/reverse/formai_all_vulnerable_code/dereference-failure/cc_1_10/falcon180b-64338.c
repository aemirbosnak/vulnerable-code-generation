//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_DESTINATIONS 20
#define MAX_BAG_SIZE 50

typedef struct {
    int flight_number;
    char origin[20];
    char destination[20];
    int num_bags;
    int *bag_sizes;
} Flight;

typedef struct {
    int flight_number;
    int bag_size;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];

void generate_flights() {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flight_number = i + 1;
        sprintf(flights[i].origin, "City%d", rand() % MAX_DESTINATIONS + 1);
        sprintf(flights[i].destination, "City%d", rand() % MAX_DESTINATIONS + 1);
        flights[i].num_bags = rand() % 10 + 1;
        flights[i].bag_sizes = malloc(flights[i].num_bags * sizeof(int));

        int j;
        for (j = 0; j < flights[i].num_bags; j++) {
            flights[i].bag_sizes[j] = rand() % MAX_BAG_SIZE + 1;
        }
    }
}

void print_flights() {
    int i;

    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %d: %s -> %s (%d bags)\n", flights[i].flight_number, flights[i].origin, flights[i].destination, flights[i].num_bags);
    }
}

void generate_bags() {
    int i, j;

    for (i = 0; i < MAX_FLIGHTS; i++) {
        for (j = 0; j < flights[i].num_bags; j++) {
            bags[j].flight_number = flights[i].flight_number;
            bags[j].bag_size = flights[i].bag_sizes[j];
        }
    }
}

void print_bags() {
    int i;

    for (i = 0; i < MAX_BAGS; i++) {
        printf("Bag %d: Flight %d, Size %d\n", i + 1, bags[i].flight_number, bags[i].bag_size);
    }
}

int main() {
    generate_flights();
    generate_bags();

    print_flights();
    print_bags();

    return 0;
}