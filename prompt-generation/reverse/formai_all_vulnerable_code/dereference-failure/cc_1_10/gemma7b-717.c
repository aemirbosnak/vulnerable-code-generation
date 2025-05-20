//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car {
    int lane;
    int position;
    int speed;
    int direction;
    struct Car* next;
} Car;

Car* createCar() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->lane = rand() % MAX_LANE;
    car->position = rand() % MAX_LANE;
    car->speed = rand() % 5;
    car->direction = rand() % 2;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    Car* tail = head;

    while (1) {
        time_t t = time(NULL);
        printf("Time: %ld\n", t);

        // Move cars
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->position++;
                    break;
                case 1:
                    car->position--;
                    break;
            }

            // Check if car has reached its destination
            if (car->position == MAX_LANE - 1) {
                car->direction = 1;
            } else if (car->position == 0) {
                car->direction = 0;
            }
        }

        // Print car positions
        for (Car* car = head; car; car = car->next) {
            printf("Car %p: Lane %d, Position %d, Speed %d\n", car, car->lane, car->position, car->speed);
        }

        sleep(1);
    }
}

int main() {
    simulateTrafficFlow();
    return 0;
}