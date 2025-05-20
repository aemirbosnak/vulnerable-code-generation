//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Task structure
typedef struct task {
    char* name;
    int priority;
    int execution_time;
    time_t start_time;
} task;

// Task queue
task* queue[100];
int queue_size = 0;

// Task scheduler
void schedule_tasks() {
    while (queue_size > 0) {
        // Find the task with the highest priority
        int highest_priority = -1;
        int highest_priority_index = -1;
        for (int i = 0; i < queue_size; i++) {
            if (queue[i]->priority > highest_priority) {
                highest_priority = queue[i]->priority;
                highest_priority_index = i;
            }
        }

        // Execute the task with the highest priority
        task* highest_priority_task = queue[highest_priority_index];
        printf("Executing task: %s\n", highest_priority_task->name);
        sleep(highest_priority_task->execution_time);

        // Remove the task from the queue
        for (int i = highest_priority_index; i < queue_size - 1; i++) {
            queue[i] = queue[i + 1];
        }
        queue_size--;
    }
}

// Task generator
void generate_tasks() {
    // Create a bunch of random tasks
    for (int i = 0; i < 100; i++) {
        task* task = malloc(sizeof(task));
        task->name = malloc(100);
        sprintf(task->name, "Task %d", i);
        task->priority = rand() % 10;
        task->execution_time = rand() % 10;
        task->start_time = time(NULL);

        // Add the task to the queue
        queue[queue_size++] = task;
    }
}

int main() {
    // Generate a bunch of random tasks
    generate_tasks();

    // Schedule the tasks
    schedule_tasks();

    return 0;
}