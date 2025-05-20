//FormAI DATASET v1.0 Category: Task Scheduler ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define MAX_TASKS 10
#define MAX_TIME 100

// Structure to store task information
typedef struct Task {
    int id;
    int interval;  // Time interval to run the task
    int lastRun;   // Time when the task was last run
    void (*function)(void);   // Pointer to function
} Task;

// Array to store the tasks
Task tasks[MAX_TASKS];

// Function declarations
void printTime();
void task1();
void task2();
void task3();
void addTask(int id, int interval, void (*function)(void));
void removeTask(int id);
void scheduler();
bool shouldRun(int lastRun, int interval);

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Add some tasks
    addTask(1, 5, task1);
    addTask(2, 10, task2);
    addTask(3, 15, task3);

    // Run the scheduler for MAX_TIME seconds
    for(int t = 0; t < MAX_TIME; t++) {
        printTime();
        scheduler();
        printf("\n");
        sleep(1);
    }

    return 0;
}

// Function to print the current time
void printTime() {
    time_t now = time(NULL);
    printf("%ld: ", now);
}

// Example tasks
void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

void task3() {
    printf("Task 3 running...\n");
}

// Function to add a task to the task list
void addTask(int id, int interval, void (*function)(void)) {
    // Check if the task list is already full
    if(sizeof(tasks) / sizeof(Task) >= MAX_TASKS)
        printf("Cannot add any more tasks!\n");
    else {
        // Create a new task
        Task task = {id, interval, -interval, function};
        tasks[sizeof(tasks) / sizeof(Task)] = task;
        printf("Task %d added.\n", id);
    }
}

// Function to remove a task from the task list
void removeTask(int id) {
    int size = sizeof(tasks) / sizeof(Task);
    for(int i = 0; i < size; i++) {
        if(tasks[i].id == id) {
            // Shift remaining tasks to fill gap
            for(int j = i; j < size-1; j++)
                tasks[j] = tasks[j+1];
            printf("Task %d removed.\n", id);
            break;
        }
    }
}

// Main scheduling function
void scheduler() {
    int size = sizeof(tasks) / sizeof(Task);
    for(int i = 0; i < size; i++) {
        int lastRun = tasks[i].lastRun;
        int interval = tasks[i].interval;
        if(shouldRun(lastRun, interval)) {
            tasks[i].function();
            tasks[i].lastRun = time(NULL);
        }
    }
}

// Function to determine if a given task should run based on its interval and last run time
bool shouldRun(int lastRun, int interval) {
    return time(NULL) - lastRun > interval;
}