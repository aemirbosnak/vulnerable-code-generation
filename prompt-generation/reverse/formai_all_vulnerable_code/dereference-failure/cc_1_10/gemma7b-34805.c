//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10

typedef struct Car {
    int x, y, direction, speed, lane;
    struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed, int lane) {
    Car* car = (Car*)malloc(sizeof(Car));
    car->x = x;
    car->y = y;
    car->direction = direction;
    car->speed = speed;
    car->lane = lane;
    car->next = NULL;
    return car;
}

void simulateTrafficFlow(Car* car) {
    switch (car->direction) {
        case 0: // North
            car->x++;
            break;
        case 1: // East
            car->y++;
            break;
        case 2: // South
            car->x--;
            break;
        case 3: // West
            car->y--;
            break;
    }

    // Change lane if necessary
    if (car->lane != 0 && car->lane != 1) {
        if (rand() % 20 == 0) {
            car->lane = (car->lane == 0) ? 1 : 0;
        }
    }

    // Adjust speed
    if (rand() % 10 == 0) {
        car->speed = (car->speed == 1) ? 2 : 1;
    }
}

int main() {
    srand(time(NULL));

    Car* head = createCar(1, 1, 0, 1, 0);

    for (int i = 0; i < MAX_Cars; i++) {
        simulateTrafficFlow(head);
        head = head->next;
    }

    return 0;
}