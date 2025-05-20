//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct car {
    int lane;
    int position;
    int speed;
    struct car* next;
} car;

void simulateTrafficFlow() {
    // Create a linked list of cars
    car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        car* newCar = (car*)malloc(sizeof(car));
        newCar->lane = rand() % NUM_LANE;
        newCar->position = rand() % 100;
        newCar->speed = rand() % 5 + 1;
        newCar->next = head;
        head = newCar;
    }

    // Simulate traffic flow for a certain time
    int time = 0;
    while (time < 100) {
        // Move each car
        car* currentCar = head;
        while (currentCar) {
            currentCar->position += currentCar->speed * time / 100;

            // If the car reaches the end of its lane, it changes lanes
            if (currentCar->position % NUM_LANE == 0) {
                currentCar->lane = (currentCar->lane + 1) % NUM_LANE;
            }

            currentCar = currentCar->next;
        }

        time++;
    }

    // Print the final positions of the cars
    car* currentCar = head;
    while (currentCar) {
        printf("Car %d is at position %d in lane %d\n", currentCar->position, currentCar->lane);
        currentCar = currentCar->next;
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}