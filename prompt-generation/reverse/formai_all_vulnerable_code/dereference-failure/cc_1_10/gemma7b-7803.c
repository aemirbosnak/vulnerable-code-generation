//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

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
        Task* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    Task* current = head;
    while (current) {
        if (current->priority == now) {
            printf("Task: %s, Started at: %ld\n", current->name, now);
            current = current->next;
        } else if (current->priority < now) {
            printf("Task: %s, Completed at: %ld\n", current->name, now);
            free(current);
            current = current->next;
        } else {
            current = current->next;
        }
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Wash dishes", 10);
    insertTask(&head, "Do laundry", 8);
    insertTask(&head, "Buy groceries", 6);
    insertTask(&head, "Clean the bathroom", 4);
    insertTask(&head, "Water the plants", 2);

    scheduleTasks(head);

    return 0;
}