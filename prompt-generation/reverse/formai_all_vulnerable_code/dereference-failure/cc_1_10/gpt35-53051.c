//FormAI DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define task struct
typedef struct Task {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int wait_time;
    struct Task *next;
} Task;

int time = 0; // Global variable to keep track of time

// Create new task
Task *new_task(int id, int priority, int arrival_time, int burst_time) {
    Task *task = (Task *)malloc(sizeof(Task));
    task->id = id;
    task->priority = priority;
    task->arrival_time = arrival_time;
    task->burst_time = burst_time;
    task->wait_time = 0;
    task->next = NULL;
    return task;
}

// Add task to queue based on priority
void add_task(Task **queue, Task *task) {
    if (*queue == NULL || task->priority < (*queue)->priority) {
        task->next = *queue;
        *queue = task;
    } else {
        Task *current = *queue;
        while (current->next != NULL && task->priority >= current->next->priority) {
            current = current->next;
        }
        task->next = current->next;
        current->next = task;
    }
}

// Remove completed task from queue
void remove_task(Task **queue, Task *task) {
    if (*queue == task) {
        *queue = task->next;
    } else {
        Task *current = *queue;
        while (current->next != task) {
            current = current->next;
        }
        current->next = task->next;
    }
    free(task);
}

// Simulator loop
void scheduler(Task **queue) {
    while (*queue != NULL) {
        Task *current = *queue;
        if (current->arrival_time <= time) {
            printf("Time: %d - Running task %d with priority %d and burst time %d\n", time, current->id, current->priority, current->burst_time);

            // Simulate task execution
            usleep(current->burst_time * 1000);

            // Update wait time and remove from queue if complete
            current->wait_time = time - current->arrival_time;
            remove_task(queue, current);
        } else {
            time++;
            printf("Time: %d - Idle\n", time);
        }
    }
}

int main() {
    // Create list of tasks to execute
    Task *queue = NULL;
    add_task(&queue, new_task(1, 2, 0, 500));
    add_task(&queue, new_task(2, 1, 1000, 100));
    add_task(&queue, new_task(3, 3, 1500, 200));
    add_task(&queue, new_task(4, 4, 2000, 50));

    // Start scheduler
    scheduler(&queue);

    return 0;
}