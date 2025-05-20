//FormAI DATASET v1.0 Category: Task Scheduler ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

// Define Task Node Structure
typedef struct TaskNode {
    int id;
    time_t time;
    struct TaskNode* next;
} TaskNode;

// Define Task Scheduler Structure
typedef struct TaskScheduler {
    TaskNode* head;
    time_t timer;
} TaskScheduler;

// Create New Task Node
TaskNode* newTaskNode(int id, time_t time) {
    TaskNode* newTask = (TaskNode*) malloc(sizeof(TaskNode));
    newTask->id = id;
    newTask->time = time;
    newTask->next = NULL;
    return newTask;
}

// Add Task To Scheduler
void addTask(TaskScheduler* scheduler, int id, time_t time) {
    TaskNode* newTask = newTaskNode(id, time);
    TaskNode* current = scheduler->head;
    if (current == NULL) {
        scheduler->head = newTask;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newTask;
}

// Remove Task From Scheduler
void removeTask(TaskScheduler* scheduler, int id) {
    TaskNode* current = scheduler->head;
    TaskNode* previous = NULL;
    if (current == NULL) {
        return;
    }
    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                scheduler->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Print Task Scheduler
void printTasks(TaskScheduler* scheduler) {
    TaskNode* current = scheduler->head;
    printf("\nScheduled Tasks:");
    while (current != NULL) {
        printf("\nTask %d at %s", current->id, ctime(&current->time));
        current = current->next;
    }
}

// Schedule Tasks
void scheduleTasks(TaskScheduler* scheduler) {
    int id = 0;
    time_t currentTime = time(NULL);
    while (scheduler->head != NULL && scheduler->head->time <= currentTime) {
        TaskNode* current = scheduler->head;
        scheduler->head = current->next;
        printf("\nExecuting Task %d at %s", current->id, ctime(&current->time));
        free(current);
    }
}

// Signal Handler
void signalHandler(int signal) {
    printf("\nSignal %d received.\n", signal);
}

// Main Function
int main() {
    // Initialize Task Scheduler
    TaskScheduler scheduler;
    scheduler.head = NULL;
    scheduler.timer = time(NULL);

    // Add Tasks To Scheduler
    addTask(&scheduler, 1, time(NULL)+5);
    addTask(&scheduler, 2, time(NULL)+10);
    addTask(&scheduler, 3, time(NULL)+15);

    // Print Initial Tasks
    printTasks(&scheduler);

    // Set Signal Handler
    signal(SIGALRM, signalHandler);

    // Infinite Loop
    while(1) {
        // Schedule Tasks
        scheduleTasks(&scheduler);

        // Set Timer
        time_t nextTime = scheduler.head ? scheduler.head->time : scheduler.timer+10;
        alarm(nextTime-scheduler.timer);

        // Wait For Signal
        pause();

        // Update Timer
        scheduler.timer = time(NULL);
    }
    return 0;
}