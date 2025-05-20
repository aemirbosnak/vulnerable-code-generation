//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a task
struct Task {
    int id;
    int executionTime;
    struct Task* next;
};

// Define a function to initialize a task
void initializeTask(struct Task* task) {
    task->id = rand() % 100;
    task->executionTime = rand() % 100;
    task->next = NULL;
}

// Define a function to print a task
void printTask(struct Task* task) {
    printf("Task ID: %d, Execution Time: %d\n", task->id, task->executionTime);
}

// Define a function to add a task to the list
void addTask(struct Task** head, struct Task* newTask) {
    if (*head == NULL) {
        *head = newTask;
    } else {
        struct Task* current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newTask;
    }
}

// Define a function to execute a task
void executeTask(struct Task* task) {
    printf("Executing task %d with execution time %d\n", task->id, task->executionTime);
    sleep(task->executionTime);
}

// Define a function to print the task list
void printList(struct Task* head) {
    struct Task* current = head;
    while (current!= NULL) {
        printTask(current);
        current = current->next;
    }
}

// Define a function to run the task scheduler
int runScheduler() {
    struct Task* head = NULL;
    struct Task* task = NULL;

    // Create and initialize a task
    initializeTask(&task);
    addTask(&head, task);

    // Loop indefinitely
    while (1) {
        // Print the current task list
        printList(head);

        // Remove the first task from the list
        task = head->next;
        head->next = NULL;

        // Execute the task
        executeTask(task);

        // Add a new task to the list
        initializeTask(&task);
        addTask(&head, task);
    }

    return 0;
}

int main() {
    runScheduler();
    return 0;
}