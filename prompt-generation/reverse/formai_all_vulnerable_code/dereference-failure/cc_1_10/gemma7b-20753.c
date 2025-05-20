//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Cars 10

typedef struct Car {
    int position;
    int direction;
    int speed;
    struct Car* next;
} Car;

void simulateTrafficFlow(Car* head) {
    time_t t = time(NULL);
    srand(t);

    while (head) {
        int move = rand() % 3;
        switch (move) {
            case 0:
                head->position++;
                break;
            case 1:
                head->position--;
                break;
            case 2:
                head->speed++;
                break;
            default:
                head->speed--;
                break;
        }

        sleep(1);
        head = head->next;
    }
}

int main() {
    Car* head = NULL;

    for (int i = 0; i < MAX_Cars; i++) {
        Car* newCar = malloc(sizeof(Car));
        newCar->position = rand() % 10;
        newCar->direction = rand() % 2;
        newCar->speed = rand() % 5;
        newCar->next = head;
        head = newCar;
    }

    simulateTrafficFlow(head);

    return 0;
}