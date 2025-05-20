//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    char *name;
    int duration;
    int priority;
    struct Task *next;
} Task;

Task *head = NULL;
Task *current = NULL;

void createTask(char *name, int duration, int priority) {
    Task *newTask = (Task *) malloc(sizeof(Task));
    newTask->name = name;
    newTask->duration = duration;
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
        current = head;
    } else {
        current->next = newTask;
        current = newTask;
    }
}

void printQueue() {
    Task *temp = head;
    while (temp!= NULL) {
        printf("%s - %d - %d\n", temp->name, temp->duration, temp->priority);
        temp = temp->next;
    }
}

void printTask(Task *task) {
    printf("%s - %d - %d\n", task->name, task->duration, task->priority);
}

void executeTask(Task *task) {
    printf("Executing: %s\n", task->name);
    sleep(task->duration);
    printf("Executed: %s\n", task->name);
}

int main() {
    Task *task1 = (Task *) malloc(sizeof(Task));
    task1->name = "Task 1";
    task1->duration = 5;
    task1->priority = 1;
    createTask(task1->name, task1->duration, task1->priority);

    Task *task2 = (Task *) malloc(sizeof(Task));
    task2->name = "Task 2";
    task2->duration = 10;
    task2->priority = 2;
    createTask(task2->name, task2->duration, task2->priority);

    Task *task3 = (Task *) malloc(sizeof(Task));
    task3->name = "Task 3";
    task3->duration = 2;
    task3->priority = 3;
    createTask(task3->name, task3->duration, task3->priority);

    Task *task4 = (Task *) malloc(sizeof(Task));
    task4->name = "Task 4";
    task4->duration = 8;
    task4->priority = 4;
    createTask(task4->name, task4->duration, task4->priority);

    printQueue();

    executeTask(head);
    executeTask(head->next);

    return 0;
}