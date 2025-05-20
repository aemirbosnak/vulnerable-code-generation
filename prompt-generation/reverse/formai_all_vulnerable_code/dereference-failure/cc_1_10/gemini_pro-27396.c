//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Task structure
typedef struct task {
    int id;
    int arrival_time;
    int execution_time;
    int priority;
    int remaining_time;
    int status; // 0 - Not started, 1 - Running, 2 - Completed
} task;

// Task queue
task *tasks;
int num_tasks;

// CPU scheduler
void cpu_scheduler() {
    while (num_tasks > 0) {
        int current_time = time(NULL);

        // Find the highest priority task that has arrived and is not completed
        int highest_priority = -1;
        int highest_priority_task_id = -1;
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].status == 0 && tasks[i].arrival_time <= current_time && tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                highest_priority_task_id = i;
            }
        }

        // If there is no such task, wait for one to arrive
        if (highest_priority_task_id == -1) {
            printf("No tasks to execute. Waiting for one to arrive...\n");
            sleep(1);
            continue;
        }

        // Run the task with the highest priority
        tasks[highest_priority_task_id].status = 1;
        printf("Running task %d with priority %d\n", tasks[highest_priority_task_id].id, tasks[highest_priority_task_id].priority);
        sleep(tasks[highest_priority_task_id].execution_time);
        tasks[highest_priority_task_id].remaining_time -= tasks[highest_priority_task_id].execution_time;

        // If the task is completed, remove it from the queue
        if (tasks[highest_priority_task_id].remaining_time <= 0) {
            tasks[highest_priority_task_id].status = 2;
            for (int i = highest_priority_task_id; i < num_tasks - 1; i++) {
                tasks[i] = tasks[i + 1];
            }
            num_tasks--;
        }
    }
}

// Main function
int main() {
    // Initialize the task queue
    num_tasks = 0;
    tasks = NULL;

    // Generate 10 random tasks
    for (int i = 0; i < 10; i++) {
        task t;
        t.id = i;
        t.arrival_time = rand() % 10;
        t.execution_time = rand() % 10;
        t.priority = rand() % 10;
        t.remaining_time = t.execution_time;
        t.status = 0;
        tasks = realloc(tasks, (num_tasks + 1) * sizeof(task));
        tasks[num_tasks++] = t;
    }

    // Print the task queue
    printf("Task Queue:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d: arrival time = %d, execution time = %d, priority = %d, remaining time = %d, status = %d\n",
            tasks[i].id, tasks[i].arrival_time, tasks[i].execution_time, tasks[i].priority, tasks[i].remaining_time, tasks[i].status);
    }

    // Start the CPU scheduler
    cpu_scheduler();

    return 0;
}