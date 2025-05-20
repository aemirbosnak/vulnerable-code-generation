//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include <stdlib.h>
#include <time.h>

#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3

#define MAX_CARS 5

typedef struct Car {
    int x, y, direction, speed;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed) {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->x = x;
    newCar->y = y;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow() {
    // Create a linked list of cars
    Car* head = createCar(0, 0, NORTH, 2);
    head->next = createCar(1, 0, SOUTH, 3);
    head->next->next = createCar(2, 0, EAST, 4);
    head->next->next->next = createCar(3, 0, WEST, 5);

    // Simulate traffic flow for 10 seconds
    int time = 0;
    while (time < 10) {
        // Move each car
        Car* currentCar = head;
        while (currentCar) {
            switch (currentCar->direction) {
                case NORTH:
                    currentCar->x++;
                    break;
                case SOUTH:
                    currentCar->x--;
                    break;
                case EAST:
                    currentCar->y++;
                    break;
                case WEST:
                    currentCar->y--;
                    break;
            }

            // Change direction randomly with a probability of 10%
            if (rand() % 10 == 0) {
                int newDirection = rand() % 4;
                currentCar->direction = newDirection;
            }

            currentCar = currentCar->next;
        }

        // Sleep for 1 second
        time++;
        sleep(1);
    }

    // Destroy the linked list of cars
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