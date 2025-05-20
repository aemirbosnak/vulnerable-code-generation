//GEMINI-pro DATASET v1.0 Category: Elevator Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 5
#define CAPACITY 5

typedef struct {
    int floor;
    int direction;
    int passengers;
} Elevator;

Elevator elevator = {0, 0, 0};

void move_elevator(Elevator *elevator) {
    if (elevator->direction == 1) {
        elevator->floor++;
        if (elevator->floor == FLOORS) {
            elevator->direction = -1;
        }
    } else {
        elevator->floor--;
        if (elevator->floor == 0) {
            elevator->direction = 1;
        }
    }
}

void load_passengers(Elevator *elevator) {
    int passengers = rand() % (CAPACITY - elevator->passengers);
    elevator->passengers += passengers;
}

void unload_passengers(Elevator *elevator) {
    int passengers = rand() % elevator->passengers;
    elevator->passengers -= passengers;
}

void print_elevator(Elevator *elevator) {
    printf("Floor: %d\n", elevator->floor);
    printf("Direction: %d\n", elevator->direction);
    printf("Passengers: %d\n", elevator->passengers);
    printf("\n");
}

int main() {
    srand(time(NULL));

    while (1) {
        move_elevator(&elevator);
        load_passengers(&elevator);
        unload_passengers(&elevator);
        print_elevator(&elevator);
    }

    return 0;
}