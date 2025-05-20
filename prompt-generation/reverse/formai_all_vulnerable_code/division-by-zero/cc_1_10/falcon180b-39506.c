//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 10
#define MAX_CARS 100
#define MAX_TIME 1000

typedef struct {
    int id;
    int road;
    int speed;
    int time;
} Car;

typedef struct {
    int id;
    int length;
    int capacity;
    int cars;
} Road;

Car cars[MAX_CARS];
Road roads[MAX_ROADS];

int main() {
    int i, j, k, n;
    int totalCars = 0;
    int totalRoads = 0;

    srand(time(NULL));

    printf("Enter the number of roads: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        roads[i].id = i + 1;
        roads[i].length = rand() % 1000 + 1;
        roads[i].capacity = rand() % 100 + 1;
        roads[i].cars = 0;
        totalRoads++;
    }

    printf("Enter the number of cars: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        cars[i].id = i + 1;
        cars[i].road = rand() % totalRoads + 1;
        cars[i].speed = rand() % 100 + 1;
        cars[i].time = 0;
        totalCars++;
    }

    printf("Starting traffic flow simulation...\n");

    for (k = 0; k < MAX_TIME; k++) {
        for (i = 0; i < totalCars; i++) {
            j = cars[i].road;

            if (roads[j].cars < roads[j].capacity) {
                roads[j].cars++;
                cars[i].time++;
            } else {
                cars[i].time++;
            }

            if (cars[i].time >= roads[j].length) {
                cars[i].road = rand() % totalRoads + 1;
                cars[i].time = 0;
            }
        }
    }

    return 0;
}