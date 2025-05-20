//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define NUM_FLOORS 10

typedef struct {
    int current_floor;
    int direction;
    int num_people;
    int capacity;
} Elevator;

typedef struct {
    int arrival_time;
    int destination_floor;
} Request;

void move_elevator(Elevator *elevator, int dest_floor) {
    if(elevator->current_floor < dest_floor) {
        elevator->direction = 1;
        printf("Elevator going up...\n");
        while(elevator->current_floor < dest_floor) {
            elevator->current_floor++;
            printf("Elevator at floor %d\n", elevator->current_floor);
        }
    } else if(elevator->current_floor > dest_floor) {
        elevator->direction = -1;
        printf("Elevator going down...\n");
        while(elevator->current_floor > dest_floor) {
            elevator->current_floor--;
            printf("Elevator at floor %d\n", elevator->current_floor);
        }
    }
}

void handle_requests(Request *requests, int num_requests, Elevator *elevator) {
    int i, dest_floor;
    for(i = 0; i < num_requests; i++) {
        if(elevator->num_people == elevator->capacity) {
            printf("Elevator is full. Request ignored.\n");
            continue;
        }
        if(requests[i].arrival_time > elevator->current_floor * 10) {
            dest_floor = requests[i].destination_floor;
            printf("Request from floor %d. Elevator going to floor %d.\n", elevator->current_floor, dest_floor);
            move_elevator(elevator, dest_floor);
            printf("Elevator arrived at floor %d.\n", elevator->current_floor);
            elevator->num_people++;
        }
    }
}

int main() {
    int i, num_requests;
    Request *requests;
    Elevator elevator = {1, 1, 0, 10};

    srand(time(NULL));

    num_requests = rand() % 10 + 1;
    requests = (Request*)malloc(num_requests * sizeof(Request));

    for(i = 0; i < num_requests; i++) {
        requests[i].arrival_time = rand() % 100;
        requests[i].destination_floor = rand() % NUM_FLOORS + 1;
    }

    for(i = 0; i <= NUM_FLOORS; i++) {
        elevator.current_floor = i;
        printf("Elevator at floor %d\n", i);
        handle_requests(requests, num_requests, &elevator);
        elevator.num_people = 0;
    }

    free(requests);
    return 0;
}