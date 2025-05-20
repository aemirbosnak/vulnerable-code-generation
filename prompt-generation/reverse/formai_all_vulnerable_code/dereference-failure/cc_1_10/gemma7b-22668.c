//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 10

typedef struct Car {
    int lane;
    int speed;
    int position;
    struct Car* next;
} Car;

Car* createCar(int lane, int speed, int position) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = lane;
    car->speed = speed;
    car->position = position;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* head) {
    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        for (Car* car = head; car; car = car->next) {
            // Accelerate
            if (car->speed < 5) {
                car->speed++;
            }

            // Lane change
            if (rand() % 10 == 0) {
                int newLane = rand() % NUM_LANE;
                if (newLane != car->lane) {
                    car->lane = newLane;
                }
            }

            // Move forward
            car->position++;
            if (car->position >= 100) {
                car->position = 0;
            }
        }

        // Sleep
        sleep(1);
    }
}

int main() {
    Car* head = createCar(1, 2, 0);
    head = createCar(2, 3, 10);
    head = createCar(0, 4, 20);

    simulateTrafficFlow(head);

    return 0;
}