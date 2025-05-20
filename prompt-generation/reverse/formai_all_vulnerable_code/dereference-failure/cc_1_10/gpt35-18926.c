//FormAI DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Task {
    char name[50];
    int priority;
    int interval;
    int next_execution;
} Task;

Task *create_task(char *name, int priority, int interval) {
    Task *task = (Task *) malloc(sizeof(Task));
    strcpy(task->name, name);
    task->priority = priority;
    task->interval = interval;
    task->next_execution = time(NULL) + interval;
    return task;
}

void destroy_task(Task *task) {
    free(task);
}

void execute_task(Task *task) {
    printf("Executing task: %s\n", task->name);
    task->next_execution = time(NULL) + task->interval;
}

int main() {
    // Create some tasks with different priorities and intervals
    Task *task1 = create_task("Task 1", 1, 5);   // Priority 1, interval 5 seconds
    Task *task2 = create_task("Task 2", 2, 10);  // Priority 2, interval 10 seconds
    Task *task3 = create_task("Task 3", 3, 15);  // Priority 2, interval 15 seconds
    
    while (1) {
        Task *highest_priority_task = NULL;
        int highest_priority = 0;
        
        // Find the task with the highest priority that is ready to execute
        if (time(NULL) >= task1->next_execution && task1->priority >= highest_priority) {
            highest_priority_task = task1;
            highest_priority = task1->priority;
        }
        if (time(NULL) >= task2->next_execution && task2->priority >= highest_priority) {
            highest_priority_task = task2;
            highest_priority = task2->priority;
        }
        if (time(NULL) >= task3->next_execution && task3->priority >= highest_priority) {
            highest_priority_task = task3;
            highest_priority = task3->priority;
        }
        
        // If a task was found, execute it
        if (highest_priority_task) {
            execute_task(highest_priority_task);
        }
        
        // Sleep for a short time to avoid busy-waiting
        usleep(1000);
    }
    
    // Destroy tasks when they are no longer needed
    destroy_task(task1);
    destroy_task(task2);
    destroy_task(task3);
    
    return 0;
}