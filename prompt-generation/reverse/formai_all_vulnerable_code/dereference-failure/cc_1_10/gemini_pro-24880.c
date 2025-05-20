//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    int priority;        // Task priority
    int arrival_time;   // Task arrival time
    int execution_time; // Task execution time
    int remaining_time; // Remaining execution time
} task;

// Task queue
typedef struct queue {
    struct task *tasks;  // Array of tasks
    int size;             // Number of tasks in the queue
    int capacity;         // Maximum number of tasks in the queue
} queue;

// Create a new task
task *create_task(int id, int priority, int arrival_time, int execution_time) {
    task *new_task = malloc(sizeof(task));
    new_task->id = id;
    new_task->priority = priority;
    new_task->arrival_time = arrival_time;
    new_task->execution_time = execution_time;
    new_task->remaining_time = execution_time;
    return new_task;
}

// Create a new queue
queue *create_queue(int capacity) {
    queue *new_queue = malloc(sizeof(queue));
    new_queue->tasks = malloc(sizeof(task) * capacity);
    new_queue->size = 0;
    new_queue->capacity = capacity;
    return new_queue;
}

// Insert a task into the queue
void enqueue(queue *q, task *new_task) {
    if (q->size == q->capacity) {
        fprintf(stderr, "Queue is full\n");
        return;
    }
    q->tasks[q->size++] = *new_task;
}

// Remove a task from the queue
task *dequeue(queue *q) {
    if (q->size == 0) {
        return NULL;
    }
    task *removed_task = malloc(sizeof(task));
    *removed_task = q->tasks[0];
    for (int i = 0; i < q->size - 1; i++) {
        q->tasks[i] = q->tasks[i + 1];
    }
    q->size--;
    return removed_task;
}

// Sort the queue by priority
void sort_queue(queue *q) {
    for (int i = 0; i < q->size - 1; i++) {
        for (int j = 0; j < q->size - i - 1; j++) {
            if (q->tasks[j].priority > q->tasks[j + 1].priority) {
                task temp = q->tasks[j];
                q->tasks[j] = q->tasks[j + 1];
                q->tasks[j + 1] = temp;
            }
        }
    }
}

// Execute a task
void execute_task(task *t) {
    t->remaining_time--;
    if (t->remaining_time == 0) {
        printf("Task %d completed\n", t->id);
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a task queue
    queue *q = create_queue(10);

    // Generate 10 random tasks
    for (int i = 0; i < 10; i++) {
        int id = i + 1;
        int priority = rand() % 5 + 1;
        int arrival_time = rand() % 10;
        int execution_time = rand() % 10 + 1;
        task *new_task = create_task(id, priority, arrival_time, execution_time);
        enqueue(q, new_task);
    }

    // Sort the queue by priority
    sort_queue(q);

    // Simulate the execution of the tasks
    int current_time = 0;
    while (q->size > 0) {
        // Get the next task from the queue
        task *t = dequeue(q);

        // Check if the task has arrived
        if (t->arrival_time > current_time) {
            current_time = t->arrival_time;
        }

        // Execute the task
        execute_task(t);

        // Increment the current time
        current_time++;
    }

    return 0;
}