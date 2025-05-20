//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOORS 20
#define MAX_ELEVATORS 4

typedef struct {
    int id;
    int current_floor;
    int target_floor;
    int direction;
} Elevator;

Elevator elevators[MAX_ELEVATORS];
int num_elevators;
int num_floors;

void initialize_elevators() {
    srand(time(NULL));
    num_elevators = rand() % (MAX_ELEVATORS + 1);
    for (int i = 0; i < num_elevators; i++) {
        elevators[i].id = i + 1;
        elevators[i].current_floor = rand() % num_floors + 1;
        elevators[i].target_floor = 0;
        elevators[i].direction = 0;
    }
}

void simulate_elevator(int elevator_id) {
    Elevator *elevator = &elevators[elevator_id - 1];

    if (elevator->target_floor == 0) {
        elevator->target_floor = rand() % num_floors + 1;
        elevator->direction = (elevator->target_floor > elevator->current_floor)? 1 : -1;
    }

    elevator->current_floor += elevator->direction;

    if (elevator->current_floor == elevator->target_floor) {
        elevator->target_floor = 0;
        elevator->direction = 0;
    }
}

int main() {
    int num_people;
    scanf("%d", &num_people);

    num_floors = num_people * 10;

    initialize_elevators();

    while (1) {
        system("clear");
        printf("Elevator Simulation\n");
        printf("Number of Floors: %d\n", num_floors);
        printf("Number of Elevators: %d\n", num_elevators);

        for (int i = 0; i < num_elevators; i++) {
            Elevator *elevator = &elevators[i];
            printf("Elevator %d: Current Floor %d, Target Floor %d, Direction %d\n", elevator->id, elevator->current_floor, elevator->target_floor, elevator->direction);
        }

        for (int i = 0; i < num_elevators; i++) {
            simulate_elevator(i + 1);
        }

        printf("\nPress any key to continue...\n");
        getchar();
    }

    return 0;
}