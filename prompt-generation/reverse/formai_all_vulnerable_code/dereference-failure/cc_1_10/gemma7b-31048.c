//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define NUM_CARS 5

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

void simulateTrafficFlow(Car* cars) {
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        for (Car* car = cars; car; car = car->next) {
            car->position++;
            if (car->position >= 10) {
                car->position = 0;
            }
            if (rand() % 5 == 0) {
                car->speed++;
            }
            if (rand() % 5 == 1) {
                car->speed--;
            }
        }
        sleep(1);
    }
}

int main() {
    Car* head = createCar(0, 5, 0);
    head->next = createCar(1, 4, 1);
    head->next->next = createCar(2, 3, 2);
    head->next->next->next = createCar(0, 4, 3);
    head->next->next->next->next = createCar(1, 3, 4);

    simulateTrafficFlow(head);

    return 0;
}