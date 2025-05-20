//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Sherlock Holmes task scheduler
typedef struct Task {
    char name[20];
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

// Create a new task
Task* newTask(char* name, time_t start_time, time_t end_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;
    return newTask;
}

// Insert a task into the scheduler
void insertTask(Task* head, Task* newTask) {
    if (head == NULL) {
        head = newTask;
    } else {
        Task* currentTask = head;
        while (currentTask->next != NULL) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

// Print the tasks in the scheduler
void printTasks(Task* head) {
    Task* currentTask = head;
    while (currentTask) {
        printf("%s, start time: %ld, end time: %ld\n", currentTask->name, currentTask->start_time, currentTask->end_time);
        currentTask = currentTask->next;
    }
}

int main() {
    // Create a new task scheduler
    Task* head = NULL;

    // Insert some tasks
    insertTask(head, newTask("A Study in Scarlet", 10, 12));
    insertTask(head, newTask("The Sign of Four", 12, 14));
    insertTask(head, newTask("The Adventure of Sherlock Holmes", 14, 16));

    // Print the tasks
    printTasks(head);

    return 0;
}