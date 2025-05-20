//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    int arrival_time;   // Task arrival time
    int execution_time; // Task execution time
    int remaining_time; // Task remaining execution time
} task;

// Task queue
task *queue;
int queue_size = 0;

// Queue operations
void enqueue(task *t) {
    queue = realloc(queue, (queue_size + 1) * sizeof(task));
    queue[queue_size++] = *t;
}

task *dequeue() {
    if (queue_size == 0) {
        return NULL;
    }
    task *t = &queue[0];
    for (int i = 1; i < queue_size; i++) {
        queue[i - 1] = queue[i];
    }
    queue_size--;
    return t;
}

// Task scheduler
void schedule(int num_tasks) {
    // Initialize task queue
    queue = malloc(sizeof(task) * num_tasks);

    // Generate random tasks
    srand(time(NULL));
    for (int i = 0; i < num_tasks; i++) {
        task t = {
            .id = i,
            .arrival_time = rand() % 10,
            .execution_time = rand() % 10 + 1,
            .remaining_time = rand() % 10 + 1,
        };
        enqueue(&t);
    }

    // Print task queue
    printf("Task Queue:\n");
    for (int i = 0; i < queue_size; i++) {
        task *t = &queue[i];
        printf("Task %d: arrival time = %d, execution time = %d, remaining time = %d\n", t->id, t->arrival_time, t->execution_time, t->remaining_time);
    }

    // Schedule tasks
    int time = 0;
    while (queue_size > 0) {
        // Get next task from queue
        task *t = dequeue();

        // Check if task has arrived
        if (t->arrival_time <= time) {
            // Run task
            printf("Running task %d at time %d\n", t->id, time);
            t->remaining_time--;

            // Check if task is completed
            if (t->remaining_time == 0) {
                printf("Task %d completed at time %d\n", t->id, time);
            } else {
                // Put task back in queue
                enqueue(t);
            }
        } else {
            // Task has not arrived yet, wait
            time++;
        }
    }
}

int main() {
    // Number of tasks
    int num_tasks = 10;

    // Schedule tasks
    schedule(num_tasks);

    return 0;
}