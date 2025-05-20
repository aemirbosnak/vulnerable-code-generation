//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    STOPPED,
    ACCELERATING,
    DECELERATING,
    MERGING
} State;

typedef struct {
    State state;
    int speed;
    int lane;
    int time;
    int distance;
} Vehicle;

typedef struct {
    int numVehicles;
    Vehicle* vehicles;
} Traffic;

void createTraffic(Traffic* traffic, int numVehicles) {
    traffic->numVehicles = numVehicles;
    traffic->vehicles = (Vehicle*)malloc(numVehicles * sizeof(Vehicle));
    for (int i = 0; i < numVehicles; i++) {
        traffic->vehicles[i].state = STOPPED;
        traffic->vehicles[i].speed = 0;
        traffic->vehicles[i].lane = rand() % 4;
        traffic->vehicles[i].time = 0;
        traffic->vehicles[i].distance = 0;
    }
}

void updateTraffic(Traffic* traffic, int numVehicles) {
    for (int i = 0; i < numVehicles; i++) {
        if (traffic->vehicles[i].state == STOPPED) {
            traffic->vehicles[i].speed = 0;
        } else if (traffic->vehicles[i].state == ACCELERATING) {
            traffic->vehicles[i].speed += 10;
        } else if (traffic->vehicles[i].state == DECELERATING) {
            traffic->vehicles[i].speed -= 10;
        } else if (traffic->vehicles[i].state == MERGING) {
            traffic->vehicles[i].speed += 5;
        }
    }
}

void printTraffic(Traffic* traffic, int numVehicles) {
    printf("Vehicles: %d\n", numVehicles);
    for (int i = 0; i < numVehicles; i++) {
        printf("Vehicle %d:\n", i);
        printf("State: %s\n", (traffic->vehicles[i].state == STOPPED)? "Stopped" : "Moving");
        printf("Speed: %d\n", traffic->vehicles[i].speed);
        printf("Lane: %d\n", traffic->vehicles[i].lane);
        printf("Time: %d\n", traffic->vehicles[i].time);
        printf("Distance: %d\n", traffic->vehicles[i].distance);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Traffic traffic;
    createTraffic(&traffic, 100);
    updateTraffic(&traffic, 100);
    printTraffic(&traffic, 100);
    return 0;
}