//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_PEOPLE 5

typedef struct {
    int id;
    int current_floor;
    int destination_floor;
} Person;

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down
    Person *passengers[MAX_PEOPLE];
    int passenger_count;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0; // starting at ground floor
    elevator->direction = 0; // 0 means idle
    elevator->passenger_count = 0;
}

bool add_passenger(Elevator *elevator, Person *person) {
    if (elevator->passenger_count < MAX_PEOPLE) {
        elevator->passengers[elevator->passenger_count++] = person;
        return true;
    } else {
        printf("Elevator full! Passenger %d cannot enter.\n", person->id);
        return false;
    }
}

void remove_passenger(Elevator *elevator, int id) {
    for (int i = 0; i < elevator->passenger_count; i++) {
        if (elevator->passengers[i]->id == id) {
            printf("Passenger %d has exited the elevator at floor %d.\n", id, elevator->current_floor);
            for (int j = i; j < elevator->passenger_count - 1; j++) {
                elevator->passengers[j] = elevator->passengers[j + 1];
            }
            elevator->passenger_count--;
            return;
        }
    }
    printf("Passenger %d not found in the elevator.\n", id);
}

void move_elevator(Elevator *elevator) {
    if (elevator->direction == 0) return; // Elevator is idle

    if (elevator->direction == 1) {
        if (elevator->current_floor < MAX_FLOORS - 1) {
            elevator->current_floor++;
        } else {
            elevator->direction = 0; // Stop if at the top floor
        }
    } else if (elevator->direction == -1) {
        if (elevator->current_floor > 0) {
            elevator->current_floor--;
        } else {
            elevator->direction = 0; // Stop if at the ground floor
        }
    }

    printf("Elevator moving to floor %d...\n", elevator->current_floor);
    sleep(1); // Simulate time taken to move
}

void check_passengers(Elevator *elevator) {
    for (int i = 0; i < elevator->passenger_count; i++) {
        if (elevator->current_floor == elevator->passengers[i]->destination_floor) {
            remove_passenger(elevator, elevator->passengers[i]->id);
            i--; // Adjust index after removal
        }
    }
}

void print_elevator_status(Elevator *elevator) {
    printf("Elevator is on floor %d. ", elevator->current_floor);
    if (elevator->direction == 1) {
        printf("Going up.\n");
    } else if (elevator->direction == -1) {
        printf("Going down.\n");
    } else {
        printf("Elevator is idle.\n");
    }
}

Person* create_person(int id, int current_floor, int destination_floor) {
    Person *new_person = (Person *)malloc(sizeof(Person));
    new_person->id = id;
    new_person->current_floor = current_floor;
    new_person->destination_floor = destination_floor;
    return new_person;
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    Person *people[6];
    people[0] = create_person(1, 0, 3);
    people[1] = create_person(2, 1, 5);
    people[2] = create_person(3, 2, 0);
    people[3] = create_person(4, 0, 1);
    people[4] = create_person(5, 1, 7);

    for (int i = 0; i < 5; i++) {
        if (people[i]->current_floor == elevator.current_floor) {
            add_passenger(&elevator, people[i]);
            elevator.direction = (people[i]->destination_floor > elevator.current_floor) ? 1 : -1;
        }
    }

    while (elevator.passenger_count > 0 || elevator.direction != 0) {
        print_elevator_status(&elevator);
        move_elevator(&elevator);
        check_passengers(&elevator);
        
        if (elevator.passenger_count == 0) {
            elevator.direction = 0; // Stop the elevator if no more passengers
        }
    }

    printf("Elevator operation completed. All passengers have exited.\n");
    for (int i = 0; i < 5; i++) {
        free(people[i]);
    }

    return 0;
}