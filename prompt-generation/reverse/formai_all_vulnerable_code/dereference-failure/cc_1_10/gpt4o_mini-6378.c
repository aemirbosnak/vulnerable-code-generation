//GPT-4o-mini DATASET v1.0 Category: Traffic Flow Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_CARS 10
#define GREEN_LIGHT_DURATION 5
#define RED_LIGHT_DURATION 3

typedef struct Car {
    int id;
    struct Car* next;
} Car;

typedef struct Queue {
    Car* front;
    Car* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool isFull(Queue* queue) {
    return queue->size == MAX_CARS;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, int id) {
    if (isFull(queue)) {
        printf("Queue is full! Car %d cannot enter.\n", id);
        return;
    }
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->id = id;
    newCar->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newCar;
    } else {
        queue->rear->next = newCar;
    }
    queue->rear = newCar;
    queue->size++;
    printf("Car %d has entered the queue.\n", id);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! No cars to exit.\n");
        return -1;
    }
    Car* temp = queue->front;
    int id = temp->id;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return id;
}

void simulateTraffic(Queue* queue) {
    int carId = 1;
    while (true) {
        printf("Traffic light is GREEN for %d seconds.\n", GREEN_LIGHT_DURATION);
        for (int i = 0; i < GREEN_LIGHT_DURATION; i++) {
            if (!isEmpty(queue)) {
                int exitingCarId = dequeue(queue);
                if (exitingCarId != -1) {
                    printf("Car %d is passing through the intersection.\n", exitingCarId);
                }
            }
            sleep(1);
        }

        printf("Traffic light is RED for %d seconds.\n", RED_LIGHT_DURATION);
        for (int i = 0; i < RED_LIGHT_DURATION; i++) {
            sleep(1);
        }

        if (!isFull(queue)) {
            enqueue(queue, carId++);
        }

        // Loops every 2 additional seconds to enqueue new cars.
        sleep(2);
    }
}

int main() {
    Queue* queue = createQueue();
    simulateTraffic(queue);

    // Free allocated queue after simulation
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
    return 0;
}