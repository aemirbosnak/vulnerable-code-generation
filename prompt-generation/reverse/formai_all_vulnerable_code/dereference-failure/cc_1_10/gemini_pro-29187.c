//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TASKS 10

// Task structure
struct task {
    int id;
    int priority;
    int execution_time;
    int arrival_time;
};

// Queue node structure
struct queue_node {
    struct task task;
    struct queue_node *next;
};

// Queue structure
struct queue {
    struct queue_node *head;
    struct queue_node *tail;
};

// Semaphore for synchronization
sem_t semaphore;

// Function to create a new queue
struct queue *create_queue() {
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Function to enqueue a new task into the queue
void enqueue(struct queue *queue, struct task task) {
    struct queue_node *new_node = (struct queue_node *)malloc(sizeof(struct queue_node));
    new_node->task = task;
    new_node->next = NULL;

    // If the queue is empty, set the head and tail to the new node
    if (queue->head == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
        return;
    }

    // Add the new node to the tail of the queue
    queue->tail->next = new_node;
    queue->tail = new_node;
}

// Function to dequeue a task from the queue
struct task dequeue(struct queue *queue) {
    if (queue->head == NULL) {
        return (struct task){-1, -1, -1, -1}; // Return an invalid task if the queue is empty
    }

    // Get the first task in the queue
    struct task task = queue->head->task;

    // Remove the first task from the queue
    struct queue_node *temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL; // If the queue becomes empty, set the tail to NULL
    }
    free(temp);

    return task;
}

// Function to simulate the execution of a task
void execute_task(struct task task) {
    printf("Executing task %d with priority %d\n", task.id, task.priority);
    sleep(task.execution_time); // Simulate the execution time
}

// Function to run the task scheduler
void run_scheduler(struct queue *queue) {
    while (queue->head != NULL) {
        // Acquire the semaphore
        sem_wait(&semaphore);

        // Dequeue the next task from the queue
        struct task task = dequeue(queue);

        // Release the semaphore
        sem_post(&semaphore);

        // Execute the task
        execute_task(task);
    }
}

// Main function
int main() {
    // Initialize the semaphore
    sem_init(&semaphore, 0, 1);

    // Create a new task queue
    struct queue *queue = create_queue();

    // Generate random tasks and enqueue them into the queue
    srand(time(NULL));
    for (int i = 0; i < NUM_TASKS; i++) {
        struct task task;
        task.id = i + 1;
        task.priority = rand() % 10 + 1;
        task.execution_time = rand() % 5 + 1;
        task.arrival_time = rand() % 10;
        enqueue(queue, task);
    }

    // Run the task scheduler
    run_scheduler(queue);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}