//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define QUEUE_SIZE 50

typedef struct {
    int floor;
    bool direction; // true for up, false for down
} Request;

typedef struct {
    Request queue[QUEUE_SIZE];
    int front;
    int rear;
} RequestQueue;

typedef struct {
    int currentFloor;
    bool direction; // true for up, false for down
    RequestQueue requestQueue;
    pthread_mutex_t lock;
} Elevator;

void initQueue(RequestQueue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isFull(RequestQueue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

bool isEmpty(RequestQueue* q) {
    return q->rear == q->front;
}

void enqueue(RequestQueue* q, Request r) {
    if (!isFull(q)) {
        q->queue[q->rear] = r;
        q->rear = (q->rear + 1) % QUEUE_SIZE;
    } else {
        printf("Queue is full!\n");
    }
}

Request dequeue(RequestQueue* q) {
    if (!isEmpty(q)) {
        Request r = q->queue[q->front];
        q->front = (q->front + 1) % QUEUE_SIZE;
        return r;
    } else {
        Request empty = { -1, false }; // Indicating empty request
        return empty;
    }
}

void* elevatorFunction(void* arg) {
    Elevator* elevator = (Elevator*)arg;
    
    while (true) {
        pthread_mutex_lock(&elevator->lock);

        if (!isEmpty(&elevator->requestQueue)) {
            Request req = dequeue(&elevator->requestQueue);
            pthread_mutex_unlock(&elevator->lock);
            
            printf("Elevator moving from floor %d to floor %d\n", elevator->currentFloor, req.floor);
            elevator->currentFloor = req.floor;
            sleep(1); // Simulating time to move
            printf("Elevator arrived at floor %d\n", elevator->currentFloor);
        } else {
            pthread_mutex_unlock(&elevator->lock);
            usleep(100000); // Sleep a bit to avoid busy waiting
        }
    }
    return NULL;
}

void requestElevator(Elevator* elevator, int floor, bool direction) {
    pthread_mutex_lock(&elevator->lock);
    Request req = { floor, direction };
    enqueue(&elevator->requestQueue, req);
    pthread_mutex_unlock(&elevator->lock);
}

int main() {
    Elevator elevator = { .currentFloor = 0, .direction = true };
    initQueue(&elevator.requestQueue);
    pthread_mutex_init(&elevator.lock, NULL);
    
    pthread_t elevatorThread;
    pthread_create(&elevatorThread, NULL, elevatorFunction, (void*)&elevator);

    int choice, floor;
    while (true) {
        printf("Enter floor number (0-%d) to call elevator or -1 to exit: ", MAX_FLOORS - 1);
        scanf("%d", &choice);
        
        if (choice == -1) {
            break;
        } else if (choice >= 0 && choice < MAX_FLOORS) {
            printf("Requesting elevator to floor %d.\n", choice);
            requestElevator(&elevator, choice, true);
        } else {
            printf("Invalid floor number! Please try again.\n");
        }
    }
    
    pthread_cancel(elevatorThread);
    pthread_mutex_destroy(&elevator.lock);
    return 0;
}