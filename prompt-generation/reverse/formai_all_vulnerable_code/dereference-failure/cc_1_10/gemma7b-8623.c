//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* currentTask = *head;
        while (currentTask->next) {
            currentTask = currentTask->next;
        }
        currentTask->next = newTask;
    }
}

void displaySchedule(Task* head) {
    printf("Tasks:\n");
    while (head) {
        printf("%s (Priority: %d)\n", head->name, head->priority);
        head = head->next;
    }
}

int main() {
    time_t t = time(NULL);
    srand(t);

    Task* head = NULL;

    insertTask(&head, "Task 1", 5);
    insertTask(&head, "Task 2", 3);
    insertTask(&head, "Task 3", 2);
    insertTask(&head, "Task 4", 4);

    displaySchedule(head);

    return 0;
}