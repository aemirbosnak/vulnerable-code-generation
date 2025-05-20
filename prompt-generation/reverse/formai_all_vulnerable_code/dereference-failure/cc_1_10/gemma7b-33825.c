//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
    int x, y, dir, speed;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int dir, int speed) {
    Car* car = malloc(sizeof(struct Car));
    car->x = x;
    car->y = y;
    car->dir = dir;
    car->speed = speed;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* cars) {
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
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

            int random_speed = rand() % 5 + 1;
            car->speed = random_speed;
            sleep(random_speed);
        }
    }
}

int main() {
    Car* cars = createCar(0, 0, 0, 5);
    cars = createCar(10, 0, 1, 3);
    cars = createCar(20, 0, 2, 4);
    simulateTrafficFlow(cars);

    return 0;
}