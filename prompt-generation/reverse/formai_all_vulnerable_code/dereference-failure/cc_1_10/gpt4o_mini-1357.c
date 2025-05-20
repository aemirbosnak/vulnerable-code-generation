//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Structure to represent a task
typedef struct Task {
    char name[50];
    time_t timeToRun;
} Task;

// Structure to represent the task scheduler
typedef struct Scheduler {
    Task* tasks;
    int size;
    int capacity;
} Scheduler;

// Function to create a new scheduler
Scheduler* createScheduler(int capacity) {
    Scheduler* scheduler = malloc(sizeof(Scheduler));
    scheduler->tasks = malloc(sizeof(Task) * capacity);
    scheduler->size = 0;
    scheduler->capacity = capacity;
    return scheduler;
}

// Function to add a task to the scheduler
void addTask(Scheduler* scheduler, const char* name, time_t timeToRun) {
    if (scheduler->size < scheduler->capacity) {
        strcpy(scheduler->tasks[scheduler->size].name, name);
        scheduler->tasks[scheduler->size].timeToRun = timeToRun;
        scheduler->size++;
    } else {
        printf("Alas! The scheduler hath no room for more tasks.\n");
    }
}

// Function to run scheduled tasks
void* runTasks(void* param) {
    Scheduler* scheduler = (Scheduler*)param;

    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < scheduler->size; i++) {
            if (scheduler->tasks[i].timeToRun <= now) {
                printf("Oh! 'Tis time for task: %s, to commence!\n", scheduler->tasks[i].name);
                
                // Simulate the execution of the task
                sleep(2);  // sleep for 2 seconds
                printf("Task '%s' hath completed its noble journey.\n", scheduler->tasks[i].name);
                
                // Shift tasks left
                for (int j = i; j < scheduler->size - 1; j++) {
                    scheduler->tasks[j] = scheduler->tasks[j + 1];
                }
                scheduler->size--; // Reduce the size of the task list
                i--; // Adjust index after removal
            }
        }
        sleep(1); // Check for tasks every second
    }
    
    return NULL;
}

// Function to free the scheduler
void freeScheduler(Scheduler* scheduler) {
    free(scheduler->tasks);
    free(scheduler);
}

// Main function
int main() {
    Scheduler* scheduler = createScheduler(5);
    
    printf("In fair Verona, where we lay our scene...\n");

    // Adding tasks with poetic names and defined run times
    time_t now = time(NULL);
    addTask(scheduler, "Prologue", now + 3); // 3 seconds from now
    addTask(scheduler, "Love's Sweet Beginnings", now + 5); // 5 seconds from now
    addTask(scheduler, "Fateful Encounter", now + 10); // 10 seconds from now
    addTask(scheduler, "Banishment's Grief", now + 15); // 15 seconds from now
    addTask(scheduler, "A Tragic End", now + 20); // 20 seconds from now

    // Create a thread for the task scheduler
    pthread_t schedulerThread;
    pthread_create(&schedulerThread, NULL, runTasks, (void*)scheduler);

    // Wait for thread to finish (in a real program you may want to handle this differently)
    pthread_join(schedulerThread, NULL);

    // Clean up
    freeScheduler(scheduler);
    
    printf("Thus concludes our tragic tale, until the next performance doth prevail.\n");
    return 0;
}