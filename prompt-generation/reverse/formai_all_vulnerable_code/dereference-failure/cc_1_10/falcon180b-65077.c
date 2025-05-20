//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_CYCLES 100

typedef struct {
    int id;
    int road;
    int speed;
    int cycle;
} Car;

typedef struct {
    int id;
    int length;
    int cycle_time;
} Road;

int main() {
    int num_roads, num_cars;
    srand(time(NULL));
    printf("Enter the number of roads: ");
    scanf("%d", &num_roads);
    printf("Enter the number of cars: ");
    scanf("%d", &num_cars);

    Road *roads = (Road*) malloc(num_roads * sizeof(Road));
    Car *cars = (Car*) malloc(num_cars * sizeof(Car));

    for (int i = 0; i < num_roads; i++) {
        roads[i].id = i;
        printf("Enter the length of road %d: ", i+1);
        scanf("%d", &roads[i].length);
        printf("Enter the cycle time of road %d: ", i+1);
        scanf("%d", &roads[i].cycle_time);
    }

    for (int i = 0; i < num_cars; i++) {
        cars[i].id = i;
        printf("Enter the road for car %d: ", i+1);
        scanf("%d", &cars[i].road);
        printf("Enter the speed of car %d: ", i+1);
        scanf("%d", &cars[i].speed);
        printf("Enter the cycle for car %d: ", i+1);
        scanf("%d", &cars[i].cycle);
    }

    int current_cycle = 0;
    while (current_cycle < MAX_CYCLES) {
        for (int i = 0; i < num_roads; i++) {
            int total_cars = 0;
            for (int j = 0; j < num_cars; j++) {
                if (cars[j].road == i) {
                    if (current_cycle % cars[j].cycle == 0) {
                        total_cars++;
                    }
                }
            }
            if (total_cars > 0) {
                printf("Road %d has %d cars at cycle %d\n", i+1, total_cars, current_cycle);
            }
        }
        current_cycle++;
    }

    return 0;
}