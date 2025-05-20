//Gemma-7B DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCHEDULER_SIZE 10

typedef struct Task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
    struct Task* next;
} Task;

void insertTask(Task** head, char* name, int priority, time_t start_time, time_t end_time) {
    Task* newTask = malloc(sizeof(Task));
    strcpy(newTask->name, name);
    newTask->priority = priority;
    newTask->start_time = start_time;
    newTask->end_time = end_time;
    newTask->next = NULL;

    if (*head == NULL) {
        *head = newTask;
    } else {
        Task* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newTask;
    }
}

void scheduleTasks(Task* head) {
    time_t current_time = time(NULL);

    while (head) {
        if (head->start_time <= current_time && current_time < head->end_time) {
            printf("Task: %s, Start Time: %s, End Time: %s\n", head->name, head->start_time, head->end_time);
        }
        head = head->next;
    }
}

int main() {
    Task* head = NULL;

    insertTask(&head, "Task 1", 1, 10, 15);
    insertTask(&head, "Task 2", 2, 12, 16);
    insertTask(&head, "Task 3", 3, 14, 18);

    scheduleTasks(head);

    return 0;
}