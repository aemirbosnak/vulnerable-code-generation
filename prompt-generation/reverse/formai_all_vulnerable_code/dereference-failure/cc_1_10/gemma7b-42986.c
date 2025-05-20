//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdlib.h>
#include <time.h>

#define NUM_CARS 50
#define MAX_SPEED 10

typedef struct Car {
    int x, y, speed, direction, lane;
    struct Car* next;
} Car;

Car* createCar() {
    Car* newCar = malloc(sizeof(Car));
    newCar->x = 0;
    newCar->y = 0;
    newCar->speed = rand() % MAX_SPEED;
    newCar->direction = rand() % 4;
    newCar->lane = rand() % 3;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow() {
    Car* head = createCar();
    head->next = createCar();
    head->next->next = createCar();
    head->next->next->next = createCar();
    head->next->next->next->next = createCar();

    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        for (Car* car = head; car; car = car->next) {
            switch (car->direction) {
                case 0:
                    car->x++;
                    break;
                case 1:
                    car->x--;
                    break;
                case 2:
                    car->y++;
                    break;
                case 3:
                    car->y--;
                    break;
            }

            if (car->x >= 10 || car->x <= -10) {
                car->direction = (car->direction + 1) % 4;
            }
            if (car->y >= 10 || car->y <= -10) {
                car->direction = (car->direction + 1) % 4;
            }
        }

        sleep(1);
    }

    free(head);
}

int main() {
    simulateTrafficFlow();
    return 0;
}