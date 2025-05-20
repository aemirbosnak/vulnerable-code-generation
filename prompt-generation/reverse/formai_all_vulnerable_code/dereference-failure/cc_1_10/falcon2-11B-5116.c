//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of bags and flights
#define MAX_BAGS 1000
#define MAX_FLIGHTS 100

// Define the structure for a bag
typedef struct {
    int bag_id;
    char origin[50];
    char destination[50];
    char owner[50];
    int weight;
} Bag;

// Define the structure for a flight
typedef struct {
    int flight_id;
    char origin[50];
    char destination[50];
    int departure_time;
    int arrival_time;
    int capacity;
} Flight;

// Define the structure for the baggage handling system
typedef struct {
    Bag *bags;
    Flight *flights;
    int num_bags;
    int num_flights;
} BHS;

// Function to initialize the baggage handling system
void init_bhs(BHS *bhs) {
    // Initialize bags array
    bhs->bags = malloc(MAX_BAGS * sizeof(Bag));
    for (int i = 0; i < MAX_BAGS; i++) {
        bhs->bags[i].bag_id = -1;
        strcpy(bhs->bags[i].origin, "");
        strcpy(bhs->bags[i].destination, "");
        strcpy(bhs->bags[i].owner, "");
        bhs->bags[i].weight = 0;
    }

    // Initialize flights array
    bhs->flights = malloc(MAX_FLIGHTS * sizeof(Flight));
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        bhs->flights[i].flight_id = -1;
        strcpy(bhs->flights[i].origin, "");
        strcpy(bhs->flights[i].destination, "");
        bhs->flights[i].departure_time = 0;
        bhs->flights[i].arrival_time = 0;
        bhs->flights[i].capacity = 0;
    }

    // Initialize counters
    bhs->num_bags = 0;
    bhs->num_flights = 0;
}

// Function to add a bag to the system
void add_bag(BHS *bhs, int bag_id, char *origin, char *destination, char *owner, int weight) {
    // Check if bag ID is valid
    if (bag_id < 0 || bag_id >= MAX_BAGS) {
        printf("Invalid bag ID\n");
        return;
    }

    // Check if bag origin and destination are valid
    if (strlen(origin) == 0 || strlen(destination) == 0) {
        printf("Invalid bag origin or destination\n");
        return;
    }

    // Check if bag owner is valid
    if (strlen(owner) == 0) {
        printf("Invalid bag owner\n");
        return;
    }

    // Check if bag weight is valid
    if (weight < 0) {
        printf("Invalid bag weight\n");
        return;
    }

    // Add the bag to the bags array
    bhs->bags[bhs->num_bags].bag_id = bag_id;
    strcpy(bhs->bags[bhs->num_bags].origin, origin);
    strcpy(bhs->bags[bhs->num_bags].destination, destination);
    strcpy(bhs->bags[bhs->num_bags].owner, owner);
    bhs->bags[bhs->num_bags].weight = weight;
    bhs->num_bags++;
}

// Function to add a flight to the system
void add_flight(BHS *bhs, int flight_id, char *origin, char *destination, int departure_time, int arrival_time, int capacity) {
    // Check if flight ID is valid
    if (flight_id < 0 || flight_id >= MAX_FLIGHTS) {
        printf("Invalid flight ID\n");
        return;
    }

    // Check if flight origin and destination are valid
    if (strlen(origin) == 0 || strlen(destination) == 0) {
        printf("Invalid flight origin or destination\n");
        return;
    }

    // Check if flight departure and arrival times are valid
    if (departure_time < 0 || arrival_time < 0) {
        printf("Invalid flight departure or arrival time\n");
        return;
    }

    // Check if flight capacity is valid
    if (capacity < 0) {
        printf("Invalid flight capacity\n");
        return;
    }

    // Add the flight to the flights array
    bhs->flights[bhs->num_flights].flight_id = flight_id;
    strcpy(bhs->flights[bhs->num_flights].origin, origin);
    strcpy(bhs->flights[bhs->num_flights].destination, destination);
    bhs->flights[bhs->num_flights].departure_time = departure_time;
    bhs->flights[bhs->num_flights].arrival_time = arrival_time;
    bhs->flights[bhs->num_flights].capacity = capacity;
    bhs->num_flights++;
}

// Function to print all bags in the system
void print_bags(BHS *bhs) {
    for (int i = 0; i < bhs->num_bags; i++) {
        printf("Bag %d: %s -> %s, %s, %d kg\n", bhs->bags[i].bag_id, bhs->bags[i].origin, bhs->bags[i].destination, bhs->bags[i].owner, bhs->bags[i].weight);
    }
}

// Function to print all flights in the system
void print_flights(BHS *bhs) {
    for (int i = 0; i < bhs->num_flights; i++) {
        printf("Flight %d: %s -> %s, %d:%d, %d kg\n", bhs->flights[i].flight_id, bhs->flights[i].origin, bhs->flights[i].destination, bhs->flights[i].departure_time, bhs->flights[i].arrival_time, bhs->flights[i].capacity);
    }
}

// Function to sort bags by origin and destination
void sort_bags(BHS *bhs) {
    // TODO: Implement sorting algorithm
}

// Function to find the bag with the highest weight
int find_highest_weight_bag(BHS *bhs) {
    int max_weight = 0;
    int highest_weight_bag_id = -1;

    for (int i = 0; i < bhs->num_bags; i++) {
        if (bhs->bags[i].weight > max_weight) {
            max_weight = bhs->bags[i].weight;
            highest_weight_bag_id = bhs->bags[i].bag_id;
        }
    }

    return highest_weight_bag_id;
}

// Function to find the flight with the most bags
int find_flight_with_most_bags(BHS *bhs) {
    int max_bags = 0;
    int most_bags_flight_id = -1;

    for (int i = 0; i < bhs->num_flights; i++) {
        int bags_on_flight = 0;
        for (int j = 0; j < bhs->num_bags; j++) {
            if (strcmp(bhs->bags[j].destination, bhs->flights[i].destination) == 0) {
                bags_on_flight++;
            }
        }

        if (bags_on_flight > max_bags) {
            max_bags = bags_on_flight;
            most_bags_flight_id = bhs->flights[i].flight_id;
        }
    }

    return most_bags_flight_id;
}

// Main function
int main() {
    BHS bhs;
    init_bhs(&bhs);

    add_bag(&bhs, 1, "New York", "Paris", "John", 10);
    add_bag(&bhs, 2, "Paris", "Tokyo", "Jane", 15);
    add_bag(&bhs, 3, "Tokyo", "New York", "Mike", 20);
    add_flight(&bhs, 1, "New York", "Paris", 8, 11, 50);
    add_flight(&bhs, 2, "Paris", "Tokyo", 14, 16, 60);
    add_flight(&bhs, 3, "Tokyo", "New York", 22, 24, 40);

    print_bags(&bhs);
    print_flights(&bhs);

    // TODO: Add more functionality here

    return 0;
}