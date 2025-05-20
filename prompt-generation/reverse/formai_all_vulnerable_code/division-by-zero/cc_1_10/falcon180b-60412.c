//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROADS 10
#define MAX_CARS 50
#define MAX_TIME 1000

struct Road {
    int length;
    int cars[MAX_CARS];
    int speeds[MAX_CARS];
};

int main() {
    int num_roads, num_cars;
    int i, j;
    struct Road roads[MAX_ROADS];

    // Initialize random seed
    srand(time(NULL));

    // Get number of roads and cars from user input
    printf("Enter number of roads: ");
    scanf("%d", &num_roads);
    printf("Enter number of cars: ");
    scanf("%d", &num_cars);

    // Initialize roads with random lengths
    for (i = 0; i < num_roads; i++) {
        roads[i].length = rand() % 1000;
    }

    // Initialize cars with random speeds
    for (i = 0; i < num_cars; i++) {
        roads[rand() % num_roads].speeds[i] = rand() % 100;
    }

    // Simulate traffic flow for a certain amount of time
    for (j = 0; j < MAX_TIME; j++) {
        // Move each car forward based on its speed
        for (i = 0; i < num_cars; i++) {
            int road_index = roads[i].speeds[i] * j;
            int distance_left = roads[road_index].length - road_index;
            if (distance_left > 0) {
                roads[road_index].cars[i]++;
                roads[road_index].speeds[i]++;
            } else {
                roads[road_index].cars[i] = 0;
                roads[road_index].speeds[i] = 0;
            }
        }
    }

    // Print final state of roads and cars
    printf("\nFinal state:\n");
    for (i = 0; i < num_roads; i++) {
        printf("Road %d: ", i);
        for (j = 0; j < num_cars; j++) {
            if (roads[i].cars[j] > 0) {
                printf("%d ", roads[i].speeds[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    return 0;
}