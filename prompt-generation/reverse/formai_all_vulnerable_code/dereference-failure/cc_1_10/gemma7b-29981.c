//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t now = time(NULL);
    struct tm* tmNow = localtime(&now);

    while (head) {
        struct tm* tmTask = localtime(&head->priority);

        if (tmTask->tm_hour == tmNow->tm_hour && tmTask->tm_min == tmNow->tm_min) {
            printf("Executing task: %s\n", head->name);
            head = head->next;
        } else if (tmTask->tm_hour > tmNow->tm_hour) {
            break;
        } else {
            head = head->next;
        }
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Pay bills", 1);
    insertTask(&head, "Do laundry", 3);
    insertTask(&head, "Go shopping", 2);
    insertTask(&head, "Study for exams", 4);

    scheduleTasks(head);

    return 0;
}