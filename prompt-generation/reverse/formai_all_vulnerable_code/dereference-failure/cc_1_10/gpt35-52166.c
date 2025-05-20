//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define NUM_FLOORS 10
#define CAPACITY 10

// struct representing an elevator
typedef struct {
    int current_floor;
    int capacity;
    int num_people;
    int *destinations;
} Elevator;

// initialize elevator
void init_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->capacity = CAPACITY;
    elevator->num_people = 0;
    elevator->destinations = (int*) calloc(NUM_FLOORS, sizeof(int));
}

// check if elevator is full
int is_full(Elevator *elevator) {
    return elevator->num_people == elevator->capacity;
}

// add person to elevator
void add_person(Elevator *elevator, int destination) {
    elevator->destinations[destination] = 1;
    elevator->num_people++;
}

// remove person from elevator
void remove_person(Elevator *elevator, int destination) {
    elevator->destinations[destination] = 0;
    elevator->num_people--;
}

// move elevator to destination floor
void move_elevator(Elevator *elevator, int destination) {
    if (destination > elevator->current_floor) {
        printf("Elevator going up to floor %d\n", destination);
        while (elevator->current_floor < destination) {
            elevator->current_floor++;
            printf("Elevator at floor %d\n", elevator->current_floor);
        }
    } else if (destination < elevator->current_floor) {
        printf("Elevator going down to floor %d\n", destination);
        while (elevator->current_floor > destination) {
            elevator->current_floor--;
            printf("Elevator at floor %d\n", elevator->current_floor);
        }
    }
    printf("Elevator doors opening on floor %d\n", elevator->current_floor);
}

int main() {
    // initialize elevator
    Elevator elevator;
    init_elevator(&elevator);

    // add people to elevator
    add_person(&elevator, 4);
    add_person(&elevator, 7);
    add_person(&elevator, 2);

    // move elevator to different floors
    move_elevator(&elevator, 2);
    move_elevator(&elevator, 4);
    move_elevator(&elevator, 7);

    // remove people from elevator
    remove_person(&elevator, 4);
    remove_person(&elevator, 2);
    remove_person(&elevator, 7);

    return 0;
}