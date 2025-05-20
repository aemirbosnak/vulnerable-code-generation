//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_FLIGHTS 100
#define MAX_BAG_SIZE 50

typedef struct {
    char flight_number[6];
    int num_bags;
    int *bag_ids;
} Flight;

typedef struct {
    int id;
    char destination[6];
    int size;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];

void generate_flights() {
    srand(time(NULL));
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        sprintf(flights[i].flight_number, "FLT%d", i + 1);
        flights[i].num_bags = rand() % 10 + 1;
        flights[i].bag_ids = (int *) malloc(flights[i].num_bags * sizeof(int));
        for (int j = 0; j < flights[i].num_bags; j++) {
            flights[i].bag_ids[j] = rand() % MAX_BAGS + 1;
        }
    }
}

void generate_bags() {
    srand(time(NULL));
    for (int i = 0; i < MAX_BAGS; i++) {
        sprintf(bags[i].destination, "DEST%d", i + 1);
        bags[i].size = rand() % MAX_BAG_SIZE + 1;
    }
}

void print_flights() {
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("Flight %s has %d bags:\n", flights[i].flight_number, flights[i].num_bags);
        for (int j = 0; j < flights[i].num_bags; j++) {
            printf("  Bag ID %d\n", flights[i].bag_ids[j]);
        }
    }
}

void print_bags() {
    for (int i = 0; i < MAX_BAGS; i++) {
        printf("Bag ID %d is going to %s and is %d units in size.\n", i + 1, bags[i].destination, bags[i].size);
    }
}

int main() {
    generate_flights();
    generate_bags();
    print_flights();
    print_bags();
    return 0;
}