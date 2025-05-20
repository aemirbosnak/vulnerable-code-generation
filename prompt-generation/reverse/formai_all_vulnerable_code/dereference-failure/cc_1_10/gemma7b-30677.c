//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int start_time;
    int end_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int start, int end) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start;
    newTask->end_time = end;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    while (head) {
        printf("Task: %s, Priority: %d, Start Time: %d, End Time: %d\n", head->name, head->priority, head->start_time, head->end_time);
        sleep(head->start_time);
        printf("Task: %s is running...\n", head->name);
        sleep(head->end_time - head->start_time);
        printf("Task: %s is completed.\n", head->name);
        head = head->next;
    }
}

int main() {
    Task* head = NULL;
    insertTask(&head, "Task 1", 1, 0, 5);
    insertTask(&head, "Task 2", 2, 2, 3);
    insertTask(&head, "Task 3", 1, 3, 4);
    insertTask(&head, "Task 4", 2, 4, 2);

    scheduleTasks(head);

    return 0;
}