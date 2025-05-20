//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Task {
    int id;                     // Unique identifier for the task
    char name[50];             // Task name
    int execution_time;        // Time when the task should be executed
    struct Task* next;         // Pointer to the next task in the list
} Task;

typedef struct TaskScheduler {
    Task* head;                // Head of the linked list of tasks
} TaskScheduler;

// Function prototypes
TaskScheduler* createScheduler();
void addTask(TaskScheduler* scheduler, const char* name, int execution_time);
void executeTasks(TaskScheduler* scheduler);
void freeScheduler(TaskScheduler* scheduler);
void printTasks(TaskScheduler* scheduler);

void executeTask(Task* task) {
    printf("Executing Task %d: %s at time %d seconds\n", task->id, task->name, task->execution_time);
    sleep(1); // Simulate task execution time
}

int main() {
    TaskScheduler* scheduler = createScheduler();
    
    // Sample task additions
    addTask(scheduler, "Task 1", 3);
    addTask(scheduler, "Task 2", 2);
    addTask(scheduler, "Task 3", 5);
    addTask(scheduler, "Task 4", 1);
    
    // Print out the tasks before execution
    printf("Scheduled Tasks:\n");
    printTasks(scheduler);
    
    // Execute the scheduled tasks
    printf("\nExecuting Scheduled Tasks:\n");
    executeTasks(scheduler);
    
    // Free allocated memory
    freeScheduler(scheduler);
    
    return 0;
}

// Creates a new Task Scheduler
TaskScheduler* createScheduler() {
    TaskScheduler* scheduler = (TaskScheduler*)malloc(sizeof(TaskScheduler));
    scheduler->head = NULL;
    return scheduler;
}

// Adds a new task to the scheduler
void addTask(TaskScheduler* scheduler, const char* name, int execution_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->id = (scheduler->head == NULL) ? 1 : scheduler->head->id + 1; // Set task ID
    strcpy(newTask->name, name);
    newTask->execution_time = execution_time;
    newTask->next = NULL;

    // Insert in sorted order based on execution_time
    if (scheduler->head == NULL || scheduler->head->execution_time > execution_time) {
        newTask->next = scheduler->head;
        scheduler->head = newTask;
    } else {
        Task* current = scheduler->head;
        while (current->next != NULL && current->next->execution_time <= execution_time) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
}

// Executes all the tasks in the scheduler based on the order of execution_time
void executeTasks(TaskScheduler* scheduler) {
    Task* current = scheduler->head;
    while (current != NULL) {
        executeTask(current);
        current = current->next;
    }
}

// Prints all the tasks in the scheduler
void printTasks(TaskScheduler* scheduler) {
    Task* current = scheduler->head;
    while (current != NULL) {
        printf("Task ID: %d, Name: %s, Execution Time: %d seconds\n",
               current->id, current->name, current->execution_time);
        current = current->next;
    }
}

// Frees all allocated memory for the scheduler and its tasks
void freeScheduler(TaskScheduler* scheduler) {
    Task* current = scheduler->head;
    while (current != NULL) {
        Task* nextTask = current->next;
        free(current);
        current = nextTask;
    }
    free(scheduler);
}