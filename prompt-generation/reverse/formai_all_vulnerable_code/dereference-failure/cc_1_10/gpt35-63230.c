//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGGAGE 500
#define MAX_FLIGHTS 20

typedef struct {
    int id;
    char airline[5];
    char destination[30];
    int weight;
} Baggage;

typedef struct {
    int id;
    char airline[5];
    char destination[30];
    int num_bags;
    Baggage *baggage_list[MAX_BAGGAGE];
} Flight;

void generate_random_bags(Baggage *bag_array, int num_bags) {
    char *destination_list[] = {"New York", "London", "Paris", "Tokyo", "Sydney", "Dubai", "Cape Town"};
    char *airline_list[] = {"AA", "UA", "DL", "BA", "AF", "JAL", "Emirates"};

    srand((unsigned int)time(NULL));

    for(int i = 0; i < num_bags; i++) {
        Baggage bag;
        bag.id = rand() % 1000 + 1;
        strcpy(bag.airline, airline_list[rand() % 7]);
        strcpy(bag.destination, destination_list[rand() % 7]);
        bag.weight = rand() % 50 + 1;
        memcpy(&bag_array[i], &bag, sizeof bag);
    }
}

void print_bag(Baggage bag) {
    printf("Bag ID: %d\n", bag.id);
    printf("Airline: %s\n", bag.airline);
    printf("Destination: %s\n", bag.destination);
    printf("Weight: %d\n", bag.weight);
    printf("\n");
}

void print_flight(Flight flight) {
    printf("Flight ID: %d\n", flight.id);
    printf("Airline: %s\n", flight.airline);
    printf("Destination: %s\n", flight.destination);
    printf("Number of bags: %d\n", flight.num_bags);
    printf("List of bags:\n");
    for(int i = 0; i < flight.num_bags; i++) {
        printf("Bag #%d:\n", i+1);
        print_bag(*flight.baggage_list[i]);
    }
}

int main() {
    Flight flight_list[MAX_FLIGHTS];
    int num_flights = 0;
    int total_num_bags = 0;
    Baggage bag_list[MAX_BAGGAGE];

    printf("Welcome to the airport baggage handling simulation!\n");
    printf("--------------------------------------------\n");

    printf("Generating random bags...\n");
    generate_random_bags(bag_list, MAX_BAGGAGE);

    printf("Enter number of flights (maximum %d): ", MAX_FLIGHTS);
    scanf("%d", &num_flights);

    for(int i = 0; i < num_flights; i++) {
        Flight flight;
        flight.id = i+1;
        printf("Enter airline code (e.g. AA, DL): ");
        scanf("%s", flight.airline);
        printf("Enter destination: ");
        scanf("%s", flight.destination);
        printf("Enter number of bags (maximum %d): ", MAX_BAGGAGE);
        scanf("%d", &flight.num_bags);

        if(total_num_bags + flight.num_bags > MAX_BAGGAGE) {
            printf("Error: exceed maximum baggage capacity! Try again.\n");
            i--;
            continue;
        }

        for(int j = 0; j < flight.num_bags; j++) {
            flight.baggage_list[j] = &bag_list[total_num_bags++];
        }

        memcpy(&flight_list[i], &flight, sizeof flight);
    }

    printf("Flight details:\n");
    printf("--------------------------------------------\n");

    for(int i = 0; i < num_flights; i++) {
        print_flight(flight_list[i]);
    }

    return 0;
}