//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a task structure
typedef struct Task {
    char name[20];
    int priority;
    int executionTime;
    struct Task* next;
} Task;

// Function to insert a task at the end
void insertTask(Task** head, char* name, int priority, int executionTime) {
    Task* newNode = malloc(sizeof(Task));
    strcpy(newNode->name, name);
    newNode->priority = priority;
    newNode->executionTime = executionTime;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

// Function to execute a task
void executeTask(Task* task) {
    printf("Executing task: %s\n", task->name);
    sleep(task->executionTime);
}

// Function to schedule tasks
void scheduleTasks(Task** head) {
    time_t currentTime = time(NULL);
    Task* currentTask = *head;

    // Iterate over the tasks and execute the ones that are ready
    while (currentTask) {
        if (currentTask->priority == 1 && currentTime >= currentTask->executionTime) {
            executeTask(currentTask);
            free(currentTask);
            *head = (*head)->next;
        } else {
            currentTask = currentTask->next;
        }
    }
}

int main() {
    Task* head = NULL;

    // Insert some tasks
    insertTask(&head, "Task 1", 1, 5);
    insertTask(&head, "Task 2", 2, 3);
    insertTask(&head, "Task 3", 1, 2);

    // Schedule the tasks
    scheduleTasks(&head);

    return 0;
}