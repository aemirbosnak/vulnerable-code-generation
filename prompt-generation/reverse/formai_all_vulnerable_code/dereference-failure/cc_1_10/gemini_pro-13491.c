//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The struct of a task
typedef struct task {
    int id;
    char *description;
    int priority;
    time_t start_time;
    time_t end_time;
} task;

// The struct of a task queue
typedef struct task_queue {
    task *tasks;
    int size;
    int capacity;
} task_queue;

// Create a new task
task *create_task(int id, char *description, int priority, time_t start_time, time_t end_time) {
    task *new_task = (task *)malloc(sizeof(task));
    new_task->id = id;
    new_task->description = description;
    new_task->priority = priority;
    new_task->start_time = start_time;
    new_task->end_time = end_time;
    return new_task;
}

// Create a new task queue
task_queue *create_task_queue(int capacity) {
    task_queue *new_queue = (task_queue *)malloc(sizeof(task_queue));
    new_queue->tasks = (task *)malloc(sizeof(task) * capacity);
    new_queue->size = 0;
    new_queue->capacity = capacity;
    return new_queue;
}

// Add a task to the queue
void add_task(task_queue *queue, task *new_task) {
    if (queue->size == queue->capacity) {
        printf("The task queue is full!\n");
        return;
    }
    queue->tasks[queue->size++] = *new_task;
}

// Remove a task from the queue
void remove_task(task_queue *queue, int task_id) {
    int i;
    for (i = 0; i < queue->size; i++) {
        if (queue->tasks[i].id == task_id) {
            break;
        }
    }
    if (i == queue->size) {
        printf("The task with id %d was not found!\n", task_id);
        return;
    }
    for (; i < queue->size - 1; i++) {
        queue->tasks[i] = queue->tasks[i + 1];
    }
    queue->size--;
}

// Print the tasks in the queue
void print_tasks(task_queue *queue) {
    int i;
    for (i = 0; i < queue->size; i++) {
        printf("Task %d: %s (priority %d, start time %s, end time %s)\n",
               queue->tasks[i].id, queue->tasks[i].description,
               queue->tasks[i].priority, ctime(&queue->tasks[i].start_time), ctime(&queue->tasks[i].end_time));
    }
}

// The main function
int main() {
    // Create a new task queue
    task_queue *queue = create_task_queue(10);

    // Add some tasks to the queue
    add_task(queue, create_task(1, "Gather wood", 1, time(NULL), time(NULL) + 3600));
    add_task(queue, create_task(2, "Build a fire", 2, time(NULL) + 3600, time(NULL) + 7200));
    add_task(queue, create_task(3, "Cook a meal", 3, time(NULL) + 7200, time(NULL) + 10800));
    add_task(queue, create_task(4, "Rest", 4, time(NULL) + 10800, time(NULL) + 14400));

    // Print the tasks in the queue
    print_tasks(queue);

    // Remove a task from the queue
    remove_task(queue, 2);

    // Print the tasks in the queue
    print_tasks(queue);

    return 0;
}