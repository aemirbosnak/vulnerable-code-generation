//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 5

typedef struct {
    int id;
    int current_floor;
    int destination_floor;
} Passenger;

typedef struct {
    int current_floor;
    bool going_up;
    Passenger *passengers[MAX_PASSENGERS];
    int passenger_count;
} Elevator;

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->going_up = true;
    elevator->passenger_count = 0;
}

void display_status(Elevator *elevator) {
    printf("\n** Elevator Status **\n");
    printf("Current Floor: %d\n", elevator->current_floor);
    printf("Passengers in Elevator: ");
    if (elevator->passenger_count == 0) {
        printf("None\n");
    } else {
        for (int i = 0; i < elevator->passenger_count; i++) {
            printf("Passenger %d -> Floor %d  ", elevator->passengers[i]->id, elevator->passengers[i]->destination_floor);
        }
        printf("\n");
    }
}

void board_passenger(Elevator *elevator, Passenger *passenger) {
    if (elevator->passenger_count < MAX_PASSENGERS) {
        elevator->passengers[elevator->passenger_count++] = passenger;
        printf("Passenger %d boarded on floor %d, heading to floor %d!\n", passenger->id, passenger->current_floor, passenger->destination_floor);
    } else {
        printf("The elevator is full. Passenger %d cannot board!\n", passenger->id);
    }
}

void unboard_passengers(Elevator *elevator) {
    for (int i = 0; i < elevator->passenger_count; i++) {
        if (elevator->passengers[i]->destination_floor == elevator->current_floor) {
            printf("Passenger %d has exited the elevator on floor %d!\n", elevator->passengers[i]->id, elevator->current_floor);
            free(elevator->passengers[i]);
            elevator->passengers[i] = NULL;
        }
    }
    // Clean up NULL passengers
    int new_count = 0;
    for (int i = 0; i < elevator->passenger_count; i++) {
        if (elevator->passengers[i] != NULL) {
            elevator->passengers[new_count++] = elevator->passengers[i];
        }
    }
    elevator->passenger_count = new_count;
}

int next_floor(Elevator *elevator) {
    if (elevator->going_up) {
        if (elevator->current_floor < MAX_FLOORS - 1) {
            return elevator->current_floor + 1;
        } else {
            elevator->going_up = false;
            return elevator->current_floor - 1;
        }
    } else {
        if (elevator->current_floor > 0) {
            return elevator->current_floor - 1;
        } else {
            elevator->going_up = true;
            return elevator->current_floor + 1;
        }
    }
}

Passenger *create_passenger(int id, int current_floor, int destination_floor) {
    Passenger *new_passenger = (Passenger *)malloc(sizeof(Passenger));
    new_passenger->id = id;
    new_passenger->current_floor = current_floor;
    new_passenger->destination_floor = destination_floor;
    return new_passenger;
}

int main(void) {
    Elevator elevator;
    initialize_elevator(&elevator);

    printf("🎢 Welcome to the Whimsical Elevator Simulator! 🎢\n");

    for (int t = 0; t < 20; t++) {
        printf("\nTime: %d  ------------------------------------\n", t);

        // Randomly board passengers.
        if (rand() % 2) {
            int id = rand() % 100;
            int current_floor = rand() % MAX_FLOORS;
            int destination_floor;
            do {
                destination_floor = rand() % MAX_FLOORS;
            } while (destination_floor == current_floor);

            Passenger *passenger = create_passenger(id, current_floor, destination_floor);
            board_passenger(&elevator, passenger);
        }

        // Move the elevator.
        elevator.current_floor = next_floor(&elevator);

        // Unboard passengers.
        unboard_passengers(&elevator);

        // Display status.
        display_status(&elevator);

        // Sleep for a second to simulate time delay.
        sleep(1);
    }

    printf("\n🥳 The Whimsical Elevator Simulator has ended! 🥳\n");
    return 0;
}