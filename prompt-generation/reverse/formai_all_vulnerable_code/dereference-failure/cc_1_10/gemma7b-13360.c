//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARS 10

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

Car* createCar(int position, int direction, int speed) {
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->position = position;
    newCar->direction = direction;
    newCar->speed = speed;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow(Car* head) {
    while (head) {
        // Move car forward or backward
        switch (head->direction) {
            case 0:
                head->position++;
                break;
            case 1:
                head->position--;
                break;
        }

        // Adjust car speed
        head->speed++;

        // Free car if it reaches the end of the road
        if (head->position == MAX_CARS) {
            free(head);
            head = NULL;
        }

        head = head->next;
    }
}

int main() {
    Car* head = createCar(0, 0, 5);
    head->next = createCar(2, 1, 3);
    head->next->next = createCar(4, 0, 4);

    simulateTrafficFlow(head);

    return 0;
}