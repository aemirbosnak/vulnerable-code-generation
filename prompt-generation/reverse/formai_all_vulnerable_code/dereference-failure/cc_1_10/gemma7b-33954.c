//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int speed;
    struct Car* next;
} Car;

void simulateTrafficFlow() {
    // Create a linked list of cars
    Car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        Car* newCar = (Car*)malloc(sizeof(Car));
        newCar->lane = rand() % NUM_LANE;
        newCar->speed = rand() % 5 + 1;
        newCar->next = head;
        head = newCar;
    }

    // Simulate traffic flow for a certain time
    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        // Move each car forward
        Car* currentCar = head;
        while (currentCar) {
            currentCar->lane = (currentCar->lane + currentCar->speed) % NUM_LANE;
            currentCar = currentCar->next;
        }

        // Print the traffic flow
        for (int i = 0; i < NUM_LANE; i++) {
            printf("Lane %d:", i);
            for (Car* car = head; car; car = car->next) {
                if (car->lane == i) {
                    printf(" Car: Lane %d, Speed %d", car->lane, car->speed);
                }
            }
            printf("\n");
        }

        // Sleep for a random amount of time
        sleep(rand() % 5);
    }

    // Free the memory of the cars
    Car* currentCar = head;
    while (currentCar) {
        Car* nextCar = currentCar->next;
        free(currentCar);
        currentCar = nextCar;
    }
}

int main() {
    simulateTrafficFlow();

    return 0;
}