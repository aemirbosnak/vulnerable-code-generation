//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: mind-bending
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_SPEED 5

typedef struct Car {
    int lane;
    int speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    int i, j, time = 0;

    // Randomly assign lanes and speeds to cars
    for (i = 0; i < head->next->next->next->next->next->next->next->next->next->next->next->next; i++) {
        head->next->next->next->next->next->next->next->next->next->next->next->next->speed = rand() % MAX_SPEED + 1;
        head->next->next->next->next->next->next->next->next->next->next->next->next->lane = rand() % NUM_LANE;
    }

    // Simulate traffic flow
    while (time < 100) {
        for (i = 0; i < NUM_LANE; i++) {
            Car* car = head->next;

            // Move cars forward
            while (car) {
                if (car->lane == i) {
                    car->speed--;
                    if (car->speed == 0) {
                        car = car->next;
                        free(car);
                    } else {
                        car->lane = (car->lane + 1) % NUM_LANE;
                        car->speed++;
                    }
                }
                car = car->next;
            }
        }

        time++;
    }

    // Free all cars
    while (head) {
        Car* car = head;
        head = head->next;
        free(car);
    }
}

int main() {
    Car* head = malloc(sizeof(Car));
    head->lane = 0;
    head->speed = 0;
    head->next = malloc(sizeof(Car));
    head->next->lane = 1;
    head->next->speed = 3;
    head->next->next = malloc(sizeof(Car));
    head->next->next->lane = 2;
    head->next->next->speed = 2;

    simulateTrafficFlow(head);

    return 0;
}