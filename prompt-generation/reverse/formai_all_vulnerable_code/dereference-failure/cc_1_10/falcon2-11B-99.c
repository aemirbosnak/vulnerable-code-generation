//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int size;
    char color[50];
} Baggage;

typedef struct {
    char name[50];
    int weight;
} Passenger;

typedef struct {
    char name[50];
    int arrivalTime;
} Flight;

int compare(const void *a, const void *b) {
    Baggage *bagA = (Baggage *) a;
    Baggage *bagB = (Baggage *) b;

    if (strcmp(bagA->name, bagB->name) == 0) {
        return 0;
    } else if (strcmp(bagA->name, bagB->name) < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    srand(time(NULL));

    Baggage *baggage = malloc(10 * sizeof(Baggage));
    Passenger *passengers = malloc(5 * sizeof(Passenger));
    Flight *flights = malloc(3 * sizeof(Flight));

    // Populate baggage, passengers, and flights
    for (int i = 0; i < 10; i++) {
        strcpy(baggage[i].name, "Baggage ");
        baggage[i].size = rand() % 10 + 1;
        strcpy(baggage[i].color, "Random color");
    }

    for (int i = 0; i < 5; i++) {
        strcpy(passengers[i].name, "Passenger ");
        passengers[i].weight = rand() % 100 + 1;
    }

    for (int i = 0; i < 3; i++) {
        strcpy(flights[i].name, "Flight ");
        flights[i].arrivalTime = rand() % 24 + 1;
    }

    // Sort baggage based on name
    qsort(baggage, 10, sizeof(Baggage), compare);

    // Sort passengers based on name
    qsort(passengers, 5, sizeof(Passenger), compare);

    // Sort flights based on arrival time
    qsort(flights, 3, sizeof(Flight), compare);

    // Print results
    printf("Baggage:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s (%d), %s\n", baggage[i].name, baggage[i].size, baggage[i].color);
    }

    printf("\nPassengers:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s (%d)\n", passengers[i].name, passengers[i].weight);
    }

    printf("\nFlights:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s (%d:%02d)\n", flights[i].name, flights[i].arrivalTime, flights[i].arrivalTime % 12);
    }

    free(baggage);
    free(passengers);
    free(flights);

    return 0;
}