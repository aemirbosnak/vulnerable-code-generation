//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 2

int elevator_positions[NUM_ELEVATORS] = {0, 0};  // Starting positions of elevators (floor 0)
bool elevator_directions[NUM_ELEVATORS] = {true, true};  // Starting directions (up)

typedef struct passenger {
    int id;  // unique identifier
    int floor;  // floor where the passenger is waiting
    bool direction;  // true for up, false for down
    int destination;  // floor where the passenger wants to go
} Passenger;

typedef struct floor_queue {
    Passenger passengers[NUM_FLOORS];  // array of passengers on each floor
    int num_waiting[NUM_FLOORS];  // number of passengers waiting on each floor
    int num_services[NUM_FLOORS];  // number of passengers serviced on each floor
} FloorQueue;

void init_floor_queue(FloorQueue* fq) {
    for (int i = 0; i < NUM_FLOORS; i++) {
        fq->num_waiting[i] = 0;
        fq->num_services[i] = 0;
    }
}

void print_floor_queue(FloorQueue* fq) {
    printf("Floor Queue:\n");
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("Floor %d - %d waiting, %d serviced\n", i, fq->num_waiting[i], fq->num_services[i]);
    }
}

void add_passenger(Passenger p, FloorQueue* fq) {
    fq->passengers[p.floor * 2 + p.direction * 1] = p;  // add passenger to corresponding index
    fq->num_waiting[p.floor]++;
}

Passenger remove_passenger(int floor, bool direction, FloorQueue* fq) {
    // remove first passenger in the queue
    Passenger p = fq->passengers[floor * 2 + direction * 1];
    fq->passengers[floor * 2 + direction * 1] = (Passenger){0, 0, 0, 0};  // clear passenger from queue
    fq->num_waiting[floor]--;
    fq->num_services[floor]++;
    return p;
}

void move_elevator(int e, FloorQueue* fq) {
    printf("Elevator %d - Floor %d - Direction %s\n", e + 1, elevator_positions[e], elevator_directions[e] ? "Up" : "Down");

    // check if elevator has reached top/bottom floor, and reverse direction if necessary
    if (elevator_positions[e] == NUM_FLOORS - 1 && elevator_directions[e]) {
        elevator_directions[e] = false;
    }
    if (elevator_positions[e] == 0 && !elevator_directions[e]) {
        elevator_directions[e] = true;
    }

    // check if elevator has passengers going to current floor, and remove them
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (fq->passengers[i * 2 + elevator_directions[e] * 1].floor == elevator_positions[e]) {
            Passenger p = remove_passenger(i, elevator_directions[e], fq);
            printf("Elevator %d - Passenger %d - Floor %d to Floor %d\n", e + 1, p.id, p.floor, p.destination);
        }
    }

    // check if there are remaining passengers waiting for elevator and add them
    for (int i = 0; i < NUM_FLOORS; i++) {
        if (fq->num_waiting[i] > 0) {
            Passenger p = fq->passengers[i * 2 + elevator_directions[e] * 1];
            if (p.floor == elevator_positions[e]) {
                continue;  // skip floor if elevator is already there
            }
            if (elevator_directions[e] == p.direction) {
                add_passenger(p, fq);  // add passenger to elevator if going in the same direction
                printf("Elevator %d - Passenger %d - Floor %d to Floor %d\n", e + 1, p.id, p.floor, p.destination);
            }
        }
    }

    // move elevator by one floor
    elevator_positions[e] += elevator_directions[e] ? 1 : -1;
    printf("\n");
}

void simulate_elevator(int num_passengers) {
    FloorQueue fq;
    init_floor_queue(&fq);

    // generate random passengers
    for (int i = 0; i < num_passengers; i++) {
        Passenger p = {i + 1, rand() % NUM_FLOORS, rand() % 2, rand() % NUM_FLOORS};
        add_passenger(p, &fq);
    }

    // run elevator simulation
    for (int i = 0; i < 100; i++) {
        for (int e = 0; e < NUM_ELEVATORS; e++) {
            move_elevator(e, &fq);
        }
    }

    print_floor_queue(&fq);
}

int main() {
    srand(0);
    simulate_elevator(20);
    return 0;
}