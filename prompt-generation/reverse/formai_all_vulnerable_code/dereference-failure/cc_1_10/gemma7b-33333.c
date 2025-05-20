//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 5

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int position, int direction, int speed) {
    Car* newCar = malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow(Car* head) {
    time_t start = time(NULL);
    while (time(NULL) - start < 10) {
        for (Car* currentCar = head; currentCar; currentCar = currentCar->next) {
            switch (currentCar->direction) {
                case 0:
                    currentCar->position++;
                    break;
                case 1:
                    currentCar->position--;
                    break;
                case 2:
                    currentCar->position++;
                    currentCar->direction = 0;
                    break;
                case 3:
                    currentCar->position--;
                    currentCar->direction = 1;
                    break;
            }
        }
        sleep(1);
    }
}

int main() {
    Car* head = createCar(0, 0, 5);
    head->next = createCar(2, 1, 3);
    head->next->next = createCar(4, 2, 4);

    simulateTrafficFlow(head);

    return 0;
}