//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

Task* insertTask(Task* head, char* name, int priority) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (head == NULL) {
        return newTask;
    }

    Task* current = head;
    Task* previous = NULL;

    while (current) {
        if (newTask->priority < current->priority) {
            break;
        }

        previous = current;
        current = current->next;
    }

    if (previous) {
        previous->next = newTask;
    } else {
        head = newTask;
    }

    return head;
}

void printTasks(Task* head) {
    while (head) {
        printf("%s (priority %d)\n", head->name, head->priority);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(head, "Do homework", 3);
    insertTask(head, "Clean the kitchen", 2);
    insertTask(head, "Buy groceries", 4);
    insertTask(head, "Water the plants", 1);

    printTasks(head);

    return 0;
}