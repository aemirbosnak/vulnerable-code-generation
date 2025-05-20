//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_TICKETS 50

typedef struct {
    int flight_num;
    int num_bags;
    int* bag_tags;
} flight_info;

void print_baggage(flight_info* flights, int num_flights) {
    printf("********************\n");
    printf("***  BAGGAGE LIST ***\n");
    printf("********************\n");

    for(int i = 0; i < num_flights; i++) {
        printf("Flight number: %d\n", flights[i].flight_num);
        printf("Number of bags: %d\n", flights[i].num_bags);
        printf("Bag tags: [");
        for(int j = 0; j < flights[i].num_bags; j++) {
            printf("%d ", flights[i].bag_tags[j]);
        }
        printf("]\n");
        printf("********************\n");
    }
}

int main() {
    srand(time(NULL));

    flight_info flights[MAX_FLIGHTS];
    int num_flights = rand() % MAX_FLIGHTS + 1;

    for(int i = 0; i < num_flights; i++) {
        int flight_num = i + 1;
        int num_bags = rand() % MAX_BAGS + 1;
        int* bag_tags = (int*)malloc(num_bags * sizeof(int));

        for(int j = 0; j < num_bags; j++) {
            bag_tags[j] = rand() % MAX_TICKETS + 1;
        }

        flights[i].flight_num = flight_num;
        flights[i].num_bags = num_bags;
        flights[i].bag_tags = bag_tags;
    }

    print_baggage(flights, num_flights);

    for(int i = 0; i < num_flights; i++) {
        free(flights[i].bag_tags);
    }

    return 0;
}