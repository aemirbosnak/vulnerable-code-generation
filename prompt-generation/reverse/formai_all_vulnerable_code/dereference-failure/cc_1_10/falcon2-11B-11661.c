//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CHECKED_BAGS 100
#define NUM_CARRIERS 10
#define NUM_AIRPORTS 5

typedef struct {
    char* flight_number;
    int checked_bags;
    int checked_at;
} Flight;

typedef struct {
    char* airport_name;
    int carriers;
    int checked_bags;
} Airport;

int main() {
    srand(time(NULL)); // seed random number generator

    Flight* flights = (Flight*) malloc(NUM_CHECKED_BAGS * sizeof(Flight));
    Airport* airports = (Airport*) malloc(NUM_AIRPORTS * sizeof(Airport));
    int checked_bags = 0;
    int checked_at = 0;

    for (int i = 0; i < NUM_CHECKED_BAGS; i++) {
        flights[i].checked_bags = rand() % 10 + 1;
        checked_bags += flights[i].checked_bags;
        flights[i].checked_at = rand() % NUM_AIRPORTS + 1;
    }

    for (int i = 0; i < NUM_AIRPORTS; i++) {
        airports[i].airport_name = (char*) malloc(100);
        airports[i].carriers = rand() % NUM_CARRIERS + 1;
        airports[i].checked_bags = 0;
    }

    // Assign bags to flights
    for (int i = 0; i < NUM_CHECKED_BAGS; i++) {
        int flight_num = rand() % NUM_AIRPORTS + 1;
        int carrier_num = rand() % NUM_CARRIERS + 1;
        if (airports[flight_num - 1].carriers < NUM_CARRIERS) {
            airports[flight_num - 1].carriers++;
            airports[flight_num - 1].checked_bags += flights[i].checked_bags;
        } else {
            for (int j = 0; j < NUM_CARRIERS; j++) {
                if (airports[j].carriers < NUM_CARRIERS) {
                    airports[j].carriers++;
                    airports[j].checked_bags += flights[i].checked_bags;
                    break;
                }
            }
        }
        flights[i].flight_number = (char*) malloc(100);
        sprintf(flights[i].flight_number, "Flight %d", flight_num);
    }

    // Print results
    for (int i = 0; i < NUM_AIRPORTS; i++) {
        printf("%s\n", airports[i].airport_name);
        printf("Carriers: %d\nChecked Bags: %d\n\n", airports[i].carriers, airports[i].checked_bags);
    }

    for (int i = 0; i < NUM_CHECKED_BAGS; i++) {
        printf("%s\n", flights[i].flight_number);
        printf("Checked Bags: %d\nChecked at: %d\n\n", flights[i].checked_bags, flights[i].checked_at);
    }

    free(flights);
    free(airports);

    return 0;
}