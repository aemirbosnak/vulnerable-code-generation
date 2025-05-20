//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_FLIGHT_BAGS 15

typedef struct {
    char code[3];
    int num_bags;
} Flight;

typedef struct {
    char id[10];
    int weight;
    Flight* flight;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];

void generate_flights() {
    int i;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        strcpy(flights[i].code, ("F" + (char)('0' + i)));
        flights[i].num_bags = rand() % MAX_FLIGHT_BAGS + 1;
    }
}

void generate_bags() {
    int i, j;
    for (i = 0; i < MAX_BAGS; i++) {
        bags[i].weight = rand() % 50 + 1;
        for (j = 0; j < MAX_FLIGHTS; j++) {
            if (!flights[j].num_bags) {
                bags[i].flight = &flights[j];
                flights[j].num_bags--;
                break;
            }
        }
    }
}

void simulate() {
    int i, j;
    int total_weight = 0;
    srand(time(NULL));

    generate_flights();
    generate_bags();

    printf("------- C Airport Baggage Handling Simulation ---------\n");
    printf("Flight Code | Number of Bags | Total Weight\n");

    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("%-9s | %-11d | %-8d\n", flights[i].code, flights[i].num_bags, 0);
    }

    for (i = 0; i < MAX_BAGS; i++) {
        for (j = 0; j < MAX_FLIGHTS; j++) {
            if (flights[j].num_bags && strcmp(bags[i].id, flights[j].code) == 0) {
                flights[j].num_bags--;
                total_weight += bags[i].weight;
                strcpy(bags[i].id, "");
                break;
            }
        }
    }

    printf("\n");
    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("%-9s | %-11d | %-8d\n", flights[i].code, flights[i].num_bags, total_weight);
    }
}

int main() {
    simulate();
    return 0;
}