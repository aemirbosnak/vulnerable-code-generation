//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct {
    int floor;
    int destination;
} Passenger;

typedef struct {
    Passenger passengers[MAX_PASSENGERS];
    int num_passengers;
    int current_floor;
    int destination_floor;
} Elevator;

void print_elevator_status(Elevator *elevator) {
    printf("Elevator Status:\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Destination Floor: %d\n", elevator->destination_floor);
    printf("Number of Passengers: %d\n", elevator->num_passengers);
    printf("Passengers List:\n");
    for(int i = 0; i < elevator->num_passengers; i++) {
        printf("Passenger %d: From Floor %d to Floor %d\n", i+1, elevator->passengers[i].floor, elevator->passengers[i].destination);
    }
}

void elevator_pickup(Elevator *elevator, Passenger *passenger) {
    if(elevator->num_passengers < MAX_PASSENGERS) {
        elevator->passengers[elevator->num_passengers] = *passenger;
        elevator->num_passengers++;
        printf("Passenger picked up at Floor %d\n", passenger->floor);
    }
    else {
        printf("Elevator is full!\n");
    }
}

void elevator_dropoff(Elevator *elevator, int index) {
    printf("Passenger dropped off at Floor %d\n", elevator->passengers[index].destination);
    for(int i = index; i < elevator->num_passengers; i++) {
        elevator->passengers[i] = elevator->passengers[i+1];
    }
    elevator->num_passengers--;
}

void elevator_move(Elevator *elevator) {
    if(elevator->current_floor < elevator->destination_floor) {
        elevator->current_floor++;
        printf("\nElevator moving up...\n\n");
    }
    else if(elevator->current_floor > elevator->destination_floor) {
        elevator->current_floor--;
        printf("\nElevator moving down...\n\n");
    }

    for(int i = 0; i < elevator->num_passengers; i++) {
        if(elevator->passengers[i].destination == elevator->current_floor) {
            elevator_dropoff(elevator, i);
            i--;
        }
    }
}

int main() {
    Elevator elevator;
    elevator.current_floor = 0;
    elevator.destination_floor = 0;
    elevator.num_passengers = 0;

    while(1) {
        printf("Enter current floor (0-%d): ", MAX_FLOORS);
        scanf("%d", &elevator.current_floor);

        printf("Enter destination floor (0-%d): ", MAX_FLOORS);
        scanf("%d", &elevator.destination_floor);

        if(elevator.current_floor >= MAX_FLOORS || elevator.destination_floor >= MAX_FLOORS) {
            printf("Invalid floor!\n");
            continue;
        }

        Passenger passenger;
        passenger.floor = elevator.current_floor;
        passenger.destination = elevator.destination_floor;

        elevator_pickup(&elevator, &passenger);

        if(elevator.num_passengers > 0) {
            printf("Enter 'm' to move elevator: ");
            char c;
            scanf(" %c", &c);

            if(c == 'm') {
                elevator_move(&elevator);
            }
            else {
                printf("Invalid input!\n");
                continue;
            }
        }

        print_elevator_status(&elevator);

        if(elevator.num_passengers == 0) {
            printf("\nNo passengers left in elevator!\n");
            break;
        }
    }

    return 0;
}