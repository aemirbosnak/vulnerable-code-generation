//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: immersive
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
        (*head)->next = newTask;
    }
}

void printTasks(Task* head) {
    while (head) {
        printf("%s (priority: %d)\n", head->name, head->priority);
        head = head->next;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    int i = 0;

    for (head = head; head; head = head->next) {
        int taskTime = now + head->priority;
        if (taskTime > now) {
            printf("Task: %s, scheduled for: %d\n", head->name, taskTime);
        }
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Wake up", 8);
    insertTask(&head, "Breakfast", 6);
    insertTask(&head, "Work", 2);
    insertTask(&head, "Lunch", 4);
    insertTask(&head, "School", 1);
    insertTask(&head, "Dinner", 3);
    insertTask(&head, "Watch TV", 5);

    printTasks(head);
    scheduleTasks(head);

    return 0;
}