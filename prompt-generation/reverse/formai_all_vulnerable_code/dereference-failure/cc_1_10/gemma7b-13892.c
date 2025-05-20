//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LANE 3
#define MAX_SPEED 5

typedef struct Vehicle {
    int lane;
    int speed;
    struct Vehicle* next;
} Vehicle;

void simulateTrafficFlow(Vehicle* head) {
    time_t start_time = time(NULL);
    time_t current_time = start_time;
    int elapsed_time = 0;

    while (elapsed_time < 10) {
        current_time = time(NULL);
        elapsed_time = current_time - start_time;

        // Update vehicle speeds
        Vehicle* vehicle = head;
        while (vehicle) {
            vehicle->speed = MAX_SPEED - (elapsed_time / 2);
            vehicle = vehicle->next;
        }

        // Move vehicles
        vehicle = head;
        while (vehicle) {
            switch (vehicle->lane) {
                case 0:
                    vehicle->lane = (vehicle->speed % 2) ? 1 : 0;
                    break;
                case 1:
                    vehicle->lane = (vehicle->speed % 2) ? 2 : 1;
                    break;
                case 2:
                    vehicle->lane = (vehicle->speed % 2) ? 0 : 2;
                    break;
            }
            vehicle = vehicle->next;
        }

        // Print traffic flow
        printf("Time: %d, Lane 0: %d, Lane 1: %d, Lane 2: %d\n", elapsed_time, head->lane, vehicle->lane, (vehicle->next) ? (vehicle->next)->lane : -1);
    }
}

int main() {
    // Create a linked list of vehicles
    Vehicle* head = malloc(sizeof(Vehicle));
    head->lane = 0;
    head->speed = 3;
    head->next = malloc(sizeof(Vehicle));
    head->next->lane = 1;
    head->next->speed = 2;
    head->next->next = malloc(sizeof(Vehicle));
    head->next->next->lane = 2;
    head->next->next->speed = 4;

    // Simulate traffic flow
    simulateTrafficFlow(head);

    return 0;
}