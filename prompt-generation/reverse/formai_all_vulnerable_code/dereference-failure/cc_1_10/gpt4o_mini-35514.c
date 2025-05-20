//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_FLOORS 10
#define UP 1
#define DOWN -1
#define IDLE 0

typedef struct {
    int current_floor;
    int direction;
    bool *request;
} Elevator;

typedef struct {
    Elevator *elevator;
    int floor_number;
} Request;

void *process_request(void *arg) {
    Request *request = (Request *)arg;
    Elevator *elevator = request->elevator;
    int floor = request->floor_number;

    // Simulating the elevator moving to the requested floor
    while (elevator->current_floor != floor) {
        if (elevator->current_floor < floor) {
            elevator->direction = UP;
            elevator->current_floor++;
        } else {
            elevator->direction = DOWN;
            elevator->current_floor--;
        }
        printf("Elevator is on floor %d moving %s\n", elevator->current_floor, elevator->direction == UP ? "UP" : "DOWN");
        sleep(1); // simulating time taken to travel one floor
    }

    elevator->direction = IDLE;
    printf("Elevator has arrived at floor %d\n", elevator->current_floor);
    elevator->request[floor] = false; // Reset the request
    free(request); // release allocated memory
    pthread_exit(NULL);
}

void request_elevator(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request: %d\n", floor);
        return;
    }

    if (!elevator->request[floor]) {
        elevator->request[floor] = true;

        Request *new_request = malloc(sizeof(Request));
        new_request->elevator = elevator;
        new_request->floor_number = floor;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, process_request, new_request);
        pthread_detach(thread_id); // Automatically clean up memory when thread finishes
    } else {
        printf("Request for floor %d already exists.\n", floor);
    }
}

void initialize_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->direction = IDLE;
    elevator->request = (bool *)calloc(MAX_FLOORS, sizeof(bool)); // Dynamically allocate requests
}

void free_elevator(Elevator *elevator) {
    free(elevator->request);
}

int main() {
    Elevator elevator;
    initialize_elevator(&elevator);

    while (true) {
        int requested_floor;

        printf("\nEnter the floor number (0-%d) to request the elevator, or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &requested_floor);

        if (requested_floor == -1) {
            printf("Exiting elevator simulation.\n");
            break;
        }

        request_elevator(&elevator, requested_floor);
        sleep(1); // Simulating time between requests
    }

    free_elevator(&elevator);
    return 0;
}