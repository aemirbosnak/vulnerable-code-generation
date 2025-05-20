//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// define struct for baggage
typedef struct {
    int weight;
    int size;
} Baggage;

int main() {
    int num_passengers;
    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    printf("Please enter the number of passengers: ");
    scanf("%d", &num_passengers);

    // dynamically allocate memory for an array of passenger names
    char** passenger_names = (char**)malloc(num_passengers * sizeof(char*));
    for (int i = 0; i < num_passengers; i++) {
        passenger_names[i] = (char*)malloc(20 * sizeof(char));
        printf("Enter the name of passenger %d: ", i + 1);
        scanf("%s", passenger_names[i]);
    }

    // dynamically allocate memory for an array of baggage for each passenger
    Baggage** passenger_baggage = (Baggage**)malloc(num_passengers * sizeof(Baggage*));
    for (int i = 0; i < num_passengers; i++) {
        passenger_baggage[i] = (Baggage*)malloc(2 * sizeof(Baggage));
        for (int j = 0; j < 2; j++) {
            printf("Enter the weight of baggage %d for passenger %s: ", j + 1, passenger_names[i]);
            scanf("%d", &passenger_baggage[i][j].weight);
            printf("Enter the size of baggage %d for passenger %s: ", j + 1, passenger_names[i]);
            scanf("%d", &passenger_baggage[i][j].size);
        }
    }

    // print out the baggage of each passenger
    printf("\nPassenger\tBaggage\n");
    for (int i = 0; i < num_passengers; i++) {
        printf("%s\t\t", passenger_names[i]);
        for (int j = 0; j < 2; j++) {
            printf("Weight: %d kg\tSize: %d cm\t", passenger_baggage[i][j].weight, passenger_baggage[i][j].size);
        }
        printf("\n");
    }

    // free dynamically allocated memory
    for (int i = 0; i < num_passengers; i++) {
        free(passenger_names[i]);
        free(passenger_baggage[i]);
    }
    free(passenger_names);
    free(passenger_baggage);

    return 0;
}