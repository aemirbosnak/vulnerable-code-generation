//FormAI DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declare task struct
typedef struct Task {
    int id;
    int priority;
    int time;
    int elapsed_time;
} Task;

// Declare priority queue node struct
typedef struct PQNode {
    Task* task;
    struct PQNode* next;
} PQNode;

// Declare priority queue struct
typedef struct PriorityQueue {
    PQNode* head;
} PriorityQueue;

// Initialize priority queue
void pq_init(PriorityQueue* pq) {
    pq->head = NULL;
}

// Push task to priority queue
void pq_push(PriorityQueue* pq, Task* task) {
    // Create new PQNode
    PQNode* node = (PQNode*)malloc(sizeof(PQNode));
    node->task = task;
    node->next = NULL;

    // If priority queue is empty, insert as head
    if (pq->head == NULL) {
        pq->head = node;
        return;
    }

    // If task priority is higher than head, insert as new head
    if (task->priority > pq->head->task->priority) {
        node->next = pq->head;
        pq->head = node;
        return;
    }

    // Search for correct insertion position
    PQNode* current = pq->head;
    while (current->next != NULL && current->next->task->priority >= task->priority) {
        current = current->next;
    }

    // Insert node after current
    node->next = current->next;
    current->next = node;
}

// Pop task from priority queue
Task* pq_pop(PriorityQueue* pq) {
    // Empty queue
    if (pq->head == NULL) {
        printf("Error: priority queue is empty\n");
        return NULL;
    }

    // Pop head
    Task* task = pq->head->task;
    PQNode* temp = pq->head;
    pq->head = pq->head->next;
    free(temp);

    return task;
}

// Generate random task
Task* generate_task(int id) {
    Task* task = (Task*)malloc(sizeof(Task));
    task->id = id;
    task->priority = rand() % 10 + 1; // 1-10 priority
    task->time = rand() % 10 + 1; // 1-10 time required
    task->elapsed_time = 0;
    return task;
}

int main() {
    int count = 0;
    PriorityQueue pq;
    pq_init(&pq);
    srand(time(NULL)); // Seed random number generator

    // Generate 10 random tasks
    for (int i = 0; i < 10; i++) {
        Task* task = generate_task(count++);
        pq_push(&pq, task);
    }

    // Run tasks in priority order
    while (pq.head != NULL) {
        Task* task = pq_pop(&pq);
        printf("Running task %d (priority %d, time required %d)\n", task->id, task->priority, task->time);
        // Simulate task execution
        while (task->elapsed_time < task->time) {
            printf("    Task %d status: %d%% complete\n", task->id, (int)(((double)task->elapsed_time / (double)task->time) * 100));
            task->elapsed_time++;
            usleep(100000); // Sleep for 100ms
        }
        printf("Task %d complete\n", task->id);
        free(task); // Free memory allocated to task
    }

    return 0;
}