//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_flights, num_conveyors, num_bags, max_bags_per_flight, max_weight_per_bag;
    int **flights, **conveyors, *weights;
    srand(time(NULL));

    // Getting user input for the number of flights, conveyors, bags, bags per flight and weight per bag
    printf("Enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("Enter the number of conveyors: ");
    scanf("%d", &num_conveyors);
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);
    printf("Enter the maximum number of bags per flight: ");
    scanf("%d", &max_bags_per_flight);
    printf("Enter the maximum weight per bag: ");
    scanf("%d", &max_weight_per_bag);

    // Allocating memory for flights and conveyors
    flights = (int **)malloc(num_flights * sizeof(int *));
    for (int i = 0; i < num_flights; i++) {
        flights[i] = (int *)malloc((max_bags_per_flight + 1) * sizeof(int));
        flights[i][0] = rand() % max_bags_per_flight + 1;
        for (int j = 1; j <= flights[i][0]; j++) {
            flights[i][j] = rand() % max_weight_per_bag + 1;
        }
    }
    conveyors = (int **)calloc(num_conveyors, sizeof(int *));
    for (int i = 0; i < num_conveyors; i++) {
        conveyors[i] = (int *)calloc(2, sizeof(int));
    }

    // Assigning bags to flights randomly
    for (int i = 0; i < num_bags; i++) {
        int flight_num = rand() % num_flights;
        int weight = rand() % max_weight_per_bag + 1;
        if (flights[flight_num][0] < max_bags_per_flight) {
            flights[flight_num][flights[flight_num][0] + 1] = weight;
            flights[flight_num][0]++;
        } else {
            i--;
        }
    }

    // Moving bags using conveyors
    for (int i = 0; i < num_conveyors; i++) {
        int bag_index = 0;
        while (bag_index < num_bags) {
            int bag_weight = weights[bag_index];
            if (bag_weight > conveyors[i][1]) {
                conveyors[i][1] = bag_weight;
            } else {
                conveyors[i][1] *= 0.9;
            }
            bag_index++;
        }
    }

    // De-allocating memory
    for (int i = 0; i < num_flights; i++) {
        free(flights[i]);
    }
    free(flights);
    for (int i = 0; i < num_conveyors; i++) {
        free(conveyors[i]);
    }
    free(conveyors);
    free(weights);

    return 0;
}