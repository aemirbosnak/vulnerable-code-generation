//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_FLOORS 20
#define MAX_PASSENGERS 10

typedef struct Passenger {
    int id;
    int current_floor;
    int destination_floor;
} Passenger;

typedef struct Elevator {
    int current_floor;
    bool going_up;
    int capacity;
    Passenger passengers[MAX_PASSENGERS];
} Elevator;

Elevator create_elevator(int capacity, int current_floor) {
    Elevator elevator;
    elevator.current_floor = current_floor;
    elevator.going_up = true;
    elevator.capacity = capacity;
    return elevator;
}

void enter_elevator(Elevator *elevator, Passenger *passenger) {
    if (elevator->current_floor == passenger->current_floor && elevator->going_up && 
        elevator->capacity < MAX_PASSENGERS && passenger->destination_floor > passenger->current_floor) {
        elevator->passengers[elevator->capacity] = *passenger;
        elevator->capacity++;
    }
}

void exit_elevator(Elevator *elevator, Passenger *passenger) {
    for (int i = 0; i < elevator->capacity; i++) {
        if (elevator->passengers[i].id == passenger->id) {
            for (int j = i; j < elevator->capacity-1; j++) {
                elevator->passengers[j] = elevator->passengers[j+1];
            }
            elevator->capacity--;
            break;
        }
    }
}

void move_elevator(Elevator *elevator) {
    if (elevator->current_floor == 1) {
        elevator->going_up = true;
    }
    else if (elevator->current_floor == MAX_FLOORS) {
        elevator->going_up = false;
    }
    if (elevator->going_up) {
        elevator->current_floor++;
    } else {
        elevator->current_floor--;
    }
}

void print_elevator(Elevator elevator) {
    printf("Elevator Status:\n\tCurrent Floor: %d\n\tDirection: %s\n\tCapacity: %d\n\tPassengers: ", 
        elevator.current_floor, elevator.going_up ? "Up" : "Down", elevator.capacity);
    for (int i = 0; i < elevator.capacity; i++) {
        printf("%d ", elevator.passengers[i].id);
    }
    printf("\n");
}

int main() {
    int num_passengers, capacity, current_floor = 1;
    printf("Enter elevator capacity: ");
    scanf("%d", &capacity);
    Elevator elevator = create_elevator(capacity, current_floor);
    printf("How many passengers? ");
    scanf("%d", &num_passengers);
    Passenger passengers[num_passengers];
    for (int i = 0; i < num_passengers; i++) {
        passengers[i].id = i+1;
        printf("Passenger %d current floor: ", i+1);
        scanf("%d", &passengers[i].current_floor);
        printf("Passenger %d destination floor: ", i+1);
        scanf("%d", &passengers[i].destination_floor);
        enter_elevator(&elevator, &passengers[i]);
    }
    print_elevator(elevator);
    move_elevator(&elevator);
    printf("Elevator is moving.\n");
    print_elevator(elevator);
    move_elevator(&elevator);
    printf("Elevator has arrived at floor %d.\n", elevator.current_floor);
    for (int i = 0; i < elevator.capacity; i++) {
        exit_elevator(&elevator, &elevator.passengers[i]);
    }
    print_elevator(elevator);
    return 0;
}