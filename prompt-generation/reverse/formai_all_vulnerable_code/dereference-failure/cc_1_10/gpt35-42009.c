//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 50

typedef struct car {
    int id;
    int roadIndex;
    int position;
} Car;

typedef struct road {
    int length;
    int capacity;
    int numCars;
    Car **cars;
} Road;

void moveCar(Car *car, Road **roads);
void printRoad(Road *road);

int main() {
    srand(time(NULL));
    Road **roads = calloc(MAX_ROADS, sizeof(Road *));
    for (int i = 0; i < MAX_ROADS; i++) {
        roads[i] = calloc(1, sizeof(Road));
        roads[i]->length = rand() % 10 + 5;
        roads[i]->capacity = rand() % 5 + 1;
    }

    Car *cars[MAX_CARS];
    for (int i = 0; i < MAX_CARS; i++) {
        cars[i] = calloc(1, sizeof(Car));
        cars[i]->id = i;
        cars[i]->roadIndex = rand() % MAX_ROADS;
        cars[i]->position = rand() % roads[cars[i]->roadIndex]->length;
        roads[cars[i]->roadIndex]->numCars++;
        roads[cars[i]->roadIndex]->cars = realloc(roads[cars[i]->roadIndex]->cars,
                roads[cars[i]->roadIndex]->numCars * sizeof(Car *));
        roads[cars[i]->roadIndex]->cars[roads[cars[i]->roadIndex]->numCars - 1] = cars[i];
    }

    int totalMoves = 0;
    while (1) {
        for (int i = 0; i < MAX_ROADS; i++) {
            for (int j = 0; j < roads[i]->numCars; j++) {
                moveCar(roads[i]->cars[j], roads);
            }
        }
        printf("Step %d\n", totalMoves);
        for (int i = 0; i < MAX_ROADS; i++) {
            printRoad(roads[i]);
        }
        totalMoves++;
        if (totalMoves == 100) {
            break;
        }
    }

    for (int i = 0; i < MAX_CARS; i++) {
        free(cars[i]);
    }
    for (int i = 0; i < MAX_ROADS; i++) {
        free(roads[i]->cars);
        free(roads[i]);
    }
    free(roads);

    return 0;
}

void moveCar(Car *car, Road **roads) {
    if (car->position + 1 < roads[car->roadIndex]->length) {
        if (roads[car->roadIndex]->cars[car->position + 1] == NULL) {
            roads[car->roadIndex]->cars[car->position + 1] = car;
            roads[car->roadIndex]->cars[car->position] = NULL;
            car->position++;
        }
    } else {
        // this car is at the end of the road
        int nextRoadIndex = car->roadIndex + 1;
        if (nextRoadIndex < MAX_ROADS) {
            int nextRoadCarCapacity = roads[nextRoadIndex]->capacity - roads[nextRoadIndex]->numCars;
            if (nextRoadCarCapacity > 0) {
                car->position = 0;
                car->roadIndex = nextRoadIndex;
                roads[nextRoadIndex]->numCars++;
                roads[nextRoadIndex]->cars = realloc(roads[nextRoadIndex]->cars,
                        roads[nextRoadIndex]->numCars * sizeof(Car *));
                roads[nextRoadIndex]->cars[roads[nextRoadIndex]->numCars - 1] = car;
                roads[car->roadIndex]->cars[car->position] = car;
                roads[car->roadIndex]->numCars--;
            }
        }
    }
}

void printRoad(Road *road) {
    printf("Road with length %d and capacity %d:\n", road->length, road->capacity);
    for (int i = 0; i < road->length; i++) {
        if (road->cars[i] != NULL) {
            printf("%d ", road->cars[i]->id);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}