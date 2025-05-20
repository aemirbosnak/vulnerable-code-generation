//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdlib.h>
#include <time.h>

#define MAX_LANE 3
#define MAX_CARS 10

typedef struct Car {
    int lane;
    int position;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed) {
    Car* car = malloc(sizeof(Car));
    car->lane = lane;
    car->position = position;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(int numCars) {
    srand(time(NULL));

    Car* head = NULL;
    for (int i = 0; i < numCars; i++) {
        Car* car = createCar(rand() % MAX_LANE, rand() % MAX_LANE, rand() % 5);
        if (head == NULL) {
            head = car;
        } else {
            car->next = head;
            head = car;
        }
    }

    // Simulate traffic flow
    for (int t = 0; t < 100; t++) {
        for (Car* car = head; car; car = car->next) {
            car->position++;
            if (car->position >= MAX_LANE) {
                car->position = 0;
            }
        }

        // Random events
        int event = rand() % 10;
        if (event == 0) {
            Car* car = head;
            free(car);
            head = NULL;
        }
    }

    // Print traffic flow
    for (Car* car = head; car; car = car->next) {
        printf("Lane: %d, Position: %d, Speed: %d\n", car->lane, car->position, car->speed);
    }
}

int main() {
    simulateTrafficFlow(5);
    return 0;
}