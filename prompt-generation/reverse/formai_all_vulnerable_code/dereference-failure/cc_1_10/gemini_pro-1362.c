//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the task structure
typedef struct task {
    int id;             // Task ID
    char *name;         // Task name
    int priority;       // Task priority
    int arrivalTime;    // Task arrival time
    int executionTime;  // Task execution time
    int remainingTime;  // Remaining execution time
    struct task *next;   // Next task in the queue
} task;

// Define the task queue
task *taskQueue = NULL;

// Function to create a new task
task *createTask(int id, char *name, int priority, int arrivalTime, int executionTime) {
    // Allocate memory for the new task
    task *newTask = (task *)malloc(sizeof(task));

    // Initialize the new task
    newTask->id = id;
    newTask->name = name;
    newTask->priority = priority;
    newTask->arrivalTime = arrivalTime;
    newTask->executionTime = executionTime;
    newTask->remainingTime = executionTime;
    newTask->next = NULL;

    // Return the new task
    return newTask;
}

// Function to add a task to the task queue
void addTask(task *newTask) {
    // If the task queue is empty, add the new task as the first task
    if (taskQueue == NULL) {
        taskQueue = newTask;
    } else {
        // Otherwise, find the appropriate position to insert the new task based on its priority
        task *currentTask = taskQueue;
        task *previousTask = NULL;

        while (currentTask != NULL && newTask->priority >= currentTask->priority) {
            previousTask = currentTask;
            currentTask = currentTask->next;
        }

        if (previousTask == NULL) {
            // Insert the new task at the beginning of the queue
            newTask->next =taskQueue;
            taskQueue = newTask;
        } else {
            // Insert the new task after the previous task
            previousTask->next = newTask;
            newTask->next = currentTask;
        }
    }
}

// Function to schedule tasks using the Round-Robin algorithm
void scheduleTasks(int timeQuantum) {
    // While there are still tasks in the queue
    while (taskQueue != NULL) {
        // Get the current task
        task *currentTask = taskQueue;

        // Execute the current task for the specified time quantum
        if (currentTask->remainingTime <= timeQuantum) {
            printf("Executing task %s for %d units of time\n", currentTask->name, currentTask->remainingTime);

            // Update the remaining execution time
            currentTask->remainingTime = 0;

            // Remove the current task from the queue
            taskQueue = currentTask->next;

            // Free the memory allocated for the current task
            free(currentTask);
        } else {
            printf("Executing task %s for %d units of time\n", currentTask->name, timeQuantum);

            // Update the remaining execution time
            currentTask->remainingTime -= timeQuantum;

            // Move the current task to the end of the queue
            taskQueue = currentTask->next;
            currentTask->next = NULL;
            addTask(currentTask);
        }

        // Sleep for the specified time quantum
        sleep(timeQuantum);
    }
}

// Main function
int main() {
    // Create a set of tasks
    task *task1 = createTask(1, "Task 1", 5, 0, 10);
    task *task2 = createTask(2, "Task 2", 3, 2, 5);
    task *task3 = createTask(3, "Task 3", 4, 4, 8);
    task *task4 = createTask(4, "Task 4", 2, 6, 3);
    task *task5 = createTask(5, "Task 5", 1, 8, 6);

    // Add the tasks to the task queue
    addTask(task1);
    addTask(task2);
    addTask(task3);
    addTask(task4);
    addTask(task5);

    // Schedule the tasks using the Round-Robin algorithm with a time quantum of 2 units
    scheduleTasks(2);

    return 0;
}