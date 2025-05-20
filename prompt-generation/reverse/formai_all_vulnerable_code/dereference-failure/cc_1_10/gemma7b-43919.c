//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, dir, speed;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = rand() % 10;
    newCar->y = rand() % 10;
    newCar->dir = rand() % 4;
    newCar->speed = rand() % 3;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow(Car* cars) {
    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        for (Car* car = cars; car; car = car->next) {
            switch (car->dir) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->y++;
                    break;
                case 2:
                    car->x--;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            car->speed--;
            if (car->speed == 0) {
                car->speed = rand() % 3;
                car->dir = rand() % 4;
            }
        }
        sleep(1);
    }
}

int main() {
    Car* cars = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        cars = createCar(cars);
    }

    simulateTrafficFlow(cars);

    return 0;
}