//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Knights and knaves are the two classes of people in the kingdom
enum class_t { KNIGHT, KNAVE };
// A request for a task
struct request_t {
    enum class_t class; // The class of the knight or knave making the request
    int arrival_time;   // The time the request arrived
    int duration;       // The duration of the task
};

// A queue of requests
struct queue_t {
    struct request_t *requests; // An array of requests
    int size;                  // The number of requests in the queue
    int head;                  // The index of the first request in the queue
    int tail;                  // The index of the last request in the queue
};

// Create a new queue
struct queue_t *create_queue() {
    struct queue_t *queue = malloc(sizeof(struct queue_t));
    queue->requests = NULL;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

// Destroy a queue
void destroy_queue(struct queue_t *queue) {
    free(queue->requests);
    free(queue);
}

// Add a request to the queue
void enqueue(struct queue_t *queue, struct request_t *request) {
    if (queue->size == 0) {
        queue->requests = malloc(sizeof(struct request_t));
        queue->requests[0] = *request;
        queue->size = 1;
        queue->head = 0;
        queue->tail = 0;
    } else {
        queue->requests = realloc(queue->requests, sizeof(struct request_t) * (queue->size + 1));
        queue->requests[queue->tail] = *request;
        queue->size++;
        queue->tail = (queue->tail + 1) % queue->size;
    }
}

// Remove a request from the queue
struct request_t *dequeue(struct queue_t *queue) {
    if (queue->size == 0) {
        return NULL;
    } else {
        struct request_t *request = &queue->requests[queue->head];
        queue->head = (queue->head + 1) % queue->size;
        queue->size--;
        return request;
    }
}

// Sir Robin is the scheduling algorithm
void sir_robin(struct queue_t *queue) {
    while (queue->size > 0) {
        struct request_t *request = dequeue(queue);
        if (request->class == KNIGHT) {
            // Knights always get their tasks done
            printf("Sir %s, a noble knight, has his task completed.\n", request->class);
        } else {
            // Knaves may or may not get their tasks done
            int dice_roll = rand() % 6 + 1;
            if (dice_roll == 6) {
                printf("Sir %s, a knave, has his task completed.\n", request->class);
            } else {
                printf("Sir %s, a knave, is sent to the dungeon.\n", request->class);
            }
        }
    }
}

int main() {
    // Create a queue of requests
    struct queue_t *queue = create_queue();

    // Add some requests to the queue
    struct request_t request1 = {KNIGHT, 0, 10};
    enqueue(queue, &request1);
    struct request_t request2 = {KNAVE, 5, 5};
    enqueue(queue, &request2);
    struct request_t request3 = {KNIGHT, 10, 15};
    enqueue(queue, &request3);
    struct request_t request4 = {KNAVE, 15, 10};
    enqueue(queue, &request4);

    // Run the scheduling algorithm
    sir_robin(queue);

    // Destroy the queue
    destroy_queue(queue);

    return 0;
}