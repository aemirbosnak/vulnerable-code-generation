//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Task structure
typedef struct Task {
    int id;
    time_t scheduledTime;
    void (*callback)(void);
} Task;

// Task queue
static Task* taskQueue[100];
static int taskQueueSize = 0;

// Helper function to compare task times
int compareTasks(const void* a, const void* b) {
    Task* task1 = (Task*)a;
    Task* task2 = (Task*)b;
    return task1->scheduledTime - task2->scheduledTime;
}

// Schedule a new task
void scheduleTask(int id, time_t scheduledTime, void (*callback)(void)) {
    Task* newTask = malloc(sizeof(Task));
    newTask->id = id;
    newTask->scheduledTime = scheduledTime;
    newTask->callback = callback;
    
    taskQueue[taskQueueSize++] = newTask;
}

// Main task loop
void runTaskLoop() {
    while (taskQueueSize > 0) {
        // Sort the task queue by scheduled time
        qsort(taskQueue, taskQueueSize, sizeof(Task*), compareTasks);
        
        // Get the earliest scheduled task
        Task* nextTask = taskQueue[0];
        
        // Check if the current time is past the scheduled time
        if (time(NULL) >= nextTask->scheduledTime) {
            // Remove the task from the queue
            for (int i = 0; i < taskQueueSize; i++) {
                if (taskQueue[i] == nextTask) {
                    for (int j = i; j < taskQueueSize; j++) {
                        taskQueue[j] = taskQueue[j+1];
                    }
                    taskQueueSize--;
                    break;
                }
            }
            
            // Execute the task
            nextTask->callback();
        }
    }
}

// Example task callbacks
void task1() { printf("Task 1 executed!\n"); }
void task2() { printf("Task 2 executed!\n"); }
void task3() { printf("Task 3 executed!\n"); }

int main() {
    // Schedule some tasks
    scheduleTask(1, time(NULL) + 5, task1);
    scheduleTask(2, time(NULL) + 10, task2);
    scheduleTask(3, time(NULL) + 15, task3);
    
    // Start the task loop
    runTaskLoop();
    
    return 0;
}