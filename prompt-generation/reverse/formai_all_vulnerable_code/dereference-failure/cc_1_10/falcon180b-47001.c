//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TASKS 100
#define MAX_PRIORITIES 10

// Task structure
typedef struct {
    char name[50];
    int priority;
    void (*func)(void);
} Task;

// Priority queue structure
typedef struct {
    Task tasks[MAX_TASKS];
    int size;
} PriorityQueue;

// Initialize priority queue
void init(PriorityQueue* pq) {
    pq->size = 0;
}

// Add task to priority queue
void add_task(PriorityQueue* pq, Task task) {
    if (pq->size >= MAX_TASKS) {
        printf("Priority queue is full!\n");
        return;
    }
    pq->tasks[pq->size++] = task;
}

// Remove task from priority queue
Task remove_task(PriorityQueue* pq) {
    Task task = pq->tasks[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->tasks[i] = pq->tasks[i + 1];
    }
    pq->size--;
    return task;
}

// Run task with highest priority
void run_task(PriorityQueue* pq) {
    Task task = remove_task(pq);
    printf("Running task %s with priority %d\n", task.name, task.priority);
    task.func();
}

// Example tasks
void task1(void) {
    printf("Task 1 is running...\n");
}

void task2(void) {
    printf("Task 2 is running...\n");
}

// Example usage
int main() {
    PriorityQueue pq;
    init(&pq);
    add_task(&pq, (Task) {"Task 1", 1, task1});
    add_task(&pq, (Task) {"Task 2", 2, task2});
    run_task(&pq);
    run_task(&pq);
    return 0;
}