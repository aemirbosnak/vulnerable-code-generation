//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULE_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    int estimated_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, int estimated_time) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->estimated_time = estimated_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        (*head)->next = newTask;
    }
}

void printSchedule(Task* head) {
    printf("Schedule:\n");
    while (head) {
        printf("  - %s (priority: %d, estimated time: %d)\n", head->name, head->priority, head->estimated_time);
        head = head->next;
    }
}

void executeTask(Task* head) {
    time_t start_time = time(NULL);
    printf("Executing task: %s\n", head->name);
    sleep(head->estimated_time);
    time_t end_time = time(NULL);
    printf("Task completed: %s (execution time: %d seconds)\n", head->name, (int)(end_time - start_time));
    free(head);
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, 5);
    insertTask(&head, "Task 2", 2, 3);
    insertTask(&head, "Task 3", 3, 7);
    insertTask(&head, "Task 4", 4, 2);

    printSchedule(head);

    executeTask(head);

    printSchedule(head);

    return 0;
}