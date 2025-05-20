//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 5

typedef struct Task {
    char name[20];
    int priority;
    int time_slot;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority, int time_slot) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->time_slot = time_slot;
    newTask->next = NULL;

    if (head == NULL) {
        return newTask;
    }

    Task* currentTask = head;
    Task* previousTask = NULL;

    while (currentTask) {
        if (newTask->priority < currentTask->priority) {
            break;
        }

        previousTask = currentTask;
        currentTask = currentTask->next;
    }

    if (previousTask) {
        previousTask->next = newTask;
    } else {
        head = newTask;
    }

    return head;
}

void printTasks(Task* head) {
    while (head) {
        printf("%s (%d) at slot %d\n", head->name, head->priority, head->time_slot);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    head = insertTask(head, "Task 1", 1, 10);
    insertTask(head, "Task 2", 2, 12);
    insertTask(head, "Task 3", 3, 14);
    insertTask(head, "Task 4", 4, 16);
    insertTask(head, "Task 5", 5, 18);

    printTasks(head);

    return 0;
}