//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A task represents a unit of work to be scheduled.
typedef struct task {
    int id;             // Unique ID of the task.
    int priority;       // Priority of the task (higher is more important).
    int execution_time; // Time required to execute the task (in seconds).
    int arrival_time;   // Time when the task arrives (in seconds).
} task;

// A task queue represents a collection of tasks that are waiting to be scheduled.
typedef struct task_queue {
    task *tasks;        // Array of tasks.
    int num_tasks;      // Number of tasks in the queue.
    int head;           // Index of the head of the queue.
    int tail;           // Index of the tail of the queue.
} task_queue;

// Create a new task queue.
task_queue *create_task_queue() {
    task_queue *queue = malloc(sizeof(task_queue));
    queue->tasks = NULL;
    queue->num_tasks = 0;
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

// Add a task to the task queue.
void add_task(task_queue *queue, task *task) {
    // Reallocate the tasks array if necessary.
    if (queue->num_tasks >= queue->head + queue->tail) {
        queue->tasks = realloc(queue->tasks, sizeof(task) * (queue->head + queue->tail + 1));
    }

    // Insert the task at the tail of the queue.
    queue->tasks[queue->tail] = *task;
    queue->tail = (queue->tail + 1) % (queue->head + queue->tail + 1);
    queue->num_tasks++;
}

// Remove a task from the task queue.
task *remove_task(task_queue *queue) {
    // Return NULL if the queue is empty.
    if (queue->num_tasks == 0) {
        return NULL;
    }

    // Get the task at the head of the queue.
    task *task = &queue->tasks[queue->head];

    // Remove the task from the queue.
    queue->head = (queue->head + 1) % (queue->head + queue->tail + 1);
    queue->num_tasks--;

    // Return the task.
    return task;
}

// Schedule tasks using the Round-Robin algorithm.
void schedule_tasks_round_robin(task_queue *queue, int time_slice) {
    // Create a queue to store the tasks that are currently being executed.
    task_queue *executing_queue = create_task_queue();

    // While there are still tasks to be scheduled, keep looping.
    while (queue->num_tasks > 0 || executing_queue->num_tasks > 0) {
        // If there are no tasks currently being executed, get a new task from the queue.
        if (executing_queue->num_tasks == 0) {
            task *task = remove_task(queue);
            if (task != NULL) {
                add_task(executing_queue, task);
            }
        }

        // Get the task that is currently being executed.
        task *task = remove_task(executing_queue);

        // Execute the task for a specified time slice.
        int time_executed = 0;
        while (time_executed < time_slice && task->execution_time > 0) {
            task->execution_time--;
            time_executed++;
        }

        // If the task is still not complete, add it back to the executing queue.
        if (task->execution_time > 0) {
            add_task(executing_queue, task);
        }
    }

    // Free the executing queue.
    free(executing_queue);
}


int main() {
    // Let's create a task queue!
    task_queue *queue = create_task_queue();

    // Now, let's add some tasks to the queue.
    task task1 = { .id = 1, .priority = 5, .execution_time = 10, .arrival_time = 0 };
    add_task(queue, &task1);

    task task2 = { .id = 2, .priority = 3, .execution_time = 5, .arrival_time = 2 };
    add_task(queue, &task2);

    task task3 = { .id = 3, .priority = 1, .execution_time = 15, .arrival_time = 4 };
    add_task(queue, &task3);

    // Let's schedule these tasks using the Round-Robin algorithm with a time slice of 3 seconds.
    schedule_tasks_round_robin(queue, 3);

    return 0;
}