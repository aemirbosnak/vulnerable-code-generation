//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: intelligent
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
    time_t tStart = time(NULL);
    int time = 0;
    while (time < 60) {
        // Calculate the time taken for each car to complete one lane change
        int timeTaken = rand() % 3 + 1;

        // Move cars in each lane
        for (int i = 0; i < MAX_LANE; i++) {
            Car* car = head->next;
            while (car) {
                if (car->lane == i) {
                    car->position++;
                    timeTaken = timeTaken > car->speed ? timeTaken : car->speed;
                }
                car = car->next;
            }
        }

        // Update the time
        time++;
        sleep(timeTaken);
    }
}

int main() {
    // Create a linked list of cars
    Car* head = malloc(sizeof(Car));
    head->lane = 1;
    head->position = 0;
    head->speed = 2;
    head->next = NULL;

    // Simulate traffic flow
    simulateTrafficFlow(head);

    return 0;
}