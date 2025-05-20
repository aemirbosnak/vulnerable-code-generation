//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function signature of the task
typedef void (*task_function)(void);

// Structure of a task
typedef struct {
    int task_id;
    int priority;
    task_function function;
    time_t execution_time;
    bool executed;
} Task;

// A queue of tasks
typedef struct {
    Task **tasks;
    int size;
} TaskQueue;

// Returns the time difference between two times in seconds
double time_difference(time_t start, time_t end) {
    return difftime(end, start);
}

// Creates a new task with a given ID, priority, function and execution time
Task *create_task(int id, int priority, task_function function, time_t execution_time) {
    Task *task = malloc(sizeof(Task));
    task->task_id = id;
    task->priority = priority;
    task->function = function;
    task->execution_time = execution_time;
    task->executed = false;
    return task;
}

// Frees the memory occupied by a task
void destroy_task(Task *task) {
    free(task);
}

// Creates a new task queue
TaskQueue *create_task_queue() {
    TaskQueue *queue = malloc(sizeof(TaskQueue));
    queue->tasks = malloc(sizeof(Task *));
    queue->size = 0;
    return queue;
}

// Adds a task to the task queue
void add_task(TaskQueue *queue, Task *task) {
    queue->tasks = realloc(queue->tasks, sizeof(Task *) * (queue->size + 1));
    queue->tasks[queue->size++] = task;
}

// Removes and returns the highest priority task from the task queue
Task *get_highest_priority_task(TaskQueue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    int highest_priority = queue->tasks[0]->priority;
    int highest_priority_index = 0;

    for (int i = 1; i < queue->size; i++) {
        if (queue->tasks[i]->priority < highest_priority) {
            highest_priority = queue->tasks[i]->priority;
            highest_priority_index = i;
        }
    }

    Task *task = queue->tasks[highest_priority_index];
    for (int i = highest_priority_index; i < queue->size - 1; i++) {
        queue->tasks[i] = queue->tasks[i + 1];
    }
    queue->size--;
    queue->tasks = realloc(queue->tasks, sizeof(Task *) * queue->size);
    return task;
}

// Frees the memory occupied by a task queue
void destroy_task_queue(TaskQueue *queue) {
    for (int i = 0; i < queue->size; i++) {
        destroy_task(queue->tasks[i]);
    }
    free(queue->tasks);
    free(queue);
}

// Example task functions
void task_1() {
    printf("Executing task 1!\n");
}

void task_2() {
    printf("Executing task 2!\n");
}

void task_3() {
    printf("Executing task 3!\n");
}

int main() {
    printf("Creating task queue...\n");
    TaskQueue *queue = create_task_queue();

    // Add tasks to the queue
    srand(time(NULL));
    printf("Adding tasks to the queue...\n");
    for (int i = 1; i <= 3; i++) {
        int priority = rand() % 10;
        int execution_time = rand() % 10;
        switch (i) {
            case 1:
                add_task(queue, create_task(i, priority, task_1, execution_time));
                break;
            case 2:
                add_task(queue, create_task(i, priority, task_2, execution_time));
                break;
            case 3:
                add_task(queue, create_task(i, priority, task_3, execution_time));
                break;
        }
    }

    // Execute tasks in the queue
    printf("Executing tasks from the queue...\n");
    time_t start_time = time(NULL);
    while (queue->size > 0) {
        Task *task = get_highest_priority_task(queue);
        if (!task->executed) {
            task->function();
            task->executed = true;
        }
        double elapsed_time = time_difference(start_time, time(NULL));
        if (elapsed_time >= task->execution_time) {
            destroy_task(task);
        }
        else {
            time_t remaining_time = task->execution_time - elapsed_time;
            add_task(queue, task);
            sleep(remaining_time);
        }
    }

    // Destroy the task queue
    printf("Destroying task queue...\n");
    destroy_task_queue(queue);

    return 0;
}