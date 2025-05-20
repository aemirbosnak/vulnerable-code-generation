//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
typedef struct task {
    int id;
    char* name;
    int priority;
    int duration;
    int arrival_time;
} task;

// Task queue
task* queue[100];
int queue_size = 0;

// Task scheduler
void schedule() {
    // Initialize the scheduler
    int current_time = 0;
    int completed_tasks = 0;

    // Run the scheduler until all tasks are completed
    while (completed_tasks < queue_size) {
        // Find the highest priority task that has arrived
        task* highest_priority_task = NULL;
        for (int i = 0; i < queue_size; i++) {
            if (queue[i]->arrival_time <= current_time && (highest_priority_task == NULL || queue[i]->priority > highest_priority_task->priority)) {
                highest_priority_task = queue[i];
            }
        }

        // If there is no task to run, skip a time unit
        if (highest_priority_task == NULL) {
            current_time++;
            continue;
        }

        // Run the task
        highest_priority_task->duration--;
        current_time++;

        // If the task is completed, remove it from the queue
        if (highest_priority_task->duration == 0) {
            for (int i = 0; i < queue_size; i++) {
                if (queue[i] == highest_priority_task) {
                    queue[i] = queue[queue_size - 1];
                    queue_size--;
                    completed_tasks++;
                    break;
                }
            }
        }
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a random task queue
    for (int i = 0; i < 100; i++) {
        task* task = malloc(sizeof(task));
        task->id = i;
        task->name = malloc(16);
        snprintf(task->name, 16, "Task %d", i);
        task->priority = rand() % 10;
        task->duration = rand() % 10;
        task->arrival_time = rand() % 10;
        queue[i] = task;
        queue_size++;
    }

    // Schedule the tasks
    schedule();

    // Print the completed tasks
    printf("Completed tasks:\n");
    for (int i = 0; i < queue_size; i++) {
        printf("%s\n", queue[i]->name);
    }

    // Cleanup
    for (int i = 0; i < queue_size; i++) {
        free(queue[i]->name);
        free(queue[i]);
    }

    return 0;
}