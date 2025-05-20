//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_LUGGAGE_WEIGHT 50
#define MAX_FLIGHTS 10
#define MAX_TIME 100

struct baggage {
    int flight_number;
    int weight;
};

typedef struct {
    struct baggage bags[MAX_BAGGAGE];
    int num_bags;
} flight_baggage;

int main() {
    srand(time(NULL));
    flight_baggage flights[MAX_FLIGHTS];
    int i, j, k, num_flights, num_ops, time_elapsed;
    printf("Enter number of flights: ");
    scanf("%d", &num_flights);
    printf("Enter number of operations: ");
    scanf("%d", &num_ops);
    for (i = 0; i < num_flights; i++) {
        flights[i].num_bags = 0;
        flights[i].bags[0].flight_number = i+1;
        for (j = 1; j < 5; j++) {
            flights[i].bags[j].flight_number = flights[i].bags[0].flight_number;
            flights[i].bags[j].weight = rand() % MAX_LUGGAGE_WEIGHT + 1;
            flights[i].num_bags += 1;
        }
        printf("Flight %d has been scheduled with %d bags.\n", flights[i].bags[0].flight_number, flights[i].num_bags);
    }

    for (i = 0; i < num_ops; i++) {
        int flight_index = rand() % num_flights;
        int op_type = rand() % 2; // 0 for arrival, 1 for departure
        if (op_type == 0) { // flight arrival
            printf("Flight %d has arrived.\n", flights[flight_index].bags[0].flight_number);
            time_elapsed = rand() % MAX_TIME + 1;
            for (j = 0; j < flights[flight_index].num_bags; j++) {
                printf("Processing baggage %d of weight %d...\n", j+1, flights[flight_index].bags[j].weight);
                time_elapsed += rand() % MAX_TIME + 1;
            }
            printf("All baggage for flight %d has been processed in %d minutes.\n", flights[flight_index].bags[0].flight_number, time_elapsed);
        } else { // flight departure
            printf("Flight %d is departing.\n", flights[flight_index].bags[0].flight_number);
            time_elapsed = rand() % MAX_TIME + 1;
            for (j = 0; j < flights[flight_index].num_bags; j++) {
                printf("Loading baggage %d of weight %d...\n", j+1, flights[flight_index].bags[j].weight);
                time_elapsed += rand() % MAX_TIME + 1;
            }
            printf("All baggage for flight %d has been loaded in %d minutes.\n", flights[flight_index].bags[0].flight_number, time_elapsed);
        }
    }

    return 0;
}