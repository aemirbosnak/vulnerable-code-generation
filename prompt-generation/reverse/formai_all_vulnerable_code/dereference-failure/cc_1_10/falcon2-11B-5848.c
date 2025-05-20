//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct elevator {
    int floor;
    int direction;
} elevator;

typedef struct thread_data {
    int id;
    elevator* elevator_data;
    int next_floor;
} thread_data;

void* elevator_thread(void* data) {
    thread_data* td = (thread_data*)data;
    elevator* elevator = td->elevator_data;
    int floor = td->next_floor;

    elevator->floor = floor;
    elevator->direction = 0;

    printf("Elevator %d going to floor %d\n", td->id, floor);
    sleep(2);
    elevator->floor = 0;
    elevator->direction = 1;

    printf("Elevator %d going to floor %d\n", td->id, elevator->floor);
    sleep(2);

    pthread_exit(NULL);
}

int main() {
    elevator* elevator1 = malloc(sizeof(elevator));
    elevator1->floor = 1;
    elevator1->direction = 0;

    pthread_t thread1;
    pthread_create(&thread1, NULL, elevator_thread, (void*)elevator1);
    pthread_join(thread1, NULL);

    elevator1->floor = 0;
    elevator1->direction = 1;

    pthread_t thread2;
    pthread_create(&thread2, NULL, elevator_thread, (void*)elevator1);
    pthread_join(thread2, NULL);

    free(elevator1);

    return 0;
}