//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOOR 20
#define MAX_PASSENGERS 10

typedef enum Direction {UP, DOWN} Direction;
typedef enum Status {IDLE, MOVING} Status;

typedef struct Passenger {
    int id;
    int current_floor;
    int destination_floor;
} Passenger;

typedef struct Elevator {
    int current_floor;
    Direction direction;
    Status status;
    Passenger* passengers[MAX_PASSENGERS];
    int num_passengers;
} Elevator;

void initiate_elevator(Elevator* e) {
    e->current_floor = 1;
    e->direction = UP;
    e->status = IDLE;
    e->num_passengers = 0;
}

void add_passenger(Elevator* e) {
    if (e->num_passengers == MAX_PASSENGERS) {
        printf("Elevator is full, could not add passenger.\n");
        return;
    }
    Passenger* p = (Passenger*) malloc(sizeof(Passenger));
    p->id = rand() % 1000 + 1;
    p->current_floor = rand() % MAX_FLOOR + 1;
    do {
        p->destination_floor = rand() % MAX_FLOOR + 1;
    } while (p->destination_floor == p->current_floor);
    printf("Passenger %d is waiting at floor %d to go to floor %d.\n", p->id, p->current_floor, p->destination_floor);
    e->passengers[e->num_passengers] = p;
    e->num_passengers++;
}

void remove_passenger(Elevator* e, int index) {
    printf("Passenger %d has arrived at the destination floor %d.\n", e->passengers[index]->id, e->passengers[index]->destination_floor);
    free(e->passengers[index]);
    for (int i = index; i < e->num_passengers-1; i++) {
        e->passengers[i] = e->passengers[i+1];
    }
    e->num_passengers--;
}

void move_elevator(Elevator* e) {
    printf("Elevator is moving %s from floor %d.\n", e->direction == UP ? "up" : "down", e->current_floor);
    if (e->direction == UP && e->current_floor == MAX_FLOOR) {
        e->direction = DOWN;
        printf("Elevator has reached the top floor and changed direction to down.\n");
    } else if (e->direction == DOWN && e->current_floor == 1) {
        e->direction = UP;
        printf("Elevator has reached the bottom floor and changed direction to up.\n");
    } else {
        e->current_floor += (e->direction == UP ? 1 : -1);
        for (int i = 0; i < e->num_passengers; i++) {
            if (e->passengers[i]->destination_floor == e->current_floor) {
                remove_passenger(e, i);
            }
        }
    }
}

int main() {
    Elevator e;
    initiate_elevator(&e);
    srand(time(NULL));
    for (int i = 0; i < 15; i++) {
        add_passenger(&e);
    }
    while (e.num_passengers > 0) {
        move_elevator(&e);
    }
    printf("Elevator is now empty and idle at floor %d.\n", e.current_floor);
    return 0;
}