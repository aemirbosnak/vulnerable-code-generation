//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* tail = *head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* current = head;

    while (current) {
        if (now >= current->priority) {
            printf("Executing task: %s\n", current->name);
            // Simulate task execution
            sleep(2);
        }
        current = current->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 10);
    insertTask(&head, "Task 2", 8);
    insertTask(&head, "Task 3", 12);
    insertTask(&head, "Task 4", 9);

    scheduleTasks(head);

    return 0;
}