//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

typedef struct {
    int floor;
    int direction;
    int speed;
} Elevator;

Elevator elevators[NUM_ELEVATORS];
int elevator_count = 0;

int main() {
    srand(time(NULL));

    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].floor = rand() % NUM_FLOORS;
        elevators[i].direction = rand() % 2;
        elevators[i].speed = rand() % 3 + 1;
    }

    int floor_request;
    printf("Enter floor request: ");
    scanf("%d", &floor_request);

    int elevator_selected = -1;
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (elevators[i].floor == floor_request) {
            elevator_selected = i;
            break;
        }
    }

    if (elevator_selected == -1) {
        printf("No elevator available.\n");
        return 0;
    }

    elevators[elevator_selected].direction = (floor_request > elevators[elevator_selected].floor)? 1 : 0;
    elevators[elevator_selected].speed = (floor_request - elevators[elevator_selected].floor) / abs(floor_request - elevators[elevator_selected].floor) + 1;

    while (1) {
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            if (i!= elevator_selected) {
                elevators[i].floor += elevators[i].direction * elevators[i].speed;
            }
        }
        elevators[elevator_selected].floor += elevators[elevator_selected].direction * elevators[elevator_selected].speed;

        printf("Current floor: %d\n", elevators[elevator_selected].floor);

        if (elevators[elevator_selected].floor == floor_request) {
            printf("Arrived at floor %d.\n", floor_request);
            break;
        }
    }

    return 0;
}