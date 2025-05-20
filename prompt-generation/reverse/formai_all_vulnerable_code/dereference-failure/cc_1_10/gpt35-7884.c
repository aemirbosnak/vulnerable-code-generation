//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: distributed
#include <stdio.h>
#include <pthread.h>

#define MAX_ELEVATORS 3 // number of elevators
#define MAX_FLOORS 10 // number of floors

enum state {
    GOING_UP,
    GOING_DOWN,
    IDLE
};

struct elevator {
    int current_floor;
    enum state current_state;
    int dest_floor;

    pthread_mutex_t state_mutex;
    pthread_cond_t state_condition;
};

struct elevator elevators[MAX_ELEVATORS];

void* elevator_thread(void* arg) {
    int elevator_id = *((int*)arg);
    struct elevator* elevator = &(elevators[elevator_id]);

    while (1) {
        pthread_mutex_lock(&(elevator->state_mutex));

        // Wait until elevator is needed
        pthread_cond_wait(&(elevator->state_condition), &(elevator->state_mutex));

        printf("Elevator %d is going from %d to %d\n", elevator_id, elevator->current_floor, elevator->dest_floor);

        // Move elevator to destination floor
        while (elevator->current_floor != elevator->dest_floor) {
            if (elevator->current_floor < elevator->dest_floor) {
                elevator->current_floor++;
            } else {
                elevator->current_floor--;
            }

            printf("Elevator %d is at floor %d\n", elevator_id, elevator->current_floor);
        }

        // Elevator has arrived at destination, so set back to idle
        printf("Elevator %d has arrived at floor %d\n", elevator_id, elevator->dest_floor);
        elevator->current_state = IDLE;
        pthread_mutex_unlock(&(elevator->state_mutex));
    }

    return NULL;
}

void request_elevator(int floor, enum state desired_direction) {
    int selected_elevator_id = -1;
    int selected_elevator_distance = 9999;

    // Find closest elevator
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        struct elevator* elevator = &(elevators[i]);

        pthread_mutex_lock(&(elevator->state_mutex));

        // Only consider elevators that are idle or heading in the correct direction
        if (
            (elevator->current_state == IDLE) ||
            (
                (elevator->current_state == GOING_UP) && (desired_direction == GOING_UP) &&
                (elevator->dest_floor > elevator->current_floor) && (floor <= elevator->current_floor)
            ) ||
            (
                (elevator->current_state == GOING_DOWN) && (desired_direction == GOING_DOWN) &&
                (elevator->dest_floor < elevator->current_floor) && (floor >= elevator->current_floor)
            )
        ) {
            int distance = abs(elevator->current_floor - floor);

            if (distance < selected_elevator_distance) {
                selected_elevator_id = i;
                selected_elevator_distance = distance;
            }
        }

        pthread_mutex_unlock(&(elevator->state_mutex));
    }

    // If an elevator was found, assign it to the request
    if (selected_elevator_id != -1) {
        struct elevator* elevator = &(elevators[selected_elevator_id]);

        pthread_mutex_lock(&(elevator->state_mutex));

        elevator->dest_floor = floor;

        if (floor > elevator->current_floor) {
            elevator->current_state = GOING_UP;
        } else if (floor < elevator->current_floor) {
            elevator->current_state = GOING_DOWN;
        }

        printf("Elevator %d has been assigned to floor %d\n", selected_elevator_id, floor);

        pthread_cond_signal(&(elevator->state_condition));
        pthread_mutex_unlock(&(elevator->state_mutex));
    } else {
        printf("No elevators available to service request for floor %d\n", floor);
    }
}

int main() {
    pthread_t elevator_threads[MAX_ELEVATORS];

    for (int i = 0; i < MAX_ELEVATORS; i++) {
        struct elevator* elevator = &(elevators[i]);

        elevator->current_state = IDLE;
        elevator->current_floor = 1;

        pthread_mutex_init(&(elevator->state_mutex), NULL);
        pthread_cond_init(&(elevator->state_condition), NULL);

        int* arg = malloc(sizeof(*arg));
        *arg = i;

        pthread_create(&(elevator_threads[i]), NULL, elevator_thread, arg);
    }

    // Generate some requests
    request_elevator(5, GOING_UP);
    request_elevator(2, GOING_DOWN);
    request_elevator(8, GOING_DOWN);
    request_elevator(6, GOING_UP);
    request_elevator(3, GOING_UP);

    for (int i = 0; i < MAX_ELEVATORS; i++) {
        pthread_join(elevator_threads[i], NULL);
    }

    printf("All elevators have shut down\n");

    return 0;
}