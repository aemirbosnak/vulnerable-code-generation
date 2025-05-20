//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
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

void simulateTrafficFlow(Car* head) {
    time_t start = time(NULL);
    time_t end = start + 60;

    while (time(NULL) < end) {
        // Move cars
        Car* current = head;
        while (current) {
            current->position++;
            if (current->position >= MAX_LANE) {
                current->position = 0;
            }
            current = current->next;
        }

        // Randomly spawn new cars
        if (rand() % 10 == 0) {
            Car* newCar = malloc(sizeof(Car));
            newCar->lane = rand() % MAX_LANE;
            newCar->position = 0;
            newCar->speed = rand() % 5 + 1;
            newCar->next = head;
            head = newCar;
        }

        // Print traffic flow
        printf("Time: %ld\n", time(NULL) - start);
        printf("Lane 0: ");
        for (int i = 0; i < MAX_CARS; i++) {
            Car* car = head;
            while (car) {
                if (car->lane == 0) {
                    printf("%d ", car->position);
                }
                car = car->next;
            }
        }
        printf("\n");
        sleep(1);
    }
}

int main() {
    // Create a linked list of cars
    Car* head = NULL;
    for (int i = 0; i < MAX_CARS; i++) {
        Car* newCar = malloc(sizeof(Car));
        newCar->lane = rand() % MAX_LANE;
        newCar->position = 0;
        newCar->speed = rand() % 5 + 1;
        newCar->next = head;
        head = newCar;
    }

    // Simulate traffic flow
    simulateTrafficFlow(head);

    return 0;
}