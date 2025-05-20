//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100

// Baggage structure definition
typedef struct {
    char destination[20];
    int flight_number;
    int weight;
} Baggage;

// Function to initialize baggage
void init_baggage(Baggage* bag) {
    strcpy(bag->destination, "");
    bag->flight_number = 0;
    bag->weight = rand() % 50 + 1;
}

// Function to print baggage details
void print_baggage(Baggage* bag) {
    printf("Destination: %s\n", bag->destination);
    printf("Flight Number: %d\n", bag->flight_number);
    printf("Weight: %d kg\n", bag->weight);
}

// Function to generate random baggage
Baggage generate_baggage() {
    Baggage bag;
    init_baggage(&bag);
    return bag;
}

// Function to sort baggage based on flight number
int compare_flight_number(const void* a, const void* b) {
    const Baggage* bag1 = (const Baggage*)a;
    const Baggage* bag2 = (const Baggage*)b;

    if (bag1->flight_number < bag2->flight_number) {
        return -1;
    } else if (bag1->flight_number > bag2->flight_number) {
        return 1;
    } else {
        return 0;
    }
}

// Function to sort baggage based on destination
int compare_destination(const void* a, const void* b) {
    const Baggage* bag1 = (const Baggage*)a;
    const Baggage* bag2 = (const Baggage*)b;

    return strcmp(bag1->destination, bag2->destination);
}

// Function to simulate baggage handling process
void baggage_handling() {
    srand(time(NULL));

    // Generate random baggage
    Baggage* bags = malloc(MAX_BAGS * sizeof(Baggage));
    for (int i = 0; i < MAX_BAGS; i++) {
        bags[i] = generate_baggage();
    }

    // Sort baggage based on flight number
    qsort(bags, MAX_BAGS, sizeof(Baggage), compare_flight_number);

    // Print sorted baggage list
    printf("Baggage sorted by flight number:\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        print_baggage(&bags[i]);
    }

    // Sort baggage based on destination
    qsort(bags, MAX_BAGS, sizeof(Baggage), compare_destination);

    // Print sorted baggage list
    printf("\nBaggage sorted by destination:\n");
    for (int i = 0; i < MAX_BAGS; i++) {
        print_baggage(&bags[i]);
    }

    // Free memory
    free(bags);
}

int main() {
    baggage_handling();
    return 0;
}