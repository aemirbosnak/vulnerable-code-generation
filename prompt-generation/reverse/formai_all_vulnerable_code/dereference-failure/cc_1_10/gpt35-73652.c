//FormAI DATASET v1.0 Category: Task Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    char name[50];
    int priority;
    int time_remaining;
    struct Task *next;
} Task;

Task *head = NULL;

Task *createTask(char *name, int priority, int time_remaining);
void addTask(Task *newTask);
void removeTask(Task *task);
void printList();
void runTask(Task *task);

int main() {
    addTask(createTask("Task 1", 2, 10));
    addTask(createTask("Task 2", 1, 5));
    addTask(createTask("Task 3", 3, 7));
    addTask(createTask("Task 4", 1, 3));
    addTask(createTask("Task 5", 2, 6));

    printf("List of tasks:\n");
    printList();

    printf("\nRunning tasks recursively:\n");
    while (head != NULL) {
        runTask(head);
        printf("\n");
        printList();
    }

    return 0;
}

Task *createTask(char *name, int priority, int time_remaining) {
    Task *newTask = (Task *) malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->time_remaining = time_remaining;
    newTask->next = NULL;
    return newTask;
}

void addTask(Task *newTask) {
    if (head == NULL) {
        head = newTask;
        return;
    }

    if (newTask->priority < head->priority) {
        newTask->next = head;
        head = newTask;
    } else {
        Task *current = head;
        while (current->next != NULL && newTask->priority >= current->next->priority) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
}

void removeTask(Task *task) {
    if (head == NULL) {
        return;
    }

    if (head == task) {
        head = head->next;
    } else {
        Task *current = head;
        while (current->next != NULL && current->next != task) {
            current = current->next;
        }
        if (current->next != NULL) {
            current->next = task->next;
        }
    }
    free(task);
}

void printList() {
    printf("Name\tPriority\tTime remaining\n");
    if (head == NULL) {
        printf("No tasks\n");
        return;
    }

    Task *current = head;
    while (current != NULL) {
        printf("%s\t%d\t\t%d\n", current->name, current->priority, current->time_remaining);
        current = current->next;
    }
}

void runTask(Task *task) {
    printf("Running task %s...\n", task->name);
    task->time_remaining--;
    if (task->time_remaining <= 0) {
        removeTask(task);
    } else {
        removeTask(task);
        addTask(task);
        runTask(head);
    }
}