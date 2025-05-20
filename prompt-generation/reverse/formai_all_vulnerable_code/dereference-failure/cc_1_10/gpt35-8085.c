//FormAI DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

// define task structure
typedef struct {
    int id;         // task id
    int interval;   // interval in seconds
    int duration;   // duration in seconds
    bool active;    // active or not
} Task;

// global variables
Task* tasks;        // array of tasks
int numTasks;       // number of tasks
int count;          // count of intervals
bool running;       // whether the scheduler is running or not

// create new task
Task* createTask(int id, int interval, int duration) {
    Task* t = malloc(sizeof(Task));
    t->id = id;
    t->interval = interval;
    t->duration = duration;
    t->active = true;
    return t;
}

// start task
void startTask(int id) {
    tasks[id].active = true;
    printf("Task %d started\n", id);
}

// stop task
void stopTask(int id) {
    tasks[id].active = false;
    printf("Task %d stopped\n", id);
}

// stop all tasks
void stopAllTasks() {
    for (int i = 0; i < numTasks; i++) {
        tasks[i].active = false;
    }
    printf("All tasks stopped\n");
}

// signal handler for SIGINT
void interruptHandler(int sig) {
    printf("\nStopping scheduler...\n");
    running = false;
}

int main() {
    // initialize signal handler for SIGINT
    signal(SIGINT, interruptHandler);

    // initialize random number generator
    srand(time(NULL));

    // create tasks
    numTasks = 5;
    tasks = malloc(sizeof(Task) * numTasks);
    for (int i = 0; i < numTasks; i++) {
        tasks[i] = *createTask(i, rand() % 10 + 1, rand() % 5 + 1);
        printf("Task %d created with interval %d and duration %d\n", i, tasks[i].interval, tasks[i].duration);
    }

    // start scheduler
    running = true;
    count = 0;
    printf("Scheduler started\n");
    while (running) {
        // execute tasks
        for (int i = 0; i < numTasks; i++) {
            if (tasks[i].active && count % tasks[i].interval == 0) {
                printf("Executing task %d\n", i);
                sleep(tasks[i].duration);
            }
        }

        // increment count
        count++;

        // sleep for 1 second
        sleep(1);
    }

    // stop all tasks
    stopAllTasks();

    // free memory
    free(tasks);

    return 0;
}