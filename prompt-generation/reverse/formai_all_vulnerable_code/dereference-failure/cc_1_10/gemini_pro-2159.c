//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    char *name;         // Task name
    time_t start_time;  // Task start time
    time_t end_time;    // Task end time
} task_t;

// Task queue
typedef struct task_queue {
    task_t *tasks;     // Array of tasks
    int count;         // Number of tasks in the queue
    int capacity;      // Capacity of the queue
} task_queue_t;

// Create a new task queue
task_queue_t *create_task_queue(int capacity) {
    task_queue_t *queue = malloc(sizeof(task_queue_t));
    if (!queue) {
        return NULL;
    }

    queue->tasks = malloc(sizeof(task_t) * capacity);
    if (!queue->tasks) {
        free(queue);
        return NULL;
    }

    queue->count = 0;
    queue->capacity = capacity;

    return queue;
}

// Destroy the task queue
void destroy_task_queue(task_queue_t *queue) {
    free(queue->tasks);
    free(queue);
}

// Add a task to the queue
int add_task(task_queue_t *queue, task_t *task) {
    if (queue->count == queue->capacity) {
        return -1;  // Queue is full
    }

    queue->tasks[queue->count++] = *task;

    return 0;
}

// Remove a task from the queue
int remove_task(task_queue_t *queue, task_t *task) {
    int i;

    for (i = 0; i < queue->count; i++) {
        if (queue->tasks[i].id == task->id) {
            queue->tasks[i] = queue->tasks[queue->count - 1];
            queue->count--;
            return 0;
        }
    }

    return -1;  // Task not found
}

// Get the next task from the queue
task_t *get_next_task(task_queue_t *queue) {
    if (queue->count == 0) {
        return NULL;  // Queue is empty
    }

    return &queue->tasks[0];
}

// Main function
int main() {
    // Create a task queue
    task_queue_t *queue = create_task_queue(10);

    // Add some tasks to the queue
    task_t task1 = {1, "Task 1", time(NULL), time(NULL) + 10};
    add_task(queue, &task1);

    task_t task2 = {2, "Task 2", time(NULL) + 5, time(NULL) + 15};
    add_task(queue, &task2);

    task_t task3 = {3, "Task 3", time(NULL) + 10, time(NULL) + 20};
    add_task(queue, &task3);

    // Get the next task from the queue
    task_t *task = get_next_task(queue);

    // Execute the task
    printf("Executing task %d: %s\n", task->id, task->name);

    // Remove the task from the queue
    remove_task(queue, task);

    // Destroy the task queue
    destroy_task_queue(queue);

    return 0;
}